/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_SQL_HPP_INCLUDED
# define YY_YY_YACC_SQL_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SEMICOLON = 258,               /* SEMICOLON  */
    BY = 259,                      /* BY  */
    CREATE = 260,                  /* CREATE  */
    DROP = 261,                    /* DROP  */
    GROUP = 262,                   /* GROUP  */
    ORDER = 263,                   /* ORDER  */
    ASC = 264,                     /* ASC  */
    TABLE = 265,                   /* TABLE  */
    TABLES = 266,                  /* TABLES  */
    UNIQUE = 267,                  /* UNIQUE  */
    INDEX = 268,                   /* INDEX  */
    CALC = 269,                    /* CALC  */
    SELECT = 270,                  /* SELECT  */
    DESC = 271,                    /* DESC  */
    SHOW = 272,                    /* SHOW  */
    SYNC = 273,                    /* SYNC  */
    INSERT = 274,                  /* INSERT  */
    DELETE = 275,                  /* DELETE  */
    UPDATE = 276,                  /* UPDATE  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    LBRACKET = 279,                /* LBRACKET  */
    RBRACKET = 280,                /* RBRACKET  */
    COMMA = 281,                   /* COMMA  */
    TRX_BEGIN = 282,               /* TRX_BEGIN  */
    TRX_COMMIT = 283,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 284,            /* TRX_ROLLBACK  */
    INT_T = 285,                   /* INT_T  */
    STRING_T = 286,                /* STRING_T  */
    FLOAT_T = 287,                 /* FLOAT_T  */
    DATE_T = 288,                  /* DATE_T  */
    VECTOR_T = 289,                /* VECTOR_T  */
    NIL = 290,                     /* NIL  */
    HELP = 291,                    /* HELP  */
    EXIT = 292,                    /* EXIT  */
    DOT = 293,                     /* DOT  */
    INTO = 294,                    /* INTO  */
    VALUES = 295,                  /* VALUES  */
    FROM = 296,                    /* FROM  */
    INNER_JOIN = 297,              /* INNER_JOIN  */
    WHERE = 298,                   /* WHERE  */
    NOT = 299,                     /* NOT  */
    AND = 300,                     /* AND  */
    SET = 301,                     /* SET  */
    ON = 302,                      /* ON  */
    LOAD = 303,                    /* LOAD  */
    DATA = 304,                    /* DATA  */
    INFILE = 305,                  /* INFILE  */
    EXPLAIN = 306,                 /* EXPLAIN  */
    STORAGE = 307,                 /* STORAGE  */
    FORMAT = 308,                  /* FORMAT  */
    EQ = 309,                      /* EQ  */
    LT = 310,                      /* LT  */
    GT = 311,                      /* GT  */
    LE = 312,                      /* LE  */
    GE = 313,                      /* GE  */
    NE = 314,                      /* NE  */
    IS = 315,                      /* IS  */
    LK = 316,                      /* LK  */
    L2_DISTANCE = 317,             /* L2_DISTANCE  */
    COSINE_DISTANCE = 318,         /* COSINE_DISTANCE  */
    INNER_PRODUCT = 319,           /* INNER_PRODUCT  */
    NUMBER = 320,                  /* NUMBER  */
    FLOAT = 321,                   /* FLOAT  */
    ID = 322,                      /* ID  */
    AGGREGATE = 323,               /* AGGREGATE  */
    SSS = 324,                     /* SSS  */
    UMINUS = 325                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 131 "yacc_sql.y"

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
  std::pair<std::unique_ptr<Expression>, bool> *             order_by_item;
  std::vector<std::pair<std::unique_ptr<Expression>, bool>> *order_by_list;
  char *                                                     string;
  int                                                        number;
  float                                                      floats;
  bool                                                       booleans;

#line 159 "yacc_sql.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




int yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner);


#endif /* !YY_YY_YACC_SQL_HPP_INCLUDED  */
