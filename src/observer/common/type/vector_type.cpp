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
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/vector_type.h"
#include "common/value.h"
#include <cmath>

struct Numeric
{
  bool is_float;
  union
  {
    float   value_float;
    int32_t value_int;
  } value;
  float get_float() const { return is_float ? value.value_float : value.value_int; }
  int   get_int() const { return is_float ? value.value_float : value.value_int; }
};

int get_length(const char *data, int length)
{
  if (data == nullptr)
    return 0;
  return (length - 1) / 4;
}

Numeric get_element_at(const char *data, int offset)
{
  Numeric result;
  result.is_float = *data;
  if (result.is_float)
    result.value.value_float = *(float *)(data + 1 + offset * sizeof(float));
  else
    result.value.value_int = *(int *)(data + 1 + offset * sizeof(int32_t));
  return result;
}

int compare_numeric(void *arg1, void *arg2)
{
  Numeric v1 = *(Numeric *)arg1;
  Numeric v2 = *(Numeric *)arg2;
  if (v1.is_float || v2.is_float) {
    float f1 = v1.get_float();
    float f2 = v2.get_float();
    return common::compare_float(&f1, &f2);
  } else {
    int i1 = v1.get_int();
    int i2 = v2.get_int();
    return common::compare_int(&i1, &i2);
  }
}

int VectorType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::VECTORS && right.attr_type() == AttrType::VECTORS, "invalid type");
  if (left.length() == 0 && right.length() == 0)
    return 0;
  ASSERT(left.length() != 0 && right.length() != 0, "exactly one empty vector");
  int left_length  = get_length(left.data(), left.length());
  int right_length = get_length(right.data(), right.length());
  ASSERT(left_length == right_length, "invalid operation: comparison between vectors of different lengths");
  for (int i = 0; i < left_length; i++) {
    Numeric vl     = get_element_at(left.data(), i);
    Numeric vr     = get_element_at(right.data(), i);
    int     result = compare_numeric(&vl, &vr);
    if (result)
      return result;
  }
  return 0;
}

RC VectorType::add(const Value &left, const Value &right, Value &result) const
{
  RC           rc        = RC::SUCCESS;
  const Value *left_ptr  = &left;
  const Value *right_ptr = &right;
  if (left.attr_type() != AttrType::VECTORS) {
    Value *new_left = new Value;
    rc              = Value::cast_to(left, AttrType::VECTORS, *new_left);
    if (rc != RC::SUCCESS) {
      delete new_left;
      return rc;
    }
    left_ptr = new_left;
  }
  if (right.attr_type() != AttrType::VECTORS) {
    Value *new_right = new Value;
    rc               = Value::cast_to(right, AttrType::VECTORS, *new_right);
    if (rc != RC::SUCCESS) {
      if (&left != left_ptr)
        delete left_ptr;
      delete new_right;
      return rc;
    }
    right_ptr = new_right;
  }
  int left_length  = get_length(left_ptr->data(), left_ptr->length());
  int right_length = get_length(right_ptr->data(), right_ptr->length());
  if (left_length != right_length)
    return RC::INVALID_ARGUMENT;
  int8_t is_float     = *left_ptr->data() | *right_ptr->data();
  int    element_size = 4;
  char * data         = new char[1 + left_length * element_size];
  *data               = is_float;
  for (int i = 0; i < left_length; i++) {
    if (is_float)
      *(float *)(data + 1 + element_size * i) =
          get_element_at(left_ptr->data(), i).get_float() + get_element_at(right_ptr->data(), i).get_float();
    else
      *(int32_t *)(data + 1 + element_size * i) =
          get_element_at(left_ptr->data(), i).get_int() + get_element_at(right_ptr->data(), i).get_int();
  }
  result.set_vector(data, 1 + left_length * element_size);
  if (&left != left_ptr)
    delete left_ptr;
  if (&right != right_ptr)
    delete right_ptr;
  return rc;
}

