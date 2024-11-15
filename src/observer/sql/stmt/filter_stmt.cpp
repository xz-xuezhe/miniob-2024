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

#include "sql/stmt/filter_stmt.h"
#include "common/lang/string.h"
#include "common/log/log.h"
#include "common/rc.h"
#include "sql/expr/expression.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include "sql/expr/expression_iterator.h"

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const UnboundFieldExpr &expr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(expr.table_name())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(expr.table_name());
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(expr.table_name());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", expr.table_name());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(expr.field_name());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), expr.field_name());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    std::unique_ptr<Expression> expression, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt  = nullptr;

  if (expression == nullptr) {
    stmt = new FilterStmt();
    return rc;
  }

  function<RC(std::unique_ptr<Expression> &)> checker = [&](unique_ptr<Expression> &expr) -> RC {
    if (expr->type() == ExprType::STAR)
      return RC::INVALID_ARGUMENT;
    if (expr->type() == ExprType::COMPARISON) {
      RC rc = RC::SUCCESS;
      ComparisonExpr *comp_expr = static_cast<ComparisonExpr *>(expr.get());
      CompOp          comp      = comp_expr->comp();
      if (comp < EQUAL_TO || comp > NO_OP)
        return RC::INVALID_ARGUMENT;
      return rc;
    }
    return ExpressionIterator::iterate_child_expr(*expr, checker);
  };

  function<RC(std::unique_ptr<Expression> &)> binder = [&](unique_ptr<Expression> &expr) -> RC {
    RC rc = RC::SUCCESS;
    if (expr->type() == ExprType::UNBOUND_FIELD) {
      Table           *table      = nullptr;
      const FieldMeta *field_meta = nullptr;
      rc                          = get_table_and_field(
          db, default_table, tables, static_cast<const UnboundFieldExpr &>(*expr), table, field_meta);
      if (OB_FAIL(rc))
        return rc;
      Field field(table, field_meta);
      expr.reset(new FieldExpr(field));
      return rc;
    }
    if (expr->type() == ExprType::SUBQUERY) {
      SubqueryExpr *subquery_expr = static_cast<SubqueryExpr *>(expr.get());
      Stmt *stmt = nullptr;
      RC rc = Stmt::create_stmt(db, *subquery_expr->sql_node(), stmt);
      if (OB_FAIL(rc))
        return rc;
      subquery_expr->stmt().reset(stmt);
    }
    return ExpressionIterator::iterate_child_expr(*expr, binder);
  };

  rc = checker(expression);
  if (OB_FAIL(rc))
    return rc;

  rc = binder(expression);
  if (OB_FAIL(rc))
    return rc;

  FilterStmt *tmp_stmt  = new FilterStmt();
  tmp_stmt->expression_ = std::move(expression);
  stmt = tmp_stmt;
  return rc;
}
