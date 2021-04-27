/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.y" /* yacc.c:339  */

#define YYPARSER

#include <iostream>
#include "globals.h"
#include "scan.h"
#include "nodedef.h"
#include "parse.h"

#define YYSTYPE NodeBase*
static NodeBase* savedTree;
static int yylex();
int char2int(char*);
int yyerror(std::string);

#line 82 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENDFILE = 258,
    ERROR = 259,
    IF = 260,
    ELSE = 261,
    WHILE = 262,
    BREAK = 263,
    CONTINUE = 264,
    RETURN = 265,
    CONST = 266,
    INT = 267,
    VOID = 268,
    ASSIGN = 269,
    EQ = 270,
    NEQ = 271,
    LT = 272,
    GT = 273,
    LEQ = 274,
    GEQ = 275,
    ADD = 276,
    SUB = 277,
    MUL = 278,
    DIV = 279,
    MOD = 280,
    NOT = 281,
    AND = 282,
    OR = 283,
    LPAREN = 284,
    RPAREN = 285,
    LBRACK = 286,
    RBRACK = 287,
    LBPAREN = 288,
    RBPAREN = 289,
    ID = 290,
    NUM = 291,
    COMMA = 292,
    SEMI = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 172 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    33,    33,    37,    43,    49,    55,    65,    68,    72,
      76,    81,    88,    94,   102,   107,   114,   120,   122,   129,
     134,   145,   149,   154,   161,   167,   173,   179,   187,   192,
     199,   205,   207,   214,   219,   230,   236,   242,   248,   256,
     261,   268,   273,   280,   285,   295,   299,   305,   310,   317,
     319,   323,   329,   334,   339,   344,   351,   358,   364,   368,
     372,   377,   387,   394,   401,   406,   413,   418,   425,   430,
     435,   442,   446,   451,   456,   462,   468,   476,   481,   491,
     497,   503,   509,   516,   522,   528,   535,   541,   547,   553,
     559,   566,   572,   578,   585,   590,   597,   602,   609,   619,
     627
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ENDFILE", "ERROR", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "RETURN", "CONST", "INT", "VOID", "ASSIGN",
  "EQ", "NEQ", "LT", "GT", "LEQ", "GEQ", "ADD", "SUB", "MUL", "DIV", "MOD",
  "NOT", "AND", "OR", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBPAREN",
  "RBPAREN", "ID", "NUM", "COMMA", "SEMI", "$accept", "program",
  "compunit", "decl", "constdecl", "constdefs", "constdef", "arr_constdef",
  "constinitval", "constinitvals", "vardecl", "vardefs", "vardef",
  "arr_vardef", "initval", "initvals", "funcdef", "funcfparams",
  "funcfparam", "arr_funcfparam", "block", "blockitems", "blockitem",
  "stmt", "exp", "cond", "lval", "arr_lval", "primaryexp", "unaryexp",
  "funcrparams", "mulexp", "addexp", "relexp", "eqexp", "landexp",
  "lorexp", "constexp", "identifier", "number", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      44,   -10,   -25,   -25,    21,    44,  -108,  -108,  -108,  -108,
     -25,  -108,    -7,  -108,     9,    38,  -108,  -108,  -108,    75,
    -108,    10,   -25,  -108,   237,     5,   255,    20,     6,   -25,
    -108,   253,   255,    30,  -108,    31,   255,   255,   255,   255,
     205,  -108,  -108,  -108,  -108,  -108,  -108,   101,    96,    46,
     106,    63,    47,    69,  -108,   -25,    64,    -4,  -108,    47,
      87,   237,   255,    64,    12,  -108,   221,  -108,  -108,   105,
     253,   255,  -108,  -108,  -108,   103,  -108,  -108,    48,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,    58,   255,   107,   114,    94,  -108,    64,   134,
    -108,  -108,   115,  -108,    64,  -108,  -108,    49,  -108,  -108,
     125,  -108,  -108,   237,  -108,  -108,  -108,   101,   101,    96,
      96,    96,    96,    46,    46,   106,    63,  -108,  -108,    16,
     126,   255,   127,   129,   132,   133,   130,   131,   194,   -25,
    -108,  -108,  -108,  -108,   144,  -108,  -108,   136,   149,  -108,
    -108,  -108,  -108,  -108,   253,  -108,  -108,  -108,   255,  -108,
     135,  -108,   255,   255,   255,  -108,  -108,  -108,   137,  -108,
    -108,  -108,   255,  -108,  -108,  -108,   139,   142,    47,   146,
    -108,   150,  -108,   176,   176,  -108,   158,  -108,   176,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     5,     7,     8,     6,
       0,    99,     0,    23,    24,     0,     1,     3,     4,     0,
      11,     0,     0,    21,     0,     0,     0,    25,     0,     0,
       9,     0,     0,     0,    22,    24,     0,     0,     0,     0,
       0,   100,    26,    30,    69,    71,    82,    85,    90,    93,
      95,    97,    62,    64,    70,     0,     0,     0,    40,    98,
       0,     0,     0,     0,     0,    10,     0,    12,    16,     0,
       0,     0,    74,    75,    76,     0,    32,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    41,     0,    36,     0,     0,
      29,    27,     0,    35,     0,    18,    20,     0,    15,    13,
       0,    68,    31,     0,    79,    80,    81,    83,    84,    86,
      87,    88,    89,    91,    92,    94,    96,    72,    78,     0,
       0,     0,     0,    42,     0,     0,     0,     0,     0,     0,
      46,    52,    49,    54,     0,    48,    50,     0,    69,    38,
      39,    28,    37,    17,     0,    14,    33,    73,     0,    67,
       0,    43,     0,     0,     0,    58,    59,    60,     0,    45,
      47,    53,     0,    19,    77,    66,     0,     0,    63,     0,
      61,     0,    44,     0,     0,    51,    55,    57,     0,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,    73,  -108,  -108,   160,  -108,   -59,  -108,
    -108,  -108,   165,  -108,   -39,  -108,   185,   163,    93,  -108,
     -44,  -108,    50,  -107,   -24,    29,   -92,  -108,  -108,    -9,
    -108,    53,    24,    55,   109,   104,   -23,   -12,     3,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,   142,     7,    19,    20,    33,    67,   107,
       8,    12,    13,    27,    42,    78,     9,    57,    58,   133,
     143,   144,   145,   146,   147,   177,    44,    94,    45,    46,
     129,    47,    48,    49,    50,    51,    52,    68,    53,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    77,    10,    59,   148,    14,    15,   106,    59,    59,
      11,   109,    97,    21,    60,    75,    43,    55,    55,   103,
      69,    16,   101,    24,    31,    35,    98,    72,    73,    74,
      22,    23,    21,    99,    61,    56,    63,    43,    25,    59,
      26,    32,   104,    59,    70,    24,   157,    59,    59,    99,
     102,    62,   148,   158,   149,     1,     2,     3,    95,   110,
     152,    71,    26,    84,    85,    86,    87,    28,   128,   130,
     114,   115,   116,     6,   156,    91,   186,   187,    17,    36,
      37,   189,   112,   153,    38,   113,   154,    39,   127,    43,
      90,   148,   148,    11,    41,   173,   148,    96,    92,   134,
      93,   135,   136,   137,   138,     1,   139,   160,   119,   120,
     121,   122,    29,    30,   168,    36,    37,    82,    83,   100,
      38,    88,    89,    39,    79,    80,    81,    96,   140,    11,
      41,    59,   141,   111,   174,   117,   118,   108,   131,    59,
     178,   178,    35,   123,   124,   132,    55,   151,   181,   134,
     176,   135,   136,   137,   138,     1,   139,   155,   159,   161,
     162,   163,   164,   172,   188,    36,    37,   175,   165,   166,
      38,   182,   183,    39,   171,   180,   184,    96,   169,    11,
      41,   134,   141,   135,   136,   137,   138,    34,   185,    65,
      18,    64,   150,   179,   170,   126,     0,    36,    37,   125,
       0,     0,    38,     0,     0,    39,     0,     0,     0,    96,
       0,    11,    41,     0,   141,    36,    37,     0,     0,     0,
      38,     0,     0,    39,     0,     0,    36,    37,     0,    11,
      41,    38,   167,     0,    39,     0,     0,     0,    40,    76,
      11,    41,    36,    37,     0,     0,     0,    38,     0,     0,
      39,     0,     0,     0,    66,   105,    11,    41,    36,    37,
       0,     0,     0,    38,     0,     0,    39,     0,     0,     0,
      40,     0,    11,    41,    36,    37,    36,    37,     0,    38,
       0,    38,    39,     0,    39,     0,    66,     0,    11,    41,
      11,    41
};

