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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/field/field_meta.h"
#include "storage/table/table.h"

UpdateStmt::UpdateStmt(Table *table, const std::vector<std::pair<const FieldMeta *, const Value *>> &assignments, FilterStmt *filter_stmt)
    : table_(table), assignments_(assignments), filter_stmt_(filter_stmt)
{}

RC UpdateStmt::create(Db *db, UpdateSqlNode &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || update.assignments.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // check whether the fields exists
  std::vector<std::pair<const FieldMeta *, const Value *>> assignments;
  for (std::unique_ptr<Assignment> &assignment : update.assignments) {
    const TableMeta &table_meta = table->table_meta();
    const char *field_name = assignment->attribute_name.c_str();
    const FieldMeta *field_meta = table_meta.field(field_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. db=%s, table_name=%s, field_name=%s", db->name(), table_name, field_name);
      return RC::SCHEMA_FIELD_NOT_EXIST;
    }
    assignments.emplace_back(field_meta, &assignment->value);
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  RC          rc          = FilterStmt::create(db, table, &table_map, std::move(update.conditions), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  stmt = new UpdateStmt(table, assignments, filter_stmt);
  return rc;
}
