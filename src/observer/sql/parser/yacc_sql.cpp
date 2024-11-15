/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


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


#line 125 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_BY = 4,                         /* BY  */
  YYSYMBOL_CREATE = 5,                     /* CREATE  */
  YYSYMBOL_DROP = 6,                       /* DROP  */
  YYSYMBOL_GROUP = 7,                      /* GROUP  */
  YYSYMBOL_ORDER = 8,                      /* ORDER  */
  YYSYMBOL_ASC = 9,                        /* ASC  */
  YYSYMBOL_LIMIT = 10,                     /* LIMIT  */
  YYSYMBOL_TABLE = 11,                     /* TABLE  */
  YYSYMBOL_TABLES = 12,                    /* TABLES  */
  YYSYMBOL_UNIQUE = 13,                    /* UNIQUE  */
  YYSYMBOL_INDEX = 14,                     /* INDEX  */
  YYSYMBOL_CALC = 15,                      /* CALC  */
  YYSYMBOL_SELECT = 16,                    /* SELECT  */
  YYSYMBOL_DESC = 17,                      /* DESC  */
  YYSYMBOL_SHOW = 18,                      /* SHOW  */
  YYSYMBOL_SYNC = 19,                      /* SYNC  */
  YYSYMBOL_INSERT = 20,                    /* INSERT  */
  YYSYMBOL_DELETE = 21,                    /* DELETE  */
  YYSYMBOL_UPDATE = 22,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 24,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 25,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 26,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 28,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 29,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 30,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 31,                     /* INT_T  */
  YYSYMBOL_STRING_T = 32,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 33,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 34,                    /* DATE_T  */
  YYSYMBOL_VECTOR_T = 35,                  /* VECTOR_T  */
  YYSYMBOL_NIL = 36,                       /* NIL  */
  YYSYMBOL_HELP = 37,                      /* HELP  */
  YYSYMBOL_EXIT = 38,                      /* EXIT  */
  YYSYMBOL_DOT = 39,                       /* DOT  */
  YYSYMBOL_INTO = 40,                      /* INTO  */
  YYSYMBOL_VALUES = 41,                    /* VALUES  */
  YYSYMBOL_FROM = 42,                      /* FROM  */
  YYSYMBOL_INNER_JOIN = 43,                /* INNER_JOIN  */
  YYSYMBOL_WHERE = 44,                     /* WHERE  */
  YYSYMBOL_HAVING = 45,                    /* HAVING  */
  YYSYMBOL_OR = 46,                        /* OR  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_NOT = 48,                       /* NOT  */
  YYSYMBOL_SET = 49,                       /* SET  */
  YYSYMBOL_ON = 50,                        /* ON  */
  YYSYMBOL_LOAD = 51,                      /* LOAD  */
  YYSYMBOL_DATA = 52,                      /* DATA  */
  YYSYMBOL_INFILE = 53,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 54,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 55,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 56,                    /* FORMAT  */
  YYSYMBOL_WITH = 57,                      /* WITH  */
  YYSYMBOL_AS = 58,                        /* AS  */
  YYSYMBOL_EQ = 59,                        /* EQ  */
  YYSYMBOL_LT = 60,                        /* LT  */
  YYSYMBOL_GT = 61,                        /* GT  */
  YYSYMBOL_LE = 62,                        /* LE  */
  YYSYMBOL_GE = 63,                        /* GE  */
  YYSYMBOL_NE = 64,                        /* NE  */
  YYSYMBOL_IS = 65,                        /* IS  */
  YYSYMBOL_LK = 66,                        /* LK  */
  YYSYMBOL_IN = 67,                        /* IN  */
  YYSYMBOL_EXISTS = 68,                    /* EXISTS  */
  YYSYMBOL_L2_DISTANCE = 69,               /* L2_DISTANCE  */
  YYSYMBOL_COSINE_DISTANCE = 70,           /* COSINE_DISTANCE  */
  YYSYMBOL_INNER_PRODUCT = 71,             /* INNER_PRODUCT  */
  YYSYMBOL_NUMBER = 72,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 73,                     /* FLOAT  */
  YYSYMBOL_ID = 74,                        /* ID  */
  YYSYMBOL_AGGREGATE = 75,                 /* AGGREGATE  */
  YYSYMBOL_SSS = 76,                       /* SSS  */
  YYSYMBOL_77_ = 77,                       /* '+'  */
  YYSYMBOL_78_ = 78,                       /* '-'  */
  YYSYMBOL_79_ = 79,                       /* '*'  */
  YYSYMBOL_80_ = 80,                       /* '/'  */
  YYSYMBOL_UMINUS = 81,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_commands = 83,                  /* commands  */
  YYSYMBOL_command_wrapper = 84,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 85,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 86,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 87,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 88,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 89,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 90,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 91,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 92,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 93,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 94,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 95,           /* drop_index_stmt  */
  YYSYMBOL_create_vector_index_stmt = 96,  /* create_vector_index_stmt  */
  YYSYMBOL_create_table_stmt = 97,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 98,             /* attr_def_list  */
  YYSYMBOL_attr_def = 99,                  /* attr_def  */
  YYSYMBOL_nullable = 100,                 /* nullable  */
  YYSYMBOL_number = 101,                   /* number  */
  YYSYMBOL_type = 102,                     /* type  */
  YYSYMBOL_insert_stmt = 103,              /* insert_stmt  */
  YYSYMBOL_value_list = 104,               /* value_list  */
  YYSYMBOL_value = 105,                    /* value  */
  YYSYMBOL_storage_format = 106,           /* storage_format  */
  YYSYMBOL_delete_stmt = 107,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 108,              /* update_stmt  */
  YYSYMBOL_select_stmt = 109,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 110,                /* calc_stmt  */
  YYSYMBOL_limit = 111,                    /* limit  */
  YYSYMBOL_assignment_list = 112,          /* assignment_list  */
  YYSYMBOL_assignment = 113,               /* assignment  */
  YYSYMBOL_expression_list = 114,          /* expression_list  */
  YYSYMBOL_expression = 115,               /* expression  */
  YYSYMBOL_rel_attr = 116,                 /* rel_attr  */
  YYSYMBOL_relation = 117,                 /* relation  */
  YYSYMBOL_rel_list = 118,                 /* rel_list  */
  YYSYMBOL_rel_alias_list = 119,           /* rel_alias_list  */
  YYSYMBOL_join_list = 120,                /* join_list  */
  YYSYMBOL_where = 121,                    /* where  */
  YYSYMBOL_condition_list = 122,           /* condition_list  */
  YYSYMBOL_condition = 123,                /* condition  */
  YYSYMBOL_comp_op = 124,                  /* comp_op  */
  YYSYMBOL_group_by = 125,                 /* group_by  */
  YYSYMBOL_order_by_item = 126,            /* order_by_item  */
  YYSYMBOL_order_by_list = 127,            /* order_by_list  */
  YYSYMBOL_order_by = 128,                 /* order_by  */
  YYSYMBOL_having = 129,                   /* having  */
  YYSYMBOL_load_data_stmt = 130,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 131,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 132,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 133             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    79,    77,     2,    78,     2,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   229,   229,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   261,   267,   272,   278,   284,   290,
     296,   303,   309,   317,   329,   344,   355,   359,   363,   369,
     393,   396,   409,   418,   427,   440,   443,   447,   454,   457,
     458,   459,   460,   463,   480,   483,   494,   503,   507,   511,
     515,   524,   527,   534,   545,   558,   610,   620,   623,   629,
     634,   641,   652,   657,   664,   671,   680,   691,   704,   708,
     712,   716,   719,   722,   725,   728,   732,   735,   738,   743,
     749,   753,   759,   764,   774,   779,   784,   796,   801,   807,
     816,   830,   833,   853,   877,   880,   885,   888,   898,   910,
     914,   918,   922,   932,   942,   946,   950,   954,   961,   962,
     963,   964,   965,   966,   967,   968,   973,   976,   983,   987,
     991,   997,  1003,  1012,  1015,  1023,  1026,  1032,  1045,  1053,
    1063,  1064
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "BY",
  "CREATE", "DROP", "GROUP", "ORDER", "ASC", "LIMIT", "TABLE", "TABLES",
  "UNIQUE", "INDEX", "CALC", "SELECT", "DESC", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "VECTOR_T", "NIL", "HELP", "EXIT", "DOT", "INTO",
  "VALUES", "FROM", "INNER_JOIN", "WHERE", "HAVING", "OR", "AND", "NOT",
  "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "STORAGE", "FORMAT",
  "WITH", "AS", "EQ", "LT", "GT", "LE", "GE", "NE", "IS", "LK", "IN",
  "EXISTS", "L2_DISTANCE", "COSINE_DISTANCE", "INNER_PRODUCT", "NUMBER",
  "FLOAT", "ID", "AGGREGATE", "SSS", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "drop_index_stmt", "create_vector_index_stmt",
  "create_table_stmt", "attr_def_list", "attr_def", "nullable", "number",
  "type", "insert_stmt", "value_list", "value", "storage_format",
  "delete_stmt", "update_stmt", "select_stmt", "calc_stmt", "limit",
  "assignment_list", "assignment", "expression_list", "expression",
  "rel_attr", "relation", "rel_list", "rel_alias_list", "join_list",
  "where", "condition_list", "condition", "comp_op", "group_by",
  "order_by_item", "order_by_list", "order_by", "having", "load_data_stmt",
  "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-197)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     246,     8,    15,   116,   116,   -58,    19,  -197,   -20,    58,
     -47,  -197,  -197,  -197,  -197,  -197,    39,    64,   246,   117,
     120,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,    45,   106,    60,   122,    63,    68,    85,   168,
    -197,   115,   121,   125,  -197,  -197,   104,   130,  -197,   116,
    -197,  -197,  -197,   -17,  -197,   103,  -197,  -197,    88,    91,
     131,   141,   126,  -197,  -197,  -197,  -197,   161,   124,   151,
     128,  -197,   153,   181,     1,   186,   116,   116,   116,   140,
     116,  -197,   116,   146,   194,   116,   116,   116,   116,   148,
     182,   180,   152,   168,   149,   155,   178,   162,   185,   163,
    -197,  -197,   168,   201,   139,   154,   170,  -197,     6,  -197,
     211,   116,   -10,   -10,  -197,  -197,  -197,   -15,  -197,   216,
      99,  -197,   183,   180,   218,  -197,   213,   177,   227,   184,
     232,   195,  -197,   186,  -197,   116,   116,   116,  -197,   116,
    -197,   148,   229,    44,   168,   189,   236,   242,  -197,   -13,
     168,  -197,   152,   249,  -197,   247,  -197,  -197,   248,   -12,
     155,   253,   250,   148,   255,  -197,    13,    27,    48,  -197,
    -197,   148,   148,   265,   186,   256,   264,    36,  -197,  -197,
    -197,  -197,  -197,  -197,    18,  -197,   258,   116,    99,    99,
    -197,  -197,   208,   214,   214,  -197,   251,  -197,   227,   230,
     148,   261,   267,   215,  -197,  -197,  -197,  -197,   -18,   288,
     254,   269,   264,   270,  -197,   273,  -197,   262,    -8,    53,
    -197,  -197,  -197,  -197,   286,   287,  -197,  -197,   257,  -197,
     290,   148,  -197,   291,    99,   266,   116,    99,   304,  -197,
     293,  -197,    -8,  -197,   186,   294,   -12,   -12,   268,  -197,
    -197,   271,  -197,    99,  -197,  -197,   319,   314,  -197,   186,
     301,   302,  -197,  -197,  -197,   259,   306,  -197,   116,   260,
    -197,   307,  -197,  -197,  -197,   263,    -4,   303,  -197,  -197,
    -197,   275,  -197,  -197,   116,   272,  -197,   308,   274,   277,
      25,   311,   312,   313,   276,   278,   279,   282,   283,   284,
     285,   289,   292,   317,   318,   320,   280,   281,   295,   297,
     299,   300,   296,   298,   305,   325,   327,   336,  -197,  -197,
    -197
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     140,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    14,    13,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,    57,    58,    92,     0,    60,     0,
      90,    88,    66,    72,    89,     0,    32,    31,     0,     0,
       0,     0,     0,   138,     1,   141,     2,     0,     0,     0,
       0,    30,     0,     0,     0,    54,     0,     0,     0,     0,
       0,    86,     0,     0,    73,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    85,     0,     0,     0,     0,     0,    93,     0,    75,
      74,     0,    81,    82,    83,    84,    94,    97,   101,     0,
       0,    63,     0,   104,    69,   139,     0,     0,    40,     0,
       0,     0,    35,    54,    56,     0,     0,     0,    87,     0,
      76,     0,    98,   104,     0,     0,     0,     0,   105,   106,
       0,    64,     0,     0,    49,    50,    51,    52,     0,    45,
       0,     0,     0,     0,     0,    55,     0,     0,     0,    77,
      99,     0,     0,   126,    54,     0,     0,     0,   118,   119,
     120,   121,   122,   123,     0,   124,     0,     0,     0,     0,
      71,    70,     0,     0,     0,    46,     0,    44,    40,    61,
       0,    95,     0,     0,    78,    79,    80,   100,     0,     0,
     135,     0,     0,     0,   125,     0,   110,     0,     0,   109,
     108,   107,   137,    48,     0,     0,    47,    41,     0,    39,
       0,     0,    33,     0,     0,     0,     0,     0,   133,    53,
       0,   116,     0,   111,    54,     0,    45,    45,     0,    34,
      96,     0,   102,     0,   127,   136,     0,    67,   117,    54,
       0,     0,   114,    42,    43,     0,     0,   103,     0,     0,
      65,     0,   115,   112,    62,     0,   128,   131,   134,    68,
     113,     0,   129,   130,     0,     0,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,   344,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,   157,   193,  -145,   167,
    -197,  -197,  -140,   -45,  -197,  -197,  -197,   -46,  -197,  -197,
     204,  -197,    -3,   -48,  -197,  -164,  -196,  -128,  -197,  -118,
    -192,  -197,  -197,  -197,  -197,    73,  -197,  -197,  -197,  -197,
    -197,  -197
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,   171,   138,   207,   234,
     169,    34,   113,    61,   239,    35,    36,    37,    38,   280,
     133,   134,    62,    63,    64,   127,   212,   128,   153,   131,
     158,   159,   197,   220,   287,   288,   267,   248,    39,    40,
      41,    76
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    65,    83,   175,    85,   292,   230,   231,     4,   211,
      92,    91,   151,   293,   240,   161,    66,    49,   218,    42,
      68,    43,    44,   180,   205,   111,    46,    70,    50,    47,
     148,    67,   244,   198,   199,   183,   206,   214,   114,   115,
     116,    93,   118,    45,   221,   260,   211,   122,   123,   124,
     125,   215,   262,   217,   226,   265,   245,    94,   135,   152,
      95,    96,    97,    98,    54,    55,   227,   143,    58,    97,
      98,   277,   216,    95,    96,    97,    98,   211,    95,    96,
      97,    98,   157,    95,    96,    97,    98,   182,   130,   119,
      95,    96,    97,    98,   301,   302,   303,   176,   177,   178,
      69,     4,   224,   225,    95,    96,    97,    98,    48,   184,
      49,   273,   274,    71,   271,   200,    72,    74,   150,    77,
      78,    50,    48,    75,    49,    95,    96,    97,    98,   281,
      95,    96,    97,    98,    79,    50,    80,    81,    86,    48,
     223,    49,    82,    89,    87,    99,   179,   155,    88,   229,
     157,   157,    50,    90,    51,    52,    53,    54,    55,    56,
      57,    58,   100,    59,    60,   101,   145,   156,    51,    52,
      53,    54,    55,    56,    57,    58,   250,    59,    60,   104,
     102,   146,   255,   254,   105,    51,    52,    53,    54,    55,
      56,    57,    58,    49,    59,    60,   157,   147,   106,   157,
     103,   107,   108,   109,    50,   110,   270,   269,   164,   165,
     166,   167,   168,   112,   117,   157,    95,    96,    97,    98,
     120,   121,   126,   129,   130,   136,   132,   144,   139,   137,
     286,    95,    96,    97,    98,   141,   140,   142,   149,   154,
      54,    55,   160,   264,    58,   162,   286,    95,    96,    97,
      98,     1,     2,   163,   170,   173,   181,   185,   172,   186,
     202,     3,     4,     5,     6,     7,     8,     9,    10,   174,
     203,   204,   219,   210,    11,    12,    13,   209,   213,   222,
       4,   228,   232,    14,    15,   238,   233,   236,   241,   243,
     187,   242,   246,   249,   251,    16,   252,    17,   253,   247,
      18,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     256,   257,   266,   258,   259,   261,   263,   268,   272,    95,
      96,    97,    98,   278,   279,   282,   283,   275,   276,   285,
     294,   290,   289,   284,   295,   298,   300,   291,   304,   305,
     306,   310,   311,   312,   316,   317,   297,   318,   299,   328,
     307,   329,   308,   309,   319,   320,   322,   313,   323,   324,
     330,   314,    73,   208,   315,   237,   201,   296,   325,   321,
     326,   235,     0,     0,     0,     0,     0,   327
};

