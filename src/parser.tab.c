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
#line 1 "parser.y" /* yacc.c:339  */

  #include "Classes.h"
  #include <bits/stdc++.h>
  
  extern "C" FILE *yyin;
  extern "C" int errors;
  extern union Node yylval;
  extern "C" int yylex();
  extern "C" int yyparse();
  void yyerror (char const *s);
  extern "C" int line_num;
  int errors=0;
  class Prog* start=NULL;

#line 81 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    declaration_list = 258,
    statement_list = 259,
    INTEGER = 260,
    BOOLEAN = 261,
    ID = 262,
    TYPE = 263,
    STRING = 264,
    ETOK = 265,
    PRINT = 266,
    PRINTLN = 267,
    READ = 268,
    IF = 269,
    ELSE = 270,
    FOR = 271,
    WHILE = 272,
    GOTO = 273,
    COMMA = 274,
    SC = 275,
    COL = 276,
    OB = 277,
    CB = 278,
    OSB = 279,
    CSB = 280,
    OP = 281,
    CP = 282,
    COND_AND = 283,
    COND_OR = 284,
    NOT = 285,
    ADD = 286,
    SUB = 287,
    MUL = 288,
    DIV = 289,
    MOD = 290,
    LT = 291,
    GT = 292,
    LE = 293,
    GE = 294,
    EQUAL = 295,
    NOT_EQUAL = 296,
    EQ = 297,
    ADDEQ = 298,
    SUBEQ = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:355  */

	unsigned int number;
	char * value;

