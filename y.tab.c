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
        string typeOfReturn;
        string modifierOfReturn;
        bool declared;
        bool defined;

} function_struct;

typedef struct
{
    string label;
	bool found;

	/*utilizado no tratamento de erros
	 ou warnings*/
	unsigned int line;
} label_struct;


struct args
{
    string label;
    string translation;
    string type; /*auxiliar*/
    string modifier; /*auxiliar*/
	bool   isConstant; /*auxiliar*/

	/*controle para alertar a recursão de operações relacionais*/
	unsigned int relationalCounter;

	int intValue; /*utlizado no case, que apenas permite constantes*/

	/*utilizado para identificar funções*/
	string idFunction;

	/*utilizado para assinaturas das funções*/
	string typesArgsFunction;

	/*utilizado para verificar se tem
	identificador nos argumentos de uma
	função*/
	bool hasIdInArgs;

	/*utilizado no tratamento de erros
	 ou warnings*/
	unsigned int line;
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
        unsigned int length; /*nos casos de string*/
} variable_declarations_struct;


typedef struct
{
	string newLabel;
	YYSTYPE defCase;
} case_label_struct;


typedef map<string, id_struct> identifiers_map;
typedef map<string, variable_declarations_struct> declarations_map;
typedef map<string, function_struct> functions_map;
typedef map<string, label_struct> labels_map;
typedef map<string, case_label_struct> case_label_map;
				

/*pilhas para controle de escopo*/
list<identifiers_map*> stackIDMap;
list<declarations_map*> stackDeclarationsMap;
list<functions_map*> stackFunctionMap;


/*mapa de rótulos*/
labels_map labelMap;

/*pilhas (na verdade listas) de rótulos - usado nos comandos break e continue*/
list<string> stackBeginLabels;
list<string> stackEndLabels;

/*pilha de rótulos para o comando case*/
list<case_label_map*>  stackCaseLabel;

/*pilha de identificadores de funções correntes*/
list<string>idOfCurrentFunction;

/*mapa de operações permititdas*/
map<operation_struct, string> operationsMap;

/*constante string vazia*/
const string voidStr = "";

/*declaraçãoes (todas referente a atual função)*/
string declarations = "";

/*headers de todas as funções*/
string headersFunctions = "";

/*tradução das declarações globais, quando realiza alguma expressão*/
string globalDeclarationsTranslation = "";

/*traduções da main*/
string headMainTranslation = "";
string scopeMainTranslation = "";

/*controle de erro ou warning*/
bool error = false;
bool warning = false;


/*variáveis auxiliares para o controle da tradução do incremento/decremento*/
string auxIncreaseTranslation = "";
bool flagIncreaseTranslation = false;

/*controle de declarações, quando tais não são permititdas (exemplo: if, for, ...)*/
bool flagDeclarationNotAllowed = false;
bool flagDeclarationNotAllowedAux = false;

/*controle do uso do continue e do break*/
bool flagContinue = false;
bool flagBreak = false;

/*controle para verificar se há um CASE (ou um DEFAULT)
fora de um switch*/
bool flagWithinSwitch = false;

/*controle da função main
verifica se há main, e quantas*/
unsigned int countMain = 0;

int yylex(void);
void yyerror(string);
void yywarning(string);
string intToString(int);

void openNewScope();
void closeCurrentScope();
YYSTYPE runBasicOperation(YYSTYPE, YYSTYPE, string);
int runComputingIntValue(YYSTYPE, YYSTYPE, string);
YYSTYPE stringOperation(YYSTYPE, YYSTYPE, string);
YYSTYPE toString(YYSTYPE);
YYSTYPE* runCast(YYSTYPE, YYSTYPE);
bool verifyCast(string, string);
YYSTYPE assign(string, YYSTYPE, YYSTYPE);
YYSTYPE stringAssign(string, YYSTYPE, YYSTYPE);
YYSTYPE assignNotExpression(YYSTYPE);
YYSTYPE generateIntValue(int);
string generateID();
string generateLabel();
void relationalControl(YYSTYPE*, YYSTYPE);
id_struct* findID(string);
label_struct* findLabel(string);
bool isDeclaredCurrentScope(string);
bool isDeclaredFunction(string);
void declare(string, string, unsigned int);
unsigned int getDeclarationLength(YYSTYPE);
bool setDeclarationLength(YYSTYPE, unsigned int);
void verifyLabels();
void verifyMain();
string getDeclarations();
string getFunctionArgs();
void findAndReplace(string*, const string, const string);
string verifyResultOperation(string, string, string);
string verifyStrongType(string, string);
void loadOpearationsMap(void);