static const yytype_int16 yycheck[] =
{
      24,    40,    12,    26,    96,     2,     3,    66,    31,    32,
      35,    70,    56,    10,    26,    39,    40,    12,    12,    63,
      32,     0,    61,    14,    14,    22,    30,    36,    37,    38,
      37,    38,    29,    37,    14,    30,    30,    61,    29,    62,
      31,    31,    30,    66,    14,    14,    30,    70,    71,    37,
      62,    31,   144,    37,    98,    11,    12,    13,    55,    71,
     104,    31,    31,    17,    18,    19,    20,    29,    92,    93,
      79,    80,    81,     0,   113,    28,   183,   184,     5,    21,
      22,   188,    34,    34,    26,    37,    37,    29,    30,   113,
      27,   183,   184,    35,    36,   154,   188,    33,    29,     5,
      31,     7,     8,     9,    10,    11,    12,   131,    84,    85,
      86,    87,    37,    38,   138,    21,    22,    21,    22,    32,
      26,    15,    16,    29,    23,    24,    25,    33,    34,    35,
      36,   154,    38,    30,   158,    82,    83,    32,    31,   162,
     163,   164,   139,    88,    89,    31,    12,    32,   172,     5,
     162,     7,     8,     9,    10,    11,    12,    32,    32,    32,
      31,    29,    29,    14,     6,    21,    22,    32,    38,    38,
      26,    32,    30,    29,    38,    38,    30,    33,    34,    35,
      36,     5,    38,     7,     8,     9,    10,    22,    38,    29,
       5,    28,    99,   164,   144,    91,    -1,    21,    22,    90,
      -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,    33,
      -1,    35,    36,    -1,    38,    21,    22,    -1,    -1,    -1,
      26,    -1,    -1,    29,    -1,    -1,    21,    22,    -1,    35,
      36,    26,    38,    -1,    29,    -1,    -1,    -1,    33,    34,
      35,    36,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    35,    36,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    35,    36,    21,    22,    21,    22,    -1,    26,
      -1,    26,    29,    -1,    29,    -1,    33,    -1,    35,    36,
      35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    40,    41,    42,    43,    49,    55,
      12,    35,    50,    51,    77,    77,     0,    42,    55,    44,
      45,    77,    37,    38,    14,    29,    31,    52,    29,    37,
      38,    14,    31,    46,    51,    77,    21,    22,    26,    29,
      33,    36,    53,    63,    65,    67,    68,    70,    71,    72,
      73,    74,    75,    77,    78,    12,    30,    56,    57,    75,
      76,    14,    31,    30,    56,    45,    33,    47,    76,    76,
      14,    31,    68,    68,    68,    63,    34,    53,    54,    23,
      24,    25,    21,    22,    17,    18,    19,    20,    15,    16,
      27,    28,    29,    31,    66,    77,    33,    59,    30,    37,
      32,    53,    76,    59,    30,    34,    47,    48,    32,    47,
      76,    30,    34,    37,    68,    68,    68,    70,    70,    71,
      71,    71,    71,    72,    72,    73,    74,    30,    63,    69,
      63,    31,    31,    58,     5,     7,     8,     9,    10,    12,
      34,    38,    42,    59,    60,    61,    62,    63,    65,    59,
      57,    32,    59,    34,    37,    32,    53,    30,    37,    32,
      63,    32,    31,    29,    29,    38,    38,    38,    63,    34,
      61,    38,    14,    47,    63,    32,    76,    64,    75,    64,
      38,    63,    32,    30,    30,    38,    62,    62,     6,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    41,    41,    42,    42,    43,
      44,    44,    45,    45,    46,    46,    47,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    53,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    73,    74,    74,    75,    75,    76,    77,
      78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     1,     1,     4,
       3,     1,     3,     4,     4,     3,     1,     3,     2,     3,
       1,     3,     3,     1,     1,     2,     3,     4,     4,     3,
       1,     3,     2,     3,     1,     5,     5,     6,     6,     3,
       1,     2,     3,     2,     4,     3,     2,     2,     1,     1,
       1,     4,     1,     2,     1,     5,     7,     5,     2,     2,
       2,     3,     1,     1,     1,     2,     4,     3,     3,     1,
       1,     1,     3,     4,     2,     2,     2,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 34 "parser.y" /* yacc.c:1646  */
    {savedTree = (yyvsp[0]);}
#line 1402 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-1]);
                        ((CompUnit*)(yyval))->nb.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1411 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 44 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-1]);
                        ((CompUnit*)(yyval))->nb.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1420 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 50 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new CompUnit;
                        ((CompUnit*)(yyval))->nb.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1429 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 56 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new CompUnit;
                        ((CompUnit*)(yyval))->nb.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1438 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1444 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1450 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1456 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((ConstDecl*)(yyval))->cd.push_back((ConstDef*)(yyvsp[0]));
                    }
