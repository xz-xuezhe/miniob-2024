/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#pragma once

#include "common/rc.h"
#include "common/type/data_type.h"

/**
 * @brief 空类型
 * @ingroup DataType
 */
class NullType : public DataType
{
public:
  NullType() : DataType(AttrType::NULLS) {}
  virtual ~NullType() = default;
  RC add(const Value &left, const Value &right, Value &result) const override;
  RC subtract(const Value &left, const Value &right, Value &result) const override;
  RC multiply(const Value &left, const Value &right, Value &result) const override;
  RC divide(const Value &left, const Value &right, Value &result) const override;
  RC negative(const Value &val, Value &result) const override;
  RC to_string(const Value &val, string &result) const override;
};