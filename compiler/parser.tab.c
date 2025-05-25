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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "icg.h"

extern FILE *icg_file;

char* new_temp() { return generate_temp(); }
char* new_label() { return generate_label(); }
char *current_while_label_start = NULL;
char *current_while_label_end = NULL;
char *label_else;
char *label_end;

extern int yylex(void);
extern int yylineno;
void yyerror(const char *s);

#line 92 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_IDENTIFIER = 5,                 /* IDENTIFIER  */
  YYSYMBOL_CLASS = 6,                      /* CLASS  */
  YYSYMBOL_DEF = 7,                        /* DEF  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_NEW = 10,                       /* NEW  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_ASSIGN = 20,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MUL = 23,                       /* MUL  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_DOT = 25,                       /* DOT  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_NEWLINE = 31,                   /* NEWLINE  */
  YYSYMBOL_UMINUS = 32,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 33,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_statements = 36,                /* statements  */
  YYSYMBOL_statement_with_newlines = 37,   /* statement_with_newlines  */
  YYSYMBOL_statement = 38,                 /* statement  */
  YYSYMBOL_optional_newlines = 39,         /* optional_newlines  */
  YYSYMBOL_assignment = 40,                /* assignment  */
  YYSYMBOL_print_stmt = 41,                /* print_stmt  */
  YYSYMBOL_return_stmt = 42,               /* return_stmt  */
  YYSYMBOL_if_stmt = 43,                   /* if_stmt  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_while_stmt = 46,                /* while_stmt  */
  YYSYMBOL_class_def = 47,                 /* class_def  */
  YYSYMBOL_func_def = 48,                  /* func_def  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_primary_expression = 50,        /* primary_expression  */
  YYSYMBOL_param_list = 51,                /* param_list  */
  YYSYMBOL_arg_list = 52                   /* arg_list  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    61,    63,    67,    68,    69,    73,    74,
      75,    76,    77,    78,    79,    81,    83,    86,   101,   111,
     122,   131,   121,   154,   184,   200,   238,   239,   245,   251,
     257,   263,   269,   275,   281,   287,   293,   302,   307,   315,
     323,   331,   340,   348,   351,   356,   368,   371,   376
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "STRING",
  "IDENTIFIER", "CLASS", "DEF", "PRINT", "RETURN", "NEW", "IF", "ELSE",
  "WHILE", "EQ", "NEQ", "LE", "GE", "LT", "GT", "ASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "DOT", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "COMMA",
  "NEWLINE", "UMINUS", "LOWER_THAN_ELSE", "$accept", "program",
  "statements", "statement_with_newlines", "statement",
  "optional_newlines", "assignment", "print_stmt", "return_stmt",
  "if_stmt", "$@1", "$@2", "while_stmt", "class_def", "func_def",
  "expression", "primary_expression", "param_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -46,     7,    93,   -46,     1,    12,    20,    23,    58,    31,
      33,   -46,    29,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,    58,    36,    41,    58,   -46,   -46,    49,    58,   160,
     -46,    58,    58,   -46,   160,   -46,    72,   104,    58,   118,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      81,   132,   146,    -3,   -46,   -18,   -46,   160,   -16,   -46,
     170,   170,    86,    86,    86,    86,     6,     6,    63,    63,
      88,   -46,   -46,   -46,    89,   107,   -46,    58,    58,   -13,
      -9,   -46,   -46,   160,    24,   -46,   -46,   -46,    37,   -46,
     -46,    65,   -46,    74,   -46,   -46,   126,   -46,    27,   -46,
      84,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     7,     4,     5,     8,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,    37,    38,    39,     0,    19,
      26,     0,     0,     6,    17,     3,    43,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    18,    47,     0,    42,
      31,    32,    35,    36,    33,    34,    27,    28,    29,    30,
       0,    15,    15,    24,     0,     0,    40,     0,    46,     0,
       0,     3,    45,    48,     0,    20,    16,     3,     0,    41,
       3,     0,    25,     0,    23,    21,     0,    15,     0,     3,
       0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -34,   -46,   -46,   -45,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,    -8,   -46,   -46,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    12,    13,    79,    14,    15,    16,    17,
      90,    96,    18,    19,    20,    57,    30,    55,    58
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    53,     4,     5,     6,     7,     8,     3,     9,    74,
      10,    76,    75,    34,    77,    85,    37,    22,    86,    87,
      39,    21,    86,    51,    52,    23,    73,    80,    11,    48,
      49,    50,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     4,     5,     6,     7,     8,    88,     9,    24,
      10,    89,    98,    91,    77,    99,    93,    31,    86,    32,
      33,    25,    26,    27,    35,   100,    92,    36,    11,    83,
       4,     5,     6,     7,     8,    38,     9,    54,    10,     4,
       5,     6,     7,     8,    28,     9,    70,    10,    50,     4,
       5,     6,     7,     8,    94,     9,    11,    10,     4,     5,
       6,     7,     8,    95,     9,    11,    10,    46,    47,    48,
      49,    50,    82,   101,    78,    11,    84,    81,    40,    41,
      42,    43,    44,    45,    11,    46,    47,    48,    49,    50,
       0,    56,    40,    41,    42,    43,    44,    45,    97,    46,
      47,    48,    49,    50,     0,    59,    40,    41,    42,    43,
      44,    45,     0,    46,    47,    48,    49,    50,     0,    71,
      40,    41,    42,    43,    44,    45,     0,    46,    47,    48,
      49,    50,     0,    72,    40,    41,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50,    42,    43,    44,    45,
       0,    46,    47,    48,    49,    50
};

static const yytype_int8 yycheck[] =
{
       8,    35,     5,     6,     7,     8,     9,     0,    11,    27,
      13,    27,    30,    21,    30,    28,    24,     5,    31,    28,
      28,    20,    31,    31,    32,     5,    29,    72,    31,    23,
      24,    25,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     5,     6,     7,     8,     9,    81,    11,    26,
      13,    27,    97,    87,    30,    28,    90,    26,    31,    26,
      31,     3,     4,     5,    28,    99,    29,    26,    31,    77,
       5,     6,     7,     8,     9,    26,    11,     5,    13,     5,
       6,     7,     8,     9,    26,    11,     5,    13,    25,     5,
       6,     7,     8,     9,    29,    11,    31,    13,     5,     6,
       7,     8,     9,    29,    11,    31,    13,    21,    22,    23,
      24,    25,     5,    29,    26,    31,    78,    28,    14,    15,
      16,    17,    18,    19,    31,    21,    22,    23,    24,    25,
      -1,    27,    14,    15,    16,    17,    18,    19,    12,    21,
      22,    23,    24,    25,    -1,    27,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    27,
      14,    15,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    27,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    36,     0,     5,     6,     7,     8,     9,    11,
      13,    31,    37,    38,    40,    41,    42,    43,    46,    47,
      48,    20,     5,     5,    26,     3,     4,     5,    26,    49,
      50,    26,    26,    31,    49,    28,    26,    49,    26,    49,
      14,    15,    16,    17,    18,    19,    21,    22,    23,    24,
      25,    49,    49,    36,     5,    51,    27,    49,    52,    27,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
       5,    27,    27,    29,    27,    30,    27,    30,    26,    39,
      39,    28,     5,    49,    52,    28,    31,    28,    36,    27,
      44,    36,    29,    36,    29,    29,    45,    12,    39,    28,
      36,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    38,    38,
      38,    38,    38,    38,    38,    39,    39,    40,    41,    42,
      44,    45,    43,    46,    47,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    51,    51,    51,    52,    52,    52
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     3,     4,     2,
       0,     0,    15,     8,     5,     8,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       4,     6,     3,     0,     1,     3,     0,     1,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statements  */