static const yytype_int16 yycheck[] =
{
      48,     4,    48,   143,    49,     9,   198,   199,    16,   173,
      27,    59,    27,    17,   210,   133,    74,    25,   182,    11,
      40,    13,    14,   151,    36,    24,    11,    74,    36,    14,
      24,    12,    50,    46,    47,   153,    48,    24,    86,    87,
      88,    58,    90,    35,   184,   241,   210,    95,    96,    97,
      98,    24,   244,   181,    36,   247,    74,    74,   103,    74,
      77,    78,    79,    80,    72,    73,    48,   112,    76,    79,
      80,   263,    24,    77,    78,    79,    80,   241,    77,    78,
      79,    80,   130,    77,    78,    79,    80,    43,    44,    92,
      77,    78,    79,    80,    69,    70,    71,   145,   146,   147,
      42,    16,    66,    67,    77,    78,    79,    80,    23,   154,
      25,   256,   257,    74,   254,   160,    52,     0,   121,    74,
      14,    36,    23,     3,    25,    77,    78,    79,    80,   269,
      77,    78,    79,    80,    74,    36,    14,    74,    23,    23,
     186,    25,    74,    39,    23,    42,   149,    48,    23,   197,
     198,   199,    36,    23,    69,    70,    71,    72,    73,    74,
      75,    76,    74,    78,    79,    74,    27,    68,    69,    70,
      71,    72,    73,    74,    75,    76,   222,    78,    79,    53,
      49,    27,   228,   228,    23,    69,    70,    71,    72,    73,
      74,    75,    76,    25,    78,    79,   244,    27,    74,   247,
      59,    50,    74,    50,    36,    24,   252,   252,    31,    32,
      33,    34,    35,    27,    74,   263,    77,    78,    79,    80,
      74,    27,    74,    41,    44,    76,    74,    26,    50,    74,
     278,    77,    78,    79,    80,    50,    74,    74,    27,    23,
      72,    73,    59,   246,    76,    27,   294,    77,    78,    79,
      80,     5,     6,    40,    27,    23,    27,    68,    74,    23,
      11,    15,    16,    17,    18,    19,    20,    21,    22,    74,
      23,    23,     7,    23,    28,    29,    30,    24,    23,    23,
      16,    23,    74,    37,    38,    55,    72,    36,    27,    74,
      48,    24,     4,    24,    24,    49,    23,    51,    36,    45,
      54,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      24,    24,     8,    56,    24,    24,    50,    24,    24,    77,
      78,    79,    80,     4,    10,    24,    24,    59,    57,    23,
      27,    24,    72,    74,    59,    27,    59,    74,    27,    27,
      27,    59,    59,    59,    27,    27,    74,    27,    74,    24,
      74,    24,    74,    74,    74,    74,    59,    72,    59,    59,
      24,    72,    18,   170,    72,   208,   162,   294,    72,    74,
      72,   204,    -1,    -1,    -1,    -1,    -1,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    15,    16,    17,    18,    19,    20,    21,
      22,    28,    29,    30,    37,    38,    49,    51,    54,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   103,   107,   108,   109,   110,   130,
     131,   132,    11,    13,    14,    35,    11,    14,    23,    25,
      36,    69,    70,    71,    72,    73,    74,    75,    76,    78,
      79,   105,   114,   115,   116,   114,    74,    12,    40,    42,
      74,    74,    52,    84,     0,     3,   133,    74,    14,    74,
      14,    74,    74,   109,   115,   105,    23,    23,    23,    39,
      23,   115,    27,    58,    74,    77,    78,    79,    80,    42,
      74,    74,    49,    59,    53,    23,    74,    50,    74,    50,
      24,    24,    27,   104,   115,   115,   115,    74,   115,   114,
      74,    27,   115,   115,   115,   115,    74,   117,   119,    41,
      44,   121,    74,   112,   113,   105,    76,    74,    99,    50,
      74,    50,    74,   105,    26,    27,    27,    27,    24,    27,
     114,    27,    74,   120,    23,    48,    68,   115,   122,   123,
      59,   121,    27,    40,    31,    32,    33,    34,    35,   102,
      27,    98,    74,    23,    74,   104,   115,   115,   115,   114,
     119,    27,    43,   121,   105,    68,    23,    48,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   124,    46,    47,
     105,   112,    11,    23,    23,    36,    48,   100,    99,    24,
      23,   117,   118,    23,    24,    24,    24,   119,   117,     7,
     125,   104,    23,   109,    66,    67,    36,    48,    23,   115,
     122,   122,    74,    72,   101,   101,    36,    98,    55,   106,
     118,    27,    24,    74,    50,    74,     4,    45,   129,    24,
     109,    24,    23,    36,   105,   109,    24,    24,    56,    24,
     118,    24,   122,    50,   114,   122,     8,   128,    24,   105,
     109,   104,    24,   100,   100,    59,    57,   122,     4,    10,
     111,   104,    24,    24,    74,    23,   115,   126,   127,    72,
      24,    74,     9,    17,    27,    59,   127,    74,    27,    74,
      59,    69,    70,    71,    27,    27,    27,    74,    74,    74,
      59,    59,    59,    72,    72,    72,    27,    27,    27,    74,
      74,    74,    59,    59,    59,    72,    72,    72,    24,    24,
      24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    94,    95,    96,    96,    96,    97,
      98,    98,    99,    99,    99,   100,   100,   100,   101,   102,
     102,   102,   102,   103,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   107,   108,   109,   110,   111,   111,   112,
     112,   113,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   116,   116,   117,   118,   118,   119,   119,   119,
     119,   120,   120,   120,   121,   121,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   126,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   131,   132,
     133,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     8,     9,     5,    27,    27,    27,     8,
       0,     3,     6,     6,     3,     0,     1,     2,     1,     1,
       1,     1,     1,     8,     0,     3,     4,     1,     1,     1,
       1,     0,     4,     4,     5,    10,     2,     0,     2,     1,
       3,     3,     1,     2,     3,     3,     4,     5,     6,     6,
       6,     3,     3,     3,     3,     3,     2,     4,     1,     1,
       1,     3,     1,     3,     1,     1,     3,     1,     2,     3,
       4,     0,     5,     6,     0,     2,     1,     3,     3,     3,
       3,     4,     6,     7,     5,     6,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     1,     2,
       2,     1,     3,     0,     3,     0,     2,     7,     2,     4,
       0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 230 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1889 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 261 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1898 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 267 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1906 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 272 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1914 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 278 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1922 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 284 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1930 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 290 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1938 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 296 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1948 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 303 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1956 "yacc_sql.cpp"
    break;

  case 32: /* desc_table_stmt: DESC ID  */
#line 309 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1966 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE rel_list RBRACE  */
#line 318 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
      create_index.unique = false;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      delete (yyvsp[-1].relation_list);
    }
