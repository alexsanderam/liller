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

typedef struct
{
        string type;
        string modifier;
        string label;
} id_struct;

struct args
{
        string label;
        string traduction;
        string type; /*auxiliar*/
        string modifier; /*auxiliar*/
};

typedef struct opStruct
{
        string op1Type;
        string op2Type;
        string sOperator;

        bool operator ==(const opStruct &ops) const
        {
                return ((op1Type == ops.op1Type) && (op2Type == ops.op2Type) && (sOperator == ops.sOperator));
        };


        bool operator <(const opStruct &ops) const
        {

                return ((op1Type < ops.op1Type) || ((op1Type == ops.op1Type) && (op2Type < ops.op2Type)) || (((op1Type == ops.op1Type) && (op2Type == ops.op2Type)) && (sOperator < ops.sOperator)));
        };

} operation_struct;


map<string, id_struct> IDMap;
map<operation_struct, string> operationsMap;

string declarations = "";

bool error = false; /*utilizado para identificar se tem algum erro de compilação ou não*/

int yylex(void);
void yyerror(string);

string generateLabel();
string verifyResultOperation(string, string, string);
id_struct* defineKeyOperating(string, string, string, string);
string verifyStrongType(string, string);
void loadOpearationsMap(void);



/* Line 268 of yacc.c  */
#line 136 "y.tab.c"

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
     TK_MAIN = 264,
     TK_ID = 265,
     TK_TYPE_CHAR = 266,
     TK_TYPE_STRING = 267,
     TK_TYPE_INT = 268,
     TK_TYPE_VOID = 269,
     TK_TYPE_FLOAT = 270,
     TK_TYPE_DOUBLE = 271,
     TK_TYPE_BOOL = 272,
     TK_MODIFIER_UNSIGNED = 273,
     TK_MODIFIER_SIGNED = 274,
     TK_MODIFIER_SHORT = 275,
     TK_MODIFIER_LONG = 276,
     TK_END = 277,
     TK_ERROR = 278,
     TK_OP_SUM = 279,
     TK_OP_SUB = 280,
     TK_OP_MUL = 281,
     TK_OP_DIV = 282,
     TK_OP_MOD = 283,
     TK_OP_REL_LESS = 284,
     TK_OP_REL_GREATER = 285,
     TK_OP_REL_EQLESS = 286,
     TK_OP_REL_EQGREATER = 287,
     TK_OP_REL_EQ = 288,
     TK_OP_REL_DIFF = 289,
     TK_OP_LOGIC_AND = 290,
     TK_OP_LOGIC_OR = 291,
     TK_OP_LOGIC_NOT = 292,
     TK_OP_BIN_AND = 293,
     TK_OP_BIN_OR = 294,
     TK_OP_BIN_XOR = 295,
     TK_OP_BIN_NOT = 296,
     TK_OP_BIN_SHIFTR = 297,
     TK_OP_BIN_SHIFTL = 298,
     TK_ASSIGN = 299,
     TK_RETURN = 300,
     TK_COUT = 301
   };