/* Line 268 of yacc.c  */
#line 285 "y.tab.c"

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
     TK_COUTN = 302,
     TK_IF = 303,
     TK_ELSE = 304,
     TK_SWITCH = 305,
     TK_CASE = 306,
     TK_DEFAULT = 307,
     TK_FOR = 308,
     TK_EACH = 309,
     TK_WHILE = 310,
     TK_DO = 311,
     TK_BREAK = 312,
     TK_CONTINUE = 313,
     TK_GOTO = 314,
     TK_OP_INCREASE = 315,
     TK_OP_LESS_LESS = 316,
     TK_OP_ASSIGN = 317,
     TK_DOT_DOT = 318,
     TK_GO_LABEL = 319,
     IFX = 320,
     ELSE = 321
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
#define TK_COUTN 302
#define TK_IF 303
#define TK_ELSE 304
#define TK_SWITCH 305
#define TK_CASE 306
#define TK_DEFAULT 307
#define TK_FOR 308
#define TK_EACH 309
#define TK_WHILE 310
#define TK_DO 311
#define TK_BREAK 312
#define TK_CONTINUE 313
#define TK_GOTO 314
#define TK_OP_INCREASE 315
#define TK_OP_LESS_LESS 316
#define TK_OP_ASSIGN 317
#define TK_DOT_DOT 318
#define TK_GO_LABEL 319
#define IFX 320
#define ELSE 321




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 459 "y.tab.c"

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
#define YYLAST   368

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNRULES -- Number of states.  */
#define YYNSTATES  251

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      68,    69,     2,     2,    70,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    67,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,     2,    72,     2,     2,     2,     2,
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
      65,    66
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    13,    18,    20,    23,    26,
      28,    31,    34,    37,    43,    48,    50,    52,    57,    60,
      61,    63,    64,    69,    74,    78,    80,    82,    85,    86,
      89,    92,    95,    98,   100,   102,   104,   106,   108,   111,
     114,   117,   120,   122,   124,   127,   129,   135,   143,   145,
     151,   153,   161,   163,   164,   166,   168,   170,   172,   174,
     184,   192,   195,   199,   202,   205,   207,   209,   211,   217,
     219,   223,   225,   227,   232,   236,   240,   244,   248,   252,
     256,   260,   264,   268,   272,   276,   280,   284,   288,   292,
     296,   300,   304,   307,   310,   312,   314,   317,   320,   324,
     326,   330,   334,   340,   343,   348,   350,   352,   354,   356,
     358,   360,   362,   365,   368,   371,   374,   377,   380,   383,
     385,   387,   391,   395,   399,   403,   407,   412,   417,   421,
     425,   427,   429,   431,   433,   436,   439,   442,   445,   447,
     449,   451,   454,   456
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      74,     0,    -1,    75,    77,    -1,    -1,    13,     9,    81,
      14,    82,    -1,    13,     9,    81,    82,    -1,    78,    -1,
      77,    78,    -1,   115,    67,    -1,    79,    -1,    80,    67,
      -1,    80,    86,    -1,    76,    86,    -1,   116,    10,    81,
      83,    82,    -1,    10,    81,    83,    82,    -1,    68,    -1,
      69,    -1,   116,    84,    70,    83,    -1,   116,    84,    -1,
      -1,    10,    -1,    -1,    46,    68,   109,    69,    -1,    47,
      68,   109,    69,    -1,    87,    89,    88,    -1,    71,    -1,
      72,    -1,    90,    89,    -1,    -1,   109,    67,    -1,    91,
      67,    -1,    85,    67,    -1,   115,    67,    -1,    86,    -1,
      93,    -1,    95,    -1,    97,    -1,   102,    -1,   103,    90,
      -1,   104,    67,    -1,   105,    67,    -1,   106,    67,    -1,
     108,    -1,    67,    -1,    45,   109,    -1,    48,    -1,    92,
      68,   109,    69,    90,    -1,    92,    68,   109,    69,    90,
      49,    90,    -1,    55,    -1,    94,    68,   109,    69,    90,
      -1,    56,    -1,    96,    90,    55,    68,   109,    69,    67,
      -1,   109,    -1,    -1,    98,    -1,   115,    -1,   113,    -1,
     117,    -1,    53,    -1,   101,    68,    99,    67,    98,    67,
      98,    69,    90,    -1,   101,    68,   100,    63,   117,    69,
      90,    -1,    10,    64,    -1,    51,   109,    64,    -1,    52,
      64,    -1,    59,    10,    -1,    58,    -1,    57,    -1,    50,
      -1,   107,    68,   109,    69,    90,    -1,   110,    -1,    68,
     110,    69,    -1,   117,    -1,   113,    -1,    68,   116,    69,
     117,    -1,   110,    24,   110,    -1,   110,    25,   110,    -1,
     110,    26,   110,    -1,   110,    27,   110,    -1,   110,    28,
     110,    -1,   110,    36,   110,    -1,   110,    35,   110,    -1,
     110,    33,   110,    -1,   110,    34,   110,    -1,   110,    29,
     110,    -1,   110,    30,   110,    -1,   110,    31,   110,    -1,
     110,    32,   110,    -1,   110,    38,   110,    -1,   110,    39,
     110,    -1,   110,    40,   110,    -1,   110,    42,   110,    -1,
     110,    43,   110,    -1,    37,   110,    -1,    41,   110,    -1,
     111,    -1,   112,    -1,    10,    60,    -1,    60,    10,    -1,
      10,    44,   110,    -1,   114,    -1,    10,    62,   110,    -1,
     115,    70,    10,    -1,   115,    70,    10,    44,   110,    -1,
     116,    10,    -1,   116,    10,    44,   110,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      17,    -1,    18,    11,    -1,    19,    11,    -1,    18,    13,
      -1,    19,    13,    -1,    20,    13,    -1,    21,    13,    -1,
      21,    16,    -1,    20,    -1,    21,    -1,    18,    20,    13,
      -1,    19,    20,    13,    -1,    18,    21,    13,    -1,    19,
      21,    13,    -1,    21,    21,    13,    -1,    18,    21,    21,
      13,    -1,    19,    21,    21,    13,    -1,    18,    21,    21,
      -1,    19,    21,    21,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,   118,     3,    -1,   118,     4,    -1,   118,
       5,    -1,   118,     6,    -1,     7,    -1,     8,    -1,    10,
      -1,   118,    10,    -1,    24,    -1,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   259,   259,   301,   307,   321,   338,   339,   346,   351,
     352,   368,   402,   422,   453,   488,   497,   502,   534,   566,
     576,   578,   585,   589,   597,   606,   619,   633,   638,   645,
     646,   647,   648,   657,   658,   659,   660,   661,   662,   669,
     670,   671,   672,   673,   681,   721,   728,   747,   772,   791,
     824,   843,   875,   876,   880,   881,   887,   894,   905,   928,
     971,  1038,  1060,  1089,  1115,  1133,  1148,  1163,  1183,  1228,
    1246,  1254,  1255,  1256,  1265,  1269,  1273,  1277,  1281,  1285,
    1289,  1293,  1299,  1305,  1311,  1317,  1323,  1329,  1333,  1337,
    1341,  1345,  1349,  1362,  1379,  1380,  1386,  1429,  1470,  1477,
    1481,  1540,  1567,  1592,  1619,  1646,  1652,  1658,  1664,  1670,
    1676,  1682,  1688,  1694,  1700,  1706,  1712,  1718,  1724,  1730,
    1736,  1742,  1748,  1754,  1760,  1766,  1772,  1778,  1784,  1790,
    1800,  1813,  1824,  1836,  1848,  1860,  1871,  1883,  1895,  1908,
    1923,  1939,  1966,  1966
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
  "TK_OP_BIN_SHIFTL", "TK_ASSIGN", "TK_RETURN", "TK_COUT", "TK_COUTN",
  "TK_IF", "TK_ELSE", "TK_SWITCH", "TK_CASE", "TK_DEFAULT", "TK_FOR",
  "TK_EACH", "TK_WHILE", "TK_DO", "TK_BREAK", "TK_CONTINUE", "TK_GOTO",
  "TK_OP_INCREASE", "TK_OP_LESS_LESS", "TK_OP_ASSIGN", "TK_DOT_DOT",
  "TK_GO_LABEL", "IFX", "ELSE", "';'", "'('", "')'", "','", "'{'", "'}'",
  "$accept", "BEGIN", "START", "MAIN_HEADER", "TRANSLATION_UNIT",
  "EXTERNAL_DECLARATION", "FUNCTION", "FUNCTION_HEADER", "OPEN_ARGS",
  "CLOSE_ARGS", "ARGS", "OPTIONAL_ID", "COUT", "SCOPE", "BEGIN_SCOPE",
  "END_SCOPE", "COMMANDS", "STATEMENT", "RETURN", "IF_C", "IF", "WHILE_C",
  "WHILE", "DO_WHILE_C", "DO_WHILE", "OPTIONAL_E",
  "OPTIONAL_E_OR_DECLARATION", "ATTRIBUITION_OR_TERMINAL", "FOR_C", "FOR",
  "LABEL", "GOTO", "CONTINUE", "BREAK", "SWITCH_C", "SWITCH", "E_C", "E",
  "INCREASE", "PREV_INCREASE", "ATTRIBUITION", "OP_ASSIGN", "DECLARATION",
  "TYPE", "TERMINAL", "SIGNAL", 0
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
     315,   316,   317,   318,   319,   320,   321,    59,    40,    41,
      44,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    81,    82,    83,    83,    83,
      84,    84,    85,    85,    86,    87,    88,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    92,    93,    93,    94,    95,
      96,    97,    98,    98,    99,    99,   100,   100,   101,   102,
     102,   103,   103,   103,   104,   105,   106,   107,   108,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   111,   112,   113,   113,
     114,   115,   115,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   118,   118
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     5,     4,     1,     2,     2,     1,
       2,     2,     2,     5,     4,     1,     1,     4,     2,     0,
       1,     0,     4,     4,     3,     1,     1,     2,     0,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     1,     5,     7,     1,     5,
       1,     7,     1,     0,     1,     1,     1,     1,     1,     9,
       7,     2,     3,     2,     2,     1,     1,     1,     5,     1,
       3,     1,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     1,     2,     2,     3,     1,
       3,     3,     5,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     3,     3,     3,     3,     3,     4,     4,     3,     3,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       1,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,   105,   106,   107,   108,   109,
     110,   111,     0,     0,   119,   120,     0,     2,     6,     9,
       0,     0,     0,    15,    19,     0,   112,   114,     0,     0,
     113,   115,     0,     0,   116,   117,   118,     0,    25,    12,
      28,     7,    10,    11,     8,     0,   103,   107,     0,    21,
       0,   121,   123,   128,   122,   124,   129,   125,   130,   131,
     132,   133,   138,   139,   140,   142,   143,     0,     0,     0,
       0,     0,    45,    67,     0,     0,    58,    48,    50,    66,
      65,     0,     0,    43,     0,     0,    33,     0,    28,     0,
       0,    34,     0,    35,     0,    36,     0,    37,     0,     0,
       0,     0,     0,    42,     0,    69,    94,    95,    72,    99,
       0,     0,    71,     0,   101,     0,    19,    16,    14,    20,
      18,     0,     5,   126,   127,     0,    96,     0,    61,   140,
      92,    93,    44,     0,     0,     0,    63,    64,    97,     0,
       0,    31,    26,    24,    27,    30,     0,     0,     0,    53,
      38,    39,    40,    41,     0,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,   103,   134,   135,   136,   137,
     141,     0,   104,     0,    19,     4,    98,   100,     0,     0,
      62,    70,     0,     0,     0,     0,    54,     0,     0,    52,
      72,    55,    71,     0,    74,    75,    76,    77,    78,    83,
      84,    85,    86,    81,    82,    80,    79,    87,    88,    89,
      90,    91,   102,    13,    17,    22,    23,   140,    73,     0,
       0,     0,    53,     0,     0,    46,    49,     0,     0,     0,
      68,     0,     0,    53,     0,    47,    51,     0,    60,     0,
      59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,    18,    19,    20,    24,   118,
      48,   120,    85,    86,    40,   143,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   196,   197,   198,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -223