#line 1982 "yacc_sql.cpp"
    break;

  case 34: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE rel_list RBRACE  */
#line 330 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-5].string);
      create_index.relation_name = (yyvsp[-3].string);
      create_index.attribute_names.swap(*(yyvsp[-1].relation_list));
      create_index.unique = true;
      free((yyvsp[-5].string));
      free((yyvsp[-3].string));
      delete (yyvsp[-1].relation_list);
    }
#line 1998 "yacc_sql.cpp"
    break;

  case 35: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 345 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2010 "yacc_sql.cpp"
    break;

  case 36: /* create_vector_index_stmt: CREATE VECTOR_T INDEX ID ON ID LBRACE ID RBRACE WITH LBRACE ID EQ ID COMMA ID EQ L2_DISTANCE COMMA ID EQ NUMBER COMMA ID EQ NUMBER RBRACE  */
#line 356 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_VECTOR_INDEX);
    }
#line 2018 "yacc_sql.cpp"
    break;

  case 37: /* create_vector_index_stmt: CREATE VECTOR_T INDEX ID ON ID LBRACE ID RBRACE WITH LBRACE ID EQ ID COMMA ID EQ COSINE_DISTANCE COMMA ID EQ NUMBER COMMA ID EQ NUMBER RBRACE  */
#line 360 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_VECTOR_INDEX);
    }
