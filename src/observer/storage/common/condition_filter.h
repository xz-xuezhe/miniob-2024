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

#pragma once

#include "sql/parser/parse.h"
#include "sql/expr/tuple.h"

class Record;
class Table;

struct ConDesc
{
  bool  is_attr;      // 是否属性，false 表示是值
  int   attr_length;  // 如果是属性，表示属性值长度
  int   attr_offset;  // 如果是属性，表示在记录中的偏移量
  Value value;        // 如果是值类型，这里记录值的数据
};

class ConditionFilter
{
public:
  virtual ~ConditionFilter();

  /**
   * Filter one record
   * @param rec
   * @return true means match condition, false means failed to match.
   */
  virtual bool filter(Record &rec) const = 0;
};

class DefaultConditionFilter : public ConditionFilter
{
public:
  DefaultConditionFilter();
  virtual ~DefaultConditionFilter();

  RC init(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right, AttrType attr_type, CompOp comp_op, std::unique_ptr<RowTuple> tuple);
  RC init(Table &table, ConditionSqlNode &condition);

  virtual bool filter(Record &rec) const;

public:
  const std::unique_ptr<Expression> &left() const { return left_; }
  const std::unique_ptr<Expression> &right() const { return right_; }

  CompOp   comp_op() const { return comp_op_; }
  AttrType attr_type() const { return attr_type_; }

private:
  std::unique_ptr<Expression> left_  = nullptr;
  std::unique_ptr<Expression> right_ = nullptr;
  AttrType                    attr_type_ = AttrType::UNDEFINED;
  CompOp                      comp_op_   = NO_OP;
  std::unique_ptr<RowTuple>   tuple_;
};

class CompositeConditionFilter : public ConditionFilter
{
public:
  CompositeConditionFilter() = default;
  virtual ~CompositeConditionFilter();

  RC init(const ConditionFilter *filters[], int filter_num);
  RC init(Table &table, ConditionSqlNode *conditions, int condition_num);

  virtual bool filter(Record &rec) const;

public:
  int                    filter_num() const { return filter_num_; }
  const ConditionFilter &filter(int index) const { return *filters_[index]; }

private:
  RC init(const ConditionFilter *filters[], int filter_num, bool own_memory);

private:
  const ConditionFilter **filters_      = nullptr;
  int                     filter_num_   = 0;
  bool                    memory_owner_ = false;  // filters_的内存是否由自己来控制
};