#line 171 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 188 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    79,    83,    88,    91,    95,    98,    99,
     102,   103,   107,   108,   109,   113,   114,   115,   116,   117,
     118,   119,   122,   125,   126,   129,   130,   134,   135,   138,
     139,   140,   144,   146,   151,   156,   157,   161,   162,   166,
     167,   168,   172,   173,   177,   178,   179,   183,   184,   185,
     186,   187,   190,   191,   192,   196,   197,   198,   199,   203,
     204,   208,   209,   210,   214,   215,   216,   217,   218,   219,
     220
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "declaration_list", "statement_list",
  "INTEGER", "BOOLEAN", "ID", "TYPE", "STRING", "ETOK", "PRINT", "PRINTLN",
  "READ", "IF", "ELSE", "FOR", "WHILE", "GOTO", "COMMA", "SC", "COL", "OB",
  "CB", "OSB", "CSB", "OP", "CP", "COND_AND", "COND_OR", "NOT", "ADD",
  "SUB", "MUL", "DIV", "MOD", "LT", "GT", "LE", "GE", "EQUAL", "NOT_EQUAL",
  "EQ", "ADDEQ", "SUBEQ", "$accept", "program", "declaration_Block",
  "statement_Block", "Variable_declarations", "Variable_declaration",
  "Var_dec_names", "Var_dec_name", "Statements", "Statement",
  "Read_Statement", "Read_Seq", "Print_Statement", "Print_Seq",
  "Print_Var", "For_Statement", "While_Statement", "GoTo_Statement",
  "Conditional", "Assignment", "Variable", "Arith_Expression",
  "Arith_Factor", "Arith_Factor1", "Bool_Expression", "Bool_Term",
  "Bool_Factor", "Bool_Literal", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,    41,    38,   -58,    62,   -58,    -3,    50,    72,   -58,
      64,   -58,   -58,    67,    78,   -58,   -58,    82,    83,    72,
       2,   118,   118,    95,    28,    95,    28,   107,   -58,   -58,
     104,   106,   -58,   -58,   114,   -58,   119,    86,   113,   -58,
      69,    10,   -58,   116,   -58,   122,   -58,   -58,   122,   123,
     -58,   -58,   -58,    28,    28,    11,   -58,    81,    98,   -58,
      33,   115,   -58,   -58,   102,    33,   131,   -58,   -58,   -58,
     -58,    10,    10,    10,   -58,   -58,    10,    79,   118,    95,
      74,    24,   -58,   -58,    10,    10,    10,    10,    10,    10,
      10,    10,    11,    11,    11,    28,    28,    28,   132,    28,
      10,   -58,    28,    25,    25,    25,    74,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,    25,    25,    25,    25,    25,    25,
     -58,   -58,   -58,   115,   115,   115,    50,   -58,   -10,   -16,
     -58,    10,    84,    10,   -58,    39,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     5,     0,     1,     0,     0,     0,     3,
       0,    12,     2,    10,     7,     8,     6,     0,     0,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     4,    13,
       0,     0,    16,    17,     0,    18,     0,     0,     0,     9,
       0,     0,    31,    42,    30,    25,    27,    29,    26,    22,
      23,    53,    64,     0,     0,     0,    54,     0,    46,    51,
       0,    58,    60,    62,     0,     0,    36,    20,    21,    19,
      15,     0,     0,     0,    11,    14,     0,     0,     0,     0,
      46,     0,    63,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,    34,     0,    39,    41,    40,     0,    43,    28,    24,
      52,    61,    44,    45,    65,    66,    67,    68,    69,    70,
      47,    48,    49,    55,    56,    57,     0,    59,     0,    35,
      37,     0,     0,     0,    33,     0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   -57,   -58,   -58,   -58,   127,   -58,   108,
     -58,   -58,   -58,   128,    71,   -58,   -58,   -58,   -58,   -58,
     -11,   -41,   -49,   -53,   -25,    40,   -47,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     4,    12,     6,    10,    14,    15,    17,    29,
      30,    49,    31,    45,    46,    32,    33,    34,    35,    36,
      56,    57,    58,    59,    60,    61,    62,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      77,    65,    83,    98,    80,     8,    37,    82,   101,   131,
      47,    47,    50,    95,    64,    51,    51,    43,    43,     1,
       9,    84,    85,    40,    96,    97,    41,   106,    81,    37,
     103,   104,   105,    51,    52,    43,    76,    76,     5,   120,
     121,   122,    55,   112,   113,   114,   115,   116,   117,   118,
     119,   111,   127,    95,    53,    11,    84,    85,    54,   128,
      55,    11,    95,     3,    96,    97,     7,    47,   109,   130,
      84,    85,    11,    96,    97,   134,    43,   129,   136,    13,
      21,    22,    23,    24,    16,    25,    26,    27,    38,    20,
     132,    18,   135,    21,    22,    23,    24,    19,    25,    26,
      27,   110,    43,   133,   107,    28,    11,    92,    93,    94,
      84,    85,    84,    85,    66,    84,    85,    86,    87,    88,
      89,    90,    91,    42,    67,    43,    68,    44,    71,    72,
      73,    92,    93,    94,    69,   123,   124,   125,    74,    70,
      41,    78,    79,    99,   100,   102,    39,   126,    75,   108,
      48
};

