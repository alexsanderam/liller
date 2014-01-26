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
#include <list>

#define YYSTYPE args

extern int yylineno;

using namespace std;

typedef struct idStruct
{
        string type;
        string modifier;
        string label;
} id_struct;


typedef struct
{
        string label;
	bool found;
	unsigned int line; //utilizado no tratamento de erro
} label_struct;

struct args
{
        string label;
        string translation;
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

typedef struct
{
        string dIType; /*tipo com modificador das variáveis intermediárias*/
        unsigned int size; /*nos casos de string*/
} variable_declarations_struct;

typedef map<string, id_struct> identifiers_map;
typedef map<string, variable_declarations_struct> declarations_map;
typedef map<string, label_struct> labels_map;


/*pilhas para controle de escopo*/
list<identifiers_map*> stackIDMap;
list<declarations_map*> stackDeclarationsMap;

/*mapa de rótulos*/
labels_map labelMap;

/*mapa de operações permititdas*/
map<operation_struct, string> operationsMap;


const string voidStr = "";

/*declaraçãoes (todas)*/
string declarations = "";

/*controle de erro ou warning*/
bool error = false;
bool warning = false;


/*controle para alertar a recursão de operações relacionais*/
unsigned int relationalCounter = 0;


/*variáveis auxiliares para o controle da tradução do incremento/decremento*/
string auxIncreaseTranslation = "";
bool flagIncreaseTranslation = false;

/*controle de declarações, quando tais não são permititdas (exemplo: if, for, ...)*/
bool flagDeclarationNotAllowed = false;
bool flagDeclarationNotAllowedAux = false;

int yylex(void);
void yyerror(string);
void yywarning(string);

void openNewScope();
void closeCurrentScope();
YYSTYPE runBasicOperation(YYSTYPE, YYSTYPE, string);
YYSTYPE runCast(YYSTYPE, YYSTYPE);
bool verifyCast(string, string);
YYSTYPE assign(string, YYSTYPE, YYSTYPE);
YYSTYPE assignNotExpression(YYSTYPE);
YYSTYPE generateIntValue(int);
string generateID();
string generateLabel();
void relationalControl(YYSTYPE);
id_struct* findID(string);
label_struct* findLabel(string);
bool isDeclaredCurrentScope(string label);
void declare(string, string, unsigned int);
void verifyLabels();
string getDeclarations();
void findAndReplace(string*, const string, const string);
string verifyResultOperation(string, string, string);
id_struct* defineKeyOperating(string, string, string, string);
string verifyStrongType(string, string);
void loadOpearationsMap(void);



/* Line 268 of yacc.c  */
#line 201 "y.tab.c"

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
     TK_COUT = 301,
     TK_IF = 302,
     TK_ELSE = 303,
     TK_SWITCH = 304,
     TK_CASE = 305,
     TK_DEFAULT = 306,
     TK_FOR = 307,
     TK_EACH = 308,
     TK_WHILE = 309,
     TK_DO = 310,
     TK_BREAK = 311,
     TK_CONTINUE = 312,
     TK_GOTO = 313,
     TK_OP_INCREASE = 314,
     TK_OP_LESS_LESS = 315,
     TK_OP_ASSIGN = 316,
     TK_DOT_DOT = 317,
     TK_GO_LABEL = 318,
     IFX = 319,
     ELSE = 320
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
#define TK_IF 302
#define TK_ELSE 303
#define TK_SWITCH 304
#define TK_CASE 305
#define TK_DEFAULT 306
#define TK_FOR 307
#define TK_EACH 308
#define TK_WHILE 309
#define TK_DO 310
#define TK_BREAK 311
#define TK_CONTINUE 312
#define TK_GOTO 313
#define TK_OP_INCREASE 314
#define TK_OP_LESS_LESS 315
#define TK_OP_ASSIGN 316
#define TK_DOT_DOT 317
#define TK_GO_LABEL 318
#define IFX 319
#define ELSE 320




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 373 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      66,    67,     2,     2,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,    69,     2,     2,     2,     2,
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
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    15,    20,    24,    26,    28,
      31,    32,    34,    37,    40,    43,    46,    48,    50,    52,
      54,    56,    58,    61,    63,    66,    68,    74,    82,    84,
      90,    92,   100,   102,   103,   105,   107,   109,   111,   113,
     123,   131,   134,   137,   141,   143,   145,   150,   154,   158,
     162,   166,   170,   174,   178,   182,   186,   190,   194,   198,
     202,   206,   210,   214,   218,   222,   225,   228,   230,   232,
     235,   238,   242,   244,   248,   253,   257,   258,   262,   268,
     271,   276,   278,   280,   282,   284,   286,   288,   290,   293,
     296,   299,   302,   305,   308,   311,   313,   315,   319,   323,
     327,   331,   335,   340,   345,   349,   353,   355,   357,   359,
     361,   364,   367,   370,   373,   375,   377,   379,   382,   384
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      73,     0,    -1,    74,   102,    75,    76,    -1,    -1,    13,
       9,    66,    14,    67,    -1,    13,     9,    66,    67,    -1,
      77,    79,    78,    -1,    68,    -1,    69,    -1,    80,    79,
      -1,    -1,    81,    -1,    96,    70,    -1,    82,    70,    -1,
     101,    70,    -1,   103,    70,    -1,    76,    -1,    84,    -1,
      86,    -1,    88,    -1,    93,    -1,    94,    -1,    95,    70,
      -1,    70,    -1,    45,    96,    -1,    47,    -1,    83,    66,
      96,    67,    80,    -1,    83,    66,    96,    67,    80,    48,
      80,    -1,    54,    -1,    85,    66,    96,    67,    80,    -1,
      55,    -1,    87,    80,    54,    66,    96,    67,    70,    -1,
      96,    -1,    -1,    89,    -1,   103,    -1,    99,    -1,   105,
      -1,    52,    -1,    92,    66,    90,    70,    89,    70,    89,
      67,    80,    -1,    92,    66,    91,    62,   105,    67,    80,
      -1,    10,    63,    -1,    58,    10,    -1,    66,    96,    67,
      -1,   105,    -1,    99,    -1,    66,   104,    67,   105,    -1,
      96,    24,    96,    -1,    96,    25,    96,    -1,    96,    26,
      96,    -1,    96,    27,    96,    -1,    96,    28,    96,    -1,
      96,    36,    96,    -1,    96,    35,    96,    -1,    96,    33,
      96,    -1,    96,    34,    96,    -1,    96,    29,    96,    -1,
      96,    30,    96,    -1,    96,    31,    96,    -1,    96,    32,
      96,    -1,    96,    38,    96,    -1,    96,    39,    96,    -1,
      96,    40,    96,    -1,    96,    42,    96,    -1,    96,    43,
      96,    -1,    37,    96,    -1,    41,    96,    -1,    97,    -1,
      98,    -1,    10,    59,    -1,    59,    10,    -1,    10,    44,
      96,    -1,   100,    -1,    10,    61,    96,    -1,    46,    66,
      96,    67,    -1,   102,   103,    70,    -1,    -1,   103,    71,
      10,    -1,   103,    71,    10,    44,    96,    -1,   104,    10,
      -1,   104,    10,    44,    96,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    11,    -1,    19,    11,    -1,    18,    13,    -1,    19,
      13,    -1,    20,    13,    -1,    21,    13,    -1,    21,    16,
      -1,    20,    -1,    21,    -1,    18,    20,    13,    -1,    19,
      20,    13,    -1,    18,    21,    13,    -1,    19,    21,    13,
      -1,    21,    21,    13,    -1,    18,    21,    21,    13,    -1,
      19,    21,    21,    13,    -1,    18,    21,    21,    -1,    19,
      21,    21,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,   106,     3,    -1,   106,     4,    -1,   106,     5,    -1,
     106,     6,    -1,     7,    -1,     8,    -1,    10,    -1,   106,
      10,    -1,    24,    -1,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   174,   174,   187,   193,   198,   206,   215,   228,   242,
     247,   253,   269,   270,   271,   272,   281,   282,   283,   284,
     285,   286,   287,   288,   296,   306,   313,   332,   357,   365,
     389,   397,   416,   417,   421,   422,   428,   435,   445,   456,
     486,   529,   554,   591,   598,   605,   612,   616,   620,   624,
     628,   632,   636,   640,   644,   649,   654,   659,   664,   669,
     674,   678,   682,   686,   690,   694,   704,   718,   725,   736,
     779,   820,   827,   837,   895,   903,   909,   916,   942,   967,
     994,  1021,  1027,  1033,  1039,  1045,  1051,  1057,  1063,  1069,
    1075,  1081,  1087,  1093,  1099,  1105,  1111,  1117,  1123,  1129,
    1135,  1141,  1147,  1153,  1159,  1165,  1175,  1186,  1196,  1207,
    1218,  1229,  1239,  1250,  1261,  1271,  1285,  1299,  1324,  1324
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
  "TK_OP_BIN_SHIFTL", "TK_ASSIGN", "TK_RETURN", "TK_COUT", "TK_IF",
  "TK_ELSE", "TK_SWITCH", "TK_CASE", "TK_DEFAULT", "TK_FOR", "TK_EACH",
  "TK_WHILE", "TK_DO", "TK_BREAK", "TK_CONTINUE", "TK_GOTO",
  "TK_OP_INCREASE", "TK_OP_LESS_LESS", "TK_OP_ASSIGN", "TK_DOT_DOT",
  "TK_GO_LABEL", "IFX", "ELSE", "'('", "')'", "'{'", "'}'", "';'", "','",
  "$accept", "BEGIN", "START", "MAIN", "SCOPE", "BEGIN_SCOPE", "END_SCOPE",
  "COMMANDS", "COMMAND", "STATEMENT", "RETURN", "IF_C", "IF", "WHILE_C",
  "WHILE", "DO_WHILE_C", "DO_WHILE", "OPTIONAL_E",
  "OPTIONAL_E_OR_DECLARATION", "ATTRIBUITION_OR_TERMINAL", "FOR_C", "FOR",
  "LABEL", "GOTO", "E", "INCREASE", "PREV_INCREASE", "ATTRIBUITION",
  "OP_ASSIGN", "COUT", "DECLARATIONS", "DECLARATION", "TYPE", "TERMINAL",
  "SIGNAL", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    40,    41,   123,   125,
      59,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    75,    75,    76,    77,    78,    79,
      79,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    84,    84,    85,    86,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    93,
      93,    94,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      98,    99,    99,   100,   101,   102,   102,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     5,     4,     3,     1,     1,     2,
       0,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     5,     7,     1,     5,
       1,     7,     1,     0,     1,     1,     1,     1,     1,     9,
       7,     2,     2,     3,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     2,
       2,     3,     1,     3,     4,     3,     0,     3,     5,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     3,     3,     3,
       3,     3,     4,     4,     3,     3,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     1,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,    76,     1,     0,    81,    82,    83,    84,    85,
      86,    87,     0,     0,    95,    96,     0,     0,     0,     0,
      88,    90,     0,     0,    89,    91,     0,     0,    92,    93,
      94,     0,     7,     2,    10,    75,     0,    79,     0,    97,
      99,   104,    98,   100,   105,   101,   106,   107,   108,   109,
     114,   115,   116,    83,   118,   119,     0,     0,     0,     0,
      25,    38,    28,    30,     0,     0,     0,    23,    16,     0,
      10,    11,     0,     0,    17,     0,    18,     0,    19,     0,
      20,    21,     0,     0,    67,    68,    45,    72,     0,     0,
      44,     0,    77,     0,     0,     5,   102,   103,     0,    69,
       0,    41,   116,    65,    66,    24,     0,    42,    70,     0,
       0,     8,     6,     9,    13,     0,     0,     0,    33,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    14,
      15,   110,   111,   112,   113,   117,     0,    80,     4,    71,
      73,     0,    43,     0,     0,     0,     0,    34,     0,     0,
      32,    45,    35,    44,    47,    48,    49,    50,    51,    56,
      57,    58,    59,    54,    55,    53,    52,    60,    61,    62,
      63,    64,    78,    74,   116,    46,     0,     0,     0,    33,
       0,    26,    29,     0,     0,     0,     0,     0,    33,     0,
      27,    31,     0,    40,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    68,    34,   112,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   157,   158,   159,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       4,    89,    18,    90,    91
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
    -156,     7,  -156,  -156,   417,  -156,  -156,     5,  -156,  -156,
    -156,  -156,    -5,   103,    -4,    35,   -16,   -58,    44,    16,
    -156,  -156,    48,    98,  -156,  -156,    76,   107,  -156,  -156,
    -156,    91,  -156,  -156,   133,  -156,    47,    64,    -9,  -156,
    -156,   102,  -156,  -156,   104,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,   -14,  -156,  -156,  -156,   224,   224,   224,    55,
    -156,  -156,  -156,  -156,   119,   121,   201,  -156,  -156,    66,
     133,  -156,    89,   100,  -156,   105,  -156,   133,  -156,   106,
    -156,  -156,    99,    -7,  -156,  -156,  -156,  -156,   113,    56,
    -156,   190,   124,   224,   108,  -156,  -156,  -156,   224,  -156,
     224,  -156,    -6,  -156,  -156,   334,   224,  -156,  -156,    67,
     109,  -156,  -156,  -156,  -156,   224,   224,   123,   201,  -156,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,   224,   334,  -156,   334,
     334,   246,  -156,   157,   267,   290,   118,  -156,   116,   111,
     334,   127,   126,   136,   218,    13,   128,   162,  -156,   384,
     384,   384,   384,   375,   375,   355,   355,    60,    60,    60,
      60,    60,   334,  -156,  -156,  -156,   133,   133,   224,   224,
     157,   154,  -156,   311,   140,   156,   133,   163,   224,   133,
    -156,  -156,   168,  -156,   133,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,  -156,   208,  -156,  -156,   166,   -74,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -155,  -156,  -156,
    -156,  -156,  -156,  -156,   -56,  -156,  -156,   122,  -156,  -156,
    -156,     0,   171,  -107,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
     103,   104,   105,   117,    17,    94,    20,     3,    21,    28,
     109,   163,    35,    36,    19,    22,    23,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      98,   133,   134,   135,   194,   136,   137,   147,    98,   122,
     123,   124,   149,   202,   150,    99,   185,   100,    29,   101,
     151,    30,    32,    99,    37,   100,    31,    92,    95,   154,
     155,    39,   160,   138,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,    38,   195,   120,   121,   122,   123,   124,    42,
     182,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    45,   133,   134,   135,    93,   136,
     137,    40,   191,   192,    24,    96,    25,    97,   162,    41,
      43,   106,   200,    26,    27,   203,   140,    36,    44,   107,
     205,   108,   193,   160,   152,   111,    46,    47,    48,    49,
      50,    51,   160,    52,     5,     6,    53,     8,     9,    10,
      11,    12,    13,    14,    15,   123,   124,    54,    55,   114,
      46,    47,    48,    49,    50,    51,   115,   184,   146,   119,
      56,   116,   118,   190,    57,   148,   153,   156,    58,    59,
      60,    54,    55,   139,   188,    61,   189,    62,    63,   -36,
     124,    64,    65,   141,   142,   143,   144,    36,   -37,    66,
     145,    32,   196,    67,    46,    47,    48,    49,    50,    51,
     198,   102,     5,     6,    53,     8,     9,    10,    11,    12,
      13,    14,    15,   199,    33,    54,    55,    46,    47,    48,
      49,    50,    51,   201,   102,   204,   113,   110,    56,     0,
     161,     0,    57,   121,   122,   123,   124,     0,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    56,     0,     0,     0,    57,     0,    66,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,    65,   133,   134,   135,     0,   136,   137,
      66,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,     0,   133,   134,   135,     0,   136,
     137,     0,     0,   183,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,   133,   134,
     135,     0,   136,   137,   186,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     0,   133,
     134,   135,     0,   136,   137,     0,     0,   187,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,   133,   134,   135,     0,   136,   137,   197,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,   133,   134,   135,     0,   136,   137,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   120,   121,
     122,   123,   124,   133,   134,   135,     0,   136,   137,     0,
       0,     0,   133,   134,   135,     0,   136,   137,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-156))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      56,    57,    58,    77,     4,    14,    11,     0,    13,    13,
      66,   118,    70,    71,     9,    20,    21,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      44,    38,    39,    40,   189,    42,    43,    93,    44,    26,
      27,    28,    98,   198,   100,    59,   153,    61,    13,    63,
     106,    16,    68,    59,    10,    61,    21,    10,    67,   115,
     116,    13,   118,    70,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,    66,   190,    24,    25,    26,    27,    28,    13,
     146,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    13,    38,    39,    40,    44,    42,
      43,    13,   186,   187,    11,    13,    13,    13,   118,    21,
      13,    66,   196,    20,    21,   199,    70,    71,    21,    10,
     204,    10,   188,   189,    67,    69,     3,     4,     5,     6,
       7,     8,   198,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    27,    28,    24,    25,    70,
       3,     4,     5,     6,     7,     8,    66,    10,    44,    70,
      37,    66,    66,    62,    41,    67,    67,    54,    45,    46,
      47,    24,    25,    70,    66,    52,    70,    54,    55,    62,
      28,    58,    59,     3,     4,     5,     6,    71,    62,    66,
      10,    68,    48,    70,     3,     4,     5,     6,     7,     8,
      70,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    67,    16,    24,    25,     3,     4,     5,
       6,     7,     8,    70,    10,    67,    70,    66,    37,    -1,
     118,    -1,    41,    25,    26,    27,    28,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    37,    -1,    -1,    -1,    41,    -1,    66,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    59,    38,    39,    40,    -1,    42,    43,
      66,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    -1,    42,
      43,    -1,    -1,    67,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    -1,    42,    43,    67,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    -1,    42,    43,    -1,    -1,    67,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    40,    -1,    42,    43,    67,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    42,    43,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    24,    25,
      26,    27,    28,    38,    39,    40,    -1,    42,    43,    -1,
      -1,    -1,    38,    39,    40,    -1,    42,    43,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    73,    74,     0,   102,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    75,   103,   104,     9,
      11,    13,    20,    21,    11,    13,    20,    21,    13,    13,
      16,    21,    68,    76,    77,    70,    71,    10,    66,    13,
      13,    21,    13,    13,    21,    13,     3,     4,     5,     6,
       7,     8,    10,    13,    24,    25,    37,    41,    45,    46,
      47,    52,    54,    55,    58,    59,    66,    70,    76,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   103,
     105,   106,    10,    44,    14,    67,    13,    13,    44,    59,
      61,    63,    10,    96,    96,    96,    66,    10,    10,    96,
     104,    69,    78,    79,    70,    66,    66,    80,    66,    70,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    38,    39,    40,    42,    43,    70,    70,
      70,     3,     4,     5,     6,    10,    44,    96,    67,    96,
      96,    96,    67,    67,    96,    96,    54,    89,    90,    91,
      96,    99,   103,   105,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    67,    10,   105,    67,    67,    66,    70,
      62,    80,    80,    96,    89,   105,    48,    67,    70,    67,
      80,    70,    89,    80,    67,    80
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
#line 175 "sintatica.y"
    {
				verifyLabels(); /*verifica se há erros relacionados à rótulos*/

				if(!error)
                                        cout << "/*Compiler prescot-liller*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\nusing namespace std;\n\n" + (yyvsp[(3) - (4)]).translation + "{\n" + declarations + "\n" + (yyvsp[(2) - (4)]).translation + "\n" + (yyvsp[(4) - (4)]).translation + "}\n" << endl;
                                else
                                        exit(1);
                        }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 187 "sintatica.y"
    {
                                openNewScope();        
                        }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 194 "sintatica.y"
    {
                               (yyval).translation = "int main(void)\n";

                        }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 199 "sintatica.y"
    {
                               (yyval).translation = "int main()\n";
                        }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 207 "sintatica.y"
    {
                                (yyval).translation =  (yyvsp[(1) - (3)]).translation + (yyvsp[(2) - (3)]).translation + (yyvsp[(3) - (3)]).translation;
                        }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 216 "sintatica.y"
    {
                                openNewScope();                        
                                (yyval).translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
				flagDeclarationNotAllowedAux = flagDeclarationNotAllowed;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 229 "sintatica.y"
    {
                                declarations += getDeclarations();
                                closeCurrentScope(); /*desempilha*/                                
                                (yyval).translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
                                flagDeclarationNotAllowed = flagDeclarationNotAllowedAux;

                        }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 243 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(1) - (2)]).translation + "\n" + (yyvsp[(2) - (2)]).translation;
                        }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 247 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 254 "sintatica.y"
    {
                                /*controle para alertar a recursão de operações relacionais*/
                                relationalCounter = 0;                                        

                                /*controle da tradução do incremento/decremento*/
                                if(flagIncreaseTranslation)
                                {
                                        (yyval).translation += auxIncreaseTranslation;
                                        flagIncreaseTranslation = false;
                                        auxIncreaseTranslation = "";
                                }
                        }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 273 "sintatica.y"
    {
                                /*controle de declarações, quando tais não são permititdas (exemplo: if, for, ...)*/
                                if(flagDeclarationNotAllowed)
                                {
                                        yyerror("declarations not allowed.");
                                        flagDeclarationNotAllowed = false;
                                }
                        }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 289 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 297 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\n\t" + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";";
                        }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 307 "sintatica.y"
    {
				/*controle de declaraçãoes*/
                                flagDeclarationNotAllowed = true;
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 314 "sintatica.y"
    {                                
                                YYSTYPE notE;
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression((yyvsp[(3) - (5)]));

                                (yyval).translation = (yyvsp[(3) - (5)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\t" + (yyvsp[(1) - (5)]).translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += (yyvsp[(5) - (5)]).translation + "\n"; /*tradução: COMMAND*/
                                (yyval).translation += "\t" + labelEndIF + ":\n"; /*tradução: labelEndIF:*/

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;

                        }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 333 "sintatica.y"
    {
                                YYSTYPE notE;
                                string labelEndCmd1 = generateLabel();
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression((yyvsp[(3) - (7)]));

                                (yyval).translation = (yyvsp[(3) - (7)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\t" + (yyvsp[(1) - (7)]).translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndCmd1 + ";\n\n"; /*tradução: goto labelCmd1*/
                                (yyval).translation += (yyvsp[(5) - (7)]).translation + "\n"; /*tradução: COMMAND*/
                                (yyval).translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += "\t" + labelEndCmd1 + ":\n"; /*tradução: labelEndCmd1:*/
                                (yyval).translation += (yyvsp[(7) - (7)]).translation + "\n"; /*tradução: COMMAND (2)*/
                                (yyval).translation += "\t" + labelEndIF + ":\n"; /*tradução: labelEndId:*/

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 358 "sintatica.y"
    {
				/*controle de declaraçãoes*/
                                flagDeclarationNotAllowed = true;
			}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 366 "sintatica.y"
    {
                                YYSTYPE notE;
                                string labelBeginWhile = generateLabel();
                                string labelEndWhile = generateLabel();
        
                                notE = assignNotExpression((yyvsp[(3) - (5)]));

                                (yyval).translation = "\n\t" + labelBeginWhile + ":\n"; /*tradução: labelBeginWhile:*/
                                (yyval).translation += (yyvsp[(3) - (5)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\tif (" + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndWhile + ";\n\n"; /*tradução: goto labelEndWhile*/
                                (yyval).translation += (yyvsp[(5) - (5)]).translation + "\n"; /*tradução: COMMAND*/
                                (yyval).translation += "\t\tgoto " + labelBeginWhile + ";\n"; /*tradução: goto labelBeginWhile*/
                                (yyval).translation += "\t" + labelEndWhile + ":\n"; /*tradução: labelEndWhile:*/

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 390 "sintatica.y"
    {
				/*controle de declaraçãoes*/
                                flagDeclarationNotAllowed = true;
			}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 398 "sintatica.y"
    {
                                string labelBeginDoWhile = generateLabel();

                                (yyval).translation = "\n\t" + labelBeginDoWhile + ":\n"; /*tradução: labelBeginDoWhileIF:*/
                                (yyval).translation += (yyvsp[(2) - (7)]).translation + "\n"; /*tradução: COMMAND*/
                                (yyval).translation += (yyvsp[(5) - (7)]).translation; /*tradução da expressão E*/
                                (yyval).translation += "\tif (" + (yyvsp[(5) - (7)]).label + ")\n"; /*tradução: if (E)*/
                                (yyval).translation += "\t\tgoto " + labelBeginDoWhile + ";\n"; /*tradução: goto labelEndIf*/

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 429 "sintatica.y"
    {
					(yyval).translation = (yyvsp[(1) - (1)]).translation;
					(yyval).label = (yyvsp[(1) - (1)]).label;
					(yyval).type = (yyvsp[(1) - (1)]).type;
					(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
				}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 436 "sintatica.y"
    {
					(yyval).translation = (yyvsp[(1) - (1)]).translation;
					(yyval).label = (yyvsp[(1) - (1)]).label;
					(yyval).type = (yyvsp[(1) - (1)]).type;
					(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
				}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 446 "sintatica.y"
    {
				/*controle de declaraçãoes*/
			        flagDeclarationNotAllowed = true;

				/*para os casos de declaração dentro do for*/
                                openNewScope();        
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 457 "sintatica.y"
    {
                                YYSTYPE notE;
                                string labelBeginFor = generateLabel();
                                string labelEndFor = generateLabel();

                                (yyval).translation =  "\n" + (yyvsp[(3) - (9)]).translation + "\n"; /*tradução da inicialização do For, que pode ser vazia*/
                                (yyval).translation += "\t" + labelBeginFor + ":\n"; /*tradução: labelBeginFor:*/
                                if ((yyvsp[(5) - (9)]).translation != "") /* caso haja um teste */                                                                
                                {
                                        notE = assignNotExpression((yyvsp[(5) - (9)]));
                                        (yyval).translation += (yyvsp[(5) - (9)]).translation; /*tradução da expressão de teste E*/
                                        (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão de teste E*/
                                        (yyval).translation += "\tif (" + notE.label + ")\n"; /*tradução: if (!E)*/
                                        (yyval).translation += "\t\tgoto " + labelEndFor + ";\n\n"; /*tradução: goto labelEndFor*/
                                }
                                (yyval).translation += (yyvsp[(9) - (9)]).translation + "\n"; /*tradução: COMMAND*/
                                (yyval).translation += "\t" + (yyvsp[(7) - (9)]).translation + "\n"; /*tradução do incremento, que pode ser vazia*/
                                (yyval).translation += "\t\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginFor*/
                                (yyval).translation += "\t" + labelEndFor + ":\n"; /*tradução: labelEndFor:*/

				/*desempilha o escopo (para os casos de declaração dentro do for)*/
                                declarations += getDeclarations();
				closeCurrentScope(); /*desempilha*/

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;

                        }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 487 "sintatica.y"
    {
                                YYSTYPE expr; /*expressão que controla a parada do for*/
	        	  	YYSTYPE value; /*constante 1*/
	        		YYSTYPE op; /*operação de incremento*/
				YYSTYPE ass; /*atribuição*/

				string labelBeginFor = generateLabel();
				string labelEndFor = generateLabel();

				/*realiza o teste lógico (negado)*/
				expr = runBasicOperation((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), ">");


				/*realiza o incremento*/
				value = generateIntValue(1);
				op = runBasicOperation((yyvsp[(3) - (7)]), value, "+");
				ass.label = (yyvsp[(3) - (7)]).label;
				ass.type = op.type;
				ass.modifier = op.modifier;
				ass.translation = op.translation + "\t" + ass.label + " = " + op.label + ";\n";
				

				findAndReplace(&(expr.translation), (yyvsp[(3) - (7)]).translation, voidStr);
				findAndReplace(&(ass.translation), (yyvsp[(3) - (7)]).translation, voidStr);

				(yyval).translation = (yyvsp[(3) - (7)]).translation; /*tradução da atribuição*/
				(yyval).translation += "\n\t" + labelBeginFor + ":\n"; /*tradução: labelBeginFor:*/
				(yyval).translation += expr.translation; /*tradução da expressão que controla a parada do for*/
				(yyval).translation += "\tif (" + expr.label + ")\n"; /*tradução: if (!E1)*/
				(yyval).translation += "\t\tgoto " + labelEndFor + ";\n\n"; /*tradução: goto labelEndFor*/
				(yyval).translation += (yyvsp[(7) - (7)]).translation; /*tradução: COMMAND*/
				(yyval).translation += ass.translation; /*tradução: da atualização do identicador (atribuição)*/
				(yyval).translation += "\t\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginWhile*/
				(yyval).translation += "\n\t" + labelEndFor + ":\n"; /*tradução: labelEndWhile:*/                                

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 530 "sintatica.y"
    {
				label_struct* l;

				if(((l = findLabel((yyvsp[(1) - (2)]).label)) != NULL) && (l->found == true))
					yyerror("duplicate label " + (yyvsp[(1) - (2)]).label);
				else if(l == NULL)
				{
					(yyval).label = generateLabel();
					labelMap[(yyvsp[(1) - (2)]).label].found = false;
					labelMap[(yyvsp[(1) - (2)]).label].label = (yyval).label;
				}
				else
				{
					labelMap[(yyvsp[(1) - (2)]).label].found = true;
					(yyval).label = labelMap[(yyvsp[(1) - (2)]).label].label;
				}

				labelMap[(yyvsp[(1) - (2)]).label].line = yylineno;

				(yyval).translation = "\t" + (yyval).label + ":\n";
			}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 555 "sintatica.y"
    {
				label_struct* l;

				if((l = findLabel((yyvsp[(2) - (2)]).label)) != NULL)
					(yyval).label = l->label;
                                else
					(yyval).label = generateLabel();

				labelMap[(yyvsp[(2) - (2)]).label].found = false;
				labelMap[(yyvsp[(2) - (2)]).label].label = (yyval).label;
				labelMap[(yyvsp[(2) - (2)]).label].line = yylineno;
                                (yyval).translation = "\tgoto " + (yyval).label + ";\n";
			}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 592 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(2) - (3)]).translation;
                                (yyval).label = (yyvsp[(2) - (3)]).label;
                                (yyval).type = (yyvsp[(2) - (3)]).type;
                                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                
                        }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 599 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(1) - (1)]).translation;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 606 "sintatica.y"
    {
                                    (yyval).translation = (yyvsp[(1) - (1)]).translation;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 613 "sintatica.y"
    {
                                (yyval) = runCast((yyvsp[(4) - (4)]), (yyvsp[(2) - (4)]));
                        }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 617 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 621 "sintatica.y"
    {
                                 (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 625 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 629 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 633 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 637 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 641 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 645 "sintatica.y"
    {
                                relationalControl((yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 650 "sintatica.y"
    {
                                relationalControl((yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 655 "sintatica.y"
    {                                
                                relationalControl((yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 660 "sintatica.y"
    {
                                relationalControl((yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 665 "sintatica.y"
    {
                                relationalControl((yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 670 "sintatica.y"
    {
                                relationalControl((yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 675 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 679 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 683 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 687 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 691 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 695 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";

                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 705 "sintatica.y"
    {
                                 (yyval).label = generateID();

                                if(((yyvsp[(2) - (2)]).type != "int") && ((yyvsp[(2) - (2)]).type != "char"))
                                        yyerror("wrong type argument to bit-complement");

                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";\n";

                                (yyval).type = (yyvsp[(2) - (2)]).type;
                                (yyval).modifier = (yyvsp[(2) - (2)]).type;

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 719 "sintatica.y"
    {
                                       (yyval).translation = (yyvsp[(1) - (1)]).translation;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 726 "sintatica.y"
    {
                                       (yyval).translation = (yyvsp[(1) - (1)]).translation;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 737 "sintatica.y"
    {
                                       id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;
                        
                                if((id = findID((yyvsp[(1) - (2)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(1) - (2)]).label + "'  was not declared in this scope.");
                                else
                                {
                                        (yyvsp[(1) - (2)]).translation = "";
                                        (yyvsp[(1) - (2)]).type = id->type;
                                        (yyvsp[(1) - (2)]).modifier = id->modifier;

                                        (yyval).translation = (yyvsp[(1) - (2)]).translation;
                                        (yyval).label = id->label;
                                        (yyval).type = (yyvsp[(1) - (2)]).type;
                                        (yyval).modifier = (yyvsp[(1) - (2)]).modifier;
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = (yyvsp[(1) - (2)]);
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ((yyvsp[(2) - (2)]).translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, (yyvsp[(1) - (2)]), op);

                                        auxIncreaseTranslation = ass.translation;
                                        flagIncreaseTranslation = true;
                                }
                        }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 780 "sintatica.y"
    {
                                id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;
                        
                                if((id = findID((yyvsp[(2) - (2)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(2) - (2)]).label + "'  was not declared in this scope.");
                                else
                                {
                                        (yyvsp[(2) - (2)]).translation = "";
                                        (yyvsp[(2) - (2)]).type = id->type;
                                        (yyvsp[(2) - (2)]).modifier = id->modifier;
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = (yyvsp[(2) - (2)]);
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ((yyvsp[(1) - (2)]).translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, (yyvsp[(2) - (2)]), op);
                                        
                                        (yyval).translation = ass.translation;
                                        (yyval).label = ass.label;
                                        (yyval).type = ass.type;
                                        (yyval).modifier = ass.modifier;
                                }
                        }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 821 "sintatica.y"
    {
                                if(findID((yyvsp[(1) - (3)]).label) == NULL)
                                        yyerror("identifier: '" + (yyvsp[(1) - (3)]).label + "' was not declared in this scope.");
                                else
                                        (yyval) = assign(voidStr, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                        }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 828 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(1) - (1)]).translation;
                                (yyval).label = (yyvsp[(1) - (1)]).label;
                                (yyval).type = (yyvsp[(1) - (1)]).type;
                                (yyval).modifier = (yyvsp[(1) - (1)]).modifier;
                        }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 838 "sintatica.y"
    {
                                string operation;
                                id_struct* id;

                                YYSTYPE ass;
                                YYSTYPE op_id;
                                YYSTYPE op;

                                if((id = findID((yyvsp[(2) - (3)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(2) - (3)]).label + "'  was not declared in this scope.");
                                else
                                {
                                        
                                        (yyvsp[(1) - (3)]).translation = "";
                                        (yyvsp[(1) - (3)]).type = id->type;
                                        (yyvsp[(1) - (3)]).modifier = id->modifier;

					/*verifica qual operação deve ser realizada*/
					if ((yyvsp[(2) - (3)]).translation == "+=")
						operation = "+";
					else if ((yyvsp[(2) - (3)]).translation == "-=")
						operation = "-";
					else if ((yyvsp[(2) - (3)]).translation == "*=")
						operation = "*";
					else if ((yyvsp[(2) - (3)]).translation == "/=")
						operation = "/";
					else if ((yyvsp[(2) - (3)]).translation == "%=")
						operation = "%";
					else if ((yyvsp[(2) - (3)]).translation == "<<=")
						operation = "<<";
					else if ((yyvsp[(2) - (3)]).translation == ">>=")
						operation = ">>";
					else if ((yyvsp[(2) - (3)]).translation == "&=")
						operation = "&";
					else if ((yyvsp[(2) - (3)]).translation == "|=")
						operation = "|";
					else if ((yyvsp[(2) - (3)]).translation == "^=")
						operation = "^";

                                        /*Realiza as operações referentes a operação*/
                                        op_id = (yyvsp[(1) - (3)]);
                                        op_id.label = id->label;
                                        

                                        op = runBasicOperation(op_id, (yyvsp[(3) - (3)]), operation);
                                        ass = assign(voidStr, (yyvsp[(1) - (3)]), op);

                                        (yyval).translation = ass.translation;
                                        (yyval).label = ass.label;
                                        (yyval).type = ass.type;
                                        (yyval).modifier = ass.modifier;
                                }                                                                
                                
                        }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 896 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(3) - (4)]).translation + "\n\tcout << " + (yyvsp[(3) - (4)]).label + " << endl;\n";
                        }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 904 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(1) - (3)]).translation + (yyvsp[(2) - (3)]).translation;
                                declarations += getDeclarations();
                        }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 909 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 917 "sintatica.y"
    {
                                
                                identifiers_map* IDMap = stackIDMap.front();
                                                        
                                if(!isDeclaredCurrentScope((yyvsp[(3) - (3)]).label))
                                {
                                        (*IDMap)[(yyvsp[(3) - (3)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(3) - (3)]).label].type = (yyvsp[(1) - (3)]).type;
                                        (*IDMap)[(yyvsp[(3) - (3)]).label].modifier = (yyvsp[(1) - (3)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(3) - (3)]).label + "'  previously declared here.");

                                
                                (yyval).label = (*IDMap)[(yyvsp[(3) - (3)]).label].label;
                                (yyval).type = (*IDMap)[(yyvsp[(3) - (3)]).label].type;
                                (yyval).modifier = (*IDMap)[(yyvsp[(3) - (3)]).label].modifier;
                                (yyval).translation = (yyvsp[(1) - (3)]).translation;

                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
                                else
                                        declare((yyval).label, (yyval).type, 1);

                        }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 943 "sintatica.y"
    {
                                string cast = "";
                                string ATTRIBUITION = "";
                                
                                 identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope((yyvsp[(3) - (5)]).label))
                                {
                                        (*IDMap)[(yyvsp[(3) - (5)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(3) - (5)]).label].type = (yyvsp[(1) - (5)]).type;
                                        (*IDMap)[(yyvsp[(3) - (5)]).label].modifier = (yyvsp[(1) - (5)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(3) - (5)]).label + "'  previously declared here.");
                        

                                (yyval) = assign((yyvsp[(1) - (5)]).translation, (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));

                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
                                else
                                        declare((yyval).label, (yyval).type, 1);
                                                        
                        }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 968 "sintatica.y"
    {

                                 identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope((yyvsp[(2) - (2)]).label))
                                {
                                        (*IDMap)[(yyvsp[(2) - (2)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(2) - (2)]).label].type = (yyvsp[(1) - (2)]).type;
                                        (*IDMap)[(yyvsp[(2) - (2)]).label].modifier = (yyvsp[(1) - (2)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(2) - (2)]).label + "'  previously declared here.");


                                (yyval).label = (*IDMap)[(yyvsp[(2) - (2)]).label].label;
                                (yyval).translation = "";
                                (yyval).type = (*IDMap)[(yyvsp[(2) - (2)]).label].type;
                                (yyval).modifier = (*IDMap)[(yyvsp[(2) - (2)]).label].modifier;


                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
                                else
                                        declare((yyval).label, (yyval).type, 1);

                        }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 995 "sintatica.y"
    {

                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope((yyvsp[(2) - (4)]).label))
                                {
                                        (*IDMap)[(yyvsp[(2) - (4)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(2) - (4)]).label].type = (yyvsp[(1) - (4)]).type;
                                        (*IDMap)[(yyvsp[(2) - (4)]).label].modifier = (yyvsp[(1) - (4)]).modifier;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(2) - (4)]).label + "'  previously declared here.");

                                (yyval) = assign(voidStr, (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));


                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
                                else
                                        declare((yyval).label, (yyval).type, 1);

                        }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1022 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1028 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1034 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1040 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1046 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1052 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1058 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";
                                (yyval).translation = "";
                        }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1064 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1070 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1076 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1082 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1088 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1094 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1100 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1106 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1112 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1118 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1124 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1130 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1136 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1142 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1148 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + " " + (yyvsp[(3) - (4)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1154 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + " " + (yyvsp[(3) - (4)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1160 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation + " " + (yyvsp[(3) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1166 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation + " " + (yyvsp[(3) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1176 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "";
 

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1187 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float";
                                (yyval).modifier = "";
  
                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1197 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
          

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1208 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "char";
                                (yyval).modifier = "";
              

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1219 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "";
 

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1230 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float";
                                (yyval).modifier = "";
  
                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1240 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
          

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1251 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "char";
                                (yyval).modifier = "";
              

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1262 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "string";
                                (yyval).modifier = "";

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1272 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";


                                if ((yyvsp[(1) - (1)]).translation == "true")                        
                                        (yyval).translation = "\t" + (yyval).label + " = 1;\n"; /*true*/
                                else
                                        (yyval).translation = "\t" + (yyval).label + " = 0;\n"; /*false*/

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1286 "sintatica.y"
    {
                                id_struct* id;
                        
                                if((id = findID((yyvsp[(1) - (1)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(1) - (1)]).label + "'  was not declared in this scope.");
                                else
                                {
                                        (yyval).label = id->label;
                                        (yyval).type = id->type;
                                        (yyval).modifier = id->modifier;
                                        (yyval).translation = "";
                                }
                        }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1300 "sintatica.y"
    {
                                id_struct* id;
                        
                                if((id = findID((yyvsp[(2) - (2)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(2) - (2)]).label + "'  was not declared in this scope.");
                                else
                                {
					string modifier;					

                                        (yyval).label = generateID();
                                        (yyval).type = id->type;
                                        (yyval).modifier = id->modifier;
                                        (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + id->label + ";\n";

					modifier = (yyval).modifier;
					if(modifier != "")
						modifier+= " ";
			
					declare((yyval).label, modifier + (yyval).type, 1);
                                }
                        }
    break;



/* Line 1806 of yacc.c  */
#line 3357 "y.tab.c"
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
#line 1329 "sintatica.y"


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

void yywarning(string MSG)
{
        warning = true;
        cerr << ":" << yylineno << ": warning: " + MSG << endl;
}


void openNewScope()
{
        identifiers_map* IDMap = new identifiers_map();
        declarations_map* declarationsMap = new declarations_map();

        stackIDMap.push_front(IDMap);
        stackDeclarationsMap.push_front(declarationsMap);
}

void closeCurrentScope()
{
        stackIDMap.pop_front();
        stackDeclarationsMap.pop_front();
}

void relationalControl(YYSTYPE operation)
{
        static string lastOp = "";
        string MSG;
        
        if(relationalCounter > 0)
        {
                if ((operation.translation == "==") || (operation.translation == "!=") || (lastOp == "==") || (lastOp == "!="))
                {
                        lastOp = operation.translation;
                        MSG = "suggest parentheses around comparison in operand of '" + operation.translation + "'";
                }
                else
                        MSG = "comparisons like ‘X<=Y<=Z’ do not have their mathematical meaning";

                yywarning(MSG);
                relationalCounter --;
        }

        if(relationalCounter == 0)
                lastOp = operation.translation;

        relationalCounter++;
}

YYSTYPE runBasicOperation(YYSTYPE operand1, YYSTYPE operand2, string operation)
{
        YYSTYPE* res;

        res = new YYSTYPE();
        
        string resultOperationType;
        id_struct* keyOperating;
        string weakOperatingLabel;
        string strongOperatingLabel;

        res->label = generateID();

        res->translation = operand1.translation + operand2.translation;

        resultOperationType = verifyResultOperation(operand1.type, operand2.type, operation);

        /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
         mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
         no momento da atribuição, que deverá se fazer um cast, caso necessário*/

        res->type = resultOperationType;
        res->modifier = ""; /*desconsidera-se os modificadores*/

        declare(res->label, res->type, 1);

        if((operand1.modifier == operand2.modifier) && (operand1.type == operand2.type))
        {
                res->translation += "\t" + res->label + " = " + operand1.label + " " + operation + " " + operand2.label + ";\n";
        }
        else
        {
                keyOperating = defineKeyOperating(operand1.type, operand1.modifier, operand2.type, operand2.modifier);


                string modifier = keyOperating->modifier;
                modifier += (modifier != "" ? " " : "");

                if(keyOperating->type == operand1.type)
                {
                        weakOperatingLabel = operand2.label;
                        strongOperatingLabel = operand1.label;

                        res->translation += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                        res->translation += "\t" + res->label + " = " + strongOperatingLabel + " " + operation + " " + keyOperating->label + ";\n";
                }
                else
                {
                        weakOperatingLabel = operand1.label;
                        strongOperatingLabel = operand2.label;

                        res->translation += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                        res->translation += "\t" + res->label + " = " + keyOperating->label + " " + operation + " " + strongOperatingLabel + ";\n";
                }


                declare(keyOperating->label, modifier + keyOperating->type, 1);
        }

        return *res;
}



YYSTYPE runCast(YYSTYPE from, YYSTYPE to)
{
        YYSTYPE* res;

        string modifier ;

        res = new YYSTYPE();

        if(!verifyCast(from.type, to.type))
                yyerror("cast from " + from.type + " to " + to.type + " not allowed.");
        else
        {
                
                if(to.type == "string")
                {
                        res = NULL;//ainda deve ser implementado
                }
                else
                {
                        modifier = to.modifier;
                        modifier += (modifier != "" ? " " : "");

                        res->label = generateID();
                        res->type = to.type;
                        res->modifier = to.modifier;

                        res->translation = from.translation + "\t" + res->label + " = (" + modifier + to.type + ") " + from.label + "\n;";

                        declare(res->label, res->modifier + res->type, 1);
                }
        }

        return *res;
}

bool verifyCast(string from, string to)
{
        if(from == "int" && to == "int")
                return true;
        if(from == "float" && to == "float")
                return true;
        if(from == "double" && to == "double")
                return true;
        if(from == "char" && to == "char")
                return true;


        if ((from == "int" && to == "float") || (from == "float" && to == "int"))
                return true;
        if ((from == "int" && to == "double") || (from == "double" && to == "int"))
                return true;
        if ((from == "int" && to == "char") || (from == "char" && to == "int"))
                return true;

        if ((from == "char" && to == "float") || (from == "float" && to == "char"))
                return true;
        if ((from == "char" && to == "double") || (from == "double" && to == "char"))
                return true;

        if ((from == "float" && to == "string"))
                return true;
        if ((from == "float" && to == "double") || (from == "double" && to == "float"))
                return true;

        if ((from == "double" && to == "string"))
                return "string";
        if ((from == "char" && to == "string"))
                return "string";
        if ((from == "int" && to == "string"))
                return "string";
}


id_struct* findID(string label)
{
        list<identifiers_map*>::iterator i;
        
        for(i = stackIDMap.begin(); i != stackIDMap.end(); i++)
        {
                identifiers_map* IDMap = *i;

                if(IDMap->find(label) != IDMap->end())
                {
                        return &(*IDMap)[label];
                }
        }


        return NULL;
}


label_struct* findLabel(string label)
{       
        if(labelMap.find(label) != labelMap.end())
                return &(labelMap)[label];

        return NULL;
}


bool isDeclaredCurrentScope(string label)
{
        identifiers_map* IDMap = stackIDMap.front();

        if(IDMap->find(label) == IDMap->end())
                return false;
        else
                return true;        
}

YYSTYPE assign(string addtranslation, YYSTYPE id, YYSTYPE exp)
{
        YYSTYPE* res;        
        res = new YYSTYPE();
        string cast = "";

        id_struct* identifier = findID(id.label);

        if(identifier == NULL)
                yyerror("identifier: '" + id.label + "'  was not declared in this scope.");

        if (((exp.modifier != identifier->modifier)) || (exp.type != identifier->type))
        {
                //aqui deve-se verificar quais casts são possíveis
                if(id.modifier != "")
                        cast = "(" + identifier->modifier + " " + identifier->type + ") ";
                else
                        cast += "(" + identifier->type + ") ";
        }

        res->label = identifier->label;
        res->translation = addtranslation + exp.translation + "\t" + res->label + " = " + cast + exp.label + ";\n";
        res->type = identifier->type;
        res->modifier = identifier->modifier;

        return *res;

}


YYSTYPE assignNotExpression(YYSTYPE expr)
{
        YYSTYPE* res = new YYSTYPE();
        string modifier = expr.modifier;

        res->label = generateID();
        res->type = expr.type;
        res->modifier = expr.modifier;
        res->translation = "\t" + res->label + " = !" + expr.label + ";\n";

        if(modifier != "")
                modifier += " ";

        declare(res->label, modifier + res->type, 1);

        return *res;
}

YYSTYPE generateIntValue(int value)
{
        YYSTYPE* valueTkn = new YYSTYPE;
        stringstream valueString;

        valueString << value;

        valueTkn->label = generateID();
        valueTkn->translation = "\t" + valueTkn->label + " = " + valueString.str() + ";\n";
        valueTkn->type = "int";
        valueTkn->modifier = "";

        declare(valueTkn->label, valueTkn->type, 1);
        
        return *valueTkn;
}

string generateID()
{
        static int counter = 0;
        stringstream label;

        label << "_temp" << counter++;

        return label.str();
}          

string generateLabel()
{
        static int counterL = 0;
        stringstream label;

        label << "_tempLabel" << counterL++;

        return label.str();
}   


void verifyLabels()
{
        labels_map::iterator i;
	unsigned int line;
        
        for(i = labelMap.begin(); i != labelMap.end(); i++)
        {                        
		if(i->second.found == false)
		{
			line = yylineno; /*backup da linha*/
			yylineno = i->second.line; /*atualiza linha*/
			yyerror("'" + i->first + "' used but not defined");
			yylineno = line; /*atualiza linha*/
		}
	}
}


void declare(string label, string dIType, unsigned int size)
{
        string finalType = dIType;
        
        declarations_map* declarationsMap = stackDeclarationsMap.front();

        if (dIType == "string")
                finalType = "string"; //tem que mudar para char ainda

         declarationsMap->insert(declarations_map::value_type(label, {finalType, size}));
} 

string getDeclarations()
{
        stringstream declarations;

        declarations_map declarationsMap = *stackDeclarationsMap.front();
        declarations_map::iterator i;        
        
        for(i = declarationsMap.begin(); i != declarationsMap.end(); i++)
        {                        
                declarations << "\t" + i->second.dIType; /*tipo com modificadores*/

                declarations << " " + i->first; /*label*/
                
                if (i->second.size > 1)
                        declarations << "[" + i->second.size << "]"; /*tamanho*/

                declarations << ";\n";
        }

        return declarations.str();
}

void findAndReplace(string* source, const string find, const string replace)
{
    for(std::string::size_type i = 0; (i = source->find(find, i)) != std::string::npos;)
    {
        source->replace(i, find.length(), replace);
        i += replace.length() - find.length() + 1;
    }
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
                        yyerror("operation of type: '" + op1Type + " " + sOperator + " " + op2Type + "' not defined.");
        }
        
        return operationsMap[ops];
}

id_struct* defineKeyOperating(string op1Type, string op1Modifier, string op2Type, string op2Modifier)
{
        id_struct* keyOperating = new id_struct;
        
        keyOperating->label = generateID();

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

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";
                        
                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "float";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "double";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

                        
        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";


        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "<";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "<=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = ">";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = ">=";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "==";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "string";
        ops->op2Type = "string";
        ops->sOperator = "!=";
        operationsMap[*ops] = "int";

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
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "&&";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "||";
        operationsMap[*ops] = "int";
}

string   verifyStrongType(string op1Type, string op2Type)
{
        if(op1Type == "int" && op2Type == "int")
                return "int";
        if(op1Type == "float" && op2Type == "float")
                return "float";
        if(op1Type == "double" && op2Type == "double")
                return "double";

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

        if ((op1Type == "char" && op2Type == "float") || (op1Type == "float" && op2Type == "char"))
                return "float";
        if ((op1Type == "char" && op2Type == "double") || (op1Type == "double" && op2Type == "char"))
                return "double";
        if ((op1Type == "char" && op2Type == "string") || (op1Type == "string" && op2Type == "char"))
                return "string";


        if ((op1Type == "float" && op2Type == "string") || (op1Type == "string" && op2Type == "float"))
                return "string";
        if ((op1Type == "float" && op2Type == "double") || (op1Type == "double" && op2Type == "float"))
                return "double";


        if ((op1Type == "double" && op2Type == "string") || (op1Type == "string" && op2Type == "double"))
                return "string";



        yyerror("relation between the types: '" + op1Type + "' and '" + op2Type + "' not defined.");
        return "";

}

