
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

UnboundAggregateExpr *create_aggregate_expression(const char *aggregate_name,
                                           Expression *child,
                                           const char *sql_string,
                                           YYLTYPE *llocp)
{
  UnboundAggregateExpr *expr = new UnboundAggregateExpr(aggregate_name, child);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

%}

%define api.pure full
%define parse.error verbose
/** 启用位置标识 **/
%locations
%lex-param { yyscan_t scanner }
/** 这些定义了在yyparse函数中的参数 **/
%parse-param { const char * sql_string }
%parse-param { ParsedSqlResult * sql_result }
%parse-param { void * scanner }

//标识tokens
%token  SEMICOLON
        BY
        CREATE
        DROP
        GROUP
        ORDER
        ASC
        TABLE
        TABLES
        UNIQUE
        INDEX
        CALC
        SELECT
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        LBRACKET
        RBRACKET
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
        DATE_T
        VECTOR_T
        NIL
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        INNER_JOIN
        WHERE
        HAVING
        NOT
        AND
        SET
        ON
        LOAD
        DATA
        INFILE
        EXPLAIN
        STORAGE
        FORMAT
        AS
        EQ
        LT
        GT
        LE
        GE
        NE
        IS
        LK
        L2_DISTANCE
        COSINE_DISTANCE
        INNER_PRODUCT

/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  ParsedSqlNode *                                            sql_node;
  ConditionSqlNode *                                         condition;
  Value *                                                    value;
  enum CompOp                                                comp;
  RelAttrSqlNode *                                           rel_attr;
  std::vector<AttrInfoSqlNode> *                             attr_infos;
  AttrInfoSqlNode *                                          attr_info;
  Assignment *                                               assignment;
  std::vector<std::unique_ptr<Assignment>> *                 assignment_list;
  Expression *                                               expression;
  std::vector<std::unique_ptr<Expression>> *                 expression_list;
  std::vector<Value> *                                       value_list;
  JoinSqlNode *                                              join_list;
  std::vector<std::unique_ptr<ConditionSqlNode>> *           condition_list;
  std::vector<RelAttrSqlNode> *                              rel_attr_list;
  std::vector<std::string> *                                 relation_list;
  std::vector<std::pair<std::string, std::string>> *         rel_alias_list;
  std::pair<std::unique_ptr<Expression>, bool> *             order_by_item;
  std::vector<std::pair<std::unique_ptr<Expression>, bool>> *order_by_list;
  char *                                                     string;
  int                                                        number;
  float                                                      floats;
  bool                                                       booleans;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> ID
%token <string> AGGREGATE
%token <string> SSS
//非终结符

/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <number>              type
%type <condition>           condition
%type <value>               value
%type <number>              number
%type <string>              relation
%type <comp>                comp_op
%type <rel_attr>            rel_attr
%type <attr_infos>          attr_def_list
%type <attr_info>           attr_def
%type <value_list>          value_list
%type <join_list>           join_list
%type <condition_list>      where
%type <condition_list>      having
%type <condition_list>      condition_list
%type <string>              storage_format
%type <relation_list>       rel_list
%type <rel_alias_list>      rel_alias_list
%type <assignment>          assignment
%type <assignment_list>     assignment_list
%type <expression>          expression
%type <expression_list>     expression_list
%type <expression_list>     group_by
%type <order_by_item>       order_by_item
%type <order_by_list>       order_by_list
%type <order_by_list>       order_by
%type <booleans>            nullable
%type <sql_node>            calc_stmt
%type <sql_node>            select_stmt
%type <sql_node>            insert_stmt
%type <sql_node>            update_stmt
%type <sql_node>            delete_stmt
%type <sql_node>            create_table_stmt
%type <sql_node>            drop_table_stmt
%type <sql_node>            show_tables_stmt
%type <sql_node>            desc_table_stmt
%type <sql_node>            create_index_stmt
%type <sql_node>            drop_index_stmt
%type <sql_node>            sync_stmt
%type <sql_node>            begin_stmt
%type <sql_node>            commit_stmt
%type <sql_node>            rollback_stmt
%type <sql_node>            load_data_stmt
%type <sql_node>            explain_stmt
%type <sql_node>            set_variable_stmt
%type <sql_node>            help_stmt
%type <sql_node>            exit_stmt
%type <sql_node>            command_wrapper
// commands should be a list but I use a single command instead
%type <sql_node>            commands

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%%

