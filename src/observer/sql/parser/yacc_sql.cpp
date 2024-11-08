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
  YYSYMBOL_TABLE = 10,                     /* TABLE  */
  YYSYMBOL_TABLES = 11,                    /* TABLES  */
  YYSYMBOL_UNIQUE = 12,                    /* UNIQUE  */
  YYSYMBOL_INDEX = 13,                     /* INDEX  */
  YYSYMBOL_CALC = 14,                      /* CALC  */
  YYSYMBOL_SELECT = 15,                    /* SELECT  */
  YYSYMBOL_DESC = 16,                      /* DESC  */
  YYSYMBOL_SHOW = 17,                      /* SHOW  */
  YYSYMBOL_SYNC = 18,                      /* SYNC  */
  YYSYMBOL_INSERT = 19,                    /* INSERT  */
  YYSYMBOL_DELETE = 20,                    /* DELETE  */
  YYSYMBOL_UPDATE = 21,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 27,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 28,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 29,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 30,                     /* INT_T  */
  YYSYMBOL_STRING_T = 31,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 32,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 33,                    /* DATE_T  */
  YYSYMBOL_VECTOR_T = 34,                  /* VECTOR_T  */
  YYSYMBOL_NIL = 35,                       /* NIL  */
  YYSYMBOL_HELP = 36,                      /* HELP  */
  YYSYMBOL_EXIT = 37,                      /* EXIT  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_INTO = 39,                      /* INTO  */
  YYSYMBOL_VALUES = 40,                    /* VALUES  */
  YYSYMBOL_FROM = 41,                      /* FROM  */
  YYSYMBOL_INNER_JOIN = 42,                /* INNER_JOIN  */
  YYSYMBOL_WHERE = 43,                     /* WHERE  */
  YYSYMBOL_HAVING = 44,                    /* HAVING  */
  YYSYMBOL_NOT = 45,                       /* NOT  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_SET = 47,                       /* SET  */
  YYSYMBOL_ON = 48,                        /* ON  */
  YYSYMBOL_LOAD = 49,                      /* LOAD  */
  YYSYMBOL_DATA = 50,                      /* DATA  */
  YYSYMBOL_INFILE = 51,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 52,                   /* EXPLAIN  */
  YYSYMBOL_STORAGE = 53,                   /* STORAGE  */
  YYSYMBOL_FORMAT = 54,                    /* FORMAT  */
  YYSYMBOL_EQ = 55,                        /* EQ  */
  YYSYMBOL_LT = 56,                        /* LT  */
  YYSYMBOL_GT = 57,                        /* GT  */
  YYSYMBOL_LE = 58,                        /* LE  */
  YYSYMBOL_GE = 59,                        /* GE  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_IS = 61,                        /* IS  */
  YYSYMBOL_LK = 62,                        /* LK  */
  YYSYMBOL_L2_DISTANCE = 63,               /* L2_DISTANCE  */
  YYSYMBOL_COSINE_DISTANCE = 64,           /* COSINE_DISTANCE  */
  YYSYMBOL_INNER_PRODUCT = 65,             /* INNER_PRODUCT  */
  YYSYMBOL_NUMBER = 66,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 67,                     /* FLOAT  */
  YYSYMBOL_ID = 68,                        /* ID  */
  YYSYMBOL_AGGREGATE = 69,                 /* AGGREGATE  */
  YYSYMBOL_SSS = 70,                       /* SSS  */
  YYSYMBOL_71_ = 71,                       /* '+'  */
  YYSYMBOL_72_ = 72,                       /* '-'  */
  YYSYMBOL_73_ = 73,                       /* '*'  */
  YYSYMBOL_74_ = 74,                       /* '/'  */
  YYSYMBOL_UMINUS = 75,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_commands = 77,                  /* commands  */
  YYSYMBOL_command_wrapper = 78,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 79,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 80,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 81,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 82,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 83,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 84,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 85,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 86,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 87,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 88,         /* create_index_stmt  */
  YYSYMBOL_drop_index_stmt = 89,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 90,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 91,             /* attr_def_list  */
  YYSYMBOL_attr_def = 92,                  /* attr_def  */
  YYSYMBOL_nullable = 93,                  /* nullable  */
  YYSYMBOL_number = 94,                    /* number  */
  YYSYMBOL_type = 95,                      /* type  */
  YYSYMBOL_insert_stmt = 96,               /* insert_stmt  */
  YYSYMBOL_value_list = 97,                /* value_list  */
  YYSYMBOL_value = 98,                     /* value  */
  YYSYMBOL_storage_format = 99,            /* storage_format  */
  YYSYMBOL_delete_stmt = 100,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 101,              /* update_stmt  */
  YYSYMBOL_select_stmt = 102,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 103,                /* calc_stmt  */
  YYSYMBOL_assignment_list = 104,          /* assignment_list  */
  YYSYMBOL_assignment = 105,               /* assignment  */
  YYSYMBOL_expression_list = 106,          /* expression_list  */
  YYSYMBOL_expression = 107,               /* expression  */
  YYSYMBOL_rel_attr = 108,                 /* rel_attr  */
  YYSYMBOL_relation = 109,                 /* relation  */
  YYSYMBOL_rel_list = 110,                 /* rel_list  */
  YYSYMBOL_join_list = 111,                /* join_list  */
  YYSYMBOL_where = 112,                    /* where  */
  YYSYMBOL_condition_list = 113,           /* condition_list  */
  YYSYMBOL_condition = 114,                /* condition  */
  YYSYMBOL_comp_op = 115,                  /* comp_op  */
  YYSYMBOL_group_by = 116,                 /* group_by  */
  YYSYMBOL_order_by_item = 117,            /* order_by_item  */
  YYSYMBOL_order_by_list = 118,            /* order_by_list  */
  YYSYMBOL_order_by = 119,                 /* order_by  */
  YYSYMBOL_having = 120,                   /* having  */
  YYSYMBOL_load_data_stmt = 121,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 122,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 123,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 124             /* opt_semicolon  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


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
       2,     2,    73,    71,     2,    72,     2,    74,     2,     2,
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
      65,    66,    67,    68,    69,    70,    75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   219,   219,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   250,   256,   261,   267,   273,   279,   285,
     292,   298,   306,   318,   333,   343,   367,   370,   383,   392,
     401,   414,   417,   421,   428,   431,   432,   433,   434,   437,
     454,   457,   468,   477,   481,   485,   489,   498,   501,   508,
     520,   534,   575,   584,   589,   596,   607,   612,   623,   627,
     631,   635,   638,   641,   644,   647,   651,   654,   657,   662,
     668,   674,   679,   689,   694,   699,   713,   716,   730,   733,
     739,   742,   746,   752,   759,   766,   776,   777,   778,   779,
     780,   781,   782,   783,   788,   791,   798,   802,   806,   812,
     818,   827,   830,   838,   841,   847,   860,   868,   878,   879
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
  "CREATE", "DROP", "GROUP", "ORDER", "ASC", "TABLE", "TABLES", "UNIQUE",
  "INDEX", "CALC", "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE",
  "UPDATE", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "VECTOR_T", "NIL", "HELP", "EXIT", "DOT", "INTO",
  "VALUES", "FROM", "INNER_JOIN", "WHERE", "HAVING", "NOT", "AND", "SET",
  "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "STORAGE", "FORMAT", "EQ",
  "LT", "GT", "LE", "GE", "NE", "IS", "LK", "L2_DISTANCE",
  "COSINE_DISTANCE", "INNER_PRODUCT", "NUMBER", "FLOAT", "ID", "AGGREGATE",
  "SSS", "'+'", "'-'", "'*'", "'/'", "UMINUS", "$accept", "commands",
  "command_wrapper", "exit_stmt", "help_stmt", "sync_stmt", "begin_stmt",
  "commit_stmt", "rollback_stmt", "drop_table_stmt", "show_tables_stmt",
  "desc_table_stmt", "create_index_stmt", "drop_index_stmt",
  "create_table_stmt", "attr_def_list", "attr_def", "nullable", "number",
  "type", "insert_stmt", "value_list", "value", "storage_format",
  "delete_stmt", "update_stmt", "select_stmt", "calc_stmt",
  "assignment_list", "assignment", "expression_list", "expression",
  "rel_attr", "relation", "rel_list", "join_list", "where",
  "condition_list", "condition", "comp_op", "group_by", "order_by_item",
  "order_by_list", "order_by", "having", "load_data_stmt", "explain_stmt",
  "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     143,     4,    20,    39,    39,   -63,     2,  -129,   -20,   -19,
     -37,  -129,  -129,  -129,  -129,  -129,   -32,    12,   143,    73,
      91,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,    33,    97,    50,    51,    56,    39,   111,  -129,   103,
     104,   105,  -129,  -129,    90,   107,  -129,    39,  -129,  -129,
    -129,   -22,  -129,    92,  -129,  -129,    64,    68,    87,    86,
      96,  -129,  -129,  -129,  -129,   128,    84,   106,  -129,   108,
     -17,   125,    39,    39,    39,    85,    39,  -129,    39,    39,
      39,    39,    39,    99,   115,   122,   101,   111,   112,   117,
     126,   119,   120,  -129,   111,   148,    14,    66,    71,  -129,
      -3,  -129,   -39,   -39,  -129,  -129,  -129,   149,  -129,   154,
      39,  -129,   134,   122,   157,  -129,   155,    83,   167,   136,
     183,  -129,   125,  -129,    39,    39,    39,  -129,    99,     0,
     111,   141,  -129,   160,   111,  -129,   101,   197,  -129,   187,
    -129,  -129,   188,   -27,   117,   193,   189,    99,  -129,     5,
       9,    49,  -129,    99,   210,   125,   156,  -129,  -129,  -129,
    -129,  -129,  -129,   -24,  -129,    39,    39,  -129,  -129,   151,
     158,   158,  -129,   185,  -129,   167,   168,    99,   199,  -129,
    -129,  -129,   175,   221,   182,   204,  -129,  -129,   194,   -47,
    -129,  -129,  -129,   205,   207,  -129,  -129,   177,  -129,   209,
    -129,    39,    39,    39,   225,  -129,  -129,   -27,   -27,   179,
    -129,  -129,  -129,  -129,   231,  -129,  -129,  -129,   169,    39,
    -129,    -7,   212,  -129,  -129,  -129,    39,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     118,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,    53,    54,    81,     0,    56,     0,    80,    78,
      62,    66,    79,     0,    31,    30,     0,     0,     0,     0,
       0,   116,     1,   119,     2,     0,     0,     0,    29,     0,
       0,    50,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,    82,
       0,    67,    71,    72,    73,    74,    83,    84,    86,     0,
      90,    59,     0,    88,    63,   117,     0,     0,    36,     0,
       0,    34,    50,    52,     0,     0,     0,    77,     0,    88,
       0,     0,    89,    91,     0,    60,     0,     0,    45,    46,
      47,    48,     0,    41,     0,     0,     0,     0,    51,     0,
       0,     0,    85,     0,   104,    50,     0,    96,    97,    98,
      99,   100,   101,     0,   102,     0,    90,    65,    64,     0,
       0,     0,    42,     0,    40,    36,    57,     0,     0,    68,
      69,    70,     0,     0,   113,     0,   103,    94,     0,    93,
      92,   115,    44,     0,     0,    43,    37,     0,    35,     0,
      32,    90,     0,    90,   111,    49,    95,    41,    41,     0,
      33,    87,   105,   114,     0,    61,    38,    39,     0,     0,
      58,   106,   109,   112,   107,   108,     0,   110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   218,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,    54,    88,  -119,    59,  -129,
    -129,  -117,   -44,  -129,  -129,  -129,  -129,  -129,    95,  -129,
      -4,   -45,  -129,    80,  -128,  -129,  -116,  -118,  -129,  -129,
    -129,  -129,     8,  -129,  -129,  -129,  -129,  -129,  -129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   155,   128,   184,   203,   153,
      33,   105,    59,   208,    34,    35,    36,    37,   123,   124,
      60,    61,    62,   117,   118,   139,   121,   142,   143,   175,
     194,   232,   233,   225,   214,    38,    39,    40,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      63,    80,   234,    81,    88,    64,   103,   145,   182,   235,
     162,   197,    87,    65,    41,   158,    42,    43,   183,    66,
     137,   198,    67,   164,    89,    90,    91,    92,   189,   188,
      44,    68,   190,    45,    91,    92,    69,   106,   107,   108,
     134,   110,   163,   120,   112,   113,   114,   115,   195,    89,
      90,    91,    92,   125,    89,    90,    91,    92,   200,   209,
     132,    46,    70,    47,    89,    90,    91,    92,    89,    90,
      91,    92,   191,    72,    48,   141,    89,    90,    91,    92,
      89,    90,    91,    92,   111,    89,    90,    91,    92,   159,
     160,   161,   135,   221,    73,   223,   165,   136,   226,   227,
     177,    75,    49,    50,    51,    52,    53,    54,    55,    56,
      76,    57,    58,   148,   149,   150,   151,   152,    77,    78,
      89,    90,    91,    92,    79,    82,    83,    84,    85,    86,
     199,   141,    94,    93,    96,    47,    95,    89,    90,    91,
      92,    97,    89,    90,    91,    92,    48,    98,     1,     2,
      99,   104,   100,   109,   101,   119,   102,     3,     4,     5,
       6,     7,     8,     9,    10,   120,   141,   116,   141,   122,
      11,    12,    13,   133,   129,   138,   140,    52,    53,    14,
      15,    56,   126,   146,   231,   127,   166,   130,   131,   144,
      16,   231,    17,   154,   147,    18,   167,   168,   169,   170,
     171,   172,   173,   174,   156,   157,   176,   179,   222,   180,
     181,   187,    89,    90,    91,    92,   186,   193,   196,   201,
     205,   207,   210,   211,   202,   212,   213,   215,   217,   216,
     218,   219,   220,   224,   228,   229,    71,   230,   236,   206,
     204,   178,   185,   192,   237
};

static const yytype_uint8 yycheck[] =
{
       4,    46,     9,    47,    26,    68,    23,   123,    35,    16,
     138,    35,    57,    11,    10,   132,    12,    13,    45,    39,
      23,    45,    41,   139,    71,    72,    73,    74,    23,   157,
      10,    68,    23,    13,    73,    74,    68,    82,    83,    84,
      26,    86,    42,    43,    89,    90,    91,    92,   165,    71,
      72,    73,    74,    97,    71,    72,    73,    74,   176,   187,
     104,    22,    50,    24,    71,    72,    73,    74,    71,    72,
      73,    74,    23,     0,    35,   120,    71,    72,    73,    74,
      71,    72,    73,    74,    88,    71,    72,    73,    74,   134,
     135,   136,    26,   211,     3,   213,   140,    26,   217,   218,
     144,    68,    63,    64,    65,    66,    67,    68,    69,    70,
      13,    72,    73,    30,    31,    32,    33,    34,    68,    68,
      71,    72,    73,    74,    68,    22,    22,    22,    38,    22,
     175,   176,    68,    41,    47,    24,    68,    71,    72,    73,
      74,    55,    71,    72,    73,    74,    35,    51,     5,     6,
      22,    26,    68,    68,    48,    40,    48,    14,    15,    16,
      17,    18,    19,    20,    21,    43,   211,    68,   213,    68,
      27,    28,    29,    25,    48,    26,    22,    66,    67,    36,
      37,    70,    70,    26,   229,    68,    45,    68,    68,    55,
      47,   236,    49,    26,    39,    52,    55,    56,    57,    58,
      59,    60,    61,    62,    68,    22,    46,    10,   212,    22,
      22,    22,    71,    72,    73,    74,    23,     7,    62,    68,
      35,    53,    23,    48,    66,     4,    44,    23,    23,    35,
      23,    54,    23,     8,    55,     4,    18,    68,    26,   185,
     181,   146,   154,   163,   236
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    14,    15,    16,    17,    18,    19,    20,
      21,    27,    28,    29,    36,    37,    47,    49,    52,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    96,   100,   101,   102,   103,   121,   122,
     123,    10,    12,    13,    10,    13,    22,    24,    35,    63,
      64,    65,    66,    67,    68,    69,    70,    72,    73,    98,
     106,   107,   108,   106,    68,    11,    39,    41,    68,    68,
      50,    78,     0,     3,   124,    68,    13,    68,    68,    68,
     107,    98,    22,    22,    22,    38,    22,   107,    26,    71,
      72,    73,    74,    41,    68,    68,    47,    55,    51,    22,
      68,    48,    48,    23,    26,    97,   107,   107,   107,    68,
     107,   106,   107,   107,   107,   107,    68,   109,   110,    40,
      43,   112,    68,   104,   105,    98,    70,    68,    92,    48,
      68,    68,    98,    25,    26,    26,    26,    23,    26,   111,
      22,   107,   113,   114,    55,   112,    26,    39,    30,    31,
      32,    33,    34,    95,    26,    91,    68,    22,    97,   107,
     107,   107,   110,    42,   112,    98,    45,    55,    56,    57,
      58,    59,    60,    61,    62,   115,    46,    98,   104,    10,
      22,    22,    35,    45,    93,    92,    23,    22,   110,    23,
      23,    23,   109,     7,   116,    97,    62,    35,    45,   107,
     113,    68,    66,    94,    94,    35,    91,    53,    99,   110,
      23,    48,     4,    44,   120,    23,    35,    23,    23,    54,
      23,   113,   106,   113,     8,   119,    93,    93,    55,     4,
      68,   107,   117,   118,     9,    16,    26,   118
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    88,    89,    90,    91,    91,    92,    92,
      92,    93,    93,    93,    94,    95,    95,    95,    95,    96,
      97,    97,    98,    98,    98,    98,    98,    99,    99,   100,
     101,   102,   103,   104,   104,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   114,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   122,   123,   124,   124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     8,     9,     5,     8,     0,     3,     6,     6,
       3,     0,     1,     2,     1,     1,     1,     1,     1,     8,
       0,     3,     4,     1,     1,     1,     1,     0,     4,     4,
       5,     9,     2,     1,     3,     3,     1,     3,     6,     6,
       6,     3,     3,     3,     3,     3,     2,     4,     1,     1,
       1,     1,     3,     1,     1,     3,     0,     5,     0,     2,
       0,     1,     3,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     1,     2,     2,     1,
       3,     0,     3,     0,     2,     7,     2,     4,     0,     1
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
#line 220 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1811 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 250 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1820 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 256 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1828 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 261 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1836 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 267 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1844 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 273 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1852 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 279 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1860 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 285 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1870 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 292 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1878 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 298 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1888 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE rel_list RBRACE  */
#line 307 "yacc_sql.y"
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
#line 1904 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE rel_list RBRACE  */
#line 319 "yacc_sql.y"
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
#line 1920 "yacc_sql.cpp"
    break;

  case 34: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 334 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 1932 "yacc_sql.cpp"
    break;

  case 35: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format  */