#line 2026 "yacc_sql.cpp"
    break;

  case 38: /* create_vector_index_stmt: CREATE VECTOR_T INDEX ID ON ID LBRACE ID RBRACE WITH LBRACE ID EQ ID COMMA ID EQ INNER_PRODUCT COMMA ID EQ NUMBER COMMA ID EQ NUMBER RBRACE  */
#line 364 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_VECTOR_INDEX);
    }
#line 2034 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 370 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
        delete src_attrs;
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-3].attr_info);
      if ((yyvsp[0].string) != nullptr) {
        create_table.storage_format = (yyvsp[0].string);
        free((yyvsp[0].string));
      }
    }
#line 2059 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 393 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2067 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 397 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2081 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID STRING_T LBRACE number RBRACE nullable  */
#line 410 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = AttrType::CHARS;
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-5].string));
    }
#line 2094 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID VECTOR_T LBRACE number RBRACE nullable  */
#line 419 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = AttrType::VECTORS;
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = 1 + 4 * (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-5].string));
    }
#line 2107 "yacc_sql.cpp"
    break;

  case 44: /* attr_def: ID type nullable  */
#line 428 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-2].string));
    }
#line 2120 "yacc_sql.cpp"
    break;

  case 45: /* nullable: %empty  */
#line 440 "yacc_sql.y"
    {
      (yyval.booleans) = true;
    }