#endif
/* Tokens.  */
#define TK_INT 258
#define TK_FLOAT 259
#define TK_SCIENTIFIC 260
#define TK_CHAR 261
#define TK_STRING 262
#define TK_BOOL 263
#define TK_MAIN 264
#define TK_ID 265
#define TK_TYPE_CHAR 266
#define TK_TYPE_STRING 267
#define TK_TYPE_INT 268
#define TK_TYPE_VOID 269
#define TK_TYPE_FLOAT 270
#define TK_TYPE_DOUBLE 271
#define TK_TYPE_BOOL 272
#define TK_MODIFIER_UNSIGNED 273
#define TK_MODIFIER_SIGNED 274
#define TK_MODIFIER_SHORT 275
#define TK_MODIFIER_LONG 276
#define TK_END 277
#define TK_ERROR 278
#define TK_OP_SUM 279
#define TK_OP_SUB 280
#define TK_OP_MUL 281
#define TK_OP_DIV 282
#define TK_OP_MOD 283
#define TK_OP_REL_LESS 284
#define TK_OP_REL_GREATER 285
#define TK_OP_REL_EQLESS 286
#define TK_OP_REL_EQGREATER 287
#define TK_OP_REL_EQ 288
#define TK_OP_REL_DIFF 289
#define TK_OP_LOGIC_AND 290
#define TK_OP_LOGIC_OR 291
#define TK_OP_LOGIC_NOT 292
#define TK_OP_BIN_AND 293
#define TK_OP_BIN_OR 294
#define TK_OP_BIN_XOR 295
#define TK_OP_BIN_NOT 296
#define TK_OP_BIN_SHIFTR 297
#define TK_OP_BIN_SHIFTL 298
#define TK_ASSIGN 299
#define TK_RETURN 300
#define TK_COUT 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 270 "y.tab.c"

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
#define YYLAST   555

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    16,    22,    23,    27,    28,    32,
      38,    41,    46,    48,    50,    52,    54,    56,    58,    60,
      63,    66,    69,    72,    75,    78,    81,    83,    85,    89,
      93,    97,   101,   105,   110,   115,   119,   123,   125,   127,
     129,   131,   134,   137,   140,   143,   145,   147,   149,   151,
     153,   156,   157,   160,   163,   166,   170,   172,   174,   176,
     178,   180,   182,   184,   188,   190,   192,   194,   198,   202,
     205,   207,   209,   211,   213,   215,   217,   221,   225,   227,
     229,   231,   233,   237,   240,   242,   244,   248,   252,   254,
     256,   258,   260,   264,   268,   270,   272,   274,   276,   278,
     280,   282,   284,   286,   288,   290,   292,   294,   296,   298,
     300,   302,   304
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    13,     9,    47,    14,    48,    55,    -1,
      13,     9,    47,    48,    55,    -1,    49,    61,    55,    56,
      50,    -1,    -1,    45,    63,    51,    -1,    -1,    57,    52,
      10,    -1,    57,    52,    10,    44,    63,    -1,    58,    10,
      -1,    58,    10,    44,    63,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    11,    -1,    19,    11,    -1,    18,    13,    -1,    19,
      13,    -1,    20,    13,    -1,    21,    13,    -1,    21,    16,
      -1,    20,    -1,    21,    -1,    18,    20,    13,    -1,    19,
      20,    13,    -1,    18,    21,    13,    -1,    19,    21,    13,
      -1,    21,    21,    13,    -1,    18,    21,    21,    13,    -1,
      19,    21,    21,    13,    -1,    18,    21,    21,    -1,    19,
      21,    21,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,    60,     3,    -1,    60,     4,    -1,    60,     5,    -1,
      60,     6,    -1,     7,    -1,     8,    -1,    10,    -1,    24,
      -1,    25,    -1,    62,    61,    -1,    -1,    63,    51,    -1,
      57,    51,    -1,    79,    51,    -1,    47,    63,    48,    -1,
      64,    -1,    66,    -1,    72,    -1,    68,    -1,    70,    -1,
      59,    -1,    74,    -1,    65,    75,    65,    -1,    59,    -1,
      64,    -1,    70,    -1,    47,    63,    48,    -1,    67,    77,
      67,    -1,    37,    66,    -1,    59,    -1,    66,    -1,    72,
      -1,    70,    -1,    68,    -1,    64,    -1,    47,    63,    48,
      -1,    69,    78,    69,    -1,    59,    -1,    68,    -1,    70,
      -1,    64,    -1,    47,    63,    48,    -1,    41,    71,    -1,
      59,    -1,    70,    -1,    47,    63,    48,    -1,    73,    76,
      73,    -1,    59,    -1,    70,    -1,    68,    -1,    64,    -1,
      47,    63,    48,    -1,    10,    44,    63,    -1,    24,    -1,
      25,    -1,    27,    -1,    26,    -1,    28,    -1,    29,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      36,    -1,    35,    -1,    38,    -1,    39,    -1,    40,    -1,
      42,    -1,    43,    -1,    46,    47,    63,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   106,   117,   122,   129,   134,   141,   167,
     202,   228,   268,   274,   280,   286,   292,   298,   304,   310,
     316,   322,   328,   334,   340,   346,   352,   358,   364,   370,
     376,   382,   388,   394,   400,   406,   412,   422,   433,   443,
     454,   467,   478,   488,   499,   512,   522,   532,   545,   545,
     549,   554,   560,   561,   562,   566,   573,   580,   587,   594,
     601,   608,   615,   625,   683,   690,   697,   704,   715,   726,
     740,   747,   754,   761,   768,   775,   782,   792,   852,   859,
     866,   873,   880,   891,   908,   915,   922,   933,   993,  1000,
    1007,  1014,  1021,  1032,  1058,  1058,  1058,  1058,  1058,  1062,
    1062,  1062,  1062,  1062,  1062,  1067,  1067,  1072,  1072,  1072,
    1072,  1072,  1076
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_INT", "TK_FLOAT", "TK_SCIENTIFIC",
  "TK_CHAR", "TK_STRING", "TK_BOOL", "TK_MAIN", "TK_ID", "TK_TYPE_CHAR",
  "TK_TYPE_STRING", "TK_TYPE_INT", "TK_TYPE_VOID", "TK_TYPE_FLOAT",
  "TK_TYPE_DOUBLE", "TK_TYPE_BOOL", "TK_MODIFIER_UNSIGNED",
  "TK_MODIFIER_SIGNED", "TK_MODIFIER_SHORT", "TK_MODIFIER_LONG", "TK_END",
  "TK_ERROR", "TK_OP_SUM", "TK_OP_SUB", "TK_OP_MUL", "TK_OP_DIV",
  "TK_OP_MOD", "TK_OP_REL_LESS", "TK_OP_REL_GREATER", "TK_OP_REL_EQLESS",
  "TK_OP_REL_EQGREATER", "TK_OP_REL_EQ", "TK_OP_REL_DIFF",
  "TK_OP_LOGIC_AND", "TK_OP_LOGIC_OR", "TK_OP_LOGIC_NOT", "TK_OP_BIN_AND",
  "TK_OP_BIN_OR", "TK_OP_BIN_XOR", "TK_OP_BIN_NOT", "TK_OP_BIN_SHIFTR",
  "TK_OP_BIN_SHIFTL", "TK_ASSIGN", "TK_RETURN", "TK_COUT", "'('", "')'",
  "'{'", "'}'", "';'", "','", "$accept", "Begin", "BLOCK", "RETURN",
  "DECLARATION", "TYPE", "TERMINAL", "SIGNAL", "COMMANDS", "COMMAND", "E",
  "ARITHMETIC_E", "ARITHMETIC_OPERAND", "LOGIC_E", "LOGIC_OPERAND",
  "BIN_E", "BIN_OPERAND", "BITWISE_E", "BITWISE_OPERAND", "RELATIONAL_E",
  "RELATIONAL_OPERAND", "ATRIBUITION", "ARITHMETIC_OPERATION",
  "RELATIONAL_OPERATION", "LOGIC_OPERATION", "BIN_OPERATION", "COUT", 0
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
     295,   296,   297,   298,   299,   300,   301,    40,    41,   123,
     125,    59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    65,    65,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    69,    69,
      69,    69,    69,    70,    71,    71,    71,    72,    73,    73,
      73,    73,    73,    74,    75,    75,    75,    75,    75,    76,
      76,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     5,     0,     3,     0,     3,     5,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     3,     3,     4,     4,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       2,     0,     2,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     5,     5,    51,
       3,     2,    37,    38,    39,    40,    45,    46,    47,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    26,    27,
      48,    49,     0,     0,     0,     0,     0,     0,    88,     0,
       5,    51,     0,    91,     0,    57,     0,    90,     0,    89,
      58,     0,    62,     0,     0,    19,    21,     0,     0,    20,
      22,     0,     0,    23,    24,    25,     0,    47,     0,    88,
      91,    69,    90,    89,    72,     0,    84,    85,    83,     0,
       0,    53,     0,    10,    41,    42,    43,    44,     7,    50,
      52,    94,    95,    97,    96,    98,     0,   106,   105,     0,
     107,   108,   109,   110,   111,     0,    99,   100,   101,   102,
     103,   104,     0,    54,    93,    28,    30,    35,    29,    31,
      36,    32,     0,     0,     0,    92,     8,     0,     0,     0,
       0,    64,    65,    63,    66,    71,    68,     0,    78,    81,
      79,    77,    80,     0,    64,    65,    79,    66,    87,    33,
      34,    92,    86,   112,     0,    11,     0,     4,     0,     0,
       0,     9,     6,    67,    82,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,   129,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    78,    50,
      51,    52,    96,   112,    99,   105,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -36