#line 55 "parser.y"
    {
        optimize_instructions();
        write_instructions_to_file(icg_file);
    }
#line 1212 "parser.tab.c"
    break;

  case 8: /* statement: assignment  */
#line 73 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1218 "parser.tab.c"
    break;

  case 9: /* statement: print_stmt  */
#line 74 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1224 "parser.tab.c"
    break;

  case 10: /* statement: return_stmt  */
#line 75 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1230 "parser.tab.c"
    break;

  case 11: /* statement: if_stmt  */
#line 76 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1236 "parser.tab.c"
    break;

  case 12: /* statement: while_stmt  */
#line 77 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1242 "parser.tab.c"
    break;

  case 13: /* statement: class_def  */
#line 78 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1248 "parser.tab.c"
    break;

  case 14: /* statement: func_def  */
#line 79 "parser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1254 "parser.tab.c"
    break;

  case 17: /* assignment: IDENTIFIER ASSIGN expression  */
#line 87 "parser.y"
    {
        Instruction *inst = create_assign_instruction((yyvsp[-2].str), (yyvsp[0].str));
        add_instruction(inst);

        if (!lookup_symbol((yyvsp[-2].str))) {
            insert_symbol((yyvsp[-2].str), VAR);
        }
        free((yyvsp[-2].str));
        free((yyvsp[0].str));
        (yyval.str) = NULL;
    }