static const yytype_uint8 yycheck[] =
{
      41,    26,    55,    60,    53,     8,    17,    54,    65,    19,
      21,    22,    23,    29,    25,     5,     5,     7,     7,     3,
      23,    31,    32,    21,    40,    41,    24,    76,    53,    40,
      71,    72,    73,     5,     6,     7,    26,    26,     0,    92,
      93,    94,    32,    84,    85,    86,    87,    88,    89,    90,
      91,    27,    99,    29,    26,    22,    31,    32,    30,   100,
      32,    22,    29,    22,    40,    41,     4,    78,    79,   126,
      31,    32,    22,    40,    41,   132,     7,   102,   135,     7,
      11,    12,    13,    14,    20,    16,    17,    18,     5,     7,
     131,    24,   133,    11,    12,    13,    14,    19,    16,    17,
      18,    27,     7,    19,    25,    23,    22,    33,    34,    35,
      31,    32,    31,    32,     7,    31,    32,    36,    37,    38,
      39,    40,    41,     5,    20,     7,    20,     9,    42,    43,
      44,    33,    34,    35,    20,    95,    96,    97,    25,    20,
      24,    19,    19,    28,    42,    14,    19,    15,    40,    78,
      22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    46,    22,    47,     0,    49,     4,     8,    23,
      50,    22,    48,     7,    51,    52,    20,    53,    24,    19,
       7,    11,    12,    13,    14,    16,    17,    18,    23,    54,
      55,    57,    60,    61,    62,    63,    64,    65,     5,    52,
      21,    24,     5,     7,     9,    58,    59,    65,    58,    56,
      65,     5,     6,    26,    30,    32,    65,    66,    67,    68,
      69,    70,    71,    72,    65,    69,     7,    20,    20,    20,
      20,    42,    43,    44,    25,    54,    26,    66,    19,    19,
      67,    69,    71,    68,    31,    32,    36,    37,    38,    39,
      40,    41,    33,    34,    35,    29,    40,    41,    48,    28,
      42,    48,    14,    66,    66,    66,    67,    25,    59,    65,
      27,    27,    66,    66,    66,    66,    66,    66,    66,    66,
      68,    68,    68,    70,    70,    70,    15,    71,    66,    69,
      48,    19,    66,    19,    48,    66,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    49,    49,    50,    51,    51,
      52,    52,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    60,    60,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66,    66,    66,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     3,     2,     1,     3,
       1,     4,     0,     2,     4,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       1,     1,     9,     7,     3,     4,     2,     5,     3,     3,
       3,     3,     1,     4,     3,     3,     1,     3,     3,     3,
       2,     1,     3,     1,     1,     3,     3,     3,     1,     3,
       1,     3,     1,     2,     1,     3,     3,     3,     3,     3,
       3
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
#line 72 "parser.y" /* yacc.c:1646  */
    {
	(yyval.prog) = new Prog((yyvsp[-2].declblock),(yyvsp[0].stblock));
	start = (yyval.prog);
}
#line 1369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.declblock) = new declarationBlock((yyvsp[-1].fields));}
#line 1375 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval.stblock) = new statementBlock((yyvsp[-1].stmts));}
#line 1381 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 88 "parser.y" /* yacc.c:1646  */
    {
		(yyval.fields) = new fieldDecls();
	}
#line 1389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.fields)->push_back((yyvsp[-1].field));}
#line 1395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.field) = new fieldDecl(string((yyvsp[-1].value)),(yyvsp[0].vars));}
#line 1401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval.vars) = new Vars();(yyval.vars)->push_back((yyvsp[0].var));}
#line 1407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.vars)->push_back((yyvsp[0].var)); }
#line 1413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = new Var(string("Normal"),string((yyvsp[0].value)));}
#line 1419 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.var) = new Var(string("Array"),string((yyvsp[-3].value)),stoi((yyvsp[-1].value)));}
#line 1425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.stmts) = new Stmts();}
#line 1431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.stmts)->push_back((yyvsp[0].stmt));}
#line 1437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.stmts)->push_back((yyvsp[0].stmt));}
#line 1443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[-1].assignment);}
#line 1449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].for_stmt);}
#line 1455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].while_stmt);}
#line 1461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].if_stmt);}
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].goto_stmt);}
#line 1473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].read_stmt);}
#line 1479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 119 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[-1].print_stmt);}
#line 1485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.read_stmt) = new readStmt((yyvsp[0].readcans));}
#line 1491 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval.readcans) = new readCands(); (yyval.readcans)->push_back((yyvsp[0].location));}
#line 1497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval.readcans)->push_back((yyvsp[0].location));}
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval.print_stmt) = new printStmt(0, (yyvsp[0].printcans));}
#line 1509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval.print_stmt) = new printStmt(1, (yyvsp[0].printcans));}
#line 1515 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.printcans) = new printCands; (yyval.printcans)->push_back((yyvsp[0].printcan));}
#line 1521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval.printcans)->push_back((yyvsp[0].printcan));}
#line 1527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.printcan) = new printCand((yyvsp[0].location)); }
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.printcan) = new printCand(new stringLiteral((yyvsp[0].value)));}
#line 1539 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.printcan) = new printCand(new intLiteral(stoi((yyvsp[0].value))));}
#line 1545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.for_stmt) = new forStmt((yyvsp[-7].location),(yyvsp[-5].arith_expr),(yyvsp[-3].arith_expr),(yyvsp[-1].arith_expr),(yyvsp[0].stblock));}
#line 1551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 147 "parser.y" /* yacc.c:1646  */
    { (yyval.for_stmt) = new forStmt((yyvsp[-5].location),(yyvsp[-3].arith_expr),(yyvsp[-1].arith_expr),1,(yyvsp[0].stblock));}
