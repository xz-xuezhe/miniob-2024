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

#pragma once

#include "common/rc.h"
#include "sql/stmt/stmt.h"

class Table;
class FilterStmt;
class FieldMeta;

/**
 * @brief 更新语句
 * @ingroup Statement
 */
class UpdateStmt : public Stmt
{
public:
  UpdateStmt() = default;
  UpdateStmt(Table *table, const std::vector<std::pair<const FieldMeta *, const Value *>> &assignments, FilterStmt *filter_stmt);

public:
  static RC create(Db *db, UpdateSqlNode &update_sql, Stmt *&stmt);

public:
  Table *                                                         table() const { return table_; }
  const std::vector<std::pair<const FieldMeta *, const Value *>> &assignments() const { return assignments_; }
  FilterStmt *                                                    filter_stmt() const { return filter_stmt_; }
  StmtType                                                        type() const override { return StmtType::UPDATE; }

private:
  Table *                                                  table_ = nullptr;
  std::vector<std::pair<const FieldMeta *, const Value *>> assignments_;
  FilterStmt *                                             filter_stmt_ = nullptr;
};