#line 344 "yacc_sql.y"
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
#line 1957 "yacc_sql.cpp"
    break;

  case 36: /* attr_def_list: %empty  */
#line 367 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 1965 "yacc_sql.cpp"
    break;

  case 37: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 371 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 1979 "yacc_sql.cpp"
    break;

  case 38: /* attr_def: ID STRING_T LBRACE number RBRACE nullable  */
#line 384 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = AttrType::CHARS;
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-5].string));
    }
#line 1992 "yacc_sql.cpp"
    break;

  case 39: /* attr_def: ID VECTOR_T LBRACE number RBRACE nullable  */
#line 393 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = AttrType::VECTORS;
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = 1 + 4 * (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-5].string));
    }
#line 2005 "yacc_sql.cpp"
    break;

  case 40: /* attr_def: ID type nullable  */
#line 402 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = (yyvsp[0].booleans);
      free((yyvsp[-2].string));
    }
#line 2018 "yacc_sql.cpp"
    break;

  case 41: /* nullable: %empty  */
#line 414 "yacc_sql.y"
    {
      (yyval.booleans) = true;
    }
#line 2026 "yacc_sql.cpp"
    break;

  case 42: /* nullable: NIL  */
#line 418 "yacc_sql.y"
    {
      (yyval.booleans) = true;
    }