#line 1465 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstDecl;
                        ((ConstDecl*)(yyval))->cd.push_back((ConstDef*)(yyvsp[0]));
                    }
#line 1474 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstDef;
                        ((ConstDef*)(yyval))->ident = (Identifier*)(yyvsp[-2]);
                        ((ConstDef*)(yyval))->civ = (ConstInitVal*)(yyvsp[0]);
                    }
#line 1484 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 95 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((ConstDef*)(yyval))->ident = (Identifier*)(yyvsp[-3]);
                        ((ConstDef*)(yyval))->civ = (ConstInitVal*)(yyvsp[0]);
                    }
#line 1494 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 103 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-3]);
                        ((ConstDef*)(yyval))->arr.push_back((ConstExp*)(yyvsp[-1]));
                    }
#line 1503 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 108 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstDef;
                        ((ConstDef*)(yyval))->arr.push_back((ConstExp*)(yyvsp[-1]));
                    }
#line 1512 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstInitVal;
                        ((ConstInitVal*)(yyval))->ce.push_back((NodeBase*)(yyvsp[0]));
                        ((ConstInitVal*)(yyval))->has_bparen = 0;
                    }
#line 1522 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 121 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1528 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 123 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstInitVal;
                        ((ConstInitVal*)(yyval))->has_bparen = 1;
                    }