#line 1270 "parser.tab.c"
    break;

  case 18: /* print_stmt: PRINT LPAREN expression RPAREN  */
#line 102 "parser.y"
    {
        Instruction *inst = create_print_instruction((yyvsp[-1].str));
        add_instruction(inst);
        free((yyvsp[-1].str));
        (yyval.str) = NULL;
    }
#line 1281 "parser.tab.c"
    break;

  case 19: /* return_stmt: RETURN expression  */
#line 112 "parser.y"
    {
        Instruction *inst = create_return_instruction((yyvsp[0].str));
        add_instruction(inst);
        free((yyvsp[0].str));
        (yyval.str) = NULL;
    }
#line 1292 "parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 122 "parser.y"
    {
        // Setup labels before parsing statements
        label_else = new_label();
        label_end = new_label();
        Instruction *inst_if_false = create_if_false_goto_instruction((yyvsp[-3].str), label_else);
        add_instruction(inst_if_false);
        free((yyvsp[-3].str)); // prevent memory leak
    }
#line 1305 "parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 131 "parser.y"
    {
        // After 'if' block, jump over else
        Instruction *inst_goto_end = create_goto_instruction(label_end);
        add_instruction(inst_goto_end);

        // Label for else block
        Instruction *inst_label_else = create_label_instruction(label_else);
        add_instruction(inst_label_else);
    }
#line 1319 "parser.tab.c"
    break;

  case 22: /* if_stmt: IF LPAREN expression RPAREN optional_newlines LBRACE $@1 statements RBRACE $@2 ELSE optional_newlines LBRACE statements RBRACE  */
#line 143 "parser.y"
    {
        // End label
        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free(label_else);
        free(label_end);
    }
#line 1332 "parser.tab.c"
    break;

  case 23: /* while_stmt: WHILE LPAREN expression RPAREN optional_newlines LBRACE statements RBRACE  */
#line 155 "parser.y"
    {
    // If the condition is constant "0", skip generating the loop entirely
    if (strcmp((yyvsp[-5].str), "0") == 0) {
        free((yyvsp[-5].str));
        (yyval.str) = NULL;
    } else {
        char *label_start = new_label();
        char *label_end = new_label();

        Instruction *inst_label_start = create_label_instruction(label_start);
        add_instruction(inst_label_start);

        Instruction *inst_if_false = create_if_false_goto_instruction((yyvsp[-5].str), label_end);
        add_instruction(inst_if_false);

        Instruction *inst_goto_start = create_goto_instruction(label_start);
        add_instruction(inst_goto_start);

        Instruction *inst_label_end = create_label_instruction(label_end);
        add_instruction(inst_label_end);

        free((yyvsp[-5].str));
        free(label_start);
        free(label_end);
        (yyval.str) = NULL;
    }
}
#line 1364 "parser.tab.c"
    break;

  case 24: /* class_def: CLASS IDENTIFIER LBRACE statements RBRACE  */