#line 2034 "yacc_sql.cpp"
    break;

  case 43: /* nullable: NOT NIL  */
#line 422 "yacc_sql.y"
    {
      (yyval.booleans) = false;
    }
#line 2042 "yacc_sql.cpp"
    break;

  case 44: /* number: NUMBER  */
#line 428 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2048 "yacc_sql.cpp"
    break;

  case 45: /* type: INT_T  */
#line 431 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::INTS); }
#line 2054 "yacc_sql.cpp"
    break;

  case 46: /* type: STRING_T  */
#line 432 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::CHARS); }
#line 2060 "yacc_sql.cpp"
    break;

  case 47: /* type: FLOAT_T  */
#line 433 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::FLOATS); }
#line 2066 "yacc_sql.cpp"
    break;

  case 48: /* type: DATE_T  */
#line 434 "yacc_sql.y"
               { (yyval.number) = static_cast<int>(AttrType::DATES); }
#line 2072 "yacc_sql.cpp"
    break;

  case 49: /* insert_stmt: INSERT INTO ID VALUES LBRACE value value_list RBRACE  */
#line 438 "yacc_sql.y"
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
#line 2089 "yacc_sql.cpp"
    break;

  case 50: /* value_list: %empty  */
#line 454 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2097 "yacc_sql.cpp"
    break;

  case 51: /* value_list: COMMA value value_list  */