#line 1537 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 130 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((ConstInitVal*)(yyval))->ce.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1546 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstInitVal;
                        ((ConstInitVal*)(yyval))->has_bparen = 1;
                        ((ConstInitVal*)(yyval))->ce.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1556 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1562 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((VarDecl*)(yyval))->vd.push_back((VarDef*)(yyvsp[0]));
                    }
#line 1571 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 155 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new VarDecl;
                        ((VarDecl*)(yyval))->vd.push_back((VarDef*)(yyvsp[0]));
                    }
#line 1580 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 162 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new VarDef;
                        ((VarDef*)(yyval))->ident = (Identifier*)(yyvsp[0]);
                        ((VarDef*)(yyval))->iv = NULL;
                    }
#line 1590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 168 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[0]);
                        ((VarDef*)(yyval))->ident = (Identifier*)(yyvsp[-1]);
                        ((VarDef*)(yyval))->iv = (InitVal*)NULL;
                    }
#line 1600 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 174 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new VarDef;
                        ((VarDef*)(yyval))->ident = (Identifier*)(yyvsp[-2]);
                        ((VarDef*)(yyval))->iv = (InitVal*)(yyvsp[0]);
                    }
#line 1610 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 180 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((VarDef*)(yyval))->ident = (Identifier*)(yyvsp[-3]);
                        ((VarDef*)(yyval))->iv = (InitVal*)(yyvsp[0]);
                    }
#line 1620 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 188 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-3]);
                        ((VarDef*)(yyval))->arr.push_back((ConstExp*)(yyvsp[-1]));
                    }
#line 1629 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 193 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new VarDef;
                        ((VarDef*)(yyval))->arr.push_back((ConstExp*)(yyvsp[-1]));
                    }
