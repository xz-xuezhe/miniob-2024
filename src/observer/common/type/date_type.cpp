#include "common/lang/comparator.h"
#include "common/lang/iomanip.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/date_type.h"
#include "common/value.h"
#include <iomanip>

int DateType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::DATES, "left type is not date");
  ASSERT(right.attr_type() == AttrType::DATES, "right type is not date");
  if (right.attr_type() == AttrType::DATES) {
    return common::compare_int((void *)&left.value_.int_value_, (void *)&right.value_.int_value_);
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