#line 457 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2111 "yacc_sql.cpp"
    break;

  case 52: /* value: LBRACKET value value_list RBRACKET  */
#line 468 "yacc_sql.y"
                                       {
      if ((yyvsp[-1].value_list) == nullptr)
        (yyvsp[-1].value_list) = new std::vector<Value>;
      (yyvsp[-1].value_list)->emplace_back(*(yyvsp[-2].value));
      delete (yyvsp[-2].value);
      std::reverse((yyvsp[-1].value_list)->begin(), (yyvsp[-1].value_list)->end());
      (yyval.value) = new Value(*(yyvsp[-1].value_list));
      delete (yyvsp[-1].value_list);
    }
#line 2125 "yacc_sql.cpp"
    break;

  case 53: /* value: NUMBER  */
#line 477 "yacc_sql.y"
            {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2134 "yacc_sql.cpp"
    break;

  case 54: /* value: FLOAT  */
#line 481 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2143 "yacc_sql.cpp"
    break;

  case 55: /* value: NIL  */
#line 485 "yacc_sql.y"
         {
      (yyval.value) = new Value(AttrType::NULLS, nullptr);
      (yyloc) = (yylsp[0]);
    }
#line 2152 "yacc_sql.cpp"
    break;

  case 56: /* value: SSS  */
#line 489 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
      free((yyvsp[0].string));
    }