static const yytype_int16 yypact[] =
{
    -223,    19,   347,  -223,   -39,  -223,  -223,    50,  -223,  -223,
    -223,  -223,    80,   135,    49,    42,     1,   347,  -223,  -223,
     -24,   -56,    64,  -223,   214,   -39,  -223,  -223,    77,    -1,
    -223,  -223,   100,    47,  -223,  -223,  -223,   128,  -223,  -223,
     199,  -223,  -223,  -223,  -223,   125,   -26,  -223,    75,   137,
      -5,  -223,  -223,   132,  -223,  -223,   138,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,    48,  -223,  -223,    99,    99,    99,
      89,    92,  -223,  -223,    99,    97,  -223,  -223,  -223,  -223,
    -223,   152,   155,  -223,    20,   106,  -223,   102,   199,   109,
      98,  -223,   110,  -223,   199,  -223,   111,  -223,   199,   113,
     114,   134,   153,  -223,   170,   267,  -223,  -223,  -223,  -223,
     -54,   167,  -223,   122,   178,    99,   214,  -223,  -223,  -223,
     168,    75,  -223,  -223,  -223,    99,  -223,    99,  -223,    25,
    -223,  -223,  -223,    99,    99,   175,  -223,  -223,  -223,   247,
     172,  -223,  -223,  -223,  -223,  -223,    99,    99,   187,    20,
    -223,  -223,  -223,  -223,    99,  -223,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,  -223,   204,  -223,  -223,  -223,  -223,
    -223,    99,   267,    75,   214,  -223,   267,   267,   174,   184,
    -223,  -223,    46,   191,   192,   194,  -223,   196,   201,  -223,
     202,   198,   206,   215,    71,    94,    56,   260,  -223,    91,
      91,    91,    91,   313,   313,   293,   293,   144,   144,   144,
     144,   144,   267,  -223,  -223,  -223,  -223,  -223,  -223,   199,
     199,    99,    99,    46,   199,   255,  -223,   239,   244,   243,
    -223,   199,   246,    99,   199,  -223,  -223,   245,  -223,   199,
    -223
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,  -223,   298,  -223,  -223,    21,   -46,
    -108,  -223,  -223,    57,  -223,  -223,   240,   -91,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -222,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,   -68,    27,  -223,  -223,
     180,  -223,     0,    -2,  -144,  -223
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -58
static const yytype_int16 yytable[] =
{
      22,   132,    21,   148,   122,   202,   135,   150,   183,   121,
     238,    44,    52,   174,    45,    22,    45,    21,   115,     3,
      53,   247,    49,    58,    59,    60,    61,    62,    63,    23,
     129,     5,     6,    47,     8,     9,    10,    11,    12,    13,
      14,    15,    23,    42,    65,    66,    50,    38,   228,    58,
      59,    60,    61,    62,    63,    35,   227,    67,    36,    25,
      55,    68,    34,    37,   117,   188,   189,   116,    56,   125,
      65,    66,    38,    39,    46,   185,   224,    43,   193,   194,
      82,   199,   140,   159,   160,   126,   203,   127,    84,   239,
      51,    26,   125,    27,   130,   131,   157,   158,   159,   160,
      28,    29,    58,    59,    60,    61,    62,    63,   126,   129,
     127,   139,   128,    54,    49,   156,   157,   158,   159,   160,
     158,   159,   160,    65,    66,   176,   177,   178,   179,   169,
     170,   171,   180,   172,   173,   114,    67,   223,   235,   236,
      68,    57,   182,   240,   117,   123,    30,   119,    31,   201,
     245,   124,   186,   248,   187,    32,    33,   133,   250,    82,
     134,   136,   137,   237,   199,   138,   146,    84,   156,   157,
     158,   159,   160,   141,   142,   199,   145,   175,   147,   149,
     151,   152,    49,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   153,    58,    59,    60,    61,    62,    63,   222,    64,
       5,     6,    47,     8,     9,    10,    11,    12,    13,    14,
      15,   154,   181,    65,    66,     5,     6,    47,     8,     9,
      10,    11,    12,    13,    14,    15,    67,   155,   184,   190,
      68,   192,   195,   225,    69,    70,    71,    72,   115,    73,
      74,    75,    76,   226,    77,    78,    79,    80,    81,    82,
     229,   230,   231,   232,   233,   -56,    83,    84,    45,   -57,
      38,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   234,   169,   170,   171,   160,   172,
     173,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   241,   169,   170,   171,   242,   172,
     173,   243,   244,   246,   249,    41,   191,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   144,   200,
       0,   169,   170,   171,     0,   172,   173,   156,   157,   158,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,   169,   170,   171,     0,   172,   173,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-223))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,    69,     2,    94,    50,   149,    74,    98,   116,    14,
     232,    67,    13,    67,    70,    17,    70,    17,    44,     0,
      21,   243,    24,     3,     4,     5,     6,     7,     8,    68,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    68,    67,    24,    25,    25,    71,   192,     3,
       4,     5,     6,     7,     8,    13,    10,    37,    16,     9,
      13,    41,    13,    21,    69,   133,   134,    46,    21,    44,
      24,    25,    71,    16,    10,   121,   184,    20,   146,   147,
      60,   149,    84,    27,    28,    60,   154,    62,    68,   233,
      13,    11,    44,    13,    67,    68,    25,    26,    27,    28,
      20,    21,     3,     4,     5,     6,     7,     8,    60,    10,
      62,    84,    64,    13,   116,    24,    25,    26,    27,    28,
      26,    27,    28,    24,    25,     3,     4,     5,     6,    38,
      39,    40,    10,    42,    43,    10,    37,   183,   229,   230,
      41,    13,   115,   234,    69,    13,    11,    10,    13,   149,
     241,    13,   125,   244,   127,    20,    21,    68,   249,    60,
      68,    64,    10,   231,   232,    10,    68,    68,    24,    25,
      26,    27,    28,    67,    72,   243,    67,    10,    68,    68,
      67,    67,   184,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,    67,     3,     4,     5,     6,     7,     8,   181,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    68,    44,    24,    25,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    37,    67,    70,    64,
      41,    69,    55,    69,    45,    46,    47,    48,    44,    50,
      51,    52,    53,    69,    55,    56,    57,    58,    59,    60,
      69,    69,    68,    67,    63,    63,    67,    68,    70,    63,
      71,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    69,    38,    39,    40,    28,    42,
      43,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    49,    38,    39,    40,    69,    42,
      43,    67,    69,    67,    69,    17,    69,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    88,   149,
      -1,    38,    39,    40,    -1,    42,    43,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    42,    43,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    74,    75,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    76,    77,    78,    79,
      80,   115,   116,    68,    81,     9,    11,    13,    20,    21,
      11,    13,    20,    21,    13,    13,    16,    21,    71,    86,
      87,    78,    67,    86,    67,    70,    10,    13,    83,   116,
      81,    13,    13,    21,    13,    13,    21,    13,     3,     4,
       5,     6,     7,     8,    10,    24,    25,    37,    41,    45,
      46,    47,    48,    50,    51,    52,    53,    55,    56,    57,
      58,    59,    60,    67,    68,    85,    86,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    10,    44,    81,    69,    82,    10,
      84,    14,    82,    13,    13,    44,    60,    62,    64,    10,
     110,   110,   109,    68,    68,   109,    64,    10,    10,   110,
     116,    67,    72,    88,    89,    67,    68,    68,    90,    68,
      90,    67,    67,    67,    68,    67,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    38,
      39,    40,    42,    43,    67,    10,     3,     4,     5,     6,
      10,    44,   110,    83,    70,    82,   110,   110,   109,   109,
      64,    69,    69,   109,   109,    55,    98,    99,   100,   109,
     113,   115,   117,   109,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,    82,    83,    69,    69,    10,   117,    69,
      69,    68,    67,    63,    69,    90,    90,   109,    98,   117,
      90,    49,    69,    67,    69,    90,    67,    98,    90,    69,
      90
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
#line 260 "sintatica.y"
    {
							verifyLabels(); /*verifica se há erros relacionados à rótulos*/
							verifyMain();

							if(error)
								exit(1);

							string globalDeclarations = getDeclarations();

							(yyval).translation = "/*Compiler prescot-liller*/\n\n";
							(yyval).translation += "#include <stdio.h>\n#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n";
							(yyval).translation += "using namespace std;\n\n";


							(yyval).translation += "/*-----Cabeçalhos de funções-------*/\n";
							(yyval).translation += headersFunctions;
							(yyval).translation += "/*-------------------------------*/\n\n";

							(yyval).translation += "/*--------Variáveis globais--------*/\n";
							(yyval).translation += globalDeclarations;
							(yyval).translation += "/*-------------------------------*/\n\n";

							
							/*Tradução da main*/
							(yyval).translation += headMainTranslation;
							(yyval).translation += "\t/*Atribuição de variáveis globais*/\n";
							(yyval).translation += globalDeclarationsTranslation;
							(yyval).translation += "\t/*-------------------------------*/\n\n";
							(yyval).translation += scopeMainTranslation;

							(yyval).translation += (yyvsp[(2) - (2)]).translation;

							cout <<  (yyval).translation << endl;

							closeCurrentScope();
                        }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 301 "sintatica.y"
    {
                                openNewScope();        
                        }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 308 "sintatica.y"
    {
							(yyval).translation = "";
							(yyval).idFunction = (yyvsp[(2) - (5)]).translation + " (void)";

                            headMainTranslation = (yyvsp[(1) - (5)]).translation + " " + (yyvsp[(2) - (5)]).translation + '(' + (yyvsp[(4) - (5)]).translation + ')' + "\n";

							idOfCurrentFunction.push_front((yyval).idFunction);

							/*controle da função main
							verifica se há main, e quantas*/
							countMain++;
							verifyMain();
                        }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 322 "sintatica.y"
    {
							(yyval).translation = "";
							(yyval).idFunction = (yyvsp[(2) - (4)]).translation + " (void)";

                            headMainTranslation = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + '(' + ')' + "\n";

							idOfCurrentFunction.push_front((yyval).idFunction);

							/*controle da função main
							verifica se há main, e quantas*/
							countMain++;
							verifyMain();
                        }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 340 "sintatica.y"
    {
							(yyval).translation = (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation;
						}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 347 "sintatica.y"
    {
							globalDeclarationsTranslation += (yyvsp[(1) - (2)]).translation;
							(yyval).translation = "";
						}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 353 "sintatica.y"
    {	
							(yyval).translation = "";
							headersFunctions = (yyvsp[(1) - (2)]).translation;
							headersFunctions += "(" + (yyvsp[(1) - (2)]).typesArgsFunction + ") ;\n";

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();
						}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 369 "sintatica.y"
    {
							functions_map* functionMap;

							if((yyvsp[(1) - (2)]).hasIdInArgs == false)
							{
								int line = yylineno;
								yylineno = (yyvsp[(1) - (2)]).line;							
								yyerror("parameter name omitted");
								yylineno = line;
							}

							(yyval).translation = (yyvsp[(1) - (2)]).translation;
							(yyval).translation += "(" + getFunctionArgs() + ")";
							(yyval).translation += "\n{\n" + declarations + "\n";
							(yyval).translation += (yyvsp[(2) - (2)]).translation + "}\n\n";

							declarations = "";

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();

							/*muda o estado da função para definida*/
							functionMap = stackFunctionMap.front();
							if((*functionMap)[(yyvsp[(1) - (2)]).idFunction].defined == false)
	                            (*functionMap)[(yyvsp[(1) - (2)]).idFunction].defined = true;
							else
								yyerror("'" + (yyval).idFunction + "' previously defined here");

						}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 403 "sintatica.y"
    {
							headMainTranslation += "{\n" + declarations + "\n";
							scopeMainTranslation = (yyvsp[(2) - (2)]).translation;
							scopeMainTranslation += "}\n\n";

							declarations = "";

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();
						}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 423 "sintatica.y"
    {
							string id;
							(yyval).idFunction = (yyvsp[(2) - (5)]).label + "(" + (yyvsp[(4) - (5)]).typesArgsFunction + ")";
							idOfCurrentFunction.push_front((yyval).idFunction);

							functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                                                        
                            if(isDeclaredFunction((yyval).idFunction) == false)
							{
									id = generateID();
                                    (*functionMap)[(yyval).idFunction].label = id;
                                    (*functionMap)[(yyval).idFunction].typeOfReturn = (yyvsp[(1) - (5)]).type;
                                    (*functionMap)[(yyval).idFunction].modifierOfReturn = (yyvsp[(1) - (5)]).modifier;
                                    (*functionMap)[(yyval).idFunction].declared = true;
                                    (*functionMap)[(yyval).idFunction].defined = false;
							}
							else// if ((*functionMap)[$$.idFunction].defined == false)
							{
									id = (*functionMap)[(yyval).idFunction].label;
									//(*functionMap)[$$.idFunction].defined = true;
							}
							//else
									//yyerror("'" + $$.idFunction + "' previously defined here");

							(yyval).label = id;
							(yyval).typesArgsFunction = (yyvsp[(4) - (5)]).typesArgsFunction;
							(yyval).translation = (yyvsp[(1) - (5)]).type + " " + id;// + '(' + $4.translation + ')';
							(yyval).hasIdInArgs = (yyvsp[(4) - (5)]).hasIdInArgs;
							(yyval).line = (yyvsp[(4) - (5)]).line;
						}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 454 "sintatica.y"
    {
							string id;
							(yyval).idFunction = (yyvsp[(1) - (4)]).label + "(" + (yyvsp[(3) - (4)]).typesArgsFunction + ")";
							idOfCurrentFunction.push_front((yyval).idFunction);

							functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                                                        
                            if(!isDeclaredFunction((yyval).idFunction))
							{
									id = generateID();
                                    (*functionMap)[(yyval).idFunction].label = id;
                                    (*functionMap)[(yyval).idFunction].typeOfReturn = "void";
                                    (*functionMap)[(yyval).idFunction].modifierOfReturn = "";
                                    (*functionMap)[(yyval).idFunction].declared = true;
                                    (*functionMap)[(yyval).idFunction].defined = false;
							}
							else// if ((*functionMap)[$$.idFunction].defined == false)
							{
									id = (*functionMap)[(yyval).idFunction].label;
									//(*functionMap)[$$.idFunction].defined = true;
							}
							//else
									//yyerror("'" + $$.idFunction + "' previously defined here");

							(yyval).label = id;
							(yyval).typesArgsFunction = (yyvsp[(3) - (4)]).typesArgsFunction;
		                    (yyval).translation = "void" + id;// + '(' + $3.translation + ')';
							(yyval).hasIdInArgs = (yyvsp[(3) - (4)]).hasIdInArgs;
							(yyval).line = (yyvsp[(3) - (4)]).line;
						}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 489 "sintatica.y"
    {
							/*cria uma nova entrada na pilha
							para armazenar os argumentos da função*/
							openNewScope();
						}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 503 "sintatica.y"
    {
								if((yyvsp[(2) - (4)]).label != "")							   	
								{
									identifiers_map* IDMap = stackIDMap.front();

		                            (*IDMap)[(yyvsp[(2) - (4)]).label].label = generateID();
		                            (*IDMap)[(yyvsp[(2) - (4)]).label].type = (yyvsp[(1) - (4)]).type;
		                            (*IDMap)[(yyvsp[(2) - (4)]).label].modifier = (yyvsp[(1) - (4)]).modifier;

									(yyval).label = (*IDMap)[(yyvsp[(2) - (4)]).label].label;
									(yyval).type = (*IDMap)[(yyvsp[(2) - (4)]).label].type;
									(yyval).modifier = (*IDMap)[(yyvsp[(2) - (4)]).label].modifier;

									(yyval).translation = (yyval).type + " " + (yyval).label + ", " + (yyvsp[(4) - (4)]).translation;
									(yyval).typesArgsFunction = (yyval).type + ", " + (yyvsp[(4) - (4)]).typesArgsFunction;
									(yyval).hasIdInArgs = (yyvsp[(4) - (4)]).hasIdInArgs &&  true;

		                            if ((yyval).modifier != "")
		                                    declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
		                            else
		                                    declare((yyval).label, (yyval).type, 1);
								}
								else
								{
									(yyval).translation = (yyval).type + ", " + (yyvsp[(4) - (4)]).translation;
									(yyval).typesArgsFunction = (yyval).type + ", " + (yyvsp[(4) - (4)]).typesArgsFunction;
									(yyval).hasIdInArgs = (yyvsp[(4) - (4)]).hasIdInArgs && false;
									(yyval).line = yylineno;
								}
									 
						}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 535 "sintatica.y"
    {
							if((yyvsp[(2) - (2)]).label != "")
							{
								identifiers_map* IDMap = stackIDMap.front();

		                        (*IDMap)[(yyvsp[(2) - (2)]).label].label = generateID();
		                        (*IDMap)[(yyvsp[(2) - (2)]).label].type = (yyvsp[(1) - (2)]).type;
		                        (*IDMap)[(yyvsp[(2) - (2)]).label].modifier = (yyvsp[(1) - (2)]).modifier;

								(yyval).label = (*IDMap)[(yyvsp[(2) - (2)]).label].label;
								(yyval).type = (*IDMap)[(yyvsp[(2) - (2)]).label].type;
								(yyval).modifier = (*IDMap)[(yyvsp[(2) - (2)]).label].modifier;

								(yyval).translation = (yyval).type + " " + (yyval).label;
								(yyval).typesArgsFunction = (yyvsp[(1) - (2)]).type;
								(yyval).hasIdInArgs = true;

		                        if ((yyval).modifier != "")
		                                declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
		                        else
		                                declare((yyval).label, (yyval).type, 1);							
							}
							else
							{
									(yyval).translation = (yyval).type;
									(yyval).typesArgsFunction = (yyval).translation;
									(yyval).hasIdInArgs = false;
									(yyval).line = yylineno;
							}
						}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 566 "sintatica.y"
    {
							(yyval).translation = "";
							(yyval).typesArgsFunction = "void";
							(yyval).hasIdInArgs = true;
							(yyval).line = yylineno;
						}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 578 "sintatica.y"
    {
							(yyval).label = "";
						}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 586 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(3) - (4)]).translation + "\n\tcout << " + (yyvsp[(3) - (4)]).label + ";\n";
                        }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 590 "sintatica.y"
    {
	                           (yyval).translation = (yyvsp[(3) - (4)]).translation + "\n\tcout << " + (yyvsp[(3) - (4)]).label + " << endl;\n";
                        }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 598 "sintatica.y"
    {
                                (yyval).translation =  (yyvsp[(1) - (3)]).translation + (yyvsp[(2) - (3)]).translation + (yyvsp[(3) - (3)]).translation;
                        }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 607 "sintatica.y"
    {
                                openNewScope();                        
                                (yyval).translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
								flagDeclarationNotAllowedAux = flagDeclarationNotAllowed;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 620 "sintatica.y"
    {
                                declarations += getDeclarations();
                                closeCurrentScope(); /*desempilha*/                                
                                (yyval).translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
                                flagDeclarationNotAllowed = flagDeclarationNotAllowedAux;

                        }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 634 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(1) - (2)]).translation + "\n" + (yyvsp[(2) - (2)]).translation;
                        }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 638 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 649 "sintatica.y"
    {
                                /*controle de declarações, quando tais não são permititdas (exemplo: if, for, ...)*/
                                if(flagDeclarationNotAllowed)
                                {
                                        yyerror("declarations not allowed.");
                                        flagDeclarationNotAllowed = false;
                                }
                        }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 663 "sintatica.y"
    {
							(yyval).translation = (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation;
							(yyval).label = (yyvsp[(2) - (2)]).label;
							(yyval).type = (yyvsp[(2) - (2)]).type;
							(yyval).modifier = (yyvsp[(2) - (2)]).modifier;
						}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 674 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 682 "sintatica.y"
    {
								functions_map* functionMap;
								functions_map::iterator i;

								YYSTYPE* cast;
								YYSTYPE func;
								function_struct f;

								functionMap = *next(stackFunctionMap.begin(), 2);
								i = functionMap->find(idOfCurrentFunction.front());

								if(i != functionMap->end())
								{
									f = i->second;

									if(f.typeOfReturn != (yyvsp[(2) - (2)]).type)
									{
										func.type = f.typeOfReturn;										
										func.modifier = f.modifierOfReturn;	

										cast = runCast((yyvsp[(2) - (2)]), func);

										if(cast == NULL)
							            	yyerror("cast from " + (yyvsp[(2) - (2)]).type + " to " + func.modifier + " " + func.type + " not allowed");
										else
											(yyval).translation = (yyvsp[(2) - (2)]).translation + cast->translation + "\n\t" + (yyvsp[(1) - (2)]).translation + " " + cast->label + ";";
									}
									else
		                                	(yyval).translation = (yyvsp[(2) - (2)]).translation + "\n\t" + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label+ ";";
								}
								else
	                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\n\t" + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";";		
                        }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 722 "sintatica.y"
    {
							/*controle de declaraçãoes*/
							                flagDeclarationNotAllowed = true;
						}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 729 "sintatica.y"
    {                                
                                YYSTYPE notE;
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression((yyvsp[(3) - (5)]));

                                (yyval).translation = (yyvsp[(3) - (5)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\t" + (yyvsp[(1) - (5)]).translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += (yyvsp[(5) - (5)]).translation + "\n"; /*tradução: STATEMENT*/
                                (yyval).translation += "\t" + labelEndIF + ":\n"; /*tradução: labelEndIF:*/

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;

                        }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 748 "sintatica.y"
    {
                                YYSTYPE notE;
                                string labelEndCmd1 = generateLabel();
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression((yyvsp[(3) - (7)]));

                                (yyval).translation = (yyvsp[(3) - (7)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\t" + (yyvsp[(1) - (7)]).translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndCmd1 + ";\n\n"; /*tradução: goto labelCmd1*/
                                (yyval).translation += (yyvsp[(5) - (7)]).translation + "\n"; /*tradução: STATEMENT*/
                                (yyval).translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += "\t" + labelEndCmd1 + ":\n"; /*tradução: labelEndCmd1:*/
                                (yyval).translation += (yyvsp[(7) - (7)]).translation + "\n"; /*tradução: COMMAND (2)*/
                                (yyval).translation += "\t" + labelEndIF + ":\n"; /*tradução: labelEndId:*/

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 773 "sintatica.y"
    {
							/*controle de declaraçãoes*/
						                    flagDeclarationNotAllowed = true;

							/*controle do continue e do break*/
							flagContinue = true;
							flagBreak = true;

						                    string labelBeginWhile = generateLabel();
						                    string labelEndWhile = generateLabel();

							/*empilha os labels*/
							stackBeginLabels.push_front(labelBeginWhile);
							stackEndLabels.push_front(labelEndWhile);
						}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 792 "sintatica.y"
    {
                                YYSTYPE notE;
                                string labelBeginWhile = stackBeginLabels.front();
                                string labelEndWhile = stackEndLabels.front();
        
                                notE = assignNotExpression((yyvsp[(3) - (5)]));

                                (yyval).translation = "\n\t" + labelBeginWhile + ":\n"; /*tradução: labelBeginWhile:*/
                                (yyval).translation += (yyvsp[(3) - (5)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\tif (" + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndWhile + ";\n\n"; /*tradução: goto labelEndWhile*/
                                (yyval).translation += (yyvsp[(5) - (5)]).translation + "\n"; /*tradução: STATEMENT*/
                                (yyval).translation += "\t\tgoto " + labelBeginWhile + ";\n"; /*tradução: goto labelBeginWhile*/
                                (yyval).translation += "\t" + labelEndWhile + ":\n"; /*tradução: labelEndWhile:*/


								/*desempilha os labels*/
								stackBeginLabels.pop_front();
								stackEndLabels.pop_front();

								/*controle do continue e do break*/
								flagContinue = false;
								flagBreak = false;

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 825 "sintatica.y"
    {
					/*controle de declaraçãoes*/
		                            flagDeclarationNotAllowed = true;

					/*controle do continue e do break*/
					flagContinue = true;
					flagBreak = true;

		                            string labelBeginDoWhile = generateLabel();
		                            string labelEndDoWhile = generateLabel();

					/*empilha os labels*/
					stackBeginLabels.push_front(labelBeginDoWhile);
					stackEndLabels.push_front(labelEndDoWhile);
				}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 844 "sintatica.y"
    {
                                string labelBeginDoWhile = stackBeginLabels.front();
                                string labelEndDoWhile = stackEndLabels.front();


                                (yyval).translation = "\n\t" + labelBeginDoWhile + ":\n"; /*tradução: labelBeginDoWhileIF:*/
                                (yyval).translation += (yyvsp[(2) - (7)]).translation + "\n"; /*tradução: STATEMENT*/
                                (yyval).translation += (yyvsp[(5) - (7)]).translation; /*tradução da expressão E*/
                                (yyval).translation += "\tif (" + (yyvsp[(5) - (7)]).label + ")\n"; /*tradução: if (E)*/
                                (yyval).translation += "\t\tgoto " + labelBeginDoWhile + ";\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += "\t" + labelEndDoWhile + ":\n\n"; /*tradução: labelEndDoWhileIF:*/


								/*desempilha os labels*/
								stackBeginLabels.pop_front();
								stackEndLabels.pop_front();

								/*controle do continue e do break*/
								flagContinue = false;
								flagBreak = false;


								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 888 "sintatica.y"
    {
								(yyval).translation = (yyvsp[(1) - (1)]).translation;
								(yyval).label = (yyvsp[(1) - (1)]).label;
								(yyval).type = (yyvsp[(1) - (1)]).type;
								(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
							}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 895 "sintatica.y"
    {
								(yyval).translation = (yyvsp[(1) - (1)]).translation;
								(yyval).label = (yyvsp[(1) - (1)]).label;
								(yyval).type = (yyvsp[(1) - (1)]).type;
								(yyval).modifier = (yyvsp[(1) - (1)]).modifier;
							}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 906 "sintatica.y"
    {
				/*controle de declaraçãoes*/
		        flagDeclarationNotAllowed = true;

				/*para os casos de declaração dentro do for*/
                                openNewScope();

				/*controle do continue e do break*/
				flagContinue = true;
				flagBreak = true;

                string labelIncreaseFor = generateLabel();
                string labelEndFor = generateLabel();

				/*empilha os labels*/
				stackBeginLabels.push_front(labelIncreaseFor);
				stackEndLabels.push_front(labelEndFor);

			}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 929 "sintatica.y"
    {
                            YYSTYPE notE;
                            string labelBeginFor = generateLabel();
                            string labelIncreaseFor = stackBeginLabels.front();
                            string labelEndFor = stackEndLabels.front();


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

							(yyval).translation += (yyvsp[(9) - (9)]).translation + "\n"; /*tradução: STATEMENT*/
                            (yyval).translation += "\t" + labelIncreaseFor + ":\n"; /*tradução: labelIncreaseFor:*/
                            (yyval).translation += (yyvsp[(7) - (9)]).translation + "\n"; /*tradução do incremento, que pode ser vazia*/
                            (yyval).translation += "\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginFor*/
                            (yyval).translation += "\t" + labelEndFor + ":\n"; /*tradução: labelEndFor:*/


							/*desempilha os labels*/
							stackBeginLabels.pop_front();
							stackEndLabels.pop_front();

							/*controle do continue e do break*/
							flagContinue = false;
							flagBreak = false;

							/*desempilha o escopo (para os casos de declaração dentro do for)*/
							declarations += getDeclarations();
							closeCurrentScope(); /*desempilha*/

							/*controle de declaraçãoes*/
							flagDeclarationNotAllowedAux = false;
							                flagDeclarationNotAllowed = false;

                    }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 972 "sintatica.y"
    {
                            YYSTYPE expr; /*expressão que controla a parada do for*/
						  	YYSTYPE value; /*constante 1*/
							YYSTYPE op; /*operação de incremento*/
							YYSTYPE ass; /*atribuição*/

                            string labelBeginFor = generateLabel();
                            string labelIncreaseFor = stackBeginLabels.front();
                            string labelEndFor = stackEndLabels.front();


							/*notifica caso os limitantes não sejam inteiros*/
							if(((yyvsp[(3) - (7)]).type != "int") || ((yyvsp[(5) - (7)]).type != "int"))
								yywarning("counter is not an integer");

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


							(yyval).translation += (yyvsp[(7) - (7)]).translation + "\n"; /*tradução: STATEMENT*/
							                (yyval).translation += "\t" + labelIncreaseFor + ":\n"; /*tradução: labelIncreaseFor:*/
							(yyval).translation += ass.translation; /*tradução: da atualização do identicador (atribuição)*/
							(yyval).translation += "\t\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginFor*/
							(yyval).translation += "\n\t" + labelEndFor + ":\n"; /*tradução: labelEndFor:*/                                


							/*desempilha os labels*/
							stackBeginLabels.pop_front();
							stackEndLabels.pop_front();

							/*controle do continue e do break*/
							flagContinue = false;
							flagBreak = false;

							/*desempilha o escopo (para os casos de declaração dentro do for)*/
							                declarations += getDeclarations();
							closeCurrentScope(); /*desempilha*/


							/*controle de declaraçãoes*/
							flagDeclarationNotAllowedAux = false;
			                flagDeclarationNotAllowed = false;
                    }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 1039 "sintatica.y"
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

  case 62:

/* Line 1806 of yacc.c  */
#line 1061 "sintatica.y"
    {
				case_label_map* caseLabelMap = stackCaseLabel.front();
				string newLabel;
				string key;
			
				/*chave do mapa de cases (labels) é dado por intValue*/
				key = intToString((yyvsp[(2) - (3)]).intValue);


				/*verifica-se a presença de uma não constante na expressão*/
				if((yyvsp[(2) - (3)]).isConstant == false)
					yyerror("case label does not reduce to an integer constant");

				/*verifica se o case está dentro de um switch*/
				else if (flagWithinSwitch == false)
					yyerror("case label not within a switch statement");

				/*verifica se já existe um case com o mesmo valor*/
				else if (caseLabelMap->find(key) != caseLabelMap->end())
					yyerror("duplicate case value");
				else
				{
					newLabel = generateLabel();

					(yyval).translation = (yyvsp[(2) - (3)]).translation + "\t" + newLabel + ":\n";
					caseLabelMap->insert(case_label_map::value_type(key, {newLabel, (yyvsp[(2) - (3)])}));
				}
			}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 1090 "sintatica.y"
    {
				case_label_map* caseLabelMap = stackCaseLabel.front();
				string newLabel;

				/*verifica se o default está dentro de um switch*/
				if (flagWithinSwitch == false)
					yyerror("‘default’ label not within a switch statement");

				/*verifica se já existe um outro default no switch*/
				else if (caseLabelMap->find((yyvsp[(1) - (2)]).translation) != caseLabelMap->end())
					yyerror("multiple default labels in one switch");

				else
				{
					newLabel = "_default";				
					
					(yyval).translation = "\t" + newLabel + ":\n"; 
					caseLabelMap->insert(case_label_map::value_type((yyvsp[(1) - (2)]).translation, {newLabel, (yyvsp[(1) - (2)])}));
				}
			}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 1116 "sintatica.y"
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

  case 65:

/* Line 1806 of yacc.c  */
#line 1134 "sintatica.y"
    {
				if(!flagContinue)
					yyerror("continue statement not within a loop");
				else
				{			

					/*obtém o primeiro label da pilha de Begins*/
					string label = stackBeginLabels.front();
					(yyval).translation = "\tgoto " + label + ";\n";
				}
			}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 1149 "sintatica.y"
    {
				if(!flagBreak)
					yyerror("break statement not within loop or switch");
				else
				{	
					/*obtém o primeiro label da pilha de Begins*/
					string label = stackEndLabels.front();

					(yyval).translation = "\tgoto " + label + ";\n";
				}
			}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 1164 "sintatica.y"
    {
				/*controle do break*/
				flagBreak = true;
				
				/*controle do case e do default*/
				flagWithinSwitch = true;

                                string labelEndSwitch = generateLabel();

				/*empilha os labels*/
				stackEndLabels.push_front(labelEndSwitch);

				/*insere um novo mapa de rótulos de case na pilha*/
				case_label_map* caseLabelMap = new case_label_map();
				stackCaseLabel.push_front(caseLabelMap);
			}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 1184 "sintatica.y"
    {
				YYSTYPE ass;
				YYSTYPE op;

				string labelEndSwitch = stackEndLabels.front();

				(yyval).translation = (yyvsp[(3) - (5)]).translation;

				case_label_map* caseLabelMap = stackCaseLabel.front();
				case_label_map::iterator i;
        
				for(i = caseLabelMap->begin(); i != caseLabelMap->end(); i++)
				{                        
					if(i->first != "default")
					{
						op = runBasicOperation((yyvsp[(3) - (5)]), i->second.defCase, "==");
	  									
						(yyval).translation += op.translation + "\tif(" + op.label + ")\n";
						(yyval).translation += "\t\tgoto " + i->second.newLabel + ";\n";
					}
					else
						(yyval).translation += "\n\tgoto " + i->second.newLabel + ";\n";
				}

				(yyval).translation += (yyvsp[(5) - (5)]).translation; /*tradução do statement*/
				(yyval).translation += "\t" + labelEndSwitch + ":\n";


				/*desempilha o label de fim*/
				stackEndLabels.pop_front();
	
				/*desempilha o case*/
				stackCaseLabel.pop_front();

				/*controle do break*/
				flagBreak = false;

				/*controle do case e do default*/
				flagWithinSwitch = false;
			}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 1229 "sintatica.y"
    {
				/*controle para alertar a recursão de operações relacionais*/
                                (yyval).relationalCounter = 0;

                                /*controle da tradução do incremento/decremento*/
                                if(flagIncreaseTranslation)
                                {
                                        (yyval).translation += auxIncreaseTranslation;
                                        flagIncreaseTranslation = false;
                                        auxIncreaseTranslation = "";
                                }

			}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 1247 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(2) - (3)]).translation;
                                (yyval).label = (yyvsp[(2) - (3)]).label;
                                (yyval).type = (yyvsp[(2) - (3)]).type;
                                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                
                                (yyval).isConstant = (yyvsp[(2) - (3)]).isConstant; 
                        }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 1257 "sintatica.y"
    {
	                        (yyval) = *runCast((yyvsp[(4) - (4)]), (yyvsp[(2) - (4)]));

							if((yyval).label == "")
			                	yyerror("cast from " + (yyvsp[(4) - (4)]).type + " to " + (yyvsp[(2) - (4)]).type + " not allowed");

								(yyval).translation = (yyvsp[(4) - (4)]).translation + (yyval).translation;
                        }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 1266 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 1270 "sintatica.y"
    {
                                 (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 1274 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 1278 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1282 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1286 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1290 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1294 "sintatica.y"
    {

                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1300 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1306 "sintatica.y"
    {                                
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1312 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1318 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1324 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1330 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1334 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1338 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1342 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1346 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1350 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";

                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";\n";                                
                                
                                if((yyvsp[(2) - (2)]).type == "int")
                                	(yyval).intValue = !(yyvsp[(2) - (2)]).intValue;

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1363 "sintatica.y"
    {
                                 (yyval).label = generateID();

                                if(((yyvsp[(2) - (2)]).type != "int") && ((yyvsp[(2) - (2)]).type != "char"))
                                        yyerror("wrong type argument to bit-complement");

                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";\n";

                                (yyval).type = (yyvsp[(2) - (2)]).type;
                                (yyval).modifier = (yyvsp[(2) - (2)]).type;
                                                             
                                if((yyvsp[(2) - (2)]).type == "int")
                                	(yyval).intValue = ~(yyvsp[(2) - (2)]).intValue;

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1387 "sintatica.y"
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

  case 97:

/* Line 1806 of yacc.c  */
#line 1430 "sintatica.y"
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

  case 98:

/* Line 1806 of yacc.c  */
#line 1471 "sintatica.y"
    {
                                if(findID((yyvsp[(1) - (3)]).label) == NULL)
                                        yyerror("identifier: '" + (yyvsp[(1) - (3)]).label + "' was not declared in this scope.");
                                else
                                        (yyval) = assign(voidStr, (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                        }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1482 "sintatica.y"
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

  case 101:

/* Line 1806 of yacc.c  */
#line 1541 "sintatica.y"
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

  case 102:

/* Line 1806 of yacc.c  */
#line 1568 "sintatica.y"
    {
                                string ATTRIBUITION = "";
								unsigned int length;
                                
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
								length = getDeclarationLength((yyval));

                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, length);
                                else
                                        declare((yyval).label, (yyval).type, length);
                                                        
                        }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1593 "sintatica.y"
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

  case 104:

/* Line 1806 of yacc.c  */
#line 1620 "sintatica.y"
    {

								unsigned int length;
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
								length = getDeclarationLength((yyval));
				
                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, length);
                                else
                                        declare((yyval).label, (yyval).type, length);
                        }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1647 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1653 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1659 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1665 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1671 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1677 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1683 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";
                                (yyval).translation = "";
                        }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1689 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 1695 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1701 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1707 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1713 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1719 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1725 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1731 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1737 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1743 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1749 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1755 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1761 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1767 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1773 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + " " + (yyvsp[(3) - (4)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1779 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + " " + (yyvsp[(3) - (4)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1785 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation + " " + (yyvsp[(3) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1791 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation + " " + (yyvsp[(3) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1801 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
								(yyval).intValue = (yyvsp[(1) - (1)]).intValue;
 

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1814 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
  
                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1825 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
          

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1837 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "char";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
              

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1849 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
 

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1861 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
  
                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1872 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
          

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1884 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "char";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
              

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + "\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1896 "sintatica.y"
    {                        

			       				(yyval).label = generateID();
                                (yyval).type = "string";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;

								(yyval).translation = "\tstrcpy(" + (yyval).label + ", " + (yyvsp[(1) - (1)]).translation + ");\n";                           

								/*comprimento da string '-2' por conta das aspas*/
                                declare((yyval).label, (yyval).type, (yyvsp[(1) - (1)]).translation.length() - 2);
                        }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1909 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";
                               	(yyval).isConstant = true;


                                if ((yyvsp[(1) - (1)]).translation == "true")                        
                                        (yyval).translation = "\t" + (yyval).label + " = 1;\n"; /*true*/
                                else
                                        (yyval).translation = "\t" + (yyval).label + " = 0;\n"; /*false*/

                                declare((yyval).label, (yyval).modifier + " " + (yyval).type, 1);
                        }
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1924 "sintatica.y"
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

                               	(yyval).isConstant = false;
                        }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1940 "sintatica.y"
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

                               	(yyval).isConstant = false;
                        }
    break;



/* Line 1806 of yacc.c  */
#line 4051 "y.tab.c"
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
#line 1972 "sintatica.y"


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

string intToString(int n)
{
	stringstream declarations;
	
	declarations << n;
	return declarations.str();
}


void openNewScope()
{
        identifiers_map* IDMap = new identifiers_map();
        declarations_map* declarationsMap = new declarations_map();
        functions_map* functionMap = new functions_map();

        stackIDMap.push_front(IDMap);
        stackDeclarationsMap.push_front(declarationsMap);
        stackFunctionMap.push_front(functionMap);
}

void closeCurrentScope()
{
        stackIDMap.pop_front();
        stackDeclarationsMap.pop_front();
		stackFunctionMap.pop_front();
}

void relationalControl(YYSTYPE* expr, YYSTYPE operation)
{
        static string lastOp = "";
        string MSG;


        if(expr->relationalCounter > 0)
        {
                if ((operation.translation == "==") || (operation.translation == "!=") || (lastOp == "==") || (lastOp == "!="))
                {
                        lastOp = operation.translation;
                        MSG = "suggest parentheses around comparison in operand of '" + operation.translation + "'";
                }
                else
                        MSG = "comparisons like ‘X<=Y<=Z’ do not have their mathematical meaning";

                yywarning(MSG);
                expr->relationalCounter = expr->relationalCounter - 1;
        }

        if(expr->relationalCounter == 0)
                lastOp = operation.translation;

        expr->relationalCounter = expr->relationalCounter + 1;

	//cout << "//" << expr->relationalCounter << endl;
}

YYSTYPE runBasicOperation(YYSTYPE operand1, YYSTYPE operand2, string operation)
{
        YYSTYPE* res; /*resultado da operação*/
        res = new YYSTYPE();
        
        string resultOperationType;

	/*operando chave - operando em que o cast 
	será atribuído, qual este for necessário*/
        YYSTYPE keyOperand;

	//Tipo forte
	string strongType;	

	/*no caso de operação com strings*/
	if((operand1.type == "string") || (operand2.type == "string"))
		return stringOperation(operand1, operand2, operation);

	/*no caso de inteiros, preenche-se o campo intValue*/
	if(operand1.type == "int" && operand2.type == "int")
		res->intValue = runComputingIntValue(operand1, operand2, operation);
		

        res->label = generateID();
        res->translation = operand1.translation + operand2.translation;

	/*verifica-se a operação é permitida*/
        resultOperationType = verifyResultOperation(operand1.type, operand2.type, operation);

        /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
         mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
         no momento da atribuição, que deverá se fazer um cast, caso necessário*/

        res->type = resultOperationType;
        res->modifier = ""; /*desconsidera-se os modificadores*/
	res->isConstant = operand1.isConstant && operand2.isConstant;

        declare(res->label, res->type, 1);


        if(((operand1.modifier == operand2.modifier) || ((operand1.modifier == "") || (operand2.modifier == ""))) && (operand1.type == operand2.type))
        {
                res->translation += "\t" + res->label + " = " + operand1.label + " " + operation + " " + operand2.label + ";\n";
        }
        else
        {	
		strongType = verifyStrongType(operand1.type, operand2.type);

                if(operand1.type == strongType)
                {
			keyOperand = *runCast(operand2, operand1);

			res->translation += keyOperand.translation;
                        res->translation += "\t" + res->label + " = " + operand1.label + " " + operation + " " + keyOperand.label + ";\n";
                }
                else
                {
			keyOperand = *runCast(operand1, operand2);

			res->translation += keyOperand.translation;
                        res->translation += "\t" + res->label + " = " + keyOperand.label + " " + operation + " " + operand2.label + ";\n";
                }
        }

        return *res;
}


int runComputingIntValue(YYSTYPE operand1, YYSTYPE operand2, string operation)
{
	if(operation == "+")
		return operand1.intValue + operand2.intValue;
	else if(operation == "-")
		return operand1.intValue - operand2.intValue;
	else if(operation == "*")
		return operand1.intValue * operand2.intValue;
	else if(operation == "/")
		return operand1.intValue / operand2.intValue;
	else if(operation == "%")
		return operand1.intValue % operand2.intValue;
	else if(operation == "<")
		return operand1.intValue < operand2.intValue;
	else if(operation == ">")
		return operand1.intValue > operand2.intValue;
	else if(operation == "<=")
		return operand1.intValue <= operand2.intValue;
	else if(operation == ">=")
		return operand1.intValue >= operand2.intValue;
	else if(operation == "==")
		return operand1.intValue == operand2.intValue;
	else if(operation == "!=")
		return operand1.intValue != operand2.intValue;
	else if(operation == "<<")
		return operand1.intValue << operand2.intValue;
	else if(operation == ">>")
		return operand1.intValue >> operand2.intValue;
	else if(operation == "&&")
		return operand1.intValue && operand2.intValue;
	else if(operation == "||")
		return operand1.intValue || operand2.intValue;
	else if(operation == "|")
		return operand1.intValue | operand2.intValue;
	else if(operation == "&")
		return operand1.intValue & operand2.intValue;
	else if(operation == "^")
		return operand1.intValue ^ operand2.intValue;
}



YYSTYPE stringOperation(YYSTYPE operand1, YYSTYPE operand2, string operation)
{

	YYSTYPE* res;
	YYSTYPE* auxCmp;
	YYSTYPE value;
	YYSTYPE op;
	YYSTYPE op1Str = operand1;
	YYSTYPE op2Str = operand2;

	res = new YYSTYPE();

	/*tamanho da string resultante
	por padrão, o valor é 1*/
	unsigned int length = 1;

	string resultOperationType;

	/*verifica-se a operação é permitida*/
        resultOperationType = verifyResultOperation(operand1.type, operand2.type, operation);

	/*se a operação é permitida*/
	if(resultOperationType != "")
	{
		res->type = resultOperationType;
		res->modifier = "";
		res->isConstant = operand1.isConstant && operand2.isConstant;


		/*caso um operando seja de tipo diferente, 
		converte-o para string*/
		if(operand1.type != "string")
			op1Str = toString(operand1); 
		else if(operand2.type != "string")
			op2Str = toString(operand2);

		res->translation = op1Str.translation + op2Str.translation;

		/*realiza a operação referente*/
		if(operation == "+")
		{
			res->label = generateID();			
			res->translation += "\tstrcpy(" + res->label + ", " + op1Str.label + ");\n";
			res->translation += "\tstrcat(" + res->label + ", " + op2Str.label + ");\n";

			length = getDeclarationLength(op1Str) + getDeclarationLength(op2Str);
		}
		else /*no caso de operações relacionais*/
		{
			auxCmp = new YYSTYPE();			
			auxCmp->type = "int";			
			auxCmp->modifier = "short";
			auxCmp->label = generateID();

			auxCmp->translation = "\t" + auxCmp->label + " = " + "strcmp(" + op1Str.label + ", " + op2Str.label + ");\n";

			/*realiza a declaração da variável auxiliar*/
			declare(auxCmp->label, auxCmp->type, 1);	

			/*realiza as comparações devidas*/
			if(operation == "<")
			{
				value = generateIntValue(-1);				
				op = runBasicOperation(*auxCmp, value, "==");

				res->translation += auxCmp->translation + op.translation;
				res->label = op.label;
			}
			else if(operation == ">")
			{
				value = generateIntValue(1);				
				op = runBasicOperation(*auxCmp, value, "==");

				res->translation += auxCmp->translation + op.translation;
				res->label = op.label;
			}
			else if(operation == "==")
			{
				value = generateIntValue(0);				
				op = runBasicOperation(*auxCmp, value, "==");

				res->translation += auxCmp->translation + op.translation;
				res->label = op.label;
			}
			else if(operation == "<=")
			{
				YYSTYPE op2;				
				YYSTYPE opOr;

				value = generateIntValue(-1);
				op = runBasicOperation(*auxCmp, value, "==");
				
				value = generateIntValue(0);
				op2 = runBasicOperation(*auxCmp, value, "==");

				opOr = runBasicOperation(*auxCmp, value, "||");

				res->translation += auxCmp->translation + op.translation + op2.translation + opOr.translation;
				res->label = opOr.label;
			}
			else if(operation == ">=")
			{
				YYSTYPE op2;				
				YYSTYPE opOr;

				value = generateIntValue(1);
				op = runBasicOperation(*auxCmp, value, "==");
				
				value = generateIntValue(0);
				op2 = runBasicOperation(*auxCmp, value, "==");

				opOr = runBasicOperation(*auxCmp, value, "||");

				res->translation += auxCmp->translation + op.translation + op2.translation + opOr.translation;
				res->label = opOr.label;
			}

		}		
		
		declare(res->label, res->type, length);
	}
			
	return *res;
}


YYSTYPE toString(YYSTYPE n)
{
	YYSTYPE* res = new YYSTYPE();
	unsigned int length;

	res->label = generateID();
	res->type = "string";
	res->modifier = "";
	res->isConstant = false;

	res->translation = n.translation;

	if(n.type == "int")
	{
		length = 100;
		//res->translation += "\titoa(" + n.label + ", " + res->label + ", " + "10" + ");\n";
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%d\", " + n.label + ");\n";
	}
	else if(n.type == "char")
	{
		length = 2;
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%c\", " + n.label + ");\n";
		//res->translation += "\tstrcpy(" + res->label + ", " + n.label + ");\n";
		res->translation += "\t" + res->label + "[" + intToString(1) + "] = " + "'\\0';\n";
	}
	else if(n.type == "float")
	{
		length = 100;
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%f\", " + n.label + ");\n";		
	}
	else if(n.type == "double")
	{
		length = 100;
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%f\", " + n.label + ");\n";
	}

	declare(res->label, res->type, length);

	return *res;
}


YYSTYPE* runCast(YYSTYPE from, YYSTYPE to)
{
        YYSTYPE* res;

        string modifier = "";

        res = new YYSTYPE();

        if(!verifyCast(from.type, to.type))
			return NULL;

	
		modifier = to.modifier;
        modifier += (modifier != "" ? " " : "");

		res->label = generateID();
		res->type = to.type;
		res->modifier = to.modifier;
		res->isConstant = from.isConstant && to.isConstant;

		res->translation = "\t" + res->label + " = (" + modifier + to.type + ") " + from.label + ";\n";

		declare(res->label, modifier + res->type, 1); 

	return res;        
}

bool verifyCast(string from, string to)
{
        if((from == "int") && (to == "int"))
                return true;
        else if((from == "float") && (to == "float"))
                return true;
        else if((from == "double") && (to == "double"))
                return true;
        else if((from == "char") && (to == "char"))
                return true;


        else if (((from == "int") && (to == "float")) || ((from == "float") && (to == "int")))
                return true;
        else if (((from == "int") && (to == "double")) || ((from == "double") && (to == "int")))
                return true;
        else if (((from == "int") && (to == "char")) || ((from == "char") && (to == "int")))
                return true;

        else if (((from == "char") && (to == "float") || ((from == "float" && to == "char"))))
                return true;
        else if (((from == "char") && (to == "double") || ((from == "double" && to == "char"))))
                return true;

        else if (((from == "float") && (to == "double")) || ((from == "double") && (to == "float")))
                return true;
	else
		return false;
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

bool isDeclaredFunction(string idFunction)
{
        functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
		functions_map::iterator i;
		i = functionMap->find(idFunction);

        if(i == functionMap->end())
                return false;
		return true;

		//function_struct f = i->second;

        //if (f.defined == false)
		//	return false;
		//else
		//	return true;
           
}

YYSTYPE assign(string addtranslation, YYSTYPE id, YYSTYPE exp)
{
        YYSTYPE* res; 
        res = new YYSTYPE();
        YYSTYPE* cast;
		YYSTYPE yID;

        id_struct* identifier = findID(id.label);

        if(identifier == NULL)
                yyerror("identifier: '" + id.label + "'  was not declared in this scope");

        res->label = identifier->label;
        res->type = identifier->type;
        res->modifier = identifier->modifier;
        res->isConstant = false;
	
		/*no caso de operação com strings*/
		if(identifier->type == "string")
			return stringAssign(addtranslation, *res, exp);

		    if (((exp.modifier != identifier->modifier)) || (exp.type != identifier->type))
		    {	
			cast = runCast(exp, *res);

			if(cast == NULL)
				yyerror("assign from " + exp.type + " to " + identifier->type + " not allowed");


			    res->translation = addtranslation + exp.translation + cast->translation + "\t" + res->label + " = " + cast->label + ";\n";
		    }
		else
			    res->translation = addtranslation + exp.translation + "\t" + res->label + " = " + exp.label + ";\n";


        return *res;
}


YYSTYPE stringAssign(string addtranslation, YYSTYPE id, YYSTYPE exp)
{
	YYSTYPE* res; 
	YYSTYPE expStr; 
	unsigned int length;
	string modifier;

    res = new YYSTYPE();

	res->label = id.label;
	res->type = id.type;
	res->modifier = id.modifier;
	res->isConstant = id.isConstant;
	modifier = res->modifier;

	expStr = exp; //por padrão (inicialmente)

	if((exp.type != "string") && ((exp.type == "int") || (exp.type == "char") || (exp.type == "float") || (exp.type == "double")))
		expStr = toString(exp); /*realiza conversão para o tipo string*/
	else if (exp.type != "string")
		yyerror("assign from " + exp.type + " to " + id.type + " not allowed");

	if (getDeclarationLength(expStr) >= getDeclarationLength(id))
		length = getDeclarationLength(expStr) + 1;
	else
		length = getDeclarationLength(id) + 1;

	res->translation = addtranslation + expStr.translation;
	res->translation += "\tstrcpy(" + id.label + ", " + expStr.label + ");\n";
	res->translation += "\t" + id.label + "[" + intToString(length - 1) + "] = '\\0';\n";

	if(res->modifier != "")
		modifier += " ";
		
	declare(res->label, modifier + res->type, length);

	return *res;
}

YYSTYPE assignNotExpression(YYSTYPE expr)
{
        YYSTYPE* res = new YYSTYPE();
        string modifier = expr.modifier;

        res->label = generateID();
        res->type = expr.type;
        res->modifier = expr.modifier;
        res->isConstant = false;
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
        valueTkn->isConstant = true;

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


void verifyMain()
{
	if(countMain > 1)
		yyerror("redefinition of ‘main’");
	else if(countMain == 0)
		yyerror("undefined reference to `main'");			
}

void declare(string label, string dIType, unsigned int length)
{
        string finalType = dIType;
        
        declarations_map* declarationsMap = stackDeclarationsMap.front();

        if (dIType == "string")
                finalType = "char*";

         (*declarationsMap)[label] = {finalType, length};
} 


string getDeclarations()
{
        string declarations = "";

        declarations_map declarationsMap = *stackDeclarationsMap.front();
        declarations_map::iterator i;
		string type;
        
        for(i = declarationsMap.begin(); i != declarationsMap.end(); i++)
        {                        
			type = i->second.dIType;
			if(type == "char*")
				type = "char";

		            declarations += "\t" + type + " " + i->first;

		            if ((i->second.dIType != "char*") && (i->second.length > 1))
		                    declarations += "[" + intToString(i->second.length) + "]";
					else if (i->second.dIType == "char*")
		                    declarations += "[" + intToString(i->second.length) + "]";

			declarations += ";\n";
        }

        return declarations;
}


string getFunctionArgs()
{
		string args = "";

        declarations_map declarationsMap = *stackDeclarationsMap.front();
        declarations_map::reverse_iterator i;
		string type;
        
        for(i = declarationsMap.rbegin(); i != declarationsMap.rend(); i++)
        {                        
			type = i->second.dIType;
			if(type == "char*")
				type = "char";

		            args += type + " " + i->first;

		            if ((i->second.dIType != "char*") && (i->second.length > 1))
		                    args += "[" + intToString(i->second.length) + "]";
					else if (i->second.dIType == "char*")
		                    args += "[" + intToString(i->second.length) + "]";

			if(next(i , 1) != declarationsMap.rend())
				args += ", ";
        }

        return args;
}

unsigned int getDeclarationLength(YYSTYPE id)
{
	declarations_map* declarationsMap = stackDeclarationsMap.front();
	declarations_map::iterator i;
	i = declarationsMap->find(id.label);

	if(i != declarationsMap->end())
		return i->second.length;

	return 0;
}

bool setDeclarationLength(YYSTYPE id, unsigned int length)
{
	declarations_map* declarationsMap = stackDeclarationsMap.front();
	declarations_map::iterator i;

	i = declarationsMap->find(id.label);

	if(i == declarationsMap->end())
		return false;

	i->second.length = length;

	return true;
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
        ops->op1Type = "float";
        ops->op2Type = "string";
        ops->sOperator = "+";
        operationsMap[*ops] = "string";

        ops = new operation_struct;
        ops->op1Type = "double";
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

