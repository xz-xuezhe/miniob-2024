/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "sql/operator/order_by_physical_operator.h"

OrderByPhysicalOperator::OrderByPhysicalOperator(vector<pair<unique_ptr<Expression>, bool>> &&order_by)
{
  order_by_ = std::move(order_by);
}

RC OrderByPhysicalOperator::open(Trx *trx)
{
  if (children_.size() != 1) {
    LOG_WARN("order by operator should have 1 children");
    return RC::INTERNAL;
  }
  RC                            rc    = RC::SUCCESS;
  unique_ptr<PhysicalOperator> &child = children_[0];
  rc                                  = child->open(trx);
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to open child oper. rc=%s", strrc(rc));
    return rc;
  }
  for (;;) {
    rc = child->next();
    if (OB_FAIL(rc)) {
      if (rc == RC::RECORD_EOF)
        break;
      LOG_WARN("failed to get the next item");
      return rc;
    }
    ValueListTuple tuple;
    rc = ValueListTuple::make(*child->current_tuple(), tuple);
    if (OB_FAIL(rc)) {
      LOG_WARN("failed to make value list tuple");
      return rc;
    }
    vector<pair<Value, bool>> values;
    for (pair<unique_ptr<Expression>, bool> &item : order_by_) {
      Value value;
      rc = item.first->get_value(tuple, value);
      if (OB_FAIL(rc)) {
        LOG_WARN("failed to get value");
        return rc;
      }
      values.emplace_back(value, item.second);
    }
    tuples_.emplace_back(std::move(values), tuple);
  }
  rc = child->close();
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to close child oper. rc=%s", strrc(rc));
    return rc;
  }
  sort(tuples_.begin(),
      tuples_.end(),
      [](const pair<vector<pair<Value, bool>>, ValueListTuple> & l,
          const pair<vector<pair<Value, bool>>, ValueListTuple> &r) {
        ASSERT(l.first.size() == r.first.size(), "length should be same");
        for (size_t i = 0; i != l.first.size(); i++) {
          bool bl = l.first[i].first.is_null();
          bool br = r.first[i].first.is_null();
          if (bl && br)
            continue;
          if (bl)
            return true;
          if (br)
            return false;
          int result = l.first[i].first.compare(r.first[i].first);
          if (result == 0)
            continue;
          return (result < 0) == l.first[i].second;
        }
        return false;
      });
  trx_       = trx;
  tuples_it_ = tuples_.begin();
  return rc;
}

RC OrderByPhysicalOperator::next()
{
  if (tuples_it_ == tuples_.end())
    return RC::RECORD_EOF;
  current_tuple_ = &tuples_it_++->second;
  return RC::SUCCESS;
}

RC OrderByPhysicalOperator::close()
{
  tuples_.clear();
  tuples_it_ = tuples_.end();
  return RC::SUCCESS;
}

Tuple *OrderByPhysicalOperator::current_tuple() { return current_tuple_; }