#line 2163 "yacc_sql.cpp"
    break;

  case 57: /* storage_format: %empty  */
#line 498 "yacc_sql.y"
    {
      (yyval.string) = nullptr;
    }
#line 2171 "yacc_sql.cpp"
    break;

  case 58: /* storage_format: STORAGE FORMAT EQ ID  */
#line 502 "yacc_sql.y"
    {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2179 "yacc_sql.cpp"
    break;

  case 59: /* delete_stmt: DELETE FROM ID where  */
#line 509 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2193 "yacc_sql.cpp"
    break;

  case 60: /* update_stmt: UPDATE ID SET assignment_list where  */
#line 521 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.assignments.swap(*(yyvsp[-1].assignment_list));
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-3].string));
      delete (yyvsp[-1].assignment_list);
    }
#line 2209 "yacc_sql.cpp"
    break;

  case 61: /* select_stmt: SELECT expression_list FROM rel_list join_list where group_by having order_by  */
#line 535 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-7].expression_list) != nullptr) {
        (yyval.sql_node)->selection.expressions.swap(*(yyvsp[-7].expression_list));
        delete (yyvsp[-7].expression_list);
      }

      if ((yyvsp[-5].relation_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-5].relation_list));
        delete (yyvsp[-5].relation_list);
      }

      if ((yyvsp[-3].condition_list) != nullptr) {
        (yyval.sql_node)->selection.conditions.swap(*(yyvsp[-3].condition_list));
        delete (yyvsp[-3].condition_list);
      }

      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.group_by.swap(*(yyvsp[-2].expression_list));
        delete (yyvsp[-2].expression_list);
      }

      if ((yyvsp[-4].join_list) != nullptr) {
        (yyval.sql_node)->selection.relations.insert((yyval.sql_node)->selection.relations.end(), std::make_move_iterator((yyvsp[-4].join_list)->relations.begin()), std::make_move_iterator((yyvsp[-4].join_list)->relations.end()));
        (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.end(), std::make_move_iterator((yyvsp[-4].join_list)->conditions.begin()), std::make_move_iterator((yyvsp[-4].join_list)->conditions.end()));
        delete (yyvsp[-4].join_list);
      }

      if ((yyvsp[-1].condition_list) != nullptr) {
        (yyval.sql_node)->selection.having.swap(*(yyvsp[-1].condition_list));
        delete (yyvsp[-1].condition_list);
      }

      if ((yyvsp[0].order_by_list) != nullptr) {
        (yyval.sql_node)->selection.order_by.swap(*(yyvsp[0].order_by_list));
        delete (yyvsp[0].order_by_list);
      }
    }
