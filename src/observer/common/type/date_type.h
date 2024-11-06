#pragma once

#include "common/type/data_type.h"

class DateType : public DataType
{
public:
  DateType() : DataType(AttrType::DATES) {}
  virtual ~DateType() {}

  int compare(const Value &left, const Value &right) const override;
  RC cast_to(const Value &val, AttrType type, Value &result) const override;
  int cast_cost(AttrType type) override;

  RC to_string(const Value &val, string &result) const override;
};
