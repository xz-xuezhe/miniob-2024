/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2021/5/7.
//

#include "condition_filter.h"
#include "common/log/log.h"
#include "common/value.h"
#include "storage/record/record_manager.h"
#include "storage/table/table.h"
#include "sql/expr/expression.h"
#include "sql/expr/expression_iterator.h"
#include <math.h>
#include <stddef.h>

using namespace common;

ConditionFilter::~ConditionFilter() {}

DefaultConditionFilter::DefaultConditionFilter() {}
DefaultConditionFilter::~DefaultConditionFilter() {}

RC DefaultConditionFilter::init(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right, AttrType attr_type, CompOp comp_op, std::unique_ptr<RowTuple> tuple)
{
  if (attr_type <= AttrType::UNDEFINED || attr_type >= AttrType::MAXTYPE) {
    LOG_ERROR("Invalid condition with unsupported attribute type: %d", attr_type);
    return RC::INVALID_ARGUMENT;
  }

  if (comp_op < EQUAL_TO || comp_op >= NO_OP) {
    LOG_ERROR("Invalid condition with unsupported compare operation: %d", comp_op);
    return RC::INVALID_ARGUMENT;
  }

  left_      = std::move(left);
  right_     = std::move(right);
  attr_type_ = attr_type;
  comp_op_   = comp_op;
  tuple_     = std::move(tuple);
  return RC::SUCCESS;
}

RC DefaultConditionFilter::init(Table &table, ConditionSqlNode &condition)
{
  RC                                          rc         = RC::SUCCESS;
  const TableMeta &                           table_meta = table.table_meta();
  function<RC(std::unique_ptr<Expression> &)> binder     = [&](unique_ptr<Expression> &expr) -> RC {
    RC rc = RC::SUCCESS;
    switch (expr->type()) {
      case ExprType::STAR: {
        return RC::INVALID_ARGUMENT;
      } break;
      case ExprType::VALUE:
      case ExprType::FIELD: {
        return RC::SUCCESS;
      } break;
      case ExprType::UNBOUND_FIELD: {
        const char *     field_name = static_cast<const UnboundFieldExpr &>(*expr).field_name();
        const FieldMeta *field_meta = table_meta.field(field_name);
        if (nullptr == field_meta) {
          LOG_WARN("No such field in condition. %s.%s", table.name(), field_name);
          return RC::SCHEMA_FIELD_MISSING;
        }
        if (OB_FAIL(rc))
          return rc;
        Field field(&table, field_meta);
        expr.reset(new FieldExpr(field));
        return rc;
      } break;
      case ExprType::NONE:
      case ExprType::CAST:
      case ExprType::COMPARISON:
      case ExprType::CONJUNCTION:
      case ExprType::ARITHMETIC:
      case ExprType::AGGREGATION:
      case ExprType::FUNCTION: {
        // Do nothing
      } break;
      default: {
        ASSERT(false, "Unknown expression type");
      }
    }
    rc = ExpressionIterator::iterate_child_expr(*expr, binder);
    if (OB_FAIL(rc))
      return rc;
    return rc;
  };
  rc = binder(condition.left);
  if (OB_FAIL(rc))
    return rc;
  rc = binder(condition.right);
  if (OB_FAIL(rc))
    return rc;
  AttrType type_left  = condition.left->value_type();
  AttrType type_right = condition.right->value_type();

  // 校验和转换
  //  if (!field_type_compare_compatible_table[type_left][type_right]) {
  //    // 不能比较的两个字段， 要把信息传给客户端
  //    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  //  }
  // NOTE：这里没有实现不同类型的数据比较，比如整数跟浮点数之间的对比
  // 但是选手们还是要实现。这个功能在预选赛中会出现
  if (type_left != type_right) {
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  std::unique_ptr<RowTuple> tuple(new RowTuple);
  tuple->set_schema(&table, table.table_meta().field_metas());

  return init(std::move(condition.left), std::move(condition.right), type_left, condition.comp, std::move(tuple));
}

bool DefaultConditionFilter::filter(Record &rec) const
{
  RC rc = RC::SUCCESS;
  tuple_->set_record(&rec);
  Value left_value;
  Value right_value;
  rc = left_->get_value(*tuple_, left_value);
  ASSERT(rc == RC::SUCCESS, "Failed to get left_value");
  rc = right_->get_value(*tuple_, right_value);
  ASSERT(rc == RC::SUCCESS, "Failed to get right_value");
  tuple_->set_record(nullptr);

  int cmp_result = left_value.compare(right_value);

  switch (comp_op_) {
    case EQUAL_TO: return 0 == cmp_result;
    case LESS_EQUAL: return cmp_result <= 0;
    case NOT_EQUAL: return cmp_result != 0;
    case LESS_THAN: return cmp_result < 0;
    case GREAT_EQUAL: return cmp_result >= 0;
    case GREAT_THAN: return cmp_result > 0;

    default: break;
  }

  LOG_PANIC("Never should print this.");
  return cmp_result;  // should not go here
}

CompositeConditionFilter::~CompositeConditionFilter()
{
  if (memory_owner_) {
    delete[] filters_;
    filters_ = nullptr;
  }
}

RC CompositeConditionFilter::init(const ConditionFilter *filters[], int filter_num, bool own_memory)
{
  filters_      = filters;
  filter_num_   = filter_num;
  memory_owner_ = own_memory;
  return RC::SUCCESS;
}
RC CompositeConditionFilter::init(const ConditionFilter *filters[], int filter_num)
{
  return init(filters, filter_num, false);
}

RC CompositeConditionFilter::init(Table &table, ConditionSqlNode *conditions, int condition_num)
{
  if (condition_num == 0) {
    return RC::SUCCESS;
  }
  if (conditions == nullptr) {
    return RC::INVALID_ARGUMENT;
  }

  RC                rc                = RC::SUCCESS;
  ConditionFilter **condition_filters = new ConditionFilter *[condition_num];
  for (int i = 0; i < condition_num; i++) {
    DefaultConditionFilter *default_condition_filter = new DefaultConditionFilter();
    rc                                               = default_condition_filter->init(table, conditions[i]);
    if (rc != RC::SUCCESS) {
      delete default_condition_filter;
      for (int j = i - 1; j >= 0; j--) {
        delete condition_filters[j];
        condition_filters[j] = nullptr;
      }
      delete[] condition_filters;
      condition_filters = nullptr;
      return rc;
    }
    condition_filters[i] = default_condition_filter;
  }
  return init((const ConditionFilter **)condition_filters, condition_num, true);
}

bool CompositeConditionFilter::filter(Record &rec) const
{
  for (int i = 0; i < filter_num_; i++) {
    if (!filters_[i]->filter(rec)) {
      return false;
    }
  }
  return true;
}