#line 2252 "yacc_sql.cpp"
    break;

  case 62: /* calc_stmt: CALC expression_list  */
#line 576 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2262 "yacc_sql.cpp"
    break;

  case 63: /* assignment_list: assignment  */
#line 585 "yacc_sql.y"
    {
      (yyval.assignment_list) = new std::vector<std::unique_ptr<Assignment>>;
      (yyval.assignment_list)->emplace_back((yyvsp[0].assignment));
    }
#line 2271 "yacc_sql.cpp"
    break;

  case 64: /* assignment_list: assignment COMMA assignment_list  */
#line 590 "yacc_sql.y"
    {
      (yyval.assignment_list) = (yyvsp[0].assignment_list);
      (yyval.assignment_list)->emplace_back((yyvsp[-2].assignment));
    }
#line 2280 "yacc_sql.cpp"
    break;

  case 65: /* assignment: ID EQ value  */
#line 597 "yacc_sql.y"
    {
      (yyval.assignment) = new Assignment;
      (yyval.assignment)->attribute_name = (yyvsp[-2].string);
      (yyval.assignment)->value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2292 "yacc_sql.cpp"
    break;

  case 66: /* expression_list: expression  */
#line 608 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      (yyval.expression_list)->emplace_back((yyvsp[0].expression));
    }
#line 2301 "yacc_sql.cpp"
    break;

  case 67: /* expression_list: expression COMMA expression_list  */
#line 613 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<std::unique_ptr<Expression>>;
      }
      (yyval.expression_list)->emplace((yyval.expression_list)->begin(), (yyvsp[-2].expression));
    }
#line 2314 "yacc_sql.cpp"
    break;

  case 68: /* expression: L2_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 623 "yacc_sql.y"
                                                          {
      (yyval.expression) = new FunctionExpr(FunctionExpr::Type::L2_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2323 "yacc_sql.cpp"
    break;

  case 69: /* expression: COSINE_DISTANCE LBRACE expression COMMA expression RBRACE  */