#line 1638 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new InitVal;
                        ((InitVal*)(yyval))->e.push_back((NodeBase*)(yyvsp[0]));
                        ((InitVal*)(yyval))->has_bparen = 0;
                    }
#line 1648 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1654 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 208 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new InitVal;
                        ((InitVal*)(yyval))->has_bparen = 1;
                    }
#line 1663 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 215 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((InitVal*)(yyval))->e.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1672 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 220 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new InitVal;
                        ((InitVal*)(yyval))->has_bparen = 1;
                        ((InitVal*)(yyval))->e.push_back((NodeBase*)(yyvsp[0]));
                    }
#line 1682 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncDef;
                        ((FuncDef*)(yyval))->ident = (Identifier*)(yyvsp[-3]);
                        ((FuncDef*)(yyval))->body = (Block*)(yyvsp[0]);
                    }
#line 1692 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 237 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncDef;
                        ((FuncDef*)(yyval))->ident = (Identifier*)(yyvsp[-3]);
                        ((FuncDef*)(yyval))->body = (Block*)(yyvsp[0]);
                    }
#line 1702 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 243 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((FuncDef*)(yyval))->ident = (Identifier*)(yyvsp[-4]);
                        ((FuncDef*)(yyval))->body = (Block*)(yyvsp[0]);
                    }
#line 1712 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 249 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((FuncDef*)(yyval))->ident = (Identifier*)(yyvsp[-4]);
                        ((FuncDef*)(yyval))->body = (Block*)(yyvsp[0]);
                    }
#line 1722 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 257 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((FuncDef*)(yyval))->fp.push_back((FuncFParam*)(yyvsp[0]));
                    }
#line 1731 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 262 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncDef;
                        ((FuncDef*)(yyval))->fp.push_back((FuncFParam*)(yyvsp[0]));
                    }
#line 1740 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 269 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncFParam;
                        ((FuncFParam*)(yyval))->ident = (Identifier*)(yyvsp[0]);
                    }
#line 1749 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 274 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[0]);
                        ((FuncFParam*)(yyval))->ident = (Identifier*)(yyvsp[-1]);
                    }
#line 1758 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 281 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncFParam;
                        ((FuncFParam*)(yyval))->ce.push_back(NULL);
                    }
#line 1767 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-3]);
                        ((FuncFParam*)(yyval))->ce.push_back((ConstExp*)(yyvsp[-1]));
                    }
#line 1776 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 296 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-1]);
                    }
#line 1784 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 300 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new Block;
                    }
#line 1792 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 306 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-1]);
                        ((Block*)(yyval))->bi.push_back((BlockItem*)(yyvsp[0]));
                    }
#line 1801 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 311 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new Block;
                        ((Block*)(yyval))->bi.push_back((BlockItem*)(yyvsp[0]));
                    }
#line 1810 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 318 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1816 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1822 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 324 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new AssignStmt;
                        ((AssignStmt*)(yyval))->lv = (LVal*)(yyvsp[-3]);
                        ((AssignStmt*)(yyval))->e = (Exp*)(yyvsp[-1]);
                    }
#line 1832 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 330 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ExpStmt;
                        ((ExpStmt*)(yyval))->e = NULL;
                    }
#line 1841 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 335 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ExpStmt;
                        ((ExpStmt*)(yyval))->e = (Exp*)(yyvsp[-1]);
                    }
#line 1850 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 340 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new BlockStmt;
                        ((BlockStmt*)(yyval))->b = (Block*)(yyvsp[0]);
                    }
#line 1859 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 345 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new IfStmt;
                        ((IfStmt*)(yyval))->c = (Cond*)(yyvsp[-2]);
                        ((IfStmt*)(yyval))->then_body = (Stmt*)(yyvsp[0]);
                        ((IfStmt*)(yyval))->else_body = NULL;
                    }
#line 1870 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 352 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new IfStmt;
                        ((IfStmt*)(yyval))->c = (Cond*)(yyvsp[-4]);
                        ((IfStmt*)(yyval))->then_body = (Stmt*)(yyvsp[-2]);
                        ((IfStmt*)(yyval))->else_body = (Stmt*)(yyvsp[0]);
                    }