commands: command_wrapper opt_semicolon  //commands or sqls. parser starts here.
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>($1);
    sql_result->add_sql_node(std::move(sql_node));
  }
  ;

command_wrapper:
    calc_stmt
  | select_stmt
  | insert_stmt
  | update_stmt
  | delete_stmt
  | create_table_stmt
  | drop_table_stmt
  | show_tables_stmt
  | desc_table_stmt
  | create_index_stmt
  | drop_index_stmt
  | sync_stmt
  | begin_stmt
  | commit_stmt
  | rollback_stmt
  | load_data_stmt
  | explain_stmt
  | set_variable_stmt
  | help_stmt
  | exit_stmt
    ;

exit_stmt:      
    EXIT {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      $$ = new ParsedSqlNode(SCF_EXIT);
    };

help_stmt:
    HELP {
      $$ = new ParsedSqlNode(SCF_HELP);
    };

sync_stmt:
    SYNC {
      $$ = new ParsedSqlNode(SCF_SYNC);
    }
    ;

begin_stmt:
    TRX_BEGIN  {
      $$ = new ParsedSqlNode(SCF_BEGIN);
    }
    ;

commit_stmt:
    TRX_COMMIT {
      $$ = new ParsedSqlNode(SCF_COMMIT);
    }
    ;

rollback_stmt:
    TRX_ROLLBACK  {
      $$ = new ParsedSqlNode(SCF_ROLLBACK);
    }
    ;

drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };

show_tables_stmt:
    SHOW TABLES {
      $$ = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
    ;

desc_table_stmt:
    DESC ID  {
      $$ = new ParsedSqlNode(SCF_DESC_TABLE);
      $$->desc_table.relation_name = $2;
      free($2);
    }
    ;

create_index_stmt:    /*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE rel_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $3;
      create_index.relation_name = $5;
      create_index.attribute_names.swap(*$7);
      create_index.unique = false;
      free($3);
      free($5);
      delete $7;
    }
    | CREATE UNIQUE INDEX ID ON ID LBRACE rel_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.index_name = $4;
      create_index.relation_name = $6;
      create_index.attribute_names.swap(*$8);
      create_index.unique = true;
      free($4);
      free($6);
      delete $8;
    }
    ;

drop_index_stmt:      /*drop index 语句的语法解析树*/
    DROP INDEX ID ON ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_INDEX);
      $$->drop_index.index_name = $3;
      $$->drop_index.relation_name = $5;
      free($3);
      free($5);
    }
    ;
create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format
    {
      $$ = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = $$->create_table;
      create_table.relation_name = $3;
      free($3);

      std::vector<AttrInfoSqlNode> *src_attrs = $6;

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*$5);
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete $5;
      if ($8 != nullptr) {
        create_table.storage_format = $8;
        free($8);
      }
    }
    ;
attr_def_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA attr_def attr_def_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<AttrInfoSqlNode>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
    
attr_def:
    ID STRING_T LBRACE number RBRACE nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = AttrType::CHARS;
      $$->name = $1;
      $$->length = $4;
      $$->nullable = $6;
      free($1);
    }
    | ID VECTOR_T LBRACE number RBRACE nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = AttrType::VECTORS;
      $$->name = $1;
      $$->length = 1 + 4 * $4;
      $$->nullable = $6;
      free($1);
    }
    | ID type nullable
    {
      $$ = new AttrInfoSqlNode;
      $$->type = (AttrType)$2;
      $$->name = $1;
      $$->length = 4;
      $$->nullable = $3;
      free($1);
    }
    ;

nullable:
    /* empty */
    {
      $$ = true;
    }
    | NIL
    {
      $$ = true;
    }
    | NOT NIL
    {
      $$ = false;
    }
    ;

number:
    NUMBER {$$ = $1;}
    ;
type:
    INT_T      { $$ = static_cast<int>(AttrType::INTS); }
    | STRING_T { $$ = static_cast<int>(AttrType::CHARS); }
    | FLOAT_T  { $$ = static_cast<int>(AttrType::FLOATS); }
    | DATE_T   { $$ = static_cast<int>(AttrType::DATES); }
    ;