#line 627 "yacc_sql.y"
                                                                {
      (yyval.expression) = new FunctionExpr(FunctionExpr::Type::COSINE_DISTANCE, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2332 "yacc_sql.cpp"
    break;

  case 70: /* expression: INNER_PRODUCT LBRACE expression COMMA expression RBRACE  */
#line 631 "yacc_sql.y"
                                                              {
      (yyval.expression) = new FunctionExpr(FunctionExpr::Type::INNER_PRODUCT, (yyvsp[-3].expression), (yyvsp[-1].expression));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2341 "yacc_sql.cpp"
    break;

  case 71: /* expression: expression '+' expression  */
#line 635 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2349 "yacc_sql.cpp"
    break;

  case 72: /* expression: expression '-' expression  */
#line 638 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2357 "yacc_sql.cpp"
    break;

  case 73: /* expression: expression '*' expression  */
#line 641 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2365 "yacc_sql.cpp"
    break;

  case 74: /* expression: expression '/' expression  */
#line 644 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2373 "yacc_sql.cpp"
    break;

  case 75: /* expression: LBRACE expression RBRACE  */
#line 647 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2382 "yacc_sql.cpp"
    break;

  case 76: /* expression: '-' expression  */
#line 651 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2390 "yacc_sql.cpp"
    break;

  case 77: /* expression: AGGREGATE LBRACE expression RBRACE  */
#line 654 "yacc_sql.y"
                                         {
      (yyval.expression) = create_aggregate_expression((yyvsp[-3].string), (yyvsp[-1].expression), sql_string, &(yyloc));
    }
#line 2398 "yacc_sql.cpp"
    break;

  case 78: /* expression: value  */
#line 657 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2408 "yacc_sql.cpp"
    break;

  case 79: /* expression: rel_attr  */
#line 662 "yacc_sql.y"
               {
      RelAttrSqlNode *node = (yyvsp[0].rel_attr);
      (yyval.expression) = new UnboundFieldExpr(node->relation_name, node->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2419 "yacc_sql.cpp"
    break;

  case 80: /* expression: '*'  */
#line 668 "yacc_sql.y"
          {
      (yyval.expression) = new StarExpr();
    }
#line 2427 "yacc_sql.cpp"
    break;

  case 81: /* rel_attr: ID  */
#line 674 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2437 "yacc_sql.cpp"
    break;

  case 82: /* rel_attr: ID DOT ID  */
#line 679 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2449 "yacc_sql.cpp"
    break;

  case 83: /* relation: ID  */
#line 689 "yacc_sql.y"
       {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2457 "yacc_sql.cpp"
    break;

  case 84: /* rel_list: relation  */
#line 694 "yacc_sql.y"
             {
      (yyval.relation_list) = new std::vector<std::string>();
      (yyval.relation_list)->push_back((yyvsp[0].string));
      free((yyvsp[0].string));
    }
#line 2467 "yacc_sql.cpp"
    break;

  case 85: /* rel_list: relation COMMA rel_list  */
#line 699 "yacc_sql.y"
                              {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }

      (yyval.relation_list)->insert((yyval.relation_list)->begin(), (yyvsp[-2].string));
      free((yyvsp[-2].string));
    }
#line 2482 "yacc_sql.cpp"
    break;

  case 86: /* join_list: %empty  */
#line 713 "yacc_sql.y"
    {
      (yyval.join_list) = nullptr;
    }
#line 2490 "yacc_sql.cpp"
    break;

  case 87: /* join_list: join_list INNER_JOIN relation ON condition_list  */
#line 717 "yacc_sql.y"
    {
      if ((yyvsp[-4].join_list) == nullptr)
        (yyval.join_list) = new JoinSqlNode;
      else
        (yyval.join_list) = (yyvsp[-4].join_list);
      (yyval.join_list)->relations.emplace_back((yyvsp[-2].string));
      (yyval.join_list)->conditions.insert((yyval.join_list)->conditions.end(), std::make_move_iterator((yyvsp[0].condition_list)->begin()), std::make_move_iterator((yyvsp[0].condition_list)->end()));
      free((yyvsp[-2].string));
      delete (yyvsp[0].condition_list);
    }
#line 2505 "yacc_sql.cpp"
    break;

  case 88: /* where: %empty  */
#line 730 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2513 "yacc_sql.cpp"
    break;

  case 89: /* where: WHERE condition_list  */
#line 733 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 2521 "yacc_sql.cpp"
    break;

  case 90: /* condition_list: %empty  */
#line 739 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2529 "yacc_sql.cpp"
    break;

  case 91: /* condition_list: condition  */
#line 742 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<std::unique_ptr<ConditionSqlNode>>;
      (yyval.condition_list)->emplace_back((yyvsp[0].condition));
    }
#line 2538 "yacc_sql.cpp"
    break;

  case 92: /* condition_list: condition AND condition_list  */
#line 746 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyval.condition_list)->emplace_back((yyvsp[-2].condition));
    }
#line 2547 "yacc_sql.cpp"
    break;

  case 93: /* condition: expression comp_op expression  */
#line 753 "yacc_sql.y"
    {
      (yyval.condition)        = new ConditionSqlNode;
      (yyval.condition)->comp  = (yyvsp[-1].comp);
      (yyval.condition)->left  = std::unique_ptr<Expression>((yyvsp[-2].expression));
      (yyval.condition)->right = std::unique_ptr<Expression>((yyvsp[0].expression));
    }
#line 2558 "yacc_sql.cpp"
    break;

  case 94: /* condition: expression IS NIL  */
#line 760 "yacc_sql.y"
    {
      (yyval.condition)        = new ConditionSqlNode;
      (yyval.condition)->comp  = IS_NULL;
      (yyval.condition)->left  = std::unique_ptr<Expression>((yyvsp[-2].expression));
      (yyval.condition)->right = std::unique_ptr<Expression>(new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
#line 2569 "yacc_sql.cpp"
    break;

  case 95: /* condition: expression IS NOT NIL  */
#line 767 "yacc_sql.y"
    {
      (yyval.condition)        = new ConditionSqlNode;
      (yyval.condition)->comp  = NOT_NULL;
      (yyval.condition)->left  = std::unique_ptr<Expression>((yyvsp[-3].expression));
      (yyval.condition)->right = std::unique_ptr<Expression>(new ValueExpr(Value(AttrType::NULLS, nullptr)));
    }
#line 2580 "yacc_sql.cpp"
    break;

  case 96: /* comp_op: EQ  */
#line 776 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 2586 "yacc_sql.cpp"
    break;

  case 97: /* comp_op: LT  */
#line 777 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 2592 "yacc_sql.cpp"
    break;

  case 98: /* comp_op: GT  */
#line 778 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 2598 "yacc_sql.cpp"
    break;

  case 99: /* comp_op: LE  */
#line 779 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 2604 "yacc_sql.cpp"
    break;

  case 100: /* comp_op: GE  */
#line 780 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 2610 "yacc_sql.cpp"
    break;

  case 101: /* comp_op: NE  */
#line 781 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 2616 "yacc_sql.cpp"
    break;

  case 102: /* comp_op: LK  */
#line 782 "yacc_sql.y"
         { (yyval.comp) = LIKE; }
#line 2622 "yacc_sql.cpp"
    break;

  case 103: /* comp_op: NOT LK  */
#line 783 "yacc_sql.y"
             { (yyval.comp) = NOT_LIKE; }
#line 2628 "yacc_sql.cpp"
    break;

  case 104: /* group_by: %empty  */
#line 788 "yacc_sql.y"
    {
      (yyval.expression_list) = nullptr;
    }
#line 2636 "yacc_sql.cpp"
    break;

  case 105: /* group_by: GROUP BY expression_list  */
#line 792 "yacc_sql.y"
    {
      (yyval.expression_list) = (yyvsp[0].expression_list);
    }
#line 2644 "yacc_sql.cpp"
    break;

  case 106: /* order_by_item: expression  */
#line 799 "yacc_sql.y"
    {
      (yyval.order_by_item) = new std::pair<std::unique_ptr<Expression>, bool>((yyvsp[0].expression), true);
    }
#line 2652 "yacc_sql.cpp"
    break;

  case 107: /* order_by_item: expression ASC  */
#line 803 "yacc_sql.y"
    {
      (yyval.order_by_item) = new std::pair<std::unique_ptr<Expression>, bool>((yyvsp[-1].expression), true);
    }
#line 2660 "yacc_sql.cpp"
    break;

  case 108: /* order_by_item: expression DESC  */
#line 807 "yacc_sql.y"
    {
      (yyval.order_by_item) = new std::pair<std::unique_ptr<Expression>, bool>((yyvsp[-1].expression), false);
    }
#line 2668 "yacc_sql.cpp"
    break;

  case 109: /* order_by_list: order_by_item  */
#line 813 "yacc_sql.y"
    {
      (yyval.order_by_list) = new std::vector<std::pair<std::unique_ptr<Expression>, bool>>;
      (yyval.order_by_list)->emplace_back(std::move(*(yyvsp[0].order_by_item)));
      delete (yyvsp[0].order_by_item);
    }
#line 2678 "yacc_sql.cpp"
    break;

  case 110: /* order_by_list: order_by_item COMMA order_by_list  */
#line 819 "yacc_sql.y"
    {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
      (yyval.order_by_list)->insert((yyval.order_by_list)->begin(), std::move(*(yyvsp[-2].order_by_item)));
      delete (yyvsp[-2].order_by_item);
    }
#line 2688 "yacc_sql.cpp"
    break;

  case 111: /* order_by: %empty  */
#line 827 "yacc_sql.y"
    {
      (yyval.order_by_list) = nullptr;
    }
#line 2696 "yacc_sql.cpp"
    break;

  case 112: /* order_by: ORDER BY order_by_list  */
#line 831 "yacc_sql.y"
    {
      (yyval.order_by_list) = (yyvsp[0].order_by_list);
    }
#line 2704 "yacc_sql.cpp"
    break;

  case 113: /* having: %empty  */
#line 838 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 2712 "yacc_sql.cpp"
    break;

  case 114: /* having: HAVING condition_list  */
#line 841 "yacc_sql.y"
                            {
      (yyval.condition_list) = (yyvsp[0].condition_list);
    }
#line 2720 "yacc_sql.cpp"
    break;

  case 115: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 848 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 2734 "yacc_sql.cpp"
    break;

  case 116: /* explain_stmt: EXPLAIN command_wrapper  */
#line 861 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 2743 "yacc_sql.cpp"
    break;

  case 117: /* set_variable_stmt: SET ID EQ value  */
#line 869 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 2755 "yacc_sql.cpp"
    break;


#line 2759 "yacc_sql.cpp"

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

#line 881 "yacc_sql.y"

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