#line 2128 "yacc_sql.cpp"
    break;

  case 46: /* nullable: NIL  */
#line 444 "yacc_sql.y"
    {
      (yyval.booleans) = true;
    }
#line 2136 "yacc_sql.cpp"
    break;

  case 47: /* nullable: NOT NIL  */
#line 448 "yacc_sql.y"
    {
      (yyval.booleans) = false;
    }
#line 2144 "yacc_sql.cpp"
    break;

  case 48: /* number: NUMBER  */
#line 454 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2150 "yacc_sql.cpp"
    break;

  case 49: /* type: INT_T  */
#line 457 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2156 "yacc_sql.cpp"
    break;

  case 50: /* type: STRING_T  */
#line 458 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2162 "yacc_sql.cpp"
    break;

  case 51: /* type: FLOAT_T  */
#line 459 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2168 "yacc_sql.cpp"
    break;

  case 52: /* type: DATE_T  */
#line 460 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2174 "yacc_sql.cpp"
    break;

  case 53: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 464 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-5].string);
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-2].value));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-2].value);
      free((yyvsp[-5].string));
    }
#line 2191 "yacc_sql.cpp"
    break;

  case 54: /* value_list: %empty  */
#line 480 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2199 "yacc_sql.cpp"
    break;

  case 55: /* value_list: COMMA value value_list  */
#line 483 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2213 "yacc_sql.cpp"
    break;

  case 56: /* value: LBRACKET value value_list RBRACKET  */
#line 494 "yacc_sql.y"
                                       {
      if ((yyvsp[-1].value_list) == nullptr)
        (yyvsp[-1].value_list) = new std::vector<Value>;
      (yyvsp[-1].value_list)->emplace_back(*(yyvsp[-2].value));
      delete (yyvsp[-2].value);
      std::reverse((yyvsp[-1].value_list)->begin(), (yyvsp[-1].value_list)->end());
      (yyval.value) = new Value(*(yyvsp[-1].value_list));
      delete (yyvsp[-1].value_list);
    }
#line 2227 "yacc_sql.cpp"
    break;

  case 57: /* value: NUMBER  */
#line 503 "yacc_sql.y"
            {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2236 "yacc_sql.cpp"
    break;

  case 58: /* value: FLOAT  */
#line 507 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2245 "yacc_sql.cpp"
    break;

  case 59: /* value: NIL  */
#line 511 "yacc_sql.y"
         {
      (yyval.value) = new Value(AttrType::NULLS, nullptr);
      (yyloc) = (yylsp[0]);
    }
#line 2254 "yacc_sql.cpp"
    break;

  case 60: /* value: SSS  */
#line 515 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2265 "yacc_sql.cpp"
    break;

  case 61: /* storage_format: %empty  */
#line 524 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2273 "yacc_sql.cpp"
    break;

  case 62: /* storage_format: STORAGE FORMAT EQ ID  */
#line 528 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2281 "yacc_sql.cpp"
    break;

  case 63: /* delete_stmt: DELETE FROM ID where  */
#line 535 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.reset((yyvsp[0].condition_list));
      }
      free((yyvsp[-1].string));
    }
#line 2294 "yacc_sql.cpp"
    break;

  case 64: /* update_stmt: UPDATE ID SET assignment_list where  */
#line 546 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.assignments.swap(*(yyvsp[-1].assignment_list));
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.reset((yyvsp[0].condition_list));
      }
      free((yyvsp[-3].string));
      delete (yyvsp[-1].assignment_list);
    }
#line 2309 "yacc_sql.cpp"
    break;

  case 65: /* select_stmt: SELECT expression_list FROM rel_alias_list join_list where group_by having order_by limit  */
#line 559 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-8].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-8].expression_list));
        delete (yyvsp[-8].expression_list);
      }

      if ((yyvsp[-6].rel_alias_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-6].rel_alias_list));
        delete (yyvsp[-6].rel_alias_list);
      }

      if ((yyvsp[-4].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.reset((yyvsp[-4].condition_list));
      }

      if ((yyvsp[-3].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-3].expression_list));
        delete (yyvsp[-3].expression_list);
      }

      if ((yyvsp[-5].join_list) != nullptr) {
        (yyval.sql_node)->selection.relations.insert((yyval.sql_node)->selection.relations.end(), std::make_move_iterator((yyvsp[-5].join_list)->relations.begin()), std::make_move_iterator((yyvsp[-5].join_list)->relations.end()));
        auto &conditions = (yyval.sql_node)->selection.conditions;
        if (conditions == nullptr) {
          conditions = std::move((yyvsp[-5].join_list)->conditions);
        } else {
          if (conditions->type() != ExprType::CONJUNCTION  || ((ConjunctionExpr *)conditions.get())->conjunction_type() != ConjunctionExpr::Type::AND) {
            std::vector<std::unique_ptr<Expression>> list;
            list.emplace_back(std::move(conditions));
            ConjunctionExpr *conj_expr = new ConjunctionExpr(ConjunctionExpr::Type::AND, list);
            conditions.reset(conj_expr);
          }
          ((ConjunctionExpr *)conditions.get())->children().emplace_back(std::move((yyvsp[-5].join_list)->conditions));
        }
        delete (yyvsp[-5].join_list);
      }

      if ((yyvsp[-2].condition_list) != nullptr) {
        (yyval.sql_node)->selection.having.reset((yyvsp[-2].condition_list));
      }

      if ((yyvsp[-1].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.order_by.swap(*(yyvsp[-1].order_by_list));
        delete (yyvsp[-1].order_by_list);
      }

      (yyval.sql_node)->selection.limit = (yyvsp[0].number);
    }
#line 2363 "yacc_sql.cpp"
    break;

  case 66: /* calc_stmt: CALC expression_list  */