RC VectorType::subtract(const Value &left, const Value &right, Value &result) const
{
  RC           rc        = RC::SUCCESS;
  const Value *left_ptr  = &left;
  const Value *right_ptr = &right;
  if (left.attr_type() != AttrType::VECTORS) {
    Value *new_left = new Value;
    rc              = Value::cast_to(left, AttrType::VECTORS, *new_left);
    if (rc != RC::SUCCESS) {
      delete new_left;
      return rc;
    }
    left_ptr = new_left;
  }
  if (right.attr_type() != AttrType::VECTORS) {
    Value *new_right = new Value;
    rc               = Value::cast_to(right, AttrType::VECTORS, *new_right);
    if (rc != RC::SUCCESS) {
      if (&left != left_ptr)
        delete left_ptr;
      delete new_right;
      return rc;
    }
    right_ptr = new_right;
  }
  int left_length  = get_length(left_ptr->data(), left_ptr->length());
  int right_length = get_length(right_ptr->data(), right_ptr->length());
  if (left_length != right_length)
    return RC::INVALID_ARGUMENT;
  int8_t is_float     = *left_ptr->data() | *right_ptr->data();
  int    element_size = 4;
  char * data         = new char[1 + left_length * element_size];
  *data               = is_float;
  for (int i = 0; i < left_length; i++) {
    if (is_float)
      *(float *)(data + 1 + element_size * i) =
          get_element_at(left_ptr->data(), i).get_float() - get_element_at(right_ptr->data(), i).get_float();
    else
      *(int32_t *)(data + 1 + element_size * i) =
          get_element_at(left_ptr->data(), i).get_int() - get_element_at(right_ptr->data(), i).get_int();
  }
  result.set_vector(data, 1 + left_length * element_size);
  if (&left != left_ptr)
    delete left_ptr;
  if (&right != right_ptr)
    delete right_ptr;
  return rc;
}

RC VectorType::multiply(const Value &left, const Value &right, Value &result) const
{
  RC           rc        = RC::SUCCESS;
  const Value *left_ptr  = &left;
  const Value *right_ptr = &right;
  if (left.attr_type() != AttrType::VECTORS) {
    Value *new_left = new Value;
    rc              = Value::cast_to(left, AttrType::VECTORS, *new_left);
    if (rc != RC::SUCCESS) {
      delete new_left;
      return rc;
    }
    left_ptr = new_left;
  }
  if (right.attr_type() != AttrType::VECTORS) {
    Value *new_right = new Value;
    rc               = Value::cast_to(right, AttrType::VECTORS, *new_right);
    if (rc != RC::SUCCESS) {
      if (&left != left_ptr)
        delete left_ptr;
      delete new_right;
      return rc;
    }
    right_ptr = new_right;
  }
  int left_length  = get_length(left_ptr->data(), left_ptr->length());
  int right_length = get_length(right_ptr->data(), right_ptr->length());
  if (left_length != right_length)
    return RC::INVALID_ARGUMENT;
  int8_t is_float     = *left_ptr->data() | *right_ptr->data();
  int    element_size = 4;
  char * data         = new char[1 + left_length * element_size];
  *data               = is_float;
  for (int i = 0; i < left_length; i++) {
    if (is_float)
      *(float *)(data + 1 + element_size * i) =
          get_element_at(left_ptr->data(), i).get_float() * get_element_at(right_ptr->data(), i).get_float();
    else
      *(int32_t *)(data + 1 + element_size * i) =
          get_element_at(left_ptr->data(), i).get_int() * get_element_at(right_ptr->data(), i).get_int();
  }
  result.set_vector(data, 1 + left_length * element_size);
  if (&left != left_ptr)
    delete left_ptr;
  if (&right != right_ptr)
    delete right_ptr;
  return rc;
}

RC VectorType::l2_distance(const Value &left, const Value &right, Value &result) const
{
  RC           rc        = RC::SUCCESS;
  const Value *left_ptr  = &left;
  const Value *right_ptr = &right;
  if (left.attr_type() != AttrType::VECTORS) {
    Value *new_left = new Value;
    rc              = Value::cast_to(left, AttrType::VECTORS, *new_left);
    if (rc != RC::SUCCESS) {
      delete new_left;
      return rc;
    }
    left_ptr = new_left;
  }
  if (right.attr_type() != AttrType::VECTORS) {
    Value *new_right = new Value;
    rc               = Value::cast_to(right, AttrType::VECTORS, *new_right);
    if (rc != RC::SUCCESS) {
      if (&left != left_ptr)
        delete left_ptr;
      delete new_right;
      return rc;
    }
    right_ptr = new_right;
  }
  int left_length  = get_length(left_ptr->data(), left_ptr->length());
  int right_length = get_length(right_ptr->data(), right_ptr->length());
  if (left_length != right_length)
    return RC::INVALID_ARGUMENT;
  float sum = 0;
  for (int i = 0; i < left_length; i++) {
    float value_left  = get_element_at(left_ptr->data(), i).get_float();
    float value_right = get_element_at(right_ptr->data(), i).get_float();
    sum += (value_left - value_right) * (value_left - value_right);
  }
  result.set_float(std::round(std::sqrt(sum) * 100) / 100);
  if (&left != left_ptr)
    delete left_ptr;
  if (&right != right_ptr)
    delete right_ptr;
  return rc;
}

