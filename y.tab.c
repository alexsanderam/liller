/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define YYSTYPE args

using namespace std;

typedef struct{
	string type;
	string label;
} id_struct;

typedef map<string, id_struct> VARIABLESMAP;

VARIABLESMAP IDMap;

string declarations;

struct args
{
	string label;
	string traduction;
	string type; /*auxiliar*/
};

int yylex(void);
void yyerror(string);

string generateLabel();
id_struct* defineKeyOperating(id_struct, id_struct);



/* Line 268 of yacc.c  */
#line 108 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_INT = 258,
     TK_FLOAT = 259,
     TK_SCIENTIFIC = 260,
     TK_CHAR = 261,
     TK_STRING = 262,
     TK_BOOL = 263,
     TK_TRUE = 264,
     TK_FALSE = 265,
     TK_MAIN = 266,
     TK_ID = 267,
     TK_TYPE_CHAR = 268,
     TK_TYPE_STRING = 269,
     TK_TYPE_INT = 270,
     TK_TYPE_VOID = 271,
     TK_TYPE_FLOAT = 272,
     TK_TYPE_DOUBLE = 273,
     TK_TYPE_BOOLEAN = 274,
     TK_MODIFIER_UNSIGNED = 275,
     TK_MODIFIER_SIGNED = 276,
     TK_MODIFIER_SHORT = 277,
     TK_MODIFIER_LONG = 278,
     TK_END = 279,
     TK_ERROR = 280,
     TK_OP_SUM = 281,
     TK_OP_SUB = 282,
     TK_OP_MUL = 283,
     TK_OP_DIV = 284,
     TK_OP_REL_LESS = 285,
     TK_OP_REL_GREATER = 286,
     TK_OP_REL_EQLESS = 287,
     TK_OP_REL_EQGREATER = 288,
     TK_OP_REL_EQ = 289,
     TK_OP_REL_DIFF = 290,
     TK_OP_LOGIC_AND = 291,
     TK_OP_LOGIC_OR = 292,
     TK_OP_LOGIC_NOT = 293,
     TK_OP_BIN_AND = 294,
     TK_OP_BIN_OR = 295,
     TK_OP_BIN_XOR = 296,
     TK_OP_BIN_NOT = 297,
     TK_OP_BIN_SHIFTR = 298,
     TK_OP_BIN_SHIFTL = 299,
     TK_ASSIGN = 300,
     TK_RETURN = 301,
     TK_OP_MOD = 302
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_FLOAT 259
#define TK_SCIENTIFIC 260
#define TK_CHAR 261
#define TK_STRING 262
#define TK_BOOL 263
#define TK_TRUE 264
#define TK_FALSE 265
#define TK_MAIN 266
#define TK_ID 267
#define TK_TYPE_CHAR 268
#define TK_TYPE_STRING 269
#define TK_TYPE_INT 270
#define TK_TYPE_VOID 271
#define TK_TYPE_FLOAT 272
#define TK_TYPE_DOUBLE 273
#define TK_TYPE_BOOLEAN 274
#define TK_MODIFIER_UNSIGNED 275
#define TK_MODIFIER_SIGNED 276
#define TK_MODIFIER_SHORT 277
#define TK_MODIFIER_LONG 278
#define TK_END 279
#define TK_ERROR 280
#define TK_OP_SUM 281
#define TK_OP_SUB 282
#define TK_OP_MUL 283
#define TK_OP_DIV 284
#define TK_OP_REL_LESS 285
#define TK_OP_REL_GREATER 286
#define TK_OP_REL_EQLESS 287
#define TK_OP_REL_EQGREATER 288
#define TK_OP_REL_EQ 289
#define TK_OP_REL_DIFF 290
#define TK_OP_LOGIC_AND 291
#define TK_OP_LOGIC_OR 292
#define TK_OP_LOGIC_NOT 293
#define TK_OP_BIN_AND 294
#define TK_OP_BIN_OR 295
#define TK_OP_BIN_XOR 296
#define TK_OP_BIN_NOT 297
#define TK_OP_BIN_SHIFTR 298
#define TK_OP_BIN_SHIFTL 299
#define TK_ASSIGN 300
#define TK_RETURN 301
#define TK_OP_MOD 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 244 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  98

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    16,    22,    23,    27,    28,    32,
      38,    41,    46,    48,    50,    52,    54,    56,    58,    60,
      63,    66,    69,    72,    75,    78,    81,    83,    85,    89,
      93,    97,   101,   105,   110,   115,   119,   123,   126,   127,
     130,   133,   137,   141,   145,   147,   149,   151,   153,   155,
     157,   159,   161,   165,   167,   169,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   195,   197
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    15,    11,    48,    49,    56,    -1,    15,
      11,    48,    16,    49,    56,    -1,    50,    60,    56,    57,
      51,    -1,    -1,    46,     3,    52,    -1,    -1,    58,    53,
      12,    -1,    58,    53,    12,    45,    62,    -1,    59,    12,
      -1,    59,    12,    45,    62,    -1,    13,    -1,    14,    -1,
      15,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    13,    -1,    21,    13,    -1,    20,    15,    -1,    21,
      15,    -1,    22,    15,    -1,    23,    15,    -1,    23,    18,
      -1,    22,    -1,    23,    -1,    20,    22,    15,    -1,    21,
      22,    15,    -1,    20,    23,    15,    -1,    21,    23,    15,
      -1,    23,    23,    15,    -1,    20,    23,    23,    15,    -1,
      21,    23,    23,    15,    -1,    20,    23,    23,    -1,    21,
      23,    23,    -1,    61,    60,    -1,    -1,    62,    52,    -1,
      58,    52,    -1,    62,    64,    62,    -1,    62,    65,    62,
      -1,    62,    66,    62,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,     7,    -1,     8,    -1,    12,    -1,    63,
      -1,    12,    45,    62,    -1,    26,    -1,    27,    -1,    29,
      -1,    28,    -1,    47,    -1,    30,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    39,    -1,    40,
      -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    67,    73,    79,    84,    89,    95,   110,
     132,   148,   175,   175,   175,   175,   175,   175,   175,   177,
     181,   185,   189,   193,   197,   201,   205,   205,   209,   213,
     217,   221,   225,   229,   233,   237,   241,   247,   252,   256,
     257,   264,   312,   317,   322,   332,   342,   352,   362,   372,
     382,   390,   398,   427,   427,   427,   427,   427,   431,   431,
     431,   431,   431,   431,   441,   441,   441,   441,   441,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INT", "TK_FLOAT", "TK_SCIENTIFIC",
  "TK_CHAR", "TK_STRING", "TK_BOOL", "TK_TRUE", "TK_FALSE", "TK_MAIN",
  "TK_ID", "TK_TYPE_CHAR", "TK_TYPE_STRING", "TK_TYPE_INT", "TK_TYPE_VOID",
  "TK_TYPE_FLOAT", "TK_TYPE_DOUBLE", "TK_TYPE_BOOLEAN",
  "TK_MODIFIER_UNSIGNED", "TK_MODIFIER_SIGNED", "TK_MODIFIER_SHORT",
  "TK_MODIFIER_LONG", "TK_END", "TK_ERROR", "TK_OP_SUM", "TK_OP_SUB",
  "TK_OP_MUL", "TK_OP_DIV", "TK_OP_REL_LESS", "TK_OP_REL_GREATER",
  "TK_OP_REL_EQLESS", "TK_OP_REL_EQGREATER", "TK_OP_REL_EQ",
  "TK_OP_REL_DIFF", "TK_OP_LOGIC_AND", "TK_OP_LOGIC_OR", "TK_OP_LOGIC_NOT",
  "TK_OP_BIN_AND", "TK_OP_BIN_OR", "TK_OP_BIN_XOR", "TK_OP_BIN_NOT",
  "TK_OP_BIN_SHIFTR", "TK_OP_BIN_SHIFTL", "TK_ASSIGN", "TK_RETURN",
  "TK_OP_MOD", "'('", "')'", "'{'", "'}'", "';'", "','", "$accept",
  "Begin", "BLOCK", "RETURN", "DECLARATION", "TYPE", "COMMANDS", "COMMAND",
  "E", "ATRIBUITION", "ARITHMETIC_OPERATION", "RELATIONAL_OPERATION",
  "BIN_OPERATION", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    40,    41,
     123,   125,    59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    64,    64,    64,    64,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    66,    66
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     5,     0,     3,     0,     3,     5,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     3,     3,     4,     4,     3,     3,     2,     0,     2,
       2,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     5,    38,
       2,     3,    44,    45,    46,    47,    48,    49,    50,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    26,    27,
       0,     0,     5,    38,     0,    51,     0,    19,    21,     0,
       0,    20,    22,     0,     0,    23,    24,    25,     0,    40,
       0,    10,     7,    37,    53,    54,    56,    55,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      57,    39,     0,     0,     0,    52,    28,    30,    35,    29,
      31,    36,    32,     8,     0,     0,     0,    41,    42,    43,
      33,    34,     0,    11,     0,     4,     9,     6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    10,    86,    30,    31,    32,    33,    34,    35,
      72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int8 yypact[] =
{
      -1,    14,    27,   -22,   -41,   -15,   -20,   -10,   -10,    76,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,     1,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,     9,    20,    15,    26,
     -40,    38,   -10,    76,   -24,   -41,    97,   -41,   -41,    36,
      24,   -41,   -41,    37,    53,   -41,   -41,   -41,    39,   -41,
      41,    10,    21,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,    97,    97,    97,    31,   -41,   -41,    54,   -41,
     -41,    62,   -41,    40,    97,    83,    55,    31,    31,    31,
     -41,   -41,    97,    31,    35,   -41,    31,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,    13,   -41,   -41,   -41,    74,   -41,   -36,   -41,
     -41,   -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      75,     6,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    49,    50,     1,    64,    65,    66,    67,    68,
      69,    11,    37,    70,    38,     3,     5,     4,    71,     8,
      45,    39,    40,    41,     7,    42,    87,    88,    89,    77,
       9,    46,    43,    44,    47,    52,    36,    78,    93,    48,
      51,    76,    79,    83,    82,    84,    96,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    85,    80,    90,
      64,    65,    66,    67,    68,    69,    81,    91,    70,    12,
      13,    14,    15,    16,    17,    92,    94,    97,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      12,    13,    14,    15,    16,    17,    95,    53,     0,    18
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-41))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      36,    16,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    52,    53,    15,    39,    40,    41,    42,    43,
      44,     8,    13,    47,    15,    11,    48,     0,    52,    49,
      15,    22,    23,    13,    49,    15,    72,    73,    74,    15,
      50,    15,    22,    23,    18,    32,    45,    23,    84,    23,
      12,    15,    15,    12,    15,    45,    92,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    46,    15,    15,
      39,    40,    41,    42,    43,    44,    23,    15,    47,     3,
       4,     5,     6,     7,     8,    45,     3,    52,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       3,     4,     5,     6,     7,     8,    51,    33,    -1,    12
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    55,    11,     0,    48,    16,    49,    49,    50,
      56,    56,     3,     4,     5,     6,     7,     8,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      58,    59,    60,    61,    62,    63,    45,    13,    15,    22,
      23,    13,    15,    22,    23,    15,    15,    18,    23,    52,
      53,    12,    56,    60,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    39,    40,    41,    42,    43,    44,
      47,    52,    64,    65,    66,    62,    15,    15,    23,    15,
      15,    23,    15,    12,    45,    46,    57,    62,    62,    62,
      15,    15,    45,    62,     3,    51,    62,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 63 "sintatica.y"
    {
				cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()"  << (yyvsp[(5) - (5)]).traduction << endl; 
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 68 "sintatica.y"
    {
			cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)"  << (yyvsp[(6) - (6)]).traduction << endl;
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 74 "sintatica.y"
    {
				//$$.traduction = "\n{\n" + $2.traduction + $3.traduction + $4.traduction + "\n}";
				(yyval).traduction = "\n{\n" + declarations + (yyvsp[(2) - (5)]).traduction + (yyvsp[(3) - (5)]).traduction + (yyvsp[(4) - (5)]).traduction + "\n}";
			}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 79 "sintatica.y"
    {
				(yyval).traduction = "";
			}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 85 "sintatica.y"
    {
				(yyval).traduction = "\n\t" + (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + ";";
			}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 89 "sintatica.y"
    {
				(yyval).traduction = "";
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 96 "sintatica.y"
    {

				if(IDMap.find((yyvsp[(3) - (3)]).label) == IDMap.end())
				{
					IDMap[(yyvsp[(3) - (3)]).label].label = generateLabel();
					IDMap[(yyvsp[(3) - (3)]).label].type = (yyvsp[(1) - (3)]).type;
				}

				declarations += "\t" + IDMap[(yyvsp[(3) - (3)]).label].type + " " + IDMap[(yyvsp[(3) - (3)]).label].label + ";\n";

				(yyval).label = IDMap[(yyvsp[(3) - (3)]).label].label;
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction;
				(yyval).type = IDMap[(yyvsp[(3) - (3)]).label].type;
			}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 111 "sintatica.y"
    {
				string cast = "";
				string atribuition = "";

				if(IDMap.find((yyvsp[(3) - (5)]).label) == IDMap.end())
				{
					IDMap[(yyvsp[(3) - (5)]).label].label = generateLabel();
					IDMap[(yyvsp[(3) - (5)]).label].type = (yyvsp[(1) - (5)]).type;
				}

				if (IDMap[(yyvsp[(5) - (5)]).label].type != IDMap[(yyvsp[(3) - (5)]).label].type)
					cast = "(" + IDMap[(yyvsp[(3) - (5)]).label].type + ") ";

				atribuition = (yyvsp[(5) - (5)]).traduction + "\t" + IDMap[(yyvsp[(3) - (5)]).label].label + " = " + cast + (yyvsp[(5) - (5)]).label + ";\n";
				declarations += "\t" + IDMap[(yyvsp[(3) - (5)]).label].type + " " + IDMap[(yyvsp[(3) - (5)]).label].label + ";\n";

				(yyval).label = IDMap[(yyvsp[(3) - (5)]).label].label;
				(yyval).traduction = "\n" + atribuition + "\n";
				(yyval).type = IDMap[(yyvsp[(3) - (5)]).label].type;	
							
			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 133 "sintatica.y"
    {

				if(IDMap.find((yyvsp[(2) - (2)]).label) == IDMap.end())
				{
					IDMap[(yyvsp[(2) - (2)]).label].label = generateLabel();
					IDMap[(yyvsp[(2) - (2)]).label].type = (yyvsp[(1) - (2)]).traduction;
				}

				declarations += "\t" + IDMap[(yyvsp[(2) - (2)]).label].type + " " + IDMap[(yyvsp[(2) - (2)]).label].label + ";\n";

				(yyval).label = IDMap[(yyvsp[(2) - (2)]).label].label;
				(yyval).traduction = "";
				(yyval).type = IDMap[(yyvsp[(2) - (2)]).label].type;

			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 149 "sintatica.y"
    {
				string cast = "";
				string atribuition = "";

				if(IDMap.find((yyvsp[(2) - (4)]).label) == IDMap.end())
				{
					IDMap[(yyvsp[(2) - (4)]).label].label = generateLabel();
					IDMap[(yyvsp[(2) - (4)]).label].type = (yyvsp[(1) - (4)]).traduction;
				}

				if (IDMap[(yyvsp[(4) - (4)]).label].type != IDMap[(yyvsp[(2) - (4)]).label].type)
					cast = "(" + IDMap[(yyvsp[(2) - (4)]).label].type + ") ";

				atribuition = (yyvsp[(4) - (4)]).traduction + "\t" + IDMap[(yyvsp[(2) - (4)]).label].label + " = " + cast + (yyvsp[(4) - (4)]).label + ";\n";


				declarations += "\t" + IDMap[(yyvsp[(2) - (4)]).label].type + " " + IDMap[(yyvsp[(2) - (4)]).label].label + ";\n";

				(yyval).label = IDMap[(yyvsp[(2) - (4)]).label].label;
				(yyval).traduction = "\n" + atribuition + "\n";
				(yyval).type = IDMap[(yyvsp[(2) - (4)]).label].type;

			}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 178 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 182 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 186 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 190 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 194 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 198 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 202 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 206 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (1)]).traduction + " int";
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 210 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
			}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 214 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 218 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
			}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 222 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
			}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 226 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
			}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 230 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (4)]).traduction + " " + (yyvsp[(2) - (4)]).traduction + " " + (yyvsp[(3) - (4)]).traduction + " " + (yyvsp[(4) - (4)]).traduction;
			}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 234 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (4)]).traduction + " " + (yyvsp[(2) - (4)]).traduction + " " + (yyvsp[(3) - (4)]).traduction + " " + (yyvsp[(4) - (4)]).traduction;
			}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 238 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction + " int";
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 242 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction + " int";
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 248 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction + "\n" + (yyvsp[(2) - (2)]).traduction;
			}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 252 "sintatica.y"
    {
				(yyval).traduction = "";
			}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 258 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (2)]).traduction;;
			}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 265 "sintatica.y"
    {
				id_struct* keyOperating;
				id_struct* weakOperating;
				id_struct* strongOperating;

				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;

				(yyval).traduction = (yyvsp[(1) - (3)]).traduction + (yyvsp[(3) - (3)]).traduction;

				if(IDMap[(yyvsp[(1) - (3)]).label].type == IDMap[(yyvsp[(3) - (3)]).label].type)
				{
					IDMap[(yyval).label].type = IDMap[(yyvsp[(1) - (3)]).label].type;
					(yyval).traduction += "\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).label + ";\n";
					declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
				}
				else
				{
					keyOperating = defineKeyOperating(IDMap[(yyvsp[(1) - (3)]).label], IDMap[(yyvsp[(3) - (3)]).label]);

					IDMap[keyOperating->label].label = keyOperating->label;
					IDMap[keyOperating->label].type = keyOperating->type;
					IDMap[(yyval).label].type = keyOperating->type;


					if(keyOperating->type == IDMap[(yyvsp[(1) - (3)]).label].type)
					{
						weakOperating = &(IDMap[(yyvsp[(3) - (3)]).label]);
						strongOperating = &(IDMap[(yyvsp[(1) - (3)]).label]);
	
						(yyval).traduction += "\t" + keyOperating->label + " = (" + keyOperating->type + ") " + weakOperating->label + ";\n";
						(yyval).traduction += "\t" + (yyval).label + " = " + keyOperating->label + " " + (yyvsp[(2) - (3)]).traduction + " " + strongOperating->label + ";\n";
					}
					else
					{
						weakOperating = &(IDMap[(yyvsp[(1) - (3)]).label]);
						strongOperating = &(IDMap[(yyvsp[(3) - (3)]).label]);

						(yyval).traduction += "\t" + keyOperating->label + " = (" + keyOperating->type + ") " + weakOperating->label + ";\n";
						(yyval).traduction += "\t" + (yyval).label + " = " + strongOperating->label + " " + (yyvsp[(2) - (3)]).traduction + " " + keyOperating->label + ";\n";
					}

					declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
					declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
				}

			}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 313 "sintatica.y"
    {
				

			}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 318 "sintatica.y"
    {


			}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 323 "sintatica.y"
    {
				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;
				IDMap[(yyval).label].type = "int";

				(yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";

				declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
			}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 333 "sintatica.y"
    {
				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;
				IDMap[(yyval).label].type = "float";

				(yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";

				declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
			}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 343 "sintatica.y"
    {
				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;
				IDMap[(yyval).label].type = "float"; //poderia ser double

				(yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";

				declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
			}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 353 "sintatica.y"
    {
				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;
				IDMap[(yyval).label].type = "char";

				(yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";				

				declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
			}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 363 "sintatica.y"
    {
				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;
				IDMap[(yyval).label].type = "string";

				(yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";				

				declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
			}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 373 "sintatica.y"
    {
				(yyval).label = generateLabel();
				IDMap[(yyval).label].label = (yyval).label;
				IDMap[(yyval).label].type = "bool";

				(yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";				

				declarations += "\t" + IDMap[(yyval).label].type + " " + IDMap[(yyval).label].label + ";\n";
			}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 383 "sintatica.y"
    {
				//if(IDMap.find($1.label) == IDMap.end())	
					//IDMap[$1.label] = generateLabel();

				(yyval).label = IDMap[(yyvsp[(1) - (1)]).label].label;
				(yyval).traduction = "";
			}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 391 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
				(yyval).label = (yyvsp[(1) - (1)]).label;
			}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 399 "sintatica.y"
    {
				if(IDMap.find((yyvsp[(1) - (3)]).label) == IDMap.end())	
					IDMap[(yyvsp[(1) - (3)]).label].label = generateLabel();

				string cast = "";

				if (IDMap[(yyvsp[(3) - (3)]).label].type != IDMap[(yyvsp[(1) - (3)]).label].type)
					cast = "(" + IDMap[(yyvsp[(1) - (3)]).label].type + ") ";

				(yyval).label = IDMap[(yyvsp[(1) - (3)]).label].label;
				(yyval).traduction = (yyvsp[(3) - (3)]).traduction + "\t" + (yyval).label + " = " + cast + (yyvsp[(3) - (3)]).label + ";\n"; 
			}
    break;



/* Line 1806 of yacc.c  */
#line 2104 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 444 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}

string generateLabel()
{
	static int counter = 0;
	stringstream label;

	label << "_temp" << counter++;

	return label.str();
}					

id_struct* defineKeyOperating(id_struct op1, id_struct op2)
{
	id_struct* keyOperating = new id_struct;
	
	keyOperating->label = generateLabel();

	if((op1.type == "int") && (op2.type == "int"))
	{
		keyOperating->type = "int";
	}
	else if((op1.type == "float") && (op2.type == "float"))
	{
		keyOperating->type = "float";
	}
	else if((op1.type == "char") && (op2.type == "char"))
	{
		keyOperating->type = "char";
	}
	else if((op1.type == "string") && (op2.type == "string"))
	{
		keyOperating->type = "string";
	}
	else if((op1.type == "bool") && (op2.type == "bool"))
	{
		keyOperating->type = "bool";
	}
	else if ((op1.type == "int") && (op2.type == "float"))
	{
		keyOperating->type = "float";
	}
	else if ((op1.type == "float") && (op2.type == "int"))
	{
		keyOperating->type = "float";
	}
	else if ((op1.type == "int") && (op2.type == "char"))
	{
		keyOperating->type = "int";
	}
	else if ((op1.type == "char") && (op2.type == "int"))
	{
		keyOperating->type = "int";
	}
	else if ((op1.type == "int") && (op2.type == "string"))
	{
		keyOperating->type = "string";
	}
	else if ((op1.type == "string") && (op2.type == "int"))
	{
		keyOperating->type = "string";
	}
	else if ((op1.type == "int") && (op2.type == "bool"))
	{
		keyOperating->type = "bool";
	}
	else if ((op1.type == "bool") && (op2.type == "int"))
	{
		keyOperating->type = "bool";
	}

	return keyOperating;
}

