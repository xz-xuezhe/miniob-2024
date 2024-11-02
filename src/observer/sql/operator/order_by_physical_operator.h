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
// Created by WangYunlai on 2021/6/10.
//

#pragma once

#include "sql/operator/physical_operator.h"
#include "sql/parser/parse.h"

/**
 * @brief 排序算子
 * @details 将所有条目取出后排序
 * @ingroup PhysicalOperator
 */
class OrderByPhysicalOperator : public PhysicalOperator
{
public:
  OrderByPhysicalOperator(std::vector<std::pair<std::unique_ptr<Expression>, bool>> &&order_by);
  virtual ~OrderByPhysicalOperator() = default;

  PhysicalOperatorType type() const override { return PhysicalOperatorType::ORDER_BY; }

  RC     open(Trx *trx) override;
  RC     next() override;
  RC     close() override;
  Tuple *current_tuple() override;

private:
  Trx *                                                                       trx_ = nullptr;
  vector<pair<unique_ptr<Expression>, bool>>                                  order_by_;  //! 排序对象
  std::vector<std::pair<std::vector<std::pair<Value, bool>>, ValueListTuple>> tuples_;    //! 排序完成后的记录
  std::vector<std::pair<std::vector<std::pair<Value, bool>>, ValueListTuple>>::iterator tuples_it_;  //! 当前记录
  Tuple *                                                                               current_tuple_ = nullptr;
};