#line 1557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.while_stmt) = new whileStmt((yyvsp[-1].bool_expr),(yyvsp[0].stblock));}
#line 1563 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval.goto_stmt) = new gotoStmt((yyvsp[-2].value),(yyvsp[0].bool_expr));}
#line 1569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval.goto_stmt) = new gotoStmt((yyvsp[0].value),NULL);}
#line 1575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.if_stmt) = new ifElseStmt((yyvsp[-3].bool_expr),(yyvsp[-2].stblock),(yyvsp[0].stblock));}
#line 1581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.if_stmt) = new ifElseStmt((yyvsp[-1].bool_expr),(yyvsp[0].stblock),NULL);}
#line 1587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.assignment) = new Assignment((yyvsp[-2].location),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.assignment) = new Assignment((yyvsp[-2].location),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.assignment) = new Assignment((yyvsp[-2].location),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.location) = new Location(string((yyvsp[0].value)),string("Normal"));}
#line 1611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.location) = new Location(string((yyvsp[-3].value)),string("Array"),(yyvsp[-1].arith_expr));}
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new binArithExpr((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 178 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new binArithExpr((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.arith_expr) = (yyvsp[0].arith_expr); }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new binArithExpr((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new binArithExpr((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new binArithExpr((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new unArithExpr(string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr)=(yyvsp[0].arith_expr);}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 190 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = (yyvsp[-1].arith_expr);}
#line 1671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = new intLiteral(stoi((yyvsp[0].value)));}
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 192 "parser.y" /* yacc.c:1646  */
    {(yyval.arith_expr) = (yyvsp[0].location);}
#line 1683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_expr) = new binBoolExpr((yyvsp[-2].bool_expr),string((yyvsp[-1].value)),(yyvsp[0].bool_expr));}
#line 1689 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_expr) = new binBoolExpr((yyvsp[-2].bool_expr),string((yyvsp[-1].value)),(yyvsp[0].bool_expr));}
#line 1695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_expr) = new binBoolExpr((yyvsp[-2].bool_expr),string((yyvsp[-1].value)),(yyvsp[0].bool_expr));}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval.bool_expr) = (yyvsp[0].bool_expr); }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_expr) = new binBoolExpr((yyvsp[-2].bool_expr),string((yyvsp[-1].value)),(yyvsp[0].bool_expr));}
#line 1713 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 204 "parser.y" /* yacc.c:1646  */
    { (yyval.bool_expr) = (yyvsp[0].bool_expr); }
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_expr) = (yyvsp[-1].bool_expr);}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval.bool_expr) = (yyvsp[0].bool_literal); }
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_expr) = new unBoolExpr(string((yyvsp[-1].value)),(yyvsp[0].bool_expr));}
#line 1737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[0].value));}
#line 1743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1755 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 218 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1767 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 219 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.bool_literal) = new boolLiteral((yyvsp[-2].arith_expr),string((yyvsp[-1].value)),(yyvsp[0].arith_expr));}
#line 1779 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1783 "parser.tab.c" /* yacc.c:1646  */
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
#line 223 "parser.y" /* yacc.c:1906  */


int main(int argc, char *argv[])
{
	if (argc == 1 ) {
		fprintf(stderr, "Correct usage: bcc filename\n");
		exit(1);
	}

	if (argc > 2) {
		fprintf(stderr, "Passing more arguments than necessary.\n");
		fprintf(stderr, "Correct usage: bcc filename\n");
	}

	yyin = fopen(argv[1], "r");

	yyparse();
	if(start){
		Visitor * visitor = new Visitor();
		start->accept(visitor);
	}
}


void yyerror(const char *s) {
	fprintf(stderr,"EEK, parse error on line %d!  Message: %s\n",line_num,s);
	// might as well halt now:
	exit(-1);
}
