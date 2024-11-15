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
    LIMIT = 265,                   /* LIMIT  */
    TABLE = 266,                   /* TABLE  */
    TABLES = 267,                  /* TABLES  */
    UNIQUE = 268,                  /* UNIQUE  */
    INDEX = 269,                   /* INDEX  */
    CALC = 270,                    /* CALC  */
    SELECT = 271,                  /* SELECT  */
    DESC = 272,                    /* DESC  */
    SHOW = 273,                    /* SHOW  */
    SYNC = 274,                    /* SYNC  */
    INSERT = 275,                  /* INSERT  */
    DELETE = 276,                  /* DELETE  */
    UPDATE = 277,                  /* UPDATE  */
    LBRACE = 278,                  /* LBRACE  */
    RBRACE = 279,                  /* RBRACE  */
    LBRACKET = 280,                /* LBRACKET  */
    RBRACKET = 281,                /* RBRACKET  */
    COMMA = 282,                   /* COMMA  */
    TRX_BEGIN = 283,               /* TRX_BEGIN  */
    TRX_COMMIT = 284,              /* TRX_COMMIT  */
    TRX_ROLLBACK = 285,            /* TRX_ROLLBACK  */
    INT_T = 286,                   /* INT_T  */
    STRING_T = 287,                /* STRING_T  */
    FLOAT_T = 288,                 /* FLOAT_T  */
    DATE_T = 289,                  /* DATE_T  */
    VECTOR_T = 290,                /* VECTOR_T  */
    NIL = 291,                     /* NIL  */
    HELP = 292,                    /* HELP  */
    EXIT = 293,                    /* EXIT  */
    DOT = 294,                     /* DOT  */
    INTO = 295,                    /* INTO  */
    VALUES = 296,                  /* VALUES  */
    FROM = 297,                    /* FROM  */
    INNER_JOIN = 298,              /* INNER_JOIN  */
    WHERE = 299,                   /* WHERE  */
    HAVING = 300,                  /* HAVING  */
    OR = 301,                      /* OR  */
    AND = 302,                     /* AND  */
    NOT = 303,                     /* NOT  */
    SET = 304,                     /* SET  */
    ON = 305,                      /* ON  */
    LOAD = 306,                    /* LOAD  */
    DATA = 307,                    /* DATA  */
    INFILE = 308,                  /* INFILE  */
    EXPLAIN = 309,                 /* EXPLAIN  */
    STORAGE = 310,                 /* STORAGE  */
    FORMAT = 311,                  /* FORMAT  */
    WITH = 312,                    /* WITH  */
    AS = 313,                      /* AS  */
    EQ = 314,                      /* EQ  */
    LT = 315,                      /* LT  */
    GT = 316,                      /* GT  */
    LE = 317,                      /* LE  */
    GE = 318,                      /* GE  */
    NE = 319,                      /* NE  */
    IS = 320,                      /* IS  */
    LK = 321,                      /* LK  */
    IN = 322,                      /* IN  */
    EXISTS = 323,                  /* EXISTS  */
    L2_DISTANCE = 324,             /* L2_DISTANCE  */
    COSINE_DISTANCE = 325,         /* COSINE_DISTANCE  */
    INNER_PRODUCT = 326,           /* INNER_PRODUCT  */
    NUMBER = 327,                  /* NUMBER  */
    FLOAT = 328,                   /* FLOAT  */
    ID = 329,                      /* ID  */
    AGGREGATE = 330,               /* AGGREGATE  */
    SSS = 331,                     /* SSS  */
    UMINUS = 332                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 138 "yacc_sql.y"

  ParsedSqlNode *                                            sql_node;
  Expression *                                               condition;
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
  Expression *                                               condition_list;
  std::vector<RelAttrSqlNode> *                              rel_attr_list;
  std::vector<std::string> *                                 relation_list;
  std::vector<std::pair<std::string, std::string>> *         rel_alias_list;
  std::pair<std::unique_ptr<Expression>, bool> *             order_by_item;
  std::vector<std::pair<std::unique_ptr<Expression>, bool>> *order_by_list;
  char *                                                     string;
  int                                                        number;
  float                                                      floats;
  bool                                                       booleans;

#line 167 "yacc_sql.hpp"

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
