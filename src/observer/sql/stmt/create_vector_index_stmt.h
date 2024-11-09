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
// Created by Wangyunlai on 2023/4/25.
//

#pragma once

#include <string>

#include "sql/stmt/stmt.h"

struct CreateIndexSqlNode;
class Table;
class FieldMeta;

/**
 * @brief 创建向量索引的语句
 * @ingroup Statement
 */
class CreateVectorIndexStmt : public Stmt
{
public:
  CreateVectorIndexStmt() = default;
  virtual ~CreateVectorIndexStmt() = default;

  StmtType type() const override { return StmtType::CREATE_VECTOR_INDEX; }

public:
  static RC create(Db *db, const CreateVectorIndexSqlNode &create_index, Stmt *&stmt);

private:
  Table *                        table_ = nullptr;
  std::vector<const FieldMeta *> field_metas_;
  std::string                    index_name_;
  bool                           unique_;
};