RC VectorType::cosine_distance(const Value &left, const Value &right, Value &result) const
{
  RC           rc        = RC::SUCCESS;
  const Value *left_ptr  = &left;
  const Value *right_ptr = &right;
  if (left.attr_type() != AttrType::VECTORS) {
    Value *new_left = new Value;
    rc              = Value::cast_to(left, AttrType::VECTORS, *new_left);
    if (rc != RC::SUCCESS) {
      delete new_left;
      return rc;
    }
    left_ptr = new_left;
  }
  if (right.attr_type() != AttrType::VECTORS) {
    Value *new_right = new Value;
    rc               = Value::cast_to(right, AttrType::VECTORS, *new_right);
    if (rc != RC::SUCCESS) {
      if (&left != left_ptr)
        delete left_ptr;
      delete new_right;
      return rc;
    }
    right_ptr = new_right;
  }
  int left_length  = get_length(left_ptr->data(), left_ptr->length());
  int right_length = get_length(right_ptr->data(), right_ptr->length());
  if (left_length != right_length)
    return RC::INVALID_ARGUMENT;
  float sum_dot   = 0;
  float sum_left  = 0;
  float sum_right = 0;
  for (int i = 0; i < left_length; i++) {
    float value_left  = get_element_at(left_ptr->data(), i).get_float();
    float value_right = get_element_at(right_ptr->data(), i).get_float();
    sum_dot += value_left * value_right;
    sum_left += value_left * value_left;
    sum_right += value_right * value_right;
  }
  result.set_float(std::round((1 - sum_dot / std::sqrt(sum_left * sum_right)) * 100) / 100);
  if (&left != left_ptr)
    delete left_ptr;
  if (&right != right_ptr)
    delete right_ptr;
  return rc;
}

RC VectorType::inner_product(const Value &left, const Value &right, Value &result) const
{
  RC           rc        = RC::SUCCESS;
  const Value *left_ptr  = &left;
  const Value *right_ptr = &right;
  if (left.attr_type() != AttrType::VECTORS) {
    Value *new_left = new Value;
    rc              = Value::cast_to(left, AttrType::VECTORS, *new_left);
    if (rc != RC::SUCCESS) {
      delete new_left;
      return rc;
    }
    left_ptr = new_left;
  }
  if (right.attr_type() != AttrType::VECTORS) {
    Value *new_right = new Value;
    rc               = Value::cast_to(right, AttrType::VECTORS, *new_right);
    if (rc != RC::SUCCESS) {
      if (&left != left_ptr)
        delete left_ptr;
      delete new_right;
      return rc;
    }
    right_ptr = new_right;
  }
  int left_length  = get_length(left_ptr->data(), left_ptr->length());
  int right_length = get_length(right_ptr->data(), right_ptr->length());
  if (left_length != right_length)
    return RC::INVALID_ARGUMENT;
  float sum = 0;
  for (int i = 0; i < left_length; i++) {
    float value_left  = get_element_at(left_ptr->data(), i).get_float();
    float value_right = get_element_at(right_ptr->data(), i).get_float();
    sum += value_left * value_right;
  }
  result.set_float(std::round(sum * 100) / 100);
  if (&left != left_ptr)
    delete left_ptr;
  if (&right != right_ptr)
    delete right_ptr;
  return rc;
}

RC VectorType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << '[';
  int length = get_length(val.data(), val.length());
  for (int i = 0; i < length; i++) {
    if (i)
      ss << ',';
    Numeric v = get_element_at(val.data(), i);
    if (v.is_float)
      ss << std::round(v.value.value_float * 100) / 100;
    else
      ss << v.value.value_int;
  }
  ss << ']';
  result = ss.str();
  return RC::SUCCESS;
}