#line 1881 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 359 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new WhileStmt;
                        ((WhileStmt*)(yyval))->c = (Cond*)(yyvsp[-2]);
                        ((WhileStmt*)(yyval))->body = (Stmt*)(yyvsp[0]);
                    }
#line 1891 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 365 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new BreakStmt;
                    }
#line 1899 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 369 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ContinueStmt;
                    }
#line 1907 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 373 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ReturnStmt;
                        ((ReturnStmt*)(yyval))->e = NULL;
                    }
#line 1916 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 378 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ReturnStmt;
                        ((ReturnStmt*)(yyval))->e = (Exp*)(yyvsp[-1]);
                    }
#line 1925 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 388 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new Exp;
                        ((Exp*)(yyval))->ae = (LOrExp*)(yyvsp[0]);
                    }
#line 1934 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 395 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new Cond;
                        ((Cond*)(yyval))->loe = (LOrExp*)(yyvsp[0]);
                    }
#line 1943 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 402 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new LVal;
                        ((LVal*)(yyval))->ident = (Identifier*)(yyvsp[0]);
                    }
#line 1952 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 407 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[0]);
                        ((LVal*)(yyval))->ident = (Identifier*)(yyvsp[-1]);
                    }
#line 1961 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 414 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-3]);
                        ((LVal*)(yyval))->e.push_back((Exp*)(yyvsp[-1]));
                    }
#line 1970 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 419 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new LVal;
                        ((LVal*)(yyval))->e.push_back((Exp*)(yyvsp[-1]));
                    }
#line 1979 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 426 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new PrimaryExp;
                        ((PrimaryExp*)(yyval))->body = (yyvsp[-1]);
                    }
#line 1988 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 431 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new PrimaryExp;
                        ((PrimaryExp*)(yyval))->body = (yyvsp[0]);
                    }
#line 1997 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 436 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new PrimaryExp;
                        ((PrimaryExp*)(yyval))->body = (yyvsp[0]);
                    }
#line 2006 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 443 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[0]);
                    }
#line 2014 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 447 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncExp;
                        ((FuncExp*)(yyval))->ident = (Identifier*)(yyvsp[-2]);
                    }
#line 2023 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 452 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-1]);
                        ((FuncExp*)(yyval))->ident = (Identifier*)(yyvsp[-3]);
                    }
#line 2032 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 457 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new UnaryExp;
                        ((UnaryExp*)(yyval))->uo = "+";
                        ((UnaryExp*)(yyval))->ue = (UnaryExp*)(yyvsp[0]);
                    }
#line 2042 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 463 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new UnaryExp;
                        ((UnaryExp*)(yyval))->uo = "-";
                        ((UnaryExp*)(yyval))->ue = (UnaryExp*)(yyvsp[0]);
                    }
#line 2052 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 469 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new UnaryExp;
                        ((UnaryExp*)(yyval))->uo = "!";
                        ((UnaryExp*)(yyval))->ue = (UnaryExp*)(yyvsp[0]);
                    }
#line 2062 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 477 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((FuncExp*)(yyval))->params.push_back((Exp*)(yyvsp[0]));
                    }
#line 2071 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 482 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new FuncExp;
                        ((FuncExp*)(yyval))->params.push_back((Exp*)(yyvsp[0]));
                    }
#line 2080 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 492 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((MulExp*)(yyval))->ue.push_back((UnaryExp*)(yyvsp[0]));
                        ((MulExp*)(yyval))->ops.push_back("*");
                    }
#line 2090 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 498 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((MulExp*)(yyval))->ue.push_back((UnaryExp*)(yyvsp[0]));
                        ((MulExp*)(yyval))->ops.push_back("/");
                    }
#line 2100 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 504 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((MulExp*)(yyval))->ue.push_back((UnaryExp*)(yyvsp[0]));
                        ((MulExp*)(yyval))->ops.push_back("%");
                    }
#line 2110 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 510 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new MulExp;
                        ((MulExp*)(yyval))->ue.push_back((UnaryExp*)(yyvsp[0]));
                    }
#line 2119 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 517 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((AddExp*)(yyval))->me.push_back((MulExp*)(yyvsp[0]));
                        ((AddExp*)(yyval))->ops.push_back("+");
                    }