static const yytype_int16 yypact[] =
{
      -4,    23,    12,    -8,   -36,    -7,     0,     6,     6,    10,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,   -36,    14,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,    69,    94,    53,    29,
     -36,   -36,    93,   141,    24,   117,    36,    74,   191,   181,
       6,    10,    40,   221,    85,    96,   120,   413,    21,   250,
     174,   162,   -36,    43,   117,   -36,   -36,    91,    25,   -36,
     -36,   103,    41,   -36,   -36,   -36,   113,   -36,   117,   279,
     308,   -36,   431,   337,   -36,   117,   -36,   -36,   -36,   117,
      58,   -36,   118,    89,   -36,   -36,   -36,   -36,    84,   -36,
     -36,   -36,   -36,   -36,   -36,   -36,   165,   -36,   -36,    93,
     -36,   -36,   -36,   -36,   -36,   173,   -36,   -36,   -36,   -36,
     -36,   -36,   197,   -36,   -36,   -36,   -36,   130,   -36,   -36,
     137,   -36,   104,   105,   109,   366,   123,   117,   117,   124,
     117,   -36,   -36,    85,   -36,   -36,   120,   117,   111,   135,
     -36,    21,   226,   117,   449,   467,     1,   485,   -36,   -36,
     -36,   395,   -36,   -36,   117,   -36,   148,   -36,   160,   163,
     175,   -36,   -36,   -36,   255,   503
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,     3,   -36,   -36,   -36,   -31,   -36,   172,   -36,
     -35,   -27,   128,   -24,   126,   -26,   127,   -29,   -36,   -22,
     116,   -36,   -36,   -36,   -36,   -36,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -93
static const yytype_int16 yytable[] =
{
      80,    69,    76,    73,    77,    70,    72,     6,    71,     1,
      74,    11,     4,    12,    13,    14,    15,    16,    17,   114,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     3,   122,    30,    31,   -90,   -90,   116,     5,
     123,     7,    64,    88,   124,    65,   117,    32,     8,   -90,
      66,    33,   -90,   -90,   119,     9,    34,    35,    54,   100,
     101,   102,   120,   103,   104,   131,    63,   134,    69,   132,
      73,    79,    70,    72,   138,   135,   142,    74,   139,   140,
      55,   144,    56,   147,    83,   145,   146,    81,    82,    57,
      58,    90,   155,   156,   113,   158,    12,    13,    14,    15,
      16,    17,   159,    67,   115,    59,   125,    60,   160,    91,
      92,    93,    94,    95,    61,    62,   118,    30,    31,   161,
      12,    13,    14,    15,    16,    17,   121,    18,   126,   128,
      32,   -71,   -71,   127,    33,   -64,   -64,   -64,   -64,   -64,
      68,    30,    31,   149,    12,    13,    14,    15,    16,    17,
     150,    67,   151,   152,    32,    97,    98,   153,    33,   -65,
     -65,   -65,   -65,   -65,    35,    30,    31,   154,    12,    13,
      14,    15,    16,    17,   157,    67,    12,    13,    14,    15,
      16,    17,    33,    67,    84,    85,    86,    87,    75,    30,
      31,   106,   107,   108,   109,   110,   111,    30,    31,   162,
      12,    13,    14,    15,    16,    17,    33,    67,   163,   -72,
     -72,   164,   130,    89,    33,   -64,   -64,   -64,   -64,   -64,
     137,    30,    31,   165,   133,   136,   -70,   -70,   148,   -78,
     -78,   -78,   141,   -78,   -78,     0,     0,     0,    33,   -61,
       0,     0,   -61,   -61,   143,   -65,   -65,   -65,   -65,   -65,
     -66,   -66,   -66,   -66,   -66,     0,   -75,   -75,     0,   -81,
     -81,   -81,     0,   -81,   -81,     0,     0,     0,     0,   -56,
       0,     0,   -56,   -56,   -66,   -66,   -66,   -66,   -66,   -67,
     -67,   -67,   -67,   -67,     0,   -73,   -73,     0,   -80,   -80,
     -80,     0,   -80,   -80,     0,     0,     0,     0,   -60,     0,
       0,   -60,   -60,   -64,   -64,   -64,   -64,   -64,     0,     0,
       0,     0,     0,     0,   -70,   -70,     0,   -78,   -78,   -78,
       0,   -78,   -78,     0,     0,     0,     0,   -70,     0,     0,
     -70,   -70,   -65,   -65,   -65,   -65,   -65,     0,     0,     0,
       0,     0,     0,   -75,   -75,     0,   -81,   -81,   -81,     0,
     -81,   -81,     0,     0,     0,     0,   -75,     0,     0,   -75,
     -75,   -66,   -66,   -66,   -66,   -66,     0,     0,     0,     0,
       0,     0,   -73,   -73,     0,   -80,   -80,   -80,     0,   -80,
     -80,     0,     0,     0,     0,   -73,     0,     0,   -73,   -73,
     -67,   -67,   -67,   -67,   -67,     0,     0,     0,     0,     0,
       0,   -76,   -76,     0,   -82,   -82,   -82,     0,   -82,   -82,
       0,     0,     0,     0,   -55,     0,     0,   -55,   -55,   -67,
     -67,   -67,   -67,   -67,     0,     0,     0,     0,     0,     0,
     -76,   -76,     0,   -82,   -82,   -82,     0,   -82,   -82,     0,
       0,     0,     0,   -76,     0,     0,   -76,   -76,   -74,   -74,
       0,   -79,   -79,   -79,     0,   -79,   -79,     0,     0,     0,
       0,   -59,     0,     0,   -59,   -59,   -74,   -74,     0,   -79,
     -79,   -79,     0,   -79,   -79,     0,     0,     0,     0,   -74,
       0,     0,   -74,   -74,   -88,   -88,     0,   -78,   -78,   -78,
       0,   -78,   -78,     0,     0,     0,     0,   -88,     0,     0,
     -88,   -88,   -91,   -91,     0,   -81,   -81,   -81,     0,   -81,
     -81,     0,     0,     0,     0,   -91,     0,     0,   -91,   -91,
     -89,   -89,     0,   -80,   -80,   -80,     0,   -80,   -80,     0,
       0,     0,     0,   -89,     0,     0,   -89,   -89,   -92,   -92,
       0,   -82,   -82,   -82,     0,   -82,   -82,     0,     0,     0,
       0,   -92,     0,     0,   -92,   -92
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-36))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      35,    32,    33,    32,    33,    32,    32,    14,    32,    13,
      32,     8,     0,     3,     4,     5,     6,     7,     8,    54,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     9,    68,    24,    25,    35,    36,    13,    47,
      75,    48,    13,    40,    79,    16,    21,    37,    48,    48,
      21,    41,    51,    52,    13,    49,    46,    47,    44,    38,
      39,    40,    21,    42,    43,    96,    13,    96,    99,    96,
      99,    47,    99,    99,   105,    99,   105,    99,   105,   105,
      11,   112,    13,   112,    10,   112,   112,    51,    52,    20,
      21,    51,   127,   128,    51,   130,     3,     4,     5,     6,
       7,     8,   137,    10,    13,    11,    48,    13,   143,    24,
      25,    26,    27,    28,    20,    21,    13,    24,    25,   154,
       3,     4,     5,     6,     7,     8,    13,    10,    10,    45,
      37,    35,    36,    44,    41,    24,    25,    26,    27,    28,
      47,    24,    25,    13,     3,     4,     5,     6,     7,     8,
      13,    10,    48,    48,    37,    35,    36,    48,    41,    24,
      25,    26,    27,    28,    47,    24,    25,    44,     3,     4,
       5,     6,     7,     8,    50,    10,     3,     4,     5,     6,
       7,     8,    41,    10,     3,     4,     5,     6,    47,    24,
      25,    29,    30,    31,    32,    33,    34,    24,    25,    51,
       3,     4,     5,     6,     7,     8,    41,    10,    48,    35,
      36,    48,    47,    41,    41,    24,    25,    26,    27,    28,
      47,    24,    25,    48,    96,    99,    35,    36,   112,    38,
      39,    40,   105,    42,    43,    -1,    -1,    -1,    41,    48,
      -1,    -1,    51,    52,    47,    24,    25,    26,    27,    28,
      24,    25,    26,    27,    28,    -1,    35,    36,    -1,    38,
      39,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    24,    25,    26,    27,    28,    24,
      25,    26,    27,    28,    -1,    35,    36,    -1,    38,    39,
      40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    51,    52,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    38,    39,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    38,    39,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
      52,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    38,    39,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    38,    39,    40,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    38,    39,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    35,    36,
      -1,    38,    39,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52,    35,    36,    -1,    38,
      39,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    51,    52,    35,    36,    -1,    38,    39,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      51,    52,    35,    36,    -1,    38,    39,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      35,    36,    -1,    38,    39,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    51,    52,    35,    36,
      -1,    38,    39,    40,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    54,     9,     0,    47,    14,    48,    48,    49,
      55,    55,     3,     4,     5,     6,     7,     8,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      24,    25,    37,    41,    46,    47,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      72,    73,    74,    79,    44,    11,    13,    20,    21,    11,
      13,    20,    21,    13,    13,    16,    21,    10,    47,    59,
      64,    66,    68,    70,    72,    47,    59,    70,    71,    47,
      63,    51,    52,    10,     3,     4,     5,     6,    55,    61,
      51,    24,    25,    26,    27,    28,    75,    35,    36,    77,
      38,    39,    40,    42,    43,    78,    29,    30,    31,    32,
      33,    34,    76,    51,    63,    13,    13,    21,    13,    13,
      21,    13,    63,    63,    63,    48,    10,    44,    45,    56,
      47,    59,    64,    65,    70,    66,    67,    47,    59,    64,
      68,    69,    70,    47,    59,    64,    68,    70,    73,    13,
      13,    48,    48,    48,    44,    63,    63,    50,    63,    63,
      63,    63,    51,    48,    48,    48
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
#line 100 "sintatica.y"
    {
                                if(!error)
                                        cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\n int main(void)" << (yyvsp[(6) - (6)]).traduction << endl;
                                else
                                        exit(1);
                        }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 107 "sintatica.y"
    {
                                if(!error)                                
                                        cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\nusing namespace std;\nint main()" << (yyvsp[(5) - (5)]).traduction << endl;
                                else
                                        exit(1);
                        }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 118 "sintatica.y"
    {
                                (yyval).traduction = "\n{\n" + declarations + (yyvsp[(2) - (5)]).traduction + (yyvsp[(3) - (5)]).traduction + (yyvsp[(4) - (5)]).traduction + "\n}";
                        }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 122 "sintatica.y"
    {
                                (yyval).traduction = "";
                        }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 130 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(2) - (3)]).traduction + "\n\t" + (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).label + ";";
                        }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 134 "sintatica.y"
    {
                                (yyval).traduction = "";
                        }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 142 "sintatica.y"
    {

                                if(IDMap.find((yyvsp[(3) - (3)]).label) == IDMap.end())
                                {
                                        IDMap[(yyvsp[(3) - (3)]).label].label = generateLabel();
                                        IDMap[(yyvsp[(3) - (3)]).label].type = (yyvsp[(1) - (3)]).type;
                                        IDMap[(yyvsp[(3) - (3)]).label].modifier = (yyvsp[(1) - (3)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(3) - (3)]).label + "' already declared.");
        
                                
                                if(IDMap[(yyvsp[(3) - (3)]).label].modifier != "")
                                        declarations += "\t" + IDMap[(yyvsp[(3) - (3)]).label].modifier + " ";
                                else
                                        declarations += "\t";

                                declarations += IDMap[(yyvsp[(3) - (3)]).label].type + " " + IDMap[(yyvsp[(3) - (3)]).label].label + ";\n";

                                (yyval).label = IDMap[(yyvsp[(3) - (3)]).label].label;
                                (yyval).traduction = (yyvsp[(1) - (3)]).traduction;
                                (yyval).type = IDMap[(yyvsp[(3) - (3)]).label].type;
                                (yyval).modifier = IDMap[(yyvsp[(3) - (3)]).label].modifier;

                        }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 168 "sintatica.y"
    {
                                string cast = "";
                                string atribuition = "";

                                if(IDMap.find((yyvsp[(3) - (5)]).label) == IDMap.end())
                                {
                                        IDMap[(yyvsp[(3) - (5)]).label].label = generateLabel();
                                        IDMap[(yyvsp[(3) - (5)]).label].type = (yyvsp[(1) - (5)]).type;
                                        IDMap[(yyvsp[(3) - (5)]).label].modifier = (yyvsp[(1) - (5)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(3) - (5)]).label + "' already declared.");

                                if (((yyvsp[(5) - (5)]).modifier != IDMap[(yyvsp[(3) - (5)]).label].modifier) || ((yyvsp[(5) - (5)]).type != IDMap[(yyvsp[(3) - (5)]).label].type))
                                {
                                        //aqui deve se verificar quais casts são possíveis.
                                        cast = "(" + IDMap[(yyvsp[(3) - (5)]).label].modifier + (IDMap[(yyvsp[(3) - (5)]).label].modifier != "" ? " " : "") + IDMap[(yyvsp[(3) - (5)]).label].type + ") ";
                                }

                                atribuition = (yyvsp[(5) - (5)]).traduction + "\t" + IDMap[(yyvsp[(3) - (5)]).label].label + " = " + cast + (yyvsp[(5) - (5)]).label + ";\n";

                                if(IDMap[(yyvsp[(3) - (5)]).label].modifier != "")
                                        declarations += "\t" + IDMap[(yyvsp[(3) - (5)]).label].modifier + " ";
                                else
                                        declarations += "\t";

                                declarations += IDMap[(yyvsp[(3) - (5)]).label].type + " " + IDMap[(yyvsp[(3) - (5)]).label].label + ";\n";

                                (yyval).label = IDMap[(yyvsp[(3) - (5)]).label].label;
                                (yyval).traduction = "\n" + atribuition + "\n";
                                (yyval).type = IDMap[(yyvsp[(3) - (5)]).label].type;        
                                (yyval).modifier = IDMap[(yyvsp[(3) - (5)]).label].modifier;
                                                        
                        }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 203 "sintatica.y"
    {

                                if(IDMap.find((yyvsp[(2) - (2)]).label) == IDMap.end())
                                {
                                        IDMap[(yyvsp[(2) - (2)]).label].label = generateLabel();
                                        IDMap[(yyvsp[(2) - (2)]).label].type = (yyvsp[(1) - (2)]).type;
                                        IDMap[(yyvsp[(2) - (2)]).label].modifier = (yyvsp[(1) - (2)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(2) - (2)]).label + "' already declared.");

                                if(IDMap[(yyvsp[(2) - (2)]).label].modifier != "")
                                        declarations += "\t" + IDMap[(yyvsp[(2) - (2)]).label].modifier + " ";
                                else
                                        declarations += "\t";


                                declarations += IDMap[(yyvsp[(2) - (2)]).label].type + " " + IDMap[(yyvsp[(2) - (2)]).label].label + ";\n";

                                (yyval).label = IDMap[(yyvsp[(2) - (2)]).label].label;
                                (yyval).traduction = "";
                                (yyval).type = IDMap[(yyvsp[(2) - (2)]).label].type;
                                (yyval).modifier = IDMap[(yyvsp[(2) - (2)]).label].modifier;

                        }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 229 "sintatica.y"
    {
                                string cast = "";
                                string atribuition = "";

                                if(IDMap.find((yyvsp[(2) - (4)]).label) == IDMap.end())
                                {
                                        IDMap[(yyvsp[(2) - (4)]).label].label = generateLabel();
                                        IDMap[(yyvsp[(2) - (4)]).label].type = (yyvsp[(1) - (4)]).type;
                                        IDMap[(yyvsp[(2) - (4)]).label].modifier = (yyvsp[(1) - (4)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(2) - (4)]).label + "' already declared.");

                                if (((yyvsp[(4) - (4)]).modifier != IDMap[(yyvsp[(2) - (4)]).label].modifier) || ((yyvsp[(4) - (4)]).type != IDMap[(yyvsp[(2) - (4)]).label].type))
                                {
                                        //aqui deve se verificar quais casts são possíveis.
                                        cast = "(" + IDMap[(yyvsp[(2) - (4)]).label].modifier + (IDMap[(yyvsp[(2) - (4)]).label].modifier != "" ? " " : "") + IDMap[(yyvsp[(2) - (4)]).label].type + ") ";
                                }

                                atribuition = (yyvsp[(4) - (4)]).traduction + "\t" + IDMap[(yyvsp[(2) - (4)]).label].label + " = " + cast + (yyvsp[(4) - (4)]).label + ";\n";


                                if(IDMap[(yyvsp[(2) - (4)]).label].modifier != "")
                                        declarations += "\t" + IDMap[(yyvsp[(2) - (4)]).label].modifier + " ";
                                else
                                        declarations += "\t";


                                declarations += IDMap[(yyvsp[(2) - (4)]).label].type + " " + IDMap[(yyvsp[(2) - (4)]).label].label + ";\n";

                                (yyval).label = IDMap[(yyvsp[(2) - (4)]).label].label;
                                (yyval).traduction = "\n" + atribuition + "\n";
                                (yyval).type = IDMap[(yyvsp[(2) - (4)]).label].type;
                                (yyval).modifier = IDMap[(yyvsp[(2) - (4)]).label].modifier;

                        }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 269 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 275 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 281 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 287 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 293 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 299 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 305 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).traduction;
                                (yyval).modifier = "";
                                (yyval).traduction = "";
                        }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 311 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 317 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 323 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 329 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 335 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 341 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 347 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (2)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 353 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 359 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 365 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 371 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 377 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 383 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 389 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 395 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (4)]).traduction + " " + (yyvsp[(2) - (4)]).traduction + " " + (yyvsp[(3) - (4)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 401 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).traduction;
                                (yyval).modifier = (yyvsp[(1) - (4)]).traduction + " " + (yyvsp[(2) - (4)]).traduction + " " + (yyvsp[(3) - (4)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 407 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 413 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).traduction + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).traduction;
                                (yyval).traduction = "";
                        }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 423 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "int";
                                (yyval).modifier = "";
 

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 434 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "float";
                                (yyval).modifier = "";
  
                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 444 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
          

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 455 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "char";
                                (yyval).modifier = "";
              

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";                                

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 468 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "int";
                                (yyval).modifier = "";
 

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).traduction + (yyvsp[(2) - (2)]).traduction + ";\n";

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 479 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "float";
                                (yyval).modifier = "";
  
                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).traduction + (yyvsp[(2) - (2)]).traduction + ";\n";

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 489 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
          

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).traduction + (yyvsp[(2) - (2)]).traduction + ";\n";

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 500 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "char";
                                (yyval).modifier = "";
              

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).traduction + (yyvsp[(2) - (2)]).traduction + ";\n";                                

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 513 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "string";
                                (yyval).modifier = "";

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";                                

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 523 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "bool";
                                (yyval).modifier = "";

                                (yyval).traduction = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).traduction + ";\n";                                

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 533 "sintatica.y"
    {
                                if(IDMap.find((yyvsp[(1) - (1)]).label) == IDMap.end())        
                                        yyerror("identifier: '" + (yyvsp[(1) - (1)]).label + "' not declared.");

                                (yyval).label = IDMap[(yyvsp[(1) - (1)]).label].label;
                                (yyval).type = IDMap[(yyvsp[(1) - (1)]).label].type;
                                (yyval).modifier = IDMap[(yyvsp[(1) - (1)]).label].modifier;
                                (yyval).traduction = "";
                        }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 550 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (2)]).traduction + "\n" + (yyvsp[(2) - (2)]).traduction;
                        }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 554 "sintatica.y"
    {
                                (yyval).traduction = "";
                        }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 567 "sintatica.y"
    {
                             	(yyval).traduction = (yyvsp[(2) - (3)]).traduction;
                                (yyval).label = (yyvsp[(2) - (3)]).label;
                                (yyval).type = (yyvsp[(2) - (3)]).type;
                                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;        	
			}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 574 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 581 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 588 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 595 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 602 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 609 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 616 "sintatica.y"
    {
                            	(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 626 "sintatica.y"
    {
			        string resultOperationType;
			        id_struct* keyOperating;
			        string weakOperatingLabel;
			        string strongOperatingLabel;

			        (yyval).label = generateLabel();

			        (yyval).traduction = (yyvsp[(1) - (3)]).traduction + (yyvsp[(3) - (3)]).traduction;

			        resultOperationType = verifyResultOperation((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(2) - (3)]).traduction);

			        /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
			         mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
			         no momento da atribuição, que deverá se fazer um cast, caso necessário*/

			        (yyval).type = resultOperationType;
			        (yyval).modifier = ""; /*desconsidera-se os modificadores*/

			        declarations += "\t" + resultOperationType + " " + (yyval).label + ";\n";

			        if((yyvsp[(1) - (3)]).type == (yyvsp[(3) - (3)]).type)
			        {
			                (yyval).traduction += "\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).label + ";\n";
			        }
			        else
			        {
			                keyOperating = defineKeyOperating((yyvsp[(1) - (3)]).type, (yyvsp[(1) - (3)]).modifier, (yyvsp[(3) - (3)]).type, (yyvsp[(3) - (3)]).modifier);



			                string modifier = keyOperating->modifier;
			                modifier += (modifier != "" ? " " : "");

			                if(keyOperating->type == (yyvsp[(1) - (3)]).type)
			                {
			                        weakOperatingLabel = (yyvsp[(3) - (3)]).label;
			                        strongOperatingLabel = (yyvsp[(1) - (3)]).label;

			                        (yyval).traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
			                        (yyval).traduction += "\t" + (yyval).label + " = " + strongOperatingLabel + " " + (yyvsp[(2) - (3)]).traduction + " " + keyOperating->label + ";\n";
			                }
			                else
			                {
			                        weakOperatingLabel = (yyvsp[(1) - (3)]).label;
			                        strongOperatingLabel = (yyvsp[(3) - (3)]).label;

			                        (yyval).traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
			                        (yyval).traduction += "\t" + (yyval).label + " = " + keyOperating->label + " " + (yyvsp[(2) - (3)]).traduction + " " + strongOperatingLabel + ";\n";
			                }

			                declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
			        }
			}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 684 "sintatica.y"
    {
		                            (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                            (yyval).label = (yyvsp[(1) - (1)]).label;
		                            (yyval).type = (yyvsp[(1) - (1)]).type;
		                            (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		                    }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 691 "sintatica.y"
    {
		                            (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                            (yyval).label = (yyvsp[(1) - (1)]).label;
		                            (yyval).type = (yyvsp[(1) - (1)]).type;
		                            (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		                    }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 698 "sintatica.y"
    {
		                            (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                            (yyval).label = (yyvsp[(1) - (1)]).label;
		                            (yyval).type = (yyvsp[(1) - (1)]).type;
		                            (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		                    }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 705 "sintatica.y"
    {
		                            (yyval).traduction = (yyvsp[(2) - (3)]).traduction;
		                            (yyval).label = (yyvsp[(2) - (3)]).label;
		                            (yyval).type = (yyvsp[(2) - (3)]).type;
		                            (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                        
		                    }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 716 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "bool";
                                (yyval).modifier = "";
                                (yyval).traduction = (yyvsp[(1) - (3)]).traduction + (yyvsp[(3) - (3)]).traduction + "\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).label + ";\n";



                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
                        }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 727 "sintatica.y"
    {
                                (yyval).label = generateLabel();
                                (yyval).type = "bool";
                                (yyval).modifier = "";
                                (yyval).traduction = (yyvsp[(2) - (2)]).traduction + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).label + ";\n";                                


                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";                                
                        }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 741 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                (yyval).label = (yyvsp[(1) - (1)]).label;
		                (yyval).type = (yyvsp[(1) - (1)]).type;
		                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 748 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                (yyval).label = (yyvsp[(1) - (1)]).label;
		                (yyval).type = (yyvsp[(1) - (1)]).type;
		                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 755 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                (yyval).label = (yyvsp[(1) - (1)]).label;
		                (yyval).type = (yyvsp[(1) - (1)]).type;
		                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 762 "sintatica.y"
    {
			    (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
			    (yyval).label = (yyvsp[(1) - (1)]).label;
			    (yyval).type = (yyvsp[(1) - (1)]).type;
			    (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 769 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                (yyval).label = (yyvsp[(1) - (1)]).label;
		                (yyval).type = (yyvsp[(1) - (1)]).type;
		                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 776 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).type = (yyvsp[(1) - (1)]).type;
				(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 783 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(2) - (3)]).traduction;
		                (yyval).label = (yyvsp[(2) - (3)]).label;
		                (yyval).type = (yyvsp[(2) - (3)]).type;
		                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                        
		        }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 793 "sintatica.y"
    {
                                string resultOperationType;
                                id_struct* keyOperating;
                                string weakOperatingLabel;
                                string strongOperatingLabel;

                                (yyval).label = generateLabel();

                                (yyval).traduction = (yyvsp[(1) - (3)]).traduction + (yyvsp[(3) - (3)]).traduction;

                                resultOperationType = verifyResultOperation((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(2) - (3)]).traduction);

                                /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
                                 mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
                                 no momento da atribuição, que deverá se fazer um cast, caso necessário*/

      
                                (yyval).type = resultOperationType;
                                (yyval).modifier = ""; /*desconsidera-se os modificadores*/


                                declarations += "\t" + resultOperationType + " " + (yyval).label + ";\n";

                                if((yyvsp[(1) - (3)]).type == (yyvsp[(3) - (3)]).type)
                                {
                                        (yyval).traduction += "\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).label + ";\n";
                                }
                                else
                                {
                                        keyOperating = defineKeyOperating((yyvsp[(1) - (3)]).type, (yyvsp[(1) - (3)]).modifier, (yyvsp[(3) - (3)]).type, (yyvsp[(3) - (3)]).modifier);

                       
                                        string modifier = keyOperating->modifier;
                                        modifier += (modifier != "" ? " " : "");

                                        if(keyOperating->type == (yyvsp[(1) - (3)]).type)
                                        {
                                                weakOperatingLabel = (yyvsp[(3) - (3)]).label;
                                                strongOperatingLabel = (yyvsp[(1) - (3)]).label;

                                                (yyval).traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                                                (yyval).traduction += "\t" + (yyval).label + " = " + strongOperatingLabel + " " + (yyvsp[(2) - (3)]).traduction + " " + keyOperating->label + ";\n";
                                        }
                                        else
                                        {
                                                weakOperatingLabel = (yyvsp[(1) - (3)]).label;
                                                strongOperatingLabel = (yyvsp[(3) - (3)]).label;

                                                (yyval).traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                                                (yyval).traduction += "\t" + (yyval).label + " = " + keyOperating->label + " " + (yyvsp[(2) - (3)]).traduction + " " + strongOperatingLabel + ";\n";
                                        }

                                        declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
                                }
                        }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 853 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                (yyval).label = (yyvsp[(1) - (1)]).label;
		                (yyval).type = (yyvsp[(1) - (1)]).type;
		                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 860 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
		                (yyval).label = (yyvsp[(1) - (1)]).label;
		                (yyval).type = (yyvsp[(1) - (1)]).type;
		                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 867 "sintatica.y"
    {
			    (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
			    (yyval).label = (yyvsp[(1) - (1)]).label;
			    (yyval).type = (yyvsp[(1) - (1)]).type;
			    (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 874 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).type = (yyvsp[(1) - (1)]).type;
				(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 881 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(2) - (3)]).traduction;
		                (yyval).label = (yyvsp[(2) - (3)]).label;
		                (yyval).type = (yyvsp[(2) - (3)]).type;
		                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                        
		        }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 892 "sintatica.y"
    {
                                (yyval).label = generateLabel();

				if(((yyvsp[(2) - (2)]).type != "int") && ((yyvsp[(2) - (2)]).type != "char"))
					yyerror("wrong type argument to bit-complement");

                                (yyval).traduction = (yyvsp[(2) - (2)]).traduction + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).traduction + " " + (yyvsp[(2) - (2)]).label + ";\n";

                                (yyval).type = (yyvsp[(2) - (2)]).type;
                                (yyval).modifier = (yyvsp[(2) - (2)]).type;

                                declarations += "\t" + (yyval).type + " " + (yyval).label + ";\n";
			}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 909 "sintatica.y"
    {
			     	(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
			        (yyval).label = (yyvsp[(1) - (1)]).label;
			        (yyval).type = (yyvsp[(1) - (1)]).type;
			        (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
		        }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 916 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).type = (yyvsp[(1) - (1)]).type;
				(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 923 "sintatica.y"
    {
		                (yyval).traduction = (yyvsp[(2) - (3)]).traduction;
		                (yyval).label = (yyvsp[(2) - (3)]).label;
		                (yyval).type = (yyvsp[(2) - (3)]).type;
		                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                        
		        }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 934 "sintatica.y"
    {
                                string resultOperationType;
                                id_struct* keyOperating;
                                string weakOperatingLabel;
                                string strongOperatingLabel;

                                (yyval).label = generateLabel();

                                (yyval).traduction = (yyvsp[(1) - (3)]).traduction + (yyvsp[(3) - (3)]).traduction;

                                resultOperationType = verifyResultOperation((yyvsp[(1) - (3)]).type, (yyvsp[(3) - (3)]).type, (yyvsp[(2) - (3)]).traduction);

                                /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
                                 mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
                                 no momento da atribuição, que deverá se fazer um cast, caso necessário*/

                                (yyval).type = resultOperationType;
                                (yyval).modifier = ""; /*desconsidera-se os modificadores*/


                                declarations += "\t" + resultOperationType + " " + (yyval).label + ";\n";

                                if((yyvsp[(1) - (3)]).type == (yyvsp[(3) - (3)]).type)
                                {
                                        (yyval).traduction += "\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).label + " " + (yyvsp[(2) - (3)]).traduction + " " + (yyvsp[(3) - (3)]).label + ";\n";
                                }
                                else
                                {
                                        keyOperating = defineKeyOperating((yyvsp[(1) - (3)]).type, (yyvsp[(1) - (3)]).modifier, (yyvsp[(3) - (3)]).type, (yyvsp[(3) - (3)]).modifier);


                                        string modifier = keyOperating->modifier;
                                        modifier += (modifier != "" ? " " : "");

                                        if(keyOperating->type == (yyvsp[(1) - (3)]).type)
                                        {
                                                weakOperatingLabel = (yyvsp[(3) - (3)]).label;
                                                strongOperatingLabel = (yyvsp[(1) - (3)]).label;

                                                (yyval).traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                                                (yyval).traduction += "\t" + (yyval).label + " = " + strongOperatingLabel + " " + (yyvsp[(2) - (3)]).traduction + " " + keyOperating->label + ";\n";
                                        }
                                        else
                                        {
                                                weakOperatingLabel = (yyvsp[(1) - (3)]).label;
                                                strongOperatingLabel = (yyvsp[(3) - (3)]).label;

                                                (yyval).traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                                                (yyval).traduction += "\t" + (yyval).label + " = " + keyOperating->label + " " + (yyvsp[(2) - (3)]).traduction + " " + strongOperatingLabel + ";\n";
                                        }

                                        declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
                                }

                        }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 994 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1001 "sintatica.y"
    {
			    (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
			    (yyval).label = (yyvsp[(1) - (1)]).label;
			    (yyval).type = (yyvsp[(1) - (1)]).type;
			    (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1008 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(1) - (1)]).traduction;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1015 "sintatica.y"
    {
				(yyval).traduction = (yyvsp[(1) - (1)]).traduction;
				(yyval).label = (yyvsp[(1) - (1)]).label;
				(yyval).type = (yyvsp[(1) - (1)]).type;
				(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
			}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1022 "sintatica.y"
    {
                                (yyval).traduction = (yyvsp[(2) - (3)]).traduction;
                                (yyval).label = (yyvsp[(2) - (3)]).label;
                                (yyval).type = (yyvsp[(2) - (3)]).type;
                                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                        
                        }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1033 "sintatica.y"
    {
                                if(IDMap.find((yyvsp[(1) - (3)]).label) == IDMap.end())        
                                        yyerror("identifier: '" + (yyvsp[(1) - (3)]).label + "' not declared.");

                                string cast = "";

                                if ((((yyvsp[(3) - (3)]).modifier != IDMap[(yyvsp[(1) - (3)]).label].modifier)) || ((yyvsp[(3) - (3)]).type != IDMap[(yyvsp[(1) - (3)]).label].type))
                                {

                                        //aqui deve-se verificar quais casts são possíveis
                                        if((yyvsp[(1) - (3)]).modifier != "")
                                                cast = "(" + IDMap[(yyvsp[(1) - (3)]).label].modifier + " " + IDMap[(yyvsp[(1) - (3)]).label].type + ") ";
                                        else
                                                cast += "(" + IDMap[(yyvsp[(1) - (3)]).label].type + ") ";
                                }

                                (yyval).label = IDMap[(yyvsp[(1) - (3)]).label].label;
                                (yyval).traduction = (yyvsp[(3) - (3)]).traduction + "\t" + (yyval).label + " = " + cast + (yyvsp[(3) - (3)]).label + ";\n";
                                (yyval).type = IDMap[(yyvsp[(1) - (3)]).label].type;
                                (yyval).modifier = IDMap[(yyvsp[(1) - (3)]).label].modifier;
                        }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1077 "sintatica.y"
    {
					(yyval).traduction = "\t" + (yyvsp[(3) - (4)]).traduction + "\n\tcout << " + (yyvsp[(3) - (4)]).label + " << endl;\n";
				}
    break;



/* Line 1806 of yacc.c  */
#line 3060 "y.tab.c"
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
#line 1082 "sintatica.y"


#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
        loadOpearationsMap();
        yyparse();

        return 0;
}

void yyerror(string MSG)
{
        error = true; /*há algum erro de compilação*/        
        cerr << ":" << yylineno << ": error: " + MSG << endl;
        //exit(0);
}

string generateLabel()
{
        static int counter = 0;
        stringstream label;

        label << "_temp" << counter++;

        return label.str();
}                                        


string verifyResultOperation(string op1Type, string op2Type, string sOperator)
{
        operation_struct ops;

        ops.op1Type = op1Type;
        ops.op2Type = op2Type;
        ops.sOperator = sOperator;


        if(operationsMap.find(ops) == operationsMap.end())
        {                
                ops.op1Type = op2Type;
                ops.op2Type = op1Type;

                if(operationsMap.find(ops) == operationsMap.end())
                        yyerror("operation of type: '" + op1Type + " " + sOperator + " " + op2Type + "' not is defined.");
        }
        
        return operationsMap[ops];
}

id_struct* defineKeyOperating(string op1Type, string op1Modifier, string op2Type, string op2Modifier)
{
        id_struct* keyOperating = new id_struct;
        
        keyOperating->label = generateLabel();

        keyOperating->type = verifyStrongType(op1Type, op2Type);

        if(keyOperating->type == op1Type)
                keyOperating->modifier = op1Modifier;
        else
                keyOperating->modifier = op2Modifier;

        return keyOperating;
}


void loadOpearationsMap(void)
{
        operation_struct* ops;

        /*Operações aritméticas*/
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "+";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "+";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "+";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "+";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "+";
        operationsMap[*ops] = "string";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "+";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "+";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "string";
        ops->sOperator = "+";
        operationsMap[*ops] = "string";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "+";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "string";
        ops->sOperator = "+";
        operationsMap[*ops] = "string";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "+";
        operationsMap[*ops] = "float";                

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "+";
        operationsMap[*ops] = "double";        

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "-";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "-";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "-";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "-";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "-";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "-";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "-";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "-";
        operationsMap[*ops] = "float";                

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "-";
        operationsMap[*ops] = "double";        


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "*";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "*";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "*";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "*";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "*";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "*";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "*";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "*";
        operationsMap[*ops] = "float";                

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "*";
        operationsMap[*ops] = "double";        

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "/";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "/";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "/";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "/";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "/";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "/";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "/";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "/";
        operationsMap[*ops] = "float";                

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "/";
        operationsMap[*ops] = "double";                

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "+";
        operationsMap[*ops] = "double";                

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "-";
        operationsMap[*ops] = "double";                        

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "*";
        operationsMap[*ops] = "double";                

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "/";
        operationsMap[*ops] = "double";                

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "%";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "%";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "%";
        operationsMap[*ops] = "int";

        /*Operações relacionais*/
        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "int";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "char";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "int";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "char";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "int";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "char";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "int";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "char";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "int";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "char";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";
                        
                        
        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "int";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "char";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";


        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "<";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "<=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = ">";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = ">=";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "==";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "!=";
        operationsMap[*ops] = "bool";

        /*Operações binárias*/
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "<<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "int";
        ops->sOperator = "<<";
        operationsMap[*ops] = "int";        

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "<<";
        operationsMap[*ops] = "char";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = ">>";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "int";
        ops->sOperator = ">>";
        operationsMap[*ops] = "int";        

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = ">>";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "&";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "int";
        ops->sOperator = "&";
        operationsMap[*ops] = "int";        

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "&";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "|";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "int";
        ops->sOperator = "|";
        operationsMap[*ops] = "int";        

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "|";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "^";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "int";
        ops->sOperator = "^";
        operationsMap[*ops] = "int";        

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "^";
        operationsMap[*ops] = "char";

        /*Operações lógicas*/
        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "&&";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "||";
        operationsMap[*ops] = "bool";
}

string   verifyStrongType(string op1Type, string op2Type)
{
        if(op1Type == "int" && op2Type == "int")
                return "int";
        if(op1Type == "float" && op2Type == "float")
                return "float";
        if(op1Type == "double" && op2Type == "double")
                return "double";
        if(op1Type == "bool" && op2Type == "bool")
                return "bool";
        if(op1Type == "char" && op2Type == "char")
                return "char";
        if(op1Type == "string" && op2Type == "string")
                return "string";


        if ((op1Type == "int" && op2Type == "float") || (op1Type == "float" && op2Type == "int"))
                return "float";
        if ((op1Type == "int" && op2Type == "double") || (op1Type == "double" && op2Type == "int"))
                return "double";
        if ((op1Type == "int" && op2Type == "char") || (op1Type == "char" && op2Type == "int"))
                return "int";
        if ((op1Type == "int" && op2Type == "string") || (op1Type == "string" && op2Type == "int"))
                return "string";
        if ((op1Type == "int" && op2Type == "bool") || (op1Type == "bool" && op2Type == "int"))
                return "bool";

        if ((op1Type == "char" && op2Type == "float") || (op1Type == "float" && op2Type == "char"))
                return "float";
        if ((op1Type == "char" && op2Type == "double") || (op1Type == "double" && op2Type == "char"))
                return "double";
        if ((op1Type == "char" && op2Type == "string") || (op1Type == "string" && op2Type == "char"))
                return "string";
        if ((op1Type == "char" && op2Type == "bool") || (op1Type == "bool" && op2Type == "char"))
                return "string";

        if ((op1Type == "float" && op2Type == "string") || (op1Type == "string" && op2Type == "float"))
                return "string";
        if ((op1Type == "float" && op2Type == "double") || (op1Type == "double" && op2Type == "float"))
                return "double";
        if ((op1Type == "float" && op2Type == "bool") || (op1Type == "bool" && op2Type == "float"))
                return "string";

        if ((op1Type == "double" && op2Type == "string") || (op1Type == "string" && op2Type == "double"))
                return "string";
        if ((op1Type == "double" && op2Type == "bool") || (op1Type == "bool" && op2Type == "double"))
                return "string";

        if ((op1Type == "bool" && op2Type == "string") || (op1Type == "string" && op2Type == "bool"))
                return "string";


        yyerror("relation between the types: '" + op1Type + "' and '" + op2Type + "' not defined.");
        return "";

}


