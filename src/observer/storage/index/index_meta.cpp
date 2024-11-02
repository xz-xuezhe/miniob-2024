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
// Created by Wangyunlai.wyl on 2021/5/18.
//

#include "storage/index/index_meta.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "storage/field/field_meta.h"
#include "storage/table/table_meta.h"
#include "json/json.h"

const static Json::StaticString FIELD_NAME("name");
const static Json::StaticString FIELD_FIELD_NAME("field_name");
const static Json::StaticString UNIQUE("unique");

RC IndexMeta::init(const char *name, const std::vector<const FieldMeta *> &fields, bool unique /*= false*/)
{
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }

  name_  = name;
  for (const FieldMeta *field : fields) {
    if (nullptr == field || common::is_blank(field->name()))
      return RC::INVALID_ARGUMENT;
    fields_.push_back(field->name());
  }

  unique_ = unique;
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
  json_value[FIELD_NAME] = name_;
  for(size_t i = 0; i != fields_.size(); i++)
    json_value[FIELD_FIELD_NAME][static_cast<int>(i)] = fields_[i];
  json_value[UNIQUE] = unique_;
}

RC IndexMeta::from_json(const TableMeta &table, const Json::Value &json_value, IndexMeta &index)
{
  const Json::Value &name_value  = json_value[FIELD_NAME];
  const Json::Value &fields_value = json_value[FIELD_FIELD_NAME];
  const Json::Value &unique_value = json_value[UNIQUE];
  if (!name_value.isString()) {
    LOG_ERROR("Index name is not a string. json value=%s", name_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  if (!fields_value.isArray()) {
    LOG_ERROR("Field names of index [%s] is not a array. json value=%s",
        name_value.asCString(), fields_value.toStyledString().c_str());
    return RC::INTERNAL;
  }

  std::vector<const FieldMeta *> fields;
  for(Json::ArrayIndex i = 0; i != fields_value.size(); i++) {
    if (!fields_value[i].isString()) {
      LOG_ERROR("Field name of index [%s] is not a string. json value=%s",
          name_value.asCString(), fields_value[i].toStyledString().c_str());
      return RC::INTERNAL;
    }
    const FieldMeta *field = table.field(fields_value[i].asCString());
    if (nullptr == field) {
      LOG_ERROR("Deserialize index [%s]: no such field: %s", name_value.asCString(), fields_value[i].asCString());
      return RC::SCHEMA_FIELD_MISSING;
    }
  }

  if (!unique_value.isBool()) {
    LOG_ERROR("Unique of index [%s] is not a boolean value. json value=%s", name_value.asCString(), unique_value.toStyledString().c_str());
    return RC::INTERNAL;
  }
  bool unique = unique_value.asBool();

  return index.init(name_value.asCString(), fields, unique);
}

const char *IndexMeta::name() const { return name_.c_str(); }

const vector<string> &IndexMeta::fields() const { return fields_; }

bool IndexMeta::unique() const { return unique_; }

void IndexMeta::desc(ostream &os) const {
  os << "index name=" << name_ << ", fields=[";
  for(size_t i = 0; i != fields_.size(); i++) {
    if (i)
      os << ", ";
    os << fields_[i];
  }
  os << ']';
}