#line 185 "parser.y"
    {
        if (!lookup_symbol((yyvsp[-3].str))) {
            insert_symbol((yyvsp[-3].str), CLASS_SYM);
            Instruction *inst = create_comment_instruction("# Class %s defined", (yyvsp[-3].str));
            add_instruction(inst);
        } else {
            Instruction *inst = create_comment_instruction("# Warning: Redefinition of class %s", (yyvsp[-3].str));
            add_instruction(inst);
        }
        free((yyvsp[-3].str));
        (yyval.str) = NULL;
    }
#line 1381 "parser.tab.c"
    break;

  case 25: /* func_def: DEF IDENTIFIER LPAREN param_list RPAREN LBRACE statements RBRACE  */
#line 201 "parser.y"
    {
        if (!lookup_symbol((yyvsp[-6].str))) {
            insert_symbol((yyvsp[-6].str), FUNC);

            Instruction *inst_func = create_function_instruction((yyvsp[-6].str));
            add_instruction(inst_func);

            if ((yyvsp[-4].str) && strlen((yyvsp[-4].str)) > 0) {
                char *param_copy = strdup((yyvsp[-4].str));
                char *token = strtok(param_copy, ",");
                while (token) {
                    // Trim whitespace
                    while (*token == ' ') token++;
                    char *end = token + strlen(token) - 1;
                    while (end > token && *end == ' ') *end-- = '\0';
                    
                    insert_symbol(token, VAR);
                    Instruction *param_inst = create_param_instruction(token);
                    add_instruction(param_inst);
                    token = strtok(NULL, ",");
                }
                free(param_copy);
            }

            Instruction *inst_endfunc = create_endfunction_instruction();
            add_instruction(inst_endfunc);
        } else {
            Instruction *inst = create_comment_instruction("# Warning: Redefinition of function %s", (yyvsp[-6].str));
            add_instruction(inst);
        }
        free((yyvsp[-6].str));
        if ((yyvsp[-4].str)) free((yyvsp[-4].str));
        (yyval.str) = NULL;
    }
#line 1420 "parser.tab.c"
    break;

  case 26: /* expression: primary_expression  */
#line 238 "parser.y"
                                        { (yyval.str) = (yyvsp[0].str); }
#line 1426 "parser.tab.c"
    break;

  case 27: /* expression: expression PLUS expression  */