insert_stmt:        /*insert   语句的语法解析树*/
    INSERT INTO ID VALUES LBRACE value value_list RBRACE 
    {
      $$ = new ParsedSqlNode(SCF_INSERT);
      $$->insertion.relation_name = $3;
      if ($7 != nullptr) {
        $$->insertion.values.swap(*$7);
        delete $7;
      }
      $$->insertion.values.emplace_back(*$6);
      std::reverse($$->insertion.values.begin(), $$->insertion.values.end());
      delete $6;
      free($3);
    }
    ;

value_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | COMMA value value_list  { 
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<Value>;
      }
      $$->emplace_back(*$2);
      delete $2;
    }
    ;
value:
    LBRACKET value value_list RBRACKET {
      if ($3 == nullptr)
        $3 = new std::vector<Value>;
      $3->emplace_back(*$2);
      delete $2;
      std::reverse($3->begin(), $3->end());
      $$ = new Value(*$3);
      delete $3;
    }
    |NUMBER {
      $$ = new Value((int)$1);
      @$ = @1;
    }
    |FLOAT {
      $$ = new Value((float)$1);
      @$ = @1;
    }
    |NIL {
      $$ = new Value(AttrType::NULLS, nullptr);
      @$ = @1;
    }
    |SSS {
      char *tmp = common::substr($1,1,strlen($1)-2);
      $$ = new Value(tmp);
      free(tmp);
      free($1);
    }
    ;
storage_format:
    /* empty */
    {
      $$ = nullptr;
    }
    | STORAGE FORMAT EQ ID
    {
      $$ = $4;
    }
    ;
    
delete_stmt:    /*  delete 语句的语法解析树*/
    DELETE FROM ID where 
    {
      $$ = new ParsedSqlNode(SCF_DELETE);
      $$->deletion.relation_name = $3;
      if ($4 != nullptr) {
        $$->deletion.conditions.swap(*$4);
        delete $4;
      }
      free($3);
    }
    ;
update_stmt:      /*  update 语句的语法解析树*/
    UPDATE ID SET assignment_list where 
    {
      $$ = new ParsedSqlNode(SCF_UPDATE);
      $$->update.relation_name = $2;
      $$->update.assignments.swap(*$4);
      if ($5 != nullptr) {
        $$->update.conditions.swap(*$5);
        delete $5;
      }
      free($2);
      delete $4;
    }
    ;
select_stmt:        /*  select 语句的语法解析树*/
    SELECT expression_list FROM rel_alias_list join_list where group_by having order_by
    {
      $$ = new ParsedSqlNode(SCF_SELECT);
      if ($2 != nullptr) {
        $$->selection.expressions.swap(*$2);
        delete $2;
      }

      if ($4 != nullptr) {
        $$->selection.relations.swap(*$4);
        delete $4;
      }

      if ($6 != nullptr) {
        $$->selection.conditions.swap(*$6);
        delete $6;
      }

      if ($7 != nullptr) {
        $$->selection.group_by.swap(*$7);
        delete $7;
      }

      if ($5 != nullptr) {
        $$->selection.relations.insert($$->selection.relations.end(), std::make_move_iterator($5->relations.begin()), std::make_move_iterator($5->relations.end()));
        $$->selection.conditions.insert($$->selection.conditions.end(), std::make_move_iterator($5->conditions.begin()), std::make_move_iterator($5->conditions.end()));
        delete $5;
      }

      if ($8 != nullptr) {
        $$->selection.having.swap(*$8);
        delete $8;
      }

      if ($9 != nullptr) {
        $$->selection.order_by.swap(*$9);
        delete $9;
      }
    }
    ;
calc_stmt:
    CALC expression_list
    {
      $$ = new ParsedSqlNode(SCF_CALC);
      $$->calc.expressions.swap(*$2);
      delete $2;
    }
    ;

assignment_list:
    assignment
    {
      $$ = new std::vector<std::unique_ptr<Assignment>>;
      $$->emplace_back($1);
    }
    | assignment COMMA assignment_list
    {
      $$ = $3;
      $$->emplace_back($1);
    }
    ;
assignment:
    ID EQ value
    {
      $$ = new Assignment;
      $$->attribute_name = $1;
      $$->value = *$3;
      free($1);
      delete $3;
    }
    ;