#line 611 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2373 "yacc_sql.cpp"
    break;

  case 67: /* limit: %empty  */
#line 620 "yacc_sql.y"
    {
      (yyval.number) = -1;
    }
#line 2381 "yacc_sql.cpp"
    break;

  case 68: /* limit: LIMIT NUMBER  */
#line 624 "yacc_sql.y"
    {
      (yyval.number) = (yyvsp[0].number);
    }
#line 2389 "yacc_sql.cpp"
    break;

  case 69: /* assignment_list: assignment  */
#line 630 "yacc_sql.y"
    {
      (yyval.assignment_list) = new std::vector<std::unique_ptr<Assignment>>;
      (yyval.assignment_list)->emplace_back((yyvsp[0].assignment));
    }
#line 2398 "yacc_sql.cpp"
    break;

  case 70: /* assignment_list: assignment COMMA assignment_list  */
#line 635 "yacc_sql.y"
    {
      (yyval.assignment_list) = (yyvsp[0].assignment_list);
      (yyval.assignment_list)->emplace_back((yyvsp[-2].assignment));
    }
#line 2407 "yacc_sql.cpp"
    break;

  case 71: /* assignment: ID EQ value  */
#line 642 "yacc_sql.y"
    {
      (yyval.assignment) = new Assignment;
      (yyval.assignment)->attribute_name = (yyvsp[-2].string);
      (yyval.assignment)->value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2419 "yacc_sql.cpp"
    break;

  case 72: /* expression_list: expression  */
#line 653 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2428 "yacc_sql.cpp"
    break;

  case 73: /* expression_list: expression ID  */
#line 658 "yacc_sql.y"
    {
      (yyvsp[-1].expression)->set_name((yyvsp[0].string));
      free (yyvsp[0].string);
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
    }
#line 2439 "yacc_sql.cpp"
    break;

  case 74: /* expression_list: expression AS ID  */
#line 665 "yacc_sql.y"
    {
      (yyvsp[-2].expression)->set_name((yyvsp[0].string));
      free (yyvsp[0].string);
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[-2].expression));
    }
#line 2450 "yacc_sql.cpp"
    break;

  case 75: /* expression_list: expression COMMA expression_list  */
#line 672 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2463 "yacc_sql.cpp"
    break;

  case 76: /* expression_list: expression ID COMMA expression_list  */
#line 681 "yacc_sql.y"
    {
      (yyvsp[-3].expression)->set_name((yyvsp[-2].string));
      free (yyvsp[-2].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-3].expression));
    }
#line 2478 "yacc_sql.cpp"
    break;

  case 77: /* expression_list: expression AS ID COMMA expression_list  */
#line 692 "yacc_sql.y"
    {
      (yyvsp[-4].expression)->set_name((yyvsp[-2].string));
      free (yyvsp[-2].string);
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-4].expression));
    }
#line 2493 "yacc_sql.cpp"
    break;

  case 78: /* expression: L2_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 704 "yacc_sql.y"
                                                          {
      (yyval.expression) = new FunctionExpr(FunctionExpr::Type::L2_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2502 "yacc_sql.cpp"
    break;

  case 79: /* expression: COSINE_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 708 "yacc_sql.y"
                                                                {
      (yyval.expression) = new FunctionExpr(FunctionExpr::Type::COSINE_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2511 "yacc_sql.cpp"
    break;

  case 80: /* expression: INNER_PRODUCT LBRACE expression COMMA expression RBRACE  */
