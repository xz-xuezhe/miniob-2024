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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/filter_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "sql/expr/expression.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/expr/expression_iterator.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    std::unique_ptr<ConditionSqlNode> *conditions, int condition_num, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt  = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;

    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const UnboundFieldExpr &expr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(expr.table_name())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(expr.table_name());
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(expr.table_name());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", expr.table_name());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(expr.field_name());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), expr.field_name());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    std::unique_ptr<ConditionSqlNode> &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;

  CompOp comp = condition->comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  function<RC(std::unique_ptr<Expression> &)> binder = [&](unique_ptr<Expression> &expr) -> RC {
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
        Table *          table = nullptr;
        const FieldMeta *field_meta = nullptr;
        rc = get_table_and_field(db, default_table, tables, static_cast<const UnboundFieldExpr &>(*expr), table, field_meta);
        if (OB_FAIL(rc))
          return rc;
        Field field(table, field_meta);
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
    return ExpressionIterator::iterate_child_expr(*expr, binder);
  };

  rc = binder(condition->left);
  if (OB_FAIL(rc))
    return rc;
  rc = binder(condition->right);
  if (OB_FAIL(rc))
    return rc;
  filter_unit = new FilterUnit;
  filter_unit->set_comp(comp);
  filter_unit->set_left(std::move(condition->left));
  filter_unit->set_right(std::move(condition->right));

  // 检查两个类型是否能够比较
  return rc;
}