expression_list:
    expression
    {
      $$ = new std::vector<std::unique_ptr<Expression>>;
      $$->emplace_back($1);
    }
    | expression ID
    {
      $1->set_name($2);
      free $2;
      $$ = new std::vector<std::unique_ptr<Expression>>;
      $$->emplace_back($1);
    }
    | expression AS ID
    {
      $1->set_name($3);
      free $3;
      $$ = new std::vector<std::unique_ptr<Expression>>;
      $$->emplace_back($1);
    }
    | expression COMMA expression_list
    {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<std::unique_ptr<Expression>>;
      }
      $$->emplace($$->begin(), $1);
    }
    | expression ID COMMA expression_list
    {
      $1->set_name($2);
      free $2;
      if ($4 != nullptr) {
        $$ = $4;
      } else {
        $$ = new std::vector<std::unique_ptr<Expression>>;
      }
      $$->emplace($$->begin(), $1);
    }
    | expression AS ID COMMA expression_list
    {
      $1->set_name($3);
      free $3;
      if ($5 != nullptr) {
        $$ = $5;
      } else {
        $$ = new std::vector<std::unique_ptr<Expression>>;
      }
      $$->emplace($$->begin(), $1);
    }
    ;
expression:
    L2_DISTANCE LBRACE expression COMMA expression RBRACE {
      $$ = new FunctionExpr(FunctionExpr::Type::L2_DISTANCE, $3, $5);
      $$->set_name(token_name(sql_string, &@$));
    }
    | COSINE_DISTANCE LBRACE expression COMMA expression RBRACE {
      $$ = new FunctionExpr(FunctionExpr::Type::COSINE_DISTANCE, $3, $5);
      $$->set_name(token_name(sql_string, &@$));
    }
    | INNER_PRODUCT LBRACE expression COMMA expression RBRACE {
      $$ = new FunctionExpr(FunctionExpr::Type::INNER_PRODUCT, $3, $5);
      $$->set_name(token_name(sql_string, &@$));
    }
    | expression '+' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::ADD, $1, $3, sql_string, &@$);
    }
    | expression '-' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::SUB, $1, $3, sql_string, &@$);
    }
    | expression '*' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::MUL, $1, $3, sql_string, &@$);
    }
    | expression '/' expression {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::DIV, $1, $3, sql_string, &@$);
    }
    | LBRACE expression RBRACE {
      $$ = $2;
      $$->set_name(token_name(sql_string, &@$));
    }
    | '-' expression %prec UMINUS {
      $$ = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, $2, nullptr, sql_string, &@$);
    }
    | AGGREGATE LBRACE expression RBRACE {
      $$ = create_aggregate_expression($1, $3, sql_string, &@$);
    }
    | value {
      $$ = new ValueExpr(*$1);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    | rel_attr {
      RelAttrSqlNode *node = $1;
      $$ = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      $$->set_name(token_name(sql_string, &@$));
      delete $1;
    }
    | '*' {
      $$ = new StarExpr();
      $$->set_name("*");
    }
    ;

rel_attr:
    ID {
      $$ = new RelAttrSqlNode;
      $$->attribute_name = $1;
      free($1);
    }
    | ID DOT ID {
      $$ = new RelAttrSqlNode;
      $$->relation_name  = $1;
      $$->attribute_name = $3;
      free($1);
      free($3);
    }
    ;

relation:
    ID {
      $$ = $1;
    }
    ;
rel_list:
    relation {
      $$ = new std::vector<std::string>();
      $$->push_back($1);
      free($1);
    }
    | relation COMMA rel_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<std::string>;
      }

      $$->insert($$->begin(), $1);
      free($1);
    }
    ;
rel_alias_list:
    relation {
      $$ = new std::vector<std::pair<std::string, std::string>>();
      $$->emplace_back($1, "");
      free($1);
    }
    | relation ID {
      $$ = new std::vector<std::pair<std::string, std::string>>();
      $$->emplace_back($1, $2);
      free($1);
      free($2);
    }
    | relation COMMA rel_alias_list {
      if ($3 != nullptr) {
        $$ = $3;
      } else {
        $$ = new std::vector<std::pair<std::string, std::string>>();
      }
      $$->emplace($$->begin(), $1, "");
      free($1);
    }
    | relation ID COMMA rel_alias_list {
      if ($4 != nullptr) {
        $$ = $4;
      } else {
        $$ = new std::vector<std::pair<std::string, std::string>>();
      }
      $$->emplace($$->begin(), $1, $2);
      free($1);
      free($2);
    }
    ;