#line 712 "yacc_sql.y"
                                                              {
      (yyval.expression) = new FunctionExpr(FunctionExpr::Type::INNER_PRODUCT, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2520 "yacc_sql.cpp"
    break;

  case 81: /* expression: expression '+' expression  */
#line 716 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2528 "yacc_sql.cpp"
    break;

  case 82: /* expression: expression '-' expression  */
#line 719 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2536 "yacc_sql.cpp"
    break;

  case 83: /* expression: expression '*' expression  */
#line 722 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2544 "yacc_sql.cpp"
    break;

  case 84: /* expression: expression '/' expression  */
#line 725 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2552 "yacc_sql.cpp"
    break;

  case 85: /* expression: LBRACE expression RBRACE  */
#line 728 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2561 "yacc_sql.cpp"
    break;

  case 86: /* expression: '-' expression  */
#line 732 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2569 "yacc_sql.cpp"
    break;

  case 87: /* expression: AGGREGATE LBRACE expression RBRACE  */
#line 735 "yacc_sql.y"
                                         {
      (yyval.expression) = create_aggregate_expression((yyvsp[-3].string), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2577 "yacc_sql.cpp"
    break;

  case 88: /* expression: value  */
#line 738 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2587 "yacc_sql.cpp"
    break;

  case 89: /* expression: rel_attr  */
#line 743 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2598 "yacc_sql.cpp"
    break;

  case 90: /* expression: '*'  */
#line 749 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
      (yyval.expression)->set_name("*");
    }
#line 2607 "yacc_sql.cpp"
    break;

  case 91: /* expression: LBRACE select_stmt RBRACE  */
#line 753 "yacc_sql.y"
                                {
      (yyval.expression) = new SubqueryExpr((yyvsp[-1].sql_node));
    }
#line 2615 "yacc_sql.cpp"
    break;

  case 92: /* rel_attr: ID  */
#line 759 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2625 "yacc_sql.cpp"
    break;

  case 93: /* rel_attr: ID DOT ID  */
#line 764 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2637 "yacc_sql.cpp"
    break;

  case 94: /* relation: ID  */
#line 774 "yacc_sql.y"
       {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2645 "yacc_sql.cpp"
    break;

  case 95: /* rel_list: relation  */
#line 779 "yacc_sql.y"
             {
      (yyval.relation_list) = new std::vector<std::string>();
      (yyval.relation_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2655 "yacc_sql.cpp"
    break;

  case 96: /* rel_list: relation COMMA rel_list  */
#line 784 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->insert((yyval.relation_list)->begin(), (yyvsp[-2].string));
      free((yyvsp[-2].string));
    }
#line 2670 "yacc_sql.cpp"
    break;

  case 97: /* rel_alias_list: relation  */
#line 796 "yacc_sql.y"
             {
      (yyval.rel_alias_list) = new std::vector<std::pair<std::string, std::string>>();
      (yyval.rel_alias_list)->emplace_back((yyvsp[0].string), "");
      free((yyvsp[0].string));
    }
#line 2680 "yacc_sql.cpp"
    break;

  case 98: /* rel_alias_list: relation ID  */
#line 801 "yacc_sql.y"
                  {
      (yyval.rel_alias_list) = new std::vector<std::pair<std::string, std::string>>();
      (yyval.rel_alias_list)->emplace_back((yyvsp[-1].string), (yyvsp[0].string));
      free((yyvsp[-1].string));
      free((yyvsp[0].string));
    }
#line 2691 "yacc_sql.cpp"
    break;

  case 99: /* rel_alias_list: relation COMMA rel_alias_list  */
#line 807 "yacc_sql.y"
                                    {
      if ((yyvsp[0].rel_alias_list) != nullptr) {
        (yyval.rel_alias_list) = (yyvsp[0].rel_alias_list);
      } else {
        (yyval.rel_alias_list) = new std::vector<std::pair<std::string, std::string>>();
      }
      (yyval.rel_alias_list)->emplace((yyval.rel_alias_list)->begin(), (yyvsp[-2].string), "");
      free((yyvsp[-2].string));
    }
#line 2705 "yacc_sql.cpp"
    break;

  case 100: /* rel_alias_list: relation ID COMMA rel_alias_list  */
#line 816 "yacc_sql.y"
                                       {
      if ((yyvsp[0].rel_alias_list) != nullptr) {
        (yyval.rel_alias_list) = (yyvsp[0].rel_alias_list);
      } else {
        (yyval.rel_alias_list) = new std::vector<std::pair<std::string, std::string>>();
      }
      (yyval.rel_alias_list)->emplace((yyval.rel_alias_list)->begin(), (yyvsp[-3].string), (yyvsp[-2].string));
      free((yyvsp[-3].string));
      free((yyvsp[-2].string));
    }
#line 2720 "yacc_sql.cpp"
    break;

  case 101: /* join_list: %empty  */
#line 830 "yacc_sql.y"
    {
      (yyval.join_list) = nullptr;
    }
#line 2728 "yacc_sql.cpp"
    break;

  case 102: /* join_list: join_list INNER_JOIN relation ON condition_list  */
#line 834 "yacc_sql.y"
    {
      if ((yyvsp[-4].join_list) == nullptr)
        (yyval.join_list) = new JoinSqlNode;
      else
        (yyval.join_list) = (yyvsp[-4].join_list);
      (yyval.join_list)->relations.emplace_back((yyvsp[-2].string), "");
      if ((yyval.join_list)->conditions == nullptr) {
        (yyval.join_list)->conditions.reset((yyvsp[0].condition_list));
      } else {
        if ((yyval.join_list)->conditions->type() != ExprType::CONJUNCTION || ((ConjunctionExpr *)(yyval.join_list)->conditions.get())->conjunction_type() != ConjunctionExpr::Type::AND) {
          std::vector<std::unique_ptr<Expression>> list;
          list.emplace_back(std::move((yyval.join_list)->conditions));
          Expression *conj_expr = new ConjunctionExpr(ConjunctionExpr::Type::AND, list);
          (yyval.join_list)->conditions.reset(conj_expr);
        }
        ((ConjunctionExpr *)(yyval.join_list)->conditions.get())->children().emplace_back((yyvsp[0].condition_list));
      }
      free((yyvsp[-2].string));
    }
#line 2752 "yacc_sql.cpp"
    break;

  case 103: /* join_list: join_list INNER_JOIN relation ID ON condition_list  */
#line 854 "yacc_sql.y"
    {
      if ((yyvsp[-5].join_list) == nullptr)
        (yyval.join_list) = new JoinSqlNode;
      else
        (yyval.join_list) = (yyvsp[-5].join_list);
      (yyval.join_list)->relations.emplace_back((yyvsp[-3].string), (yyvsp[-2].string));
      if ((yyval.join_list)->conditions == nullptr) {
        (yyval.join_list)->conditions.reset((yyvsp[0].condition_list));
      } else {
        if ((yyval.join_list)->conditions->type() != ExprType::CONJUNCTION || ((ConjunctionExpr *)(yyval.join_list)->conditions.get())->conjunction_type() != ConjunctionExpr::Type::AND) {
          std::vector<std::unique_ptr<Expression>> list;
          list.emplace_back(std::move((yyval.join_list)->conditions));
          Expression *conj_expr = new ConjunctionExpr(ConjunctionExpr::Type::AND, list);
          (yyval.join_list)->conditions.reset(conj_expr);
        }
        ((ConjunctionExpr *)(yyval.join_list)->conditions.get())->children().emplace_back((yyvsp[0].condition_list));
      }
      free((yyvsp[-3].string));
      free((yyvsp[-2].string));
    }
#line 2777 "yacc_sql.cpp"
    break;

  case 104: /* where: %empty  */
#line 877 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2785 "yacc_sql.cpp"
    break;

  case 105: /* where: WHERE condition_list  */
#line 880 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2793 "yacc_sql.cpp"
    break;

  case 106: /* condition_list: condition  */
#line 885 "yacc_sql.y"
              {
      (yyval.condition_list) = (yyvsp[0].condition);
    }
#line 2801 "yacc_sql.cpp"
    break;

  case 107: /* condition_list: condition AND condition_list  */
#line 888 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      if ((yyval.condition_list)->type() != ExprType::CONJUNCTION) {
        std::vector<std::unique_ptr<Expression>> list;
        list.emplace_back((yyval.condition_list));
        ConjunctionExpr *conj_expr = new ConjunctionExpr(ConjunctionExpr::Type::AND, list);
        (yyval.condition_list) = conj_expr;
      }
      ((ConjunctionExpr *)(yyval.condition_list))->children().emplace_back((yyvsp[-2].condition));
    }
#line 2816 "yacc_sql.cpp"
    break;

  case 108: /* condition_list: condition OR condition_list  */
#line 898 "yacc_sql.y"
                                  {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      if ((yyval.condition_list)->type() != ExprType::CONJUNCTION) {
        std::vector<std::unique_ptr<Expression>> list;
        list.emplace_back((yyval.condition_list));
        ConjunctionExpr *conj_expr = new ConjunctionExpr(ConjunctionExpr::Type::OR, list);
        (yyval.condition_list) = conj_expr;
      }
      ((ConjunctionExpr *)(yyval.condition_list))->children().emplace_back((yyvsp[-2].condition));
    }
#line 2831 "yacc_sql.cpp"
    break;

  case 109: /* condition: expression comp_op expression  */
#line 911 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr((yyvsp[-1].comp), (yyvsp[-2].expression), (yyvsp[0].expression));
    }
#line 2839 "yacc_sql.cpp"
    break;

  case 110: /* condition: expression IS NIL  */
#line 915 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr(IS_NULL, (yyvsp[-2].expression), new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
#line 2847 "yacc_sql.cpp"
    break;

  case 111: /* condition: expression IS NOT NIL  */
#line 919 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr(NOT_NULL, (yyvsp[-3].expression), new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
#line 2855 "yacc_sql.cpp"
    break;

  case 112: /* condition: expression IN LBRACE value value_list RBRACE  */
#line 923 "yacc_sql.y"
    {
      vector<Value> vl;
      if ((yyvsp[-1].value_list) != nullptr) {
        vl.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      vl.emplace(vl.begin(), (yyvsp[-2].value));
      (yyval.condition) = new ComparisonExpr(SUB_IN, (yyvsp[-5].expression), new ValueListExpr(vl));
    }
#line 2869 "yacc_sql.cpp"
    break;

  case 113: /* condition: expression NOT IN LBRACE value value_list RBRACE  */
#line 933 "yacc_sql.y"
    {
      vector<Value> vl;
      if ((yyvsp[-1].value_list) != nullptr) {
        vl.swap(*(yyvsp[-1].value_list));
        delete (yyvsp[-1].value_list);
      }
      vl.emplace(vl.begin(), (yyvsp[-2].value));
      (yyval.condition) = new ComparisonExpr(SUB_NOT_IN, (yyvsp[-6].expression), new ValueListExpr(vl));
    }
#line 2883 "yacc_sql.cpp"
    break;

  case 114: /* condition: expression IN LBRACE select_stmt RBRACE  */
#line 943 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr(SUB_IN, (yyvsp[-4].expression), new SubqueryExpr((yyvsp[-1].sql_node)));
    }
#line 2891 "yacc_sql.cpp"
    break;

  case 115: /* condition: expression NOT IN LBRACE select_stmt RBRACE  */
#line 947 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr(SUB_NOT_IN, (yyvsp[-5].expression), new SubqueryExpr((yyvsp[-1].sql_node)));
    }
#line 2899 "yacc_sql.cpp"
    break;

  case 116: /* condition: EXISTS LBRACE select_stmt RBRACE  */
#line 951 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr(SUB_EXISTS, new SubqueryExpr((yyvsp[-1].sql_node)), new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
#line 2907 "yacc_sql.cpp"
    break;

  case 117: /* condition: NOT EXISTS LBRACE select_stmt RBRACE  */
#line 955 "yacc_sql.y"
    {
      (yyval.condition) = new ComparisonExpr(SUB_NOT_EXISTS, new SubqueryExpr((yyvsp[-1].sql_node)), new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
#line 2915 "yacc_sql.cpp"
    break;

  case 118: /* comp_op: EQ  */
#line 961 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2921 "yacc_sql.cpp"
    break;

  case 119: /* comp_op: LT  */
#line 962 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2927 "yacc_sql.cpp"
    break;

  case 120: /* comp_op: GT  */
#line 963 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2933 "yacc_sql.cpp"
    break;

  case 121: /* comp_op: LE  */
#line 964 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2939 "yacc_sql.cpp"
    break;

  case 122: /* comp_op: GE  */
#line 965 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2945 "yacc_sql.cpp"
    break;

  case 123: /* comp_op: NE  */
#line 966 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2951 "yacc_sql.cpp"
    break;

  case 124: /* comp_op: LK  */
#line 967 "yacc_sql.y"
         { (yyval.comp) = LIKE; }
#line 2957 "yacc_sql.cpp"
    break;

  case 125: /* comp_op: NOT LK  */
#line 968 "yacc_sql.y"
             { (yyval.comp) = NOT_LIKE; }
#line 2963 "yacc_sql.cpp"
    break;

  case 126: /* group_by: %empty  */
#line 973 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2971 "yacc_sql.cpp"
    break;

  case 127: /* group_by: GROUP BY expression_list  */
#line 977 "yacc_sql.y"
    {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 2979 "yacc_sql.cpp"
    break;

  case 128: /* order_by_item: expression  */
#line 984 "yacc_sql.y"
    {
      (yyval.order_by_item) = new std::pair<std::unique_ptr<Expression>, bool>((yyvsp[0].expression), true);
    }
#line 2987 "yacc_sql.cpp"
    break;

  case 129: /* order_by_item: expression ASC  */
#line 988 "yacc_sql.y"
    {
      (yyval.order_by_item) = new std::pair<std::unique_ptr<Expression>, bool>((yyvsp[-1].expression), true);
    }
#line 2995 "yacc_sql.cpp"
    break;

  case 130: /* order_by_item: expression DESC  */
#line 992 "yacc_sql.y"
    {
      (yyval.order_by_item) = new std::pair<std::unique_ptr<Expression>, bool>((yyvsp[-1].expression), false);
    }
#line 3003 "yacc_sql.cpp"
    break;

  case 131: /* order_by_list: order_by_item  */
#line 998 "yacc_sql.y"
    {
      (yyval.order_by_list) = new std::vector<std::pair<std::unique_ptr<Expression>, bool>>;
      (yyval.order_by_list)->emplace_back(std::move(*(yyvsp[0].order_by_item)));
      delete (yyvsp[0].order_by_item);
    }
#line 3013 "yacc_sql.cpp"
    break;

  case 132: /* order_by_list: order_by_item COMMA order_by_list  */
#line 1004 "yacc_sql.y"
    {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
      (yyval.order_by_list)->insert((yyval.order_by_list)->begin(), std::move(*(yyvsp[-2].order_by_item)));
      delete (yyvsp[-2].order_by_item);
    }
#line 3023 "yacc_sql.cpp"
    break;

  case 133: /* order_by: %empty  */
#line 1012 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 3031 "yacc_sql.cpp"
    break;

  case 134: /* order_by: ORDER BY order_by_list  */
#line 1016 "yacc_sql.y"
    {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
    }
#line 3039 "yacc_sql.cpp"
    break;

  case 135: /* having: %empty  */
#line 1023 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3047 "yacc_sql.cpp"
    break;

  case 136: /* having: HAVING condition_list  */
#line 1026 "yacc_sql.y"
                            {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 3055 "yacc_sql.cpp"
    break;

  case 137: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1033 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3069 "yacc_sql.cpp"
    break;

  case 138: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1046 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3078 "yacc_sql.cpp"
    break;

  case 139: /* set_variable_stmt: SET ID EQ value  */
#line 1054 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3090 "yacc_sql.cpp"
    break;


#line 3094 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1066 "yacc_sql.y"

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
