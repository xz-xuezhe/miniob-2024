#include "common/lang/comparator.h"
#include "common/lang/iomanip.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/date_type.h"
#include "common/value.h"

int DateType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::DATES, "left type is not date");
  ASSERT(right.attr_type() == AttrType::DATES, "right type is not date");
  if (right.attr_type() == AttrType::DATES) {
    return common::compare_int((void *)&left.value_.int_value_, (void *)&right.value_.int_value_);
  }
  return INT32_MAX;
}

RC DateType::cast_to(const Value &val, AttrType type, Value &result) const
{
  switch (type) {
    case AttrType::NULLS: {
      result.set_null();
    } break;
    default: return RC::UNIMPLEMENTED;
  }
  return RC::SUCCESS;
}

int DateType::cast_cost(AttrType type)
{
  if (type == AttrType::DATES) {
    return 0;
  }
  if (type == AttrType::NULLS) {
    return 1;
  }
  return INT32_MAX;
}

RC DateType::to_string(const Value &val, string &result) const
{
  stringstream ss;
  ss << setw(4) << setfill('0') << val.value_.int_value_ / 10000;
  ss << '-';
  ss << setw(2) << setfill('0') << val.value_.int_value_ / 100 % 100;
  ss << '-';
  ss << setw(2) << setfill('0') << val.value_.int_value_ % 100;
  result = ss.str();
  return RC::SUCCESS;
}