#line 2129 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 523 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((AddExp*)(yyval))->me.push_back((MulExp*)(yyvsp[0]));
                        ((AddExp*)(yyval))->ops.push_back("-");
                    }
#line 2139 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 529 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new AddExp;
                        ((AddExp*)(yyval))->me.push_back((MulExp*)(yyvsp[0]));
                    }
#line 2148 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 536 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((RelExp*)(yyval))->ae.push_back((AddExp*)(yyvsp[0]));
                        ((RelExp*)(yyval))->ops.push_back("<");
                    }
#line 2158 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 542 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((RelExp*)(yyval))->ae.push_back((AddExp*)(yyvsp[0]));
                        ((RelExp*)(yyval))->ops.push_back(">");
                    }
#line 2168 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 548 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((RelExp*)(yyval))->ae.push_back((AddExp*)(yyvsp[0]));
                        ((RelExp*)(yyval))->ops.push_back("<=");
                    }
#line 2178 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 554 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((RelExp*)(yyval))->ae.push_back((AddExp*)(yyvsp[0]));
                        ((RelExp*)(yyval))->ops.push_back(">=");
                    }
#line 2188 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 560 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new RelExp;
                        ((RelExp*)(yyval))->ae.push_back((AddExp*)(yyvsp[0]));
                    }
#line 2197 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 567 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((EqExp*)(yyval))->re.push_back((RelExp*)(yyvsp[0]));
                        ((EqExp*)(yyval))->ops.push_back("==");
                    }
#line 2207 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 573 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((EqExp*)(yyval))->re.push_back((RelExp*)(yyvsp[0]));
                        ((EqExp*)(yyval))->ops.push_back("!=");
                    }
#line 2217 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 579 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new EqExp;
                        ((EqExp*)(yyval))->re.push_back((RelExp*)(yyvsp[0]));
                    }
#line 2226 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 586 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((LAndExp*)(yyval))->ee.push_back((EqExp*)(yyvsp[0]));
                    }
#line 2235 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 591 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new LAndExp;
                        ((LAndExp*)(yyval))->ee.push_back((EqExp*)(yyvsp[0]));
                    }
#line 2244 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 598 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = (yyvsp[-2]);
                        ((LOrExp*)(yyval))->lae.push_back((LAndExp*)(yyvsp[0]));
                    }
#line 2253 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 603 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new LOrExp;
                        ((LOrExp*)(yyval))->lae.push_back((LAndExp*)(yyvsp[0]));
                    }
#line 2262 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 610 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new ConstExp;
                        ((ConstExp*)(yyval))->ae = (LOrExp*)(yyvsp[0]);
                    }
#line 2271 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 620 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new Identifier;
                        ((Identifier*)(yyval))->id_name = std::string(tokenString);
                        //std::cerr<<"ident: "<<tokenString<<std::endl;
                    }
#line 2281 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 628 "parser.y" /* yacc.c:1646  */
    {
                        (yyval) = new Number;
                        ((Number*)(yyval))->num_val = char2int(tokenString);
                        //std::cerr<<"number: "<<tokenString<<std::endl;
                    }
#line 2291 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2295 "parser.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 635 "parser.y" /* yacc.c:1906  */


int yyerror(std::string message){
    std::cerr<<message<<std::endl;
    return 0;
}

static int yylex(){
    return getToken();
}

NodeBase* parse(){
    yyparse();
    return savedTree;
}

int char2int(char* a){
    if(a[0] == '0' && (a[1] == 'x' || a[1] == 'X')){
        int tmp = 0;
        for(char* p = a+2; *p != '\0'; p++)
            tmp = tmp*16 + 
                ((*p>='0' && *p<='9')? *p-'0' : ((*p>='a' && *p<='f')? *p-'a'+10 : *p-'A'+10));
        return tmp;
    }
    if(a[0] == '0'){
        int tmp = 0;
        for(char* p = a; *p != '\0'; p++)
            tmp = tmp*8 + *p - '0';
        return tmp;
    }
    int tmp = 0;
    for(char* p = a; *p != '\0'; p++)
        tmp = tmp*10 + *p - '0';
    return tmp;
}