#line 239 "parser.y"
                                       { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "+", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1437 "parser.tab.c"
    break;

  case 28: /* expression: expression MINUS expression  */
#line 245 "parser.y"
                                       { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "-", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1448 "parser.tab.c"
    break;

  case 29: /* expression: expression MUL expression  */
#line 251 "parser.y"
                                       { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "*", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1459 "parser.tab.c"
    break;

  case 30: /* expression: expression DIV expression  */
#line 257 "parser.y"
                                       { 
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "/", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1470 "parser.tab.c"
    break;

  case 31: /* expression: expression EQ expression  */
#line 263 "parser.y"
                                       {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "==", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1481 "parser.tab.c"
    break;

  case 32: /* expression: expression NEQ expression  */
#line 269 "parser.y"
                                       {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "!=", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1492 "parser.tab.c"
    break;

  case 33: /* expression: expression LT expression  */
#line 275 "parser.y"
                                       {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "<", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1503 "parser.tab.c"
    break;

  case 34: /* expression: expression GT expression  */
#line 281 "parser.y"
                                       {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), ">", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1514 "parser.tab.c"
    break;

  case 35: /* expression: expression LE expression  */
#line 287 "parser.y"
                                       {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), "<=", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1525 "parser.tab.c"
    break;

  case 36: /* expression: expression GE expression  */
#line 293 "parser.y"
                                       {
        char *temp = new_temp();
        add_instruction(create_binop_instruction(temp, (yyvsp[-2].str), ">=", (yyvsp[0].str)));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1536 "parser.tab.c"
    break;

  case 37: /* primary_expression: NUMBER  */
#line 303 "parser.y"
    {
        (yyval.str) = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1545 "parser.tab.c"
    break;

  case 38: /* primary_expression: STRING  */
#line 308 "parser.y"
    {
        int len = strlen((yyvsp[0].str));
        char *quoted = malloc(len + 3);
        sprintf(quoted, "\"%s\"", (yyvsp[0].str));
        free((yyvsp[0].str));
        (yyval.str) = quoted;
    }
#line 1557 "parser.tab.c"
    break;

  case 39: /* primary_expression: IDENTIFIER  */
#line 316 "parser.y"
    {
        if (!lookup_symbol((yyvsp[0].str))) {
            fprintf(stderr, "Warning: Undeclared variable '%s'\n", (yyvsp[0].str));
        }
        (yyval.str) = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1569 "parser.tab.c"
    break;

  case 40: /* primary_expression: IDENTIFIER LPAREN arg_list RPAREN  */
#line 324 "parser.y"
    {
        char *code = malloc(strlen((yyvsp[-3].str)) + 20);
        sprintf(code, "call %s", (yyvsp[-3].str));
        free((yyvsp[-3].str));
        if ((yyvsp[-1].str)) free((yyvsp[-1].str));
        (yyval.str) = code;
    }
#line 1581 "parser.tab.c"
    break;

  case 41: /* primary_expression: expression DOT IDENTIFIER LPAREN arg_list RPAREN  */
#line 332 "parser.y"
    {
        char *code = malloc(strlen((yyvsp[-5].str)) + strlen((yyvsp[-3].str)) + 20);
        sprintf(code, "call_method %s.%s", (yyvsp[-5].str), (yyvsp[-3].str));
        free((yyvsp[-5].str));
        free((yyvsp[-3].str));
        if ((yyvsp[-1].str)) free((yyvsp[-1].str));
        (yyval.str) = code;
    }
#line 1594 "parser.tab.c"
    break;

  case 42: /* primary_expression: LPAREN expression RPAREN  */
#line 341 "parser.y"
    { 
        (yyval.str) = (yyvsp[-1].str); 
    }
#line 1602 "parser.tab.c"
    break;

  case 43: /* param_list: %empty  */
#line 348 "parser.y"
    {
        (yyval.str) = strdup("");
    }
#line 1610 "parser.tab.c"
    break;

  case 44: /* param_list: IDENTIFIER  */
#line 352 "parser.y"
    {
        (yyval.str) = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1619 "parser.tab.c"
    break;

  case 45: /* param_list: param_list COMMA IDENTIFIER  */
#line 357 "parser.y"
    {
        char *combined = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2);
        sprintf(combined, "%s,%s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str));
        free((yyvsp[0].str));
        (yyval.str) = combined;
    }
#line 1631 "parser.tab.c"
    break;

  case 46: /* arg_list: %empty  */
#line 368 "parser.y"
    {
        (yyval.str) = strdup("");
    }
#line 1639 "parser.tab.c"
    break;

  case 47: /* arg_list: expression  */
#line 372 "parser.y"
    {
        (yyval.str) = strdup((yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1648 "parser.tab.c"
    break;

  case 48: /* arg_list: arg_list COMMA expression  */
#line 377 "parser.y"
    {
        char *combined = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2);
        sprintf(combined, "%s,%s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str));
        free((yyvsp[0].str));
        (yyval.str) = combined;
    }
#line 1660 "parser.tab.c"
    break;


#line 1664 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 386 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}
