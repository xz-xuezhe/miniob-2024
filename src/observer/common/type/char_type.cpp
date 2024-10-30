/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "common/lang/comparator.h"
#include "common/log/log.h"
#include "common/os/path.h"
#include "common/type/char_type.h"
#include "common/value.h"
#include "common/time/datetime.h"

int CharType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::CHARS && right.attr_type() == AttrType::CHARS, "invalid type");
  return common::compare_string(
      (void *)left.value_.pointer_value_, left.length_, (void *)right.value_.pointer_value_, right.length_);
}

RC CharType::set_value_from_str(Value &val, const string &data) const
{
  val.set_string(data.c_str());
  return RC::SUCCESS;
}

RC CharType::cast_to(const Value &val, AttrType type, Value &result) const
{
  switch (type) {
    case AttrType::DATES: {
      result.attr_type_ = type;
      int y, m, d;
      if (sscanf(val.value_.pointer_value_, "%d-%d-%d", &y, &m, &d) != 3 || !common::check_date(y, m, d)) {
        LOG_WARN("invalid date format: %s", val.value_.pointer_value_);
        return RC::INVALID_ARGUMENT;
      }
      result.set_date(y, m, d);
    } break;
    case AttrType::VECTORS: {
      result.attr_type_ = type;
      int8_t has_float  = 0;
      string s          = val.to_string();
      for (const char &c : s)
        if (c == '.') {
          has_float = 1;
          break;
        }
      istringstream sin(s);
      char          c;
      sin >> c;
      if (c != '[')
        return RC::INVALID_ARGUMENT;
      if (has_float) {
        float         x;
        vector<float> v;
        while (c != ']') {
          if (!(sin >> x))
            return RC::INVALID_ARGUMENT;
          v.push_back(x);
          if (!(sin >> c) || !(c == ',' || c == ']'))
            return RC::INVALID_ARGUMENT;
        }
        char *data = new char[sizeof(float) * v.size() + 1];
        *data      = has_float;
        memcpy(data + 1, v.data(), sizeof(float) * v.size());
        result.set_vector(data, sizeof(float) * v.size() + 1);
        delete[] data;
        data = nullptr;
      } else {
        int32_t         x;
        vector<int32_t> v;
        while (c != ']') {
          if (!(sin >> x))
            return RC::INVALID_ARGUMENT;
          v.push_back(x);
          if (!(sin >> c) || !(c == ',' || c == ']'))
            return RC::INVALID_ARGUMENT;
        }
        char *data = new char[sizeof(int32_t) * v.size() + 1];
        *data      = has_float;
        memcpy(data + 1, v.data(), sizeof(int32_t) * v.size());
        result.set_vector(data, sizeof(int32_t) * v.size() + 1);
        delete[] data;
        data = nullptr;
      }
    } break;
    default: return RC::UNIMPLEMENTED;
  }
  return RC::SUCCESS;
}

int CharType::cast_cost(AttrType type)
{
  if (type == AttrType::CHARS) {
    return 0;
  }
  if (type == AttrType::DATES) {
    return 1;
  }
  if (type == AttrType::VECTORS) {
    return 1;
  }
  return INT32_MAX;
}

RC CharType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << val.value_.pointer_value_;
  result = ss.str();
  return RC::SUCCESS;
}
