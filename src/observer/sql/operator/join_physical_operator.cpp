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
// Created by WangYunlai on 2022/12/30.
//

#include "sql/operator/join_physical_operator.h"

NestedLoopJoinPhysicalOperator::NestedLoopJoinPhysicalOperator() {}

RC NestedLoopJoinPhysicalOperator::open(Trx *trx)
{
  if (children_.size() != 2) {
    LOG_WARN("nlj operator should have 2 children");
    return RC::INTERNAL;
  }

  RC rc         = RC::SUCCESS;
  left_         = children_[0].get();
  right_        = children_[1].get();
  rc = right_->open(trx);
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to open right oper. rc=%s", strrc(rc));
    return rc;
  }
  while ((rc = right_->next()) != RC::RECORD_EOF) {
    if (OB_FAIL(rc))
      return rc;
    ValueListTuple temp;
    rc = ValueListTuple::make(*right_->current_tuple(), temp);
    if (OB_FAIL(rc))
      return rc;
    right_tuples_.push_back(temp);
  }
  rc = right_->close();
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to close right oper. rc=%s", strrc(rc));
    return rc;
  }
  right_it_ = right_tuples_.end();
  round_done_   = true;

  rc   = left_->open(trx);
  trx_ = trx;
  return rc;
}

RC NestedLoopJoinPhysicalOperator::next()
{
  bool left_need_step = (left_tuple_ == nullptr);
  RC   rc             = RC::SUCCESS;
  if (round_done_) {
    left_need_step = true;
  } else {
    rc = right_next();
    if (rc != RC::SUCCESS) {
      if (rc == RC::RECORD_EOF) {
        left_need_step = true;
      } else {
        return rc;
      }
    } else {
      return rc;  // got one tuple from right
    }
  }

  if (left_need_step) {
    rc = left_next();
    if (rc != RC::SUCCESS) {
      return rc;
    }
  }

  rc = right_next();
  return rc;
}

RC NestedLoopJoinPhysicalOperator::close()
{
  right_tuples_.clear();
  RC rc = left_->close();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to close left oper. rc=%s", strrc(rc));
  }
  return rc;
}

Tuple *NestedLoopJoinPhysicalOperator::current_tuple() { return &joined_tuple_; }

RC NestedLoopJoinPhysicalOperator::left_next()
{
  RC rc = RC::SUCCESS;
  rc    = left_->next();
  if (rc != RC::SUCCESS) {
    return rc;
  }

  left_tuple_ = left_->current_tuple();
  joined_tuple_.set_left(left_tuple_);
  return rc;
}

RC NestedLoopJoinPhysicalOperator::right_next()
{
  RC rc = RC::SUCCESS;
  if (round_done_) {
    right_tuple_ = nullptr;
    right_it_ = right_tuples_.begin();
    round_done_ = false;
  }

  if (right_it_ == right_tuples_.end()) {
    round_done_ = true;
    return RC::RECORD_EOF;
  }
  right_tuple_ = &*right_it_++;
  joined_tuple_.set_right(right_tuple_);
  return rc;
}

HashJoinPhysicalOperator::HashJoinPhysicalOperator(std::unique_ptr<Expression> predicate)
    : predicate_(std::move(predicate))
{}

RC HashJoinPhysicalOperator::open(Trx *trx)
{
  if (children_.size() != 2) {
    LOG_WARN("hj operator should have 2 children");
    return RC::INTERNAL;
  }
  if (!predicate_ || predicate_->type() != ExprType::COMPARISON) {
    LOG_WARN("predicate should be a comparison expression");
    return RC::INTERNAL;
  }
  ComparisonExpr &predicate = static_cast<ComparisonExpr &>(*predicate_);
  if (predicate.comp() != CompOp::EQUAL_TO) {
    LOG_WARN("predicate should be an equality");
    return RC::INTERNAL;
  }
  predicate_left_  = predicate.left().get();
  predicate_right_ = predicate.right().get();

  RC rc  = RC::SUCCESS;
  left_  = children_[0].get();
  right_ = children_[1].get();
  rc     = right_->open(trx);
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to open right oper. rc=%s", strrc(rc));
    return rc;
  }
  for (;;) {
    rc = right_->next();
    if (OB_FAIL(rc)) {
      if (rc == RC::RECORD_EOF)
        break;
      return rc;
    }
    Value value;
    rc = predicate_right_->get_value(*right_->current_tuple(), value);
    if (OB_FAIL(rc))
      return rc;
    if (value.is_null())
      continue;
    const string &str = value.to_string();
    auto          it  = tuple_map_.find(str);
    if (it == tuple_map_.end())
      it = tuple_map_.insert({str, std::vector<ValueListTuple>()}).first;
    ValueListTuple temp;
    rc = ValueListTuple::make(*right_->current_tuple(), temp);
    if (OB_FAIL(rc)) {
      LOG_WARN("failed to make value list tuple");
      return rc;
    }
    it->second.push_back(temp);
  }
  rc = right_->close();
  if (OB_FAIL(rc)) {
    LOG_WARN("failed to close right oper. rc=%s", strrc(rc));
    return rc;
  }
  rc            = left_->open(trx);
  trx_          = trx;
  map_iterator_ = tuple_map_.end();
  return rc;
}

RC HashJoinPhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  while (map_iterator_ == tuple_map_.end() || vector_iterator_ == map_iterator_->second.end()) {
    rc = left_next();
    if (OB_FAIL(rc))
      return rc;
  }
  rc = right_next();
  return rc;
}

RC HashJoinPhysicalOperator::close()
{
  RC rc = left_->close();
  if (rc != RC::SUCCESS)
    LOG_WARN("failed to close left oper. rc=%s", strrc(rc));
  tuple_map_.clear();
  return rc;
}

Tuple *HashJoinPhysicalOperator::current_tuple() { return &joined_tuple_; }

RC HashJoinPhysicalOperator::left_next()
{
  RC rc = RC::SUCCESS;
  rc    = left_->next();
  if (OB_FAIL(rc))
    return rc;
  Value value;
  rc = predicate_left_->get_value(*left_->current_tuple(), value);
  if (OB_FAIL(rc))
    return rc;
  if (value.is_null()) {
    map_iterator_ = tuple_map_.end();
    return rc;
  }
  const string &str = value.to_string();
  map_iterator_     = tuple_map_.find(str);
  if (map_iterator_ != tuple_map_.end())
    vector_iterator_ = map_iterator_->second.begin();
  left_tuple_ = left_->current_tuple();
  joined_tuple_.set_left(left_tuple_);
  return rc;
}

RC HashJoinPhysicalOperator::right_next()
{
  if (map_iterator_ == tuple_map_.end() || vector_iterator_ == map_iterator_->second.end())
    return RC::RECORD_EOF;
  right_tuple_ = (&*vector_iterator_++);
  joined_tuple_.set_right(right_tuple_);
  return RC::SUCCESS;
}