join_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | join_list INNER_JOIN relation ON condition_list
    {
      if ($1 == nullptr)
        $$ = new JoinSqlNode;
      else
        $$ = $1;
      $$->relations.emplace_back($3, "");
      $$->conditions.insert($$->conditions.end(), std::make_move_iterator($5->begin()), std::make_move_iterator($5->end()));
      free($3);
      delete $5;
    }
    | join_list INNER_JOIN relation ID ON condition_list
    {
      if ($1 == nullptr)
        $$ = new JoinSqlNode;
      else
        $$ = $1;
      $$->relations.emplace_back($3, $4);
      $$->conditions.insert($$->conditions.end(), std::make_move_iterator($6->begin()), std::make_move_iterator($6->end()));
      free($3);
      free($4);
      delete $6;
    }

where:
    /* empty */
    {
      $$ = nullptr;
    }
    | WHERE condition_list {
      $$ = $2;  
    }
    ;
condition_list:
    /* empty */
    {
      $$ = nullptr;
    }
    | condition {
      $$ = new std::vector<std::unique_ptr<ConditionSqlNode>>;
      $$->emplace_back($1);
    }
    | condition AND condition_list {
      $$ = $3;
      $$->emplace_back($1);
    }
    ;
condition:
    expression comp_op expression
    {
      $$        = new ConditionSqlNode;
      $$->comp  = $2;
      $$->left  = std::unique_ptr<Expression>($1);
      $$->right = std::unique_ptr<Expression>($3);
    }
    | expression IS NIL
    {
      $$        = new ConditionSqlNode;
      $$->comp  = IS_NULL;
      $$->left  = std::unique_ptr<Expression>($1);
      $$->right = std::unique_ptr<Expression>(new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
    | expression IS NOT NIL
    {
      $$        = new ConditionSqlNode;
      $$->comp  = NOT_NULL;
      $$->left  = std::unique_ptr<Expression>($1);
      $$->right = std::unique_ptr<Expression>(new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
    ;

comp_op:
      EQ { $$ = EQUAL_TO; }
    | LT { $$ = LESS_THAN; }
    | GT { $$ = GREAT_THAN; }
    | LE { $$ = LESS_EQUAL; }
    | GE { $$ = GREAT_EQUAL; }
    | NE { $$ = NOT_EQUAL; }
    | LK { $$ = LIKE; }
    | NOT LK { $$ = NOT_LIKE; }
    ;

group_by:
    /* empty */
    {
      $$ = nullptr;
    }
    | GROUP BY expression_list
    {
      $$ = $3;
    }
    ;

order_by_item:
    expression
    {
      $$ = new std::pair<std::unique_ptr<Expression>, bool>($1, true);
    }
    | expression ASC
    {
      $$ = new std::pair<std::unique_ptr<Expression>, bool>($1, true);
    }
    | expression DESC
    {
      $$ = new std::pair<std::unique_ptr<Expression>, bool>($1, false);
    }
    ;
order_by_list:
    order_by_item
    {
      $$ = new std::vector<std::pair<std::unique_ptr<Expression>, bool>>;
      $$->emplace_back(std::move(*$1));
      delete $1;
    }
    | order_by_item COMMA order_by_list
    {
      $$ = $3;
      $$->insert($$->begin(), std::move(*$1));
      delete $1;
    }
    ;
order_by:
    /* empty */
    {
      $$ = nullptr;
    }
    | ORDER BY order_by_list
    {
      $$ = $3;
    }
    ;

having:
    /* empty */
    {
      $$ = nullptr;
    }
    | HAVING condition_list {
      $$ = $2;
    }
    ;

load_data_stmt:
    LOAD DATA INFILE SSS INTO TABLE ID 
    {
      char *tmp_file_name = common::substr($4, 1, strlen($4) - 2);
      
      $$ = new ParsedSqlNode(SCF_LOAD_DATA);
      $$->load_data.relation_name = $7;
      $$->load_data.file_name = tmp_file_name;
      free($7);
      free(tmp_file_name);
    }
    ;

explain_stmt:
    EXPLAIN command_wrapper
    {
      $$ = new ParsedSqlNode(SCF_EXPLAIN);
      $$->explain.sql_node = std::unique_ptr<ParsedSqlNode>($2);
    }
    ;

set_variable_stmt:
    SET ID EQ value
    {
      $$ = new ParsedSqlNode(SCF_SET_VARIABLE);
      $$->set_variable.name  = $2;
      $$->set_variable.value = *$4;
      free($2);
      delete $4;
    }
    ;

opt_semicolon: /*empty*/
    | SEMICOLON
    ;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
