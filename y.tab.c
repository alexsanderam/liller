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
#include <vector>

#define YYSTYPE args

extern int yylineno;

using namespace std;



typedef struct
{
		string idFunction;
        string label;
        string typeOfReturn;
        string modifierOfReturn;
        bool declared;
        bool defined;
        bool called;
		bool hasReturn;

		unsigned int last_call_line;

		/*traduções de comandos free*/
		string freeTranslation;

		string returnTranslation;

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

	int intValue; /*utlizado em locais onde apenas se permite constantes*/

	/*utilizado para identificar funções*/
	string idFunction;

	/*utilizado para assinaturas das funções*/
	string typesArgsFunction;

	/*utilizado para verificar se tem
	identificador nos argumentos de uma
	função*/
	bool hasIdInArgs;

	/*utilizado para verificar se tem
	tamanho nos argumentos de uma
	função*/
	bool hasIdSizeInVectArgs;

	/*utilizado no tratamento de erros
	 ou warnings*/
	unsigned int line;

	/*utilizado no tratamento de vetores*/
	vector<YYSTYPE> vectPositions;
	vector<unsigned int> vectSizes;
	/*posição de acesso, refere-se a um label*/
	string posLabel;

	string normalizedArgs;

};

typedef struct idStruct
{
        string type;
        string modifier;
        string label;

		/*utilizado no tratamento de vetores*/
		vector<unsigned int> vectSizes;
		vector<YYSTYPE> vectSizesFromIds;
		bool hasSizes;
} id_struct;


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
typedef vector<string> mallocs_vector;
				

/*pilhas para controle de escopo*/
list<identifiers_map*> stackIDMap;
list<declarations_map*> stackDeclarationsMap;
list<mallocs_vector*> stackMallocsMap;
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

/*tradução de malloc no início de uma função*/
string mallocTranslations = "";

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

/*tradução de frees na main*/
string freeMainTranslation = "";
/*tradução do return da main*/
string returnMainTranslation = "";

/*tradução de frees nos argumentos de uma função*/
string freeArgsTranslation = "";

/*utilizado como auxiliar nos casos em que a declaraçãoes
devem ser globais, em especial nos casos de argumentos de funções*/
bool inFunctionArgs;

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
YYSTYPE computingPosition(vector<unsigned int>, vector<YYSTYPE>);
YYSTYPE computingPositionFromIds(vector<YYSTYPE>, vector<YYSTYPE>);
string dinamicallyVectDeclaration(YYSTYPE, YYSTYPE, unsigned int);
bool verifyCast(string, string);
YYSTYPE assign(string, YYSTYPE, YYSTYPE);
YYSTYPE stringAssign(string, YYSTYPE, YYSTYPE);
YYSTYPE assignNotExpression(YYSTYPE);
YYSTYPE generateIntValue(int);
string generateID();
string generateLabel();
void relationalControl(YYSTYPE*, YYSTYPE);
id_struct* findID(string);
function_struct* findFunction(string);
label_struct* findLabel(string);
bool isDeclaredCurrentScope(string);
bool isDeclaredFunctionInCurrentScope(string);
void declare(string, string, unsigned int);
string getMallocs();
void addMalloc(string);
string normalizedType(string);
unsigned int getDeclarationLength(YYSTYPE);
bool setDeclarationLength(string, unsigned int);
void verifyLabels();
void verifyMain();
void verifyCallsFunctions();
string getDeclarations();
string getFunctionArgs();
string findAndReplaceR(string, const string, const string);
void findAndReplace(string*, const string, const string);
string verifyResultOperation(string, string, string);
string verifyStrongType(string, string);
void loadOpearationsMap(void);



/* Line 268 of yacc.c  */
#line 342 "y.tab.c"

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
     TK_CIN = 303,
     TK_IF = 304,
     TK_ELSE = 305,
     TK_SWITCH = 306,
     TK_CASE = 307,
     TK_DEFAULT = 308,
     TK_FOR = 309,
     TK_EACH = 310,
     TK_WHILE = 311,
     TK_DO = 312,
     TK_BREAK = 313,
     TK_CONTINUE = 314,
     TK_GOTO = 315,
     TK_OP_INCREASE = 316,
     TK_OP_LESS_LESS = 317,
     TK_OP_ASSIGN = 318,
     TK_DOT_DOT = 319,
     TK_GO_LABEL = 320,
     IFX = 321
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
#define TK_CIN 303
#define TK_IF 304
#define TK_ELSE 305
#define TK_SWITCH 306
#define TK_CASE 307
#define TK_DEFAULT 308
#define TK_FOR 309
#define TK_EACH 310
#define TK_WHILE 311
#define TK_DO 312
#define TK_BREAK 313
#define TK_CONTINUE 314
#define TK_GOTO 315
#define TK_OP_INCREASE 316
#define TK_OP_LESS_LESS 317
#define TK_OP_ASSIGN 318
#define TK_DOT_DOT 319
#define TK_GO_LABEL 320
#define IFX 321




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 516 "y.tab.c"

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
#define YYLAST   509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNRULES -- Number of states.  */
#define YYNSTATES  283

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
       2,    73,     2,    74,     2,     2,     2,     2,     2,     2,
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
      61,    64,    66,    68,    69,    73,    75,    77,    79,    84,
      89,    94,    98,   103,   107,   109,   111,   114,   115,   118,
     121,   124,   126,   128,   130,   132,   134,   137,   140,   143,
     146,   148,   150,   153,   155,   161,   169,   171,   177,   179,
     187,   189,   190,   192,   194,   196,   198,   200,   210,   218,
     221,   225,   228,   231,   233,   235,   237,   243,   245,   249,
     251,   253,   255,   260,   264,   268,   272,   276,   280,   284,
     288,   292,   296,   300,   304,   308,   312,   316,   320,   324,
     328,   332,   335,   338,   340,   342,   346,   350,   355,   357,
     362,   367,   373,   377,   382,   384,   386,   388,   390,   392,
     394,   396,   399,   402,   405,   408,   411,   414,   417,   419,
     421,   425,   429,   433,   437,   441,   446,   451,   455,   459,
     461,   463,   465,   467,   470,   473,   476,   479,   481,   483,
     486,   490,   492,   494,   499,   503,   504,   509
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      76,     0,    -1,    77,    79,    -1,    -1,    13,     9,    83,
      14,    84,    -1,    13,     9,    83,    84,    -1,    80,    -1,
      79,    80,    -1,   121,    67,    -1,    81,    -1,    82,    67,
      -1,    82,    92,    -1,    78,    92,    -1,   122,    10,    83,
      85,    84,    -1,    10,    83,    85,    84,    -1,    68,    -1,
      69,    -1,    85,    70,   122,    86,    -1,   122,    86,    -1,
      -1,    10,   125,    -1,   125,    -1,    88,    -1,    -1,    88,
      70,   116,    -1,   116,    -1,    90,    -1,    91,    -1,    10,
      68,    87,    69,    -1,    46,    68,   115,    69,    -1,    47,
      68,   115,    69,    -1,    47,    68,    69,    -1,    48,    68,
     115,    69,    -1,    93,    95,    94,    -1,    71,    -1,    72,
      -1,    96,    95,    -1,    -1,   115,    67,    -1,    97,    67,
      -1,   121,    67,    -1,    92,    -1,    99,    -1,   101,    -1,
     103,    -1,   108,    -1,   109,    96,    -1,   110,    67,    -1,
     111,    67,    -1,   112,    67,    -1,   114,    -1,    67,    -1,
      45,   115,    -1,    49,    -1,    98,    68,   115,    69,    96,
      -1,    98,    68,   115,    69,    96,    50,    96,    -1,    56,
      -1,   100,    68,   115,    69,    96,    -1,    57,    -1,   102,
      96,    56,    68,   115,    69,    67,    -1,   115,    -1,    -1,
     104,    -1,   121,    -1,   119,    -1,   123,    -1,    54,    -1,
     107,    68,   105,    67,   104,    67,   104,    69,    96,    -1,
     107,    68,   106,    64,   123,    69,    96,    -1,    10,    65,
      -1,    52,   115,    65,    -1,    53,    65,    -1,    60,    10,
      -1,    59,    -1,    58,    -1,    51,    -1,   113,    68,   115,
      69,    96,    -1,   116,    -1,    68,   116,    69,    -1,    89,
      -1,   123,    -1,   119,    -1,    68,   122,    69,   123,    -1,
     116,    24,   116,    -1,   116,    25,   116,    -1,   116,    26,
     116,    -1,   116,    27,   116,    -1,   116,    28,   116,    -1,
     116,    36,   116,    -1,   116,    35,   116,    -1,   116,    33,
     116,    -1,   116,    34,   116,    -1,   116,    29,   116,    -1,
     116,    30,   116,    -1,   116,    31,   116,    -1,   116,    32,
     116,    -1,   116,    38,   116,    -1,   116,    39,   116,    -1,
     116,    40,   116,    -1,   116,    42,   116,    -1,   116,    43,
     116,    -1,    37,   116,    -1,    41,   116,    -1,   117,    -1,
     118,    -1,    10,   126,    61,    -1,    61,    10,   126,    -1,
      10,   126,    44,   116,    -1,   120,    -1,    10,   126,    63,
     116,    -1,   121,    70,    10,   125,    -1,   121,    70,    10,
      44,   116,    -1,   122,    10,   125,    -1,   122,    10,    44,
     116,    -1,    11,    -1,    12,    -1,    13,    -1,    14,    -1,
      15,    -1,    16,    -1,    17,    -1,    18,    11,    -1,    19,
      11,    -1,    18,    13,    -1,    19,    13,    -1,    20,    13,
      -1,    21,    13,    -1,    21,    16,    -1,    20,    -1,    21,
      -1,    18,    20,    13,    -1,    19,    20,    13,    -1,    18,
      21,    13,    -1,    19,    21,    13,    -1,    21,    21,    13,
      -1,    18,    21,    21,    13,    -1,    19,    21,    21,    13,
      -1,    18,    21,    21,    -1,    19,    21,    21,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,   124,     3,    -1,
     124,     4,    -1,   124,     5,    -1,   124,     6,    -1,     7,
      -1,     8,    -1,    10,   126,    -1,   124,    10,   126,    -1,
      24,    -1,    25,    -1,    73,   115,    74,   125,    -1,    73,
      74,   125,    -1,    -1,    73,   115,    74,   126,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   317,   317,   365,   371,   395,   422,   423,   430,   435,
     436,   452,   519,   555,   592,   627,   637,   645,   708,   771,
     784,   796,   813,   815,   822,   829,   838,   839,   840,   889,
     894,   899,   906,   919,   928,   941,   956,   961,   968,   969,
     970,   979,   980,   981,   982,   983,   984,   991,   992,   993,
     994,   995,  1003,  1105,  1112,  1131,  1156,  1175,  1208,  1227,
    1259,  1260,  1264,  1265,  1271,  1272,  1277,  1300,  1343,  1410,
    1432,  1461,  1487,  1505,  1520,  1535,  1555,  1600,  1621,  1631,
    1632,  1633,  1634,  1643,  1647,  1651,  1655,  1659,  1663,  1667,
    1671,  1677,  1683,  1689,  1695,  1701,  1707,  1711,  1715,  1719,
    1723,  1727,  1741,  1759,  1760,  1766,  1832,  1895,  1922,  1926,
    2004,  2049,  2077,  2128,  2158,  2164,  2170,  2176,  2182,  2188,
    2194,  2200,  2206,  2212,  2218,  2224,  2230,  2236,  2242,  2248,
    2254,  2260,  2266,  2272,  2278,  2284,  2290,  2296,  2302,  2312,
    2324,  2335,  2347,  2359,  2371,  2382,  2394,  2406,  2420,  2435,
    2467,  2510,  2510,  2515,  2533,  2543,  2554,  2566
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
  "TK_CIN", "TK_IF", "TK_ELSE", "TK_SWITCH", "TK_CASE", "TK_DEFAULT",
  "TK_FOR", "TK_EACH", "TK_WHILE", "TK_DO", "TK_BREAK", "TK_CONTINUE",
  "TK_GOTO", "TK_OP_INCREASE", "TK_OP_LESS_LESS", "TK_OP_ASSIGN",
  "TK_DOT_DOT", "TK_GO_LABEL", "IFX", "';'", "'('", "')'", "','", "'{'",
  "'}'", "'['", "']'", "$accept", "BEGIN", "START", "MAIN_HEADER",
  "TRANSLATION_UNIT", "EXTERNAL_DECLARATION", "FUNCTION",
  "FUNCTION_HEADER", "OPEN_ARGS", "CLOSE_ARGS", "ARGS", "OPTIONAL_ID",
  "OPTIONAL_PARAMETERS", "PARAMETERS", "CALL_FUNCTION", "COUT", "CIN",
  "SCOPE", "BEGIN_SCOPE", "END_SCOPE", "COMMANDS", "STATEMENT", "RETURN",
  "IF_C", "IF", "WHILE_C", "WHILE", "DO_WHILE_C", "DO_WHILE", "OPTIONAL_E",
  "OPTIONAL_E_OR_DECLARATION", "ATTRIBUITION_OR_TERMINAL", "FOR_C", "FOR",
  "LABEL", "GOTO", "CONTINUE", "BREAK", "SWITCH_C", "SWITCH", "E_C", "E",
  "INCREASE", "PREV_INCREASE", "ATTRIBUITION", "OP_ASSIGN", "DECLARATION",
  "TYPE", "TERMINAL", "SIGNAL", "VECTOR_SIZES", "VECTOR_P", 0
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
      44,   123,   125,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    78,    78,    79,    79,    80,    80,
      80,    81,    81,    82,    82,    83,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    89,    90,
      90,    90,    91,    92,    93,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    98,    99,    99,   100,   101,   102,   103,
     104,   104,   105,   105,   106,   106,   107,   108,   108,   109,
     109,   109,   110,   111,   112,   113,   114,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   118,   119,   119,   120,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   125,   125,   126,   126
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     5,     4,     1,     2,     2,     1,
       2,     2,     2,     5,     4,     1,     1,     4,     2,     0,
       2,     1,     1,     0,     3,     1,     1,     1,     4,     4,
       4,     3,     4,     3,     1,     1,     2,     0,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     1,     5,     7,     1,     5,     1,     7,
       1,     0,     1,     1,     1,     1,     1,     9,     7,     2,
       3,     2,     2,     1,     1,     1,     5,     1,     3,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     1,     1,     3,     3,     4,     1,     4,
       4,     5,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     3,     3,     3,     4,     4,     3,     3,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     1,     2,
       3,     1,     1,     4,     3,     0,     4,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,   114,   115,   116,   117,   118,
     119,   120,     0,     0,   128,   129,     0,     2,     6,     9,
       0,     0,     0,    15,    19,     0,   121,   123,     0,     0,
     122,   124,     0,     0,   125,   126,   127,     0,    34,    12,
      37,     7,    10,    11,     8,     0,   155,   116,     0,   155,
       0,   130,   132,   137,   131,   133,   138,   134,   139,   140,
     141,   142,   147,   148,   157,   151,   152,     0,     0,     0,
       0,     0,     0,    53,    75,     0,     0,    66,    56,    58,
      74,    73,     0,     0,    51,     0,    79,    26,    27,    41,
       0,    37,     0,     0,    42,     0,    43,     0,    44,     0,
      45,     0,     0,     0,     0,     0,    50,     0,    77,   103,
     104,    81,   108,     0,     0,    80,     0,   155,     0,     0,
      19,   112,    16,     0,    14,   155,    18,    21,     0,     5,
     135,   136,    69,    23,     0,   149,   157,   101,   102,    52,
       0,     0,     0,     0,    71,    72,   157,     0,     0,    35,
      33,    36,    39,     0,     0,     0,    61,    46,    47,    48,
      49,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,   155,   143,   144,   145,   146,   157,     0,   110,
     113,   155,     0,     0,   155,    20,     4,     0,    22,    25,
       0,     0,   105,     0,     0,    31,     0,     0,    70,   106,
      78,     0,     0,     0,     0,    62,     0,     0,    60,    81,
      63,    80,     0,    83,    84,    85,    86,    87,    92,    93,
      94,    95,    90,    91,    89,    88,    96,    97,    98,    99,
     100,   150,   111,   154,   155,    13,    17,    28,     0,   157,
     107,   109,    29,    30,    32,   157,    82,     0,     0,     0,
      61,     0,     0,   153,    24,   156,   149,    54,    57,     0,
       0,     0,    76,     0,     0,    61,     0,    55,    59,     0,
      68,     0,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    16,    17,    18,    19,    20,    24,   124,
      48,   126,   197,   198,    86,    87,    88,    89,    40,   150,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   215,
     216,   217,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     121,   135
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -249
static const yytype_int16 yypact[] =
{
    -249,    13,   348,  -249,   -37,  -249,  -249,    45,  -249,  -249,
    -249,  -249,     3,    69,    84,    47,    48,   348,  -249,  -249,
      27,    74,   142,  -249,   255,   -37,  -249,  -249,   149,     5,
    -249,  -249,   156,    62,  -249,  -249,  -249,   157,  -249,  -249,
     240,  -249,  -249,  -249,  -249,   145,   -15,  -249,   -50,     1,
      -5,  -249,  -249,   164,  -249,  -249,   167,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,    23,  -249,  -249,   401,   401,   401,
     113,   115,   116,  -249,  -249,   401,   121,  -249,  -249,  -249,
    -249,  -249,   178,   179,  -249,   376,  -249,  -249,  -249,  -249,
     123,   240,   127,   130,  -249,   131,  -249,   240,  -249,   132,
    -249,   240,   134,   135,   136,   140,  -249,   137,   446,  -249,
    -249,  -249,  -249,    75,   187,  -249,   117,   -16,   401,   168,
     255,  -249,  -249,   255,  -249,   138,  -249,  -249,   141,  -249,
    -249,  -249,  -249,   401,   401,    18,    -7,  -249,  -249,  -249,
     401,   309,   401,   147,  -249,  -249,   144,     9,   159,  -249,
    -249,  -249,  -249,   401,   401,   151,   376,  -249,  -249,  -249,
    -249,   401,  -249,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,  -249,   -14,  -249,  -249,  -249,  -249,   144,   401,  -249,
     446,   138,   158,   -50,     1,  -249,  -249,   161,   143,   446,
     165,   401,  -249,   401,   162,  -249,   171,   172,  -249,  -249,
    -249,   129,   180,   193,   150,  -249,   196,   214,  -249,   215,
     210,   218,   221,   122,   139,   102,   256,  -249,   466,   466,
     466,   466,   195,   195,   297,   297,   133,   133,   133,   133,
     133,  -249,   446,  -249,   138,  -249,  -249,  -249,   401,   144,
     446,   446,  -249,  -249,  -249,   144,  -249,   240,   240,   401,
     401,   129,   240,  -249,   446,  -249,  -249,   233,  -249,   226,
     235,   234,  -249,   240,   237,   401,   240,  -249,  -249,   236,
    -249,   240,  -249
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -249,  -249,  -249,  -249,  -249,   289,  -249,  -249,    21,   -42,
     189,   124,  -249,  -249,  -249,  -249,  -249,    79,  -249,  -249,
     219,   -94,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -248,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,
     -69,   -63,  -249,  -249,   176,  -249,     0,     8,  -135,  -249,
     -48,  -131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
     139,   127,    21,   155,   137,   138,   143,   157,   129,   128,
      22,   125,   270,     3,    26,   209,    27,    21,    52,   122,
     123,   221,   147,    28,    29,    22,    53,   279,   188,   118,
     118,    23,    49,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,    50,   176,   177,   178,
     192,   179,   180,    23,    25,   190,   241,   119,   119,   119,
      35,   133,   201,    36,   122,   200,   134,   120,    37,   189,
     199,   204,   206,   207,   119,    55,   256,   195,   210,   202,
      30,   203,    31,    56,   212,   213,   196,   218,   132,    32,
      33,   133,   222,   148,    42,    39,   134,    34,    38,    43,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   265,    38,
     183,   184,   185,   186,   266,   242,   271,   187,    49,   166,
     167,   194,    58,    59,    60,    61,    62,    63,   250,   255,
     251,    44,   181,   243,    45,    45,   127,   164,   165,   166,
     167,   245,    46,    65,    66,   117,   220,   163,   164,   165,
     166,   167,    51,   267,   268,   165,   166,   167,   272,    54,
      57,    58,    59,    60,    61,    62,    63,   130,   136,   277,
     131,   140,   280,   141,   142,   264,   144,   282,   145,   146,
     269,   218,    65,    66,   152,   149,   263,   182,   153,   154,
     156,   158,   159,   160,   162,    67,   218,   214,   161,    68,
     122,   119,   208,   248,    70,    71,    72,   134,   259,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   211,    83,
     247,   252,   244,   176,   177,   178,    85,   179,   180,   249,
     253,   254,   191,    58,    59,    60,    61,    62,    63,   257,
      64,     5,     6,    47,     8,     9,    10,    11,    12,    13,
      14,    15,   258,   260,    65,    66,     5,     6,    47,     8,
       9,    10,    11,    12,    13,    14,    15,    67,   261,   -64,
      45,    68,   -65,   273,   167,    69,    70,    71,    72,    73,
     262,    74,    75,    76,    77,   274,    78,    79,    80,    81,
      82,    83,   275,   276,   278,   281,    41,    84,    85,   193,
     151,    38,    58,    59,    60,    61,    62,    63,   246,   136,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   219,    65,    66,   176,   177,   178,     0,   179,
     180,     0,     0,     0,     0,     0,    67,     0,     0,     0,
      68,     0,     0,     0,     0,    70,    71,    72,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      83,     0,     0,     0,     0,     0,     0,    85,   205,    58,
      59,    60,    61,    62,    63,     0,   136,     5,     6,    47,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      65,    66,     0,     0,    58,    59,    60,    61,    62,    63,
       0,   136,     0,    67,     0,     0,     0,    68,     0,     0,
       0,     0,    70,    71,    72,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    67,     0,
       0,     0,    68,     0,    85,     0,     0,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,    85,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,   176,   177,   178,     0,   179,   180,
     163,   164,   165,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177,   178,     0,   179,   180
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-249))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      69,    49,     2,    97,    67,    68,    75,   101,    50,    14,
       2,    10,   260,     0,    11,   146,    13,    17,    13,    69,
      70,   156,    85,    20,    21,    17,    21,   275,    44,    44,
      44,    68,    24,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    25,    38,    39,    40,
     119,    42,    43,    68,     9,   118,   187,    73,    73,    73,
      13,    68,    44,    16,    69,   134,    73,    46,    21,   117,
     133,   140,   141,   142,    73,    13,   211,   125,    69,    61,
      11,    63,    13,    21,   153,   154,   128,   156,    65,    20,
      21,    68,   161,    85,    67,    16,    73,    13,    71,    20,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   249,    71,
       3,     4,     5,     6,   255,   188,   261,    10,   120,    27,
      28,   123,     3,     4,     5,     6,     7,     8,   201,    10,
     203,    67,    67,   191,    70,    70,   194,    25,    26,    27,
      28,   193,    10,    24,    25,    10,   156,    24,    25,    26,
      27,    28,    13,   257,   258,    26,    27,    28,   262,    13,
      13,     3,     4,     5,     6,     7,     8,    13,    10,   273,
      13,    68,   276,    68,    68,   248,    65,   281,    10,    10,
     259,   260,    24,    25,    67,    72,   244,    10,    68,    68,
      68,    67,    67,    67,    67,    37,   275,    56,    68,    41,
      69,    73,    65,    70,    46,    47,    48,    73,    68,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    69,    61,
      69,    69,    74,    38,    39,    40,    68,    42,    43,    74,
      69,    69,    74,     3,     4,     5,     6,     7,     8,    69,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    69,    67,    24,    25,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    37,    64,    64,
      70,    41,    64,    50,    28,    45,    46,    47,    48,    49,
      69,    51,    52,    53,    54,    69,    56,    57,    58,    59,
      60,    61,    67,    69,    67,    69,    17,    67,    68,   120,
      91,    71,     3,     4,     5,     6,     7,     8,   194,    10,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   156,    24,    25,    38,    39,    40,    -1,    42,
      43,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    37,    -1,
      -1,    -1,    41,    -1,    68,    -1,    -1,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    -1,    42,    43,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,    77,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    78,    79,    80,    81,
      82,   121,   122,    68,    83,     9,    11,    13,    20,    21,
      11,    13,    20,    21,    13,    13,    16,    21,    71,    92,
      93,    80,    67,    92,    67,    70,    10,    13,    85,   122,
      83,    13,    13,    21,    13,    13,    21,    13,     3,     4,
       5,     6,     7,     8,    10,    24,    25,    37,    41,    45,
      46,    47,    48,    49,    51,    52,    53,    54,    56,    57,
      58,    59,    60,    61,    67,    68,    89,    90,    91,    92,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    10,    44,    73,
      83,   125,    69,    70,    84,    10,    86,   125,    14,    84,
      13,    13,    65,    68,    73,   126,    10,   116,   116,   115,
      68,    68,    68,   115,    65,    10,    10,   116,   122,    72,
      94,    95,    67,    68,    68,    96,    68,    96,    67,    67,
      67,    68,    67,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    42,
      43,    67,    10,     3,     4,     5,     6,    10,    44,   125,
     116,    74,   115,    85,   122,   125,    84,    87,    88,   116,
     115,    44,    61,    63,   115,    69,   115,   115,    65,   126,
      69,    69,   115,   115,    56,   104,   105,   106,   115,   119,
     121,   123,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   126,   116,   125,    74,    84,    86,    69,    70,    74,
     116,   116,    69,    69,    69,    10,   123,    69,    69,    68,
      67,    64,    69,   125,   116,   126,   126,    96,    96,   115,
     104,   123,    96,    50,    69,    67,    69,    96,    67,   104,
      96,    69,    96
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
#line 318 "sintatica.y"
    {
							verifyLabels(); /*verifica se há erros relacionados à rótulos*/
							verifyMain(); /*verifica se há inconsistência com relação a main*/
							/*verifica se alguma função que foi chamada não foi definida*/
							verifyCallsFunctions();

							if(error)
								exit(1);

							string globalDeclarations = getDeclarations();

							(yyval).translation = "/*Compiler prescot-liller*/\n\n";
							(yyval).translation += "#include <stdio.h>\n#include <iostream>\n#include<string.h>\n#include<stdio.h>\n#include<stdlib.h>\n";
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
							(yyval).translation += findAndReplaceR(scopeMainTranslation, "return", freeMainTranslation + "\n\treturn");
							//$$.translation += freeMainTranslation;
							//$$.translation += returnMainTranslation;
							(yyval).translation += "\n}\n\n";

							(yyval).translation += (yyvsp[(2) - (2)]).translation;

							cout <<  (yyval).translation << endl;

							//Fecha o escopo global
							closeCurrentScope();
                        }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 365 "sintatica.y"
    {
                                openNewScope();        
                        }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 372 "sintatica.y"
    {
							(yyval).translation = "";
							(yyval).idFunction = (yyvsp[(2) - (5)]).translation + " (void)";

							/*functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                            (*functionMap)[$$.idFunction].idFunction = $$.idFunction;
                            (*functionMap)[$$.idFunction].label = "main";
                            (*functionMap)[$$.idFunction].typeOfReturn = $1.type;
                            (*functionMap)[$$.idFunction].modifierOfReturn = "";
                            (*functionMap)[$$.idFunction].declared = true;
                            (*functionMap)[$$.idFunction].defined = false;
                            (*functionMap)[$$.idFunction].called = false;
							(*functionMap)[$$.idFunction].freeTranslation = freeMainTranslation;*/

                            headMainTranslation = (yyvsp[(1) - (5)]).translation + " " + (yyvsp[(2) - (5)]).translation + '(' + (yyvsp[(4) - (5)]).translation + ')' + "\n";

							idOfCurrentFunction.push_front((yyval).idFunction);

							/*controle da função main
							verifica se há main, e quantos*/
							countMain++;
							verifyMain();
                        }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 396 "sintatica.y"
    {
							(yyval).translation = "";
							(yyval).idFunction = (yyvsp[(2) - (4)]).translation + " (void)";

							/*functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                            (*functionMap)[$$.idFunction].idFunction = $$.idFunction;
                            (*functionMap)[$$.idFunction].label = "main";
                            (*functionMap)[$$.idFunction].typeOfReturn = $1.type;
                            (*functionMap)[$$.idFunction].modifierOfReturn = "";
                            (*functionMap)[$$.idFunction].declared = true;
                            (*functionMap)[$$.idFunction].defined = false;
                            (*functionMap)[$$.idFunction].called = false;
							(*functionMap)[$$.idFunction].freeTranslation = freeMainTranslation;*/

                            headMainTranslation = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + '(' + ')' + "\n";

							idOfCurrentFunction.push_front((yyval).idFunction);

							/*controle da função main
							verifica se há main, e quantos*/
							countMain++;
							verifyMain();
                        }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 424 "sintatica.y"
    {
							(yyval).translation = (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation;
						}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 431 "sintatica.y"
    {
							globalDeclarationsTranslation += (yyvsp[(1) - (2)]).translation;
							(yyval).translation = "";
						}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 437 "sintatica.y"
    {								
							(yyval).translation = "";
							headersFunctions += (yyvsp[(1) - (2)]).translation;
							headersFunctions += "(" + (yyvsp[(1) - (2)]).normalizedArgs + ");\n";

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();
						}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 453 "sintatica.y"
    {
							functions_map* functionMap;
							functions_map::iterator i;
							function_struct* f;
							int line;
							string arguments = "";
							string mallocArguments = "";

							if(((yyvsp[(1) - (2)]).hasIdInArgs == false) && ((yyvsp[(1) - (2)]).type != "void"))
							{
								line = yylineno;
								yylineno = (yyvsp[(1) - (2)]).line;							
								yyerror("parameter name omitted");
								yylineno = line;
							}

							if((yyvsp[(1) - (2)]).hasIdSizeInVectArgs == false)
							{
								line = yylineno;
								yylineno = (yyvsp[(1) - (2)]).line;							
								yyerror("size not defined in vect args of fuction '" + (yyvsp[(1) - (2)]).idFunction + "'");
								yylineno = line;								
							}
						
							arguments = getFunctionArgs();
							mallocArguments = getMallocs();

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();

							functionMap = stackFunctionMap.front();
							i = functionMap->find((yyvsp[(1) - (2)]).idFunction);
							f = &i->second;

							(yyval).translation = (yyvsp[(1) - (2)]).translation;
							(yyval).translation += "(" + arguments + ")";
							(yyval).translation += "\n{\n" + declarations + mallocArguments + mallocTranslations + "\n";
							(yyval).translation += (yyvsp[(2) - (2)]).translation;
							//$$.translation += f->freeTranslation;
							//$$.translation += f->returnTranslation;
							(yyval).translation += "\n}\n\n";

							declarations = "";
							mallocTranslations = "";
							freeArgsTranslation = "";


							/*muda o estado da função para definida*/
							if((*functionMap)[(yyvsp[(1) - (2)]).idFunction].defined == false)
                				(*functionMap)[(yyvsp[(1) - (2)]).idFunction].defined = true;
							else
							{
								line = yylineno;
								yylineno = (yyvsp[(1) - (2)]).line;
								yyerror("'" + (yyval).idFunction + "' previously defined here");
								yylineno = line;
							}

							/*verifica se a função tem retorno quando essa necessita*/
							if(((*functionMap)[(yyvsp[(1) - (2)]).idFunction].typeOfReturn != "void") && ((*functionMap)[(yyvsp[(1) - (2)]).idFunction].hasReturn == false))
								yywarning("control reaches end of non-void function: '" + (yyvsp[(1) - (2)]).idFunction + "' [-Wreturn-type]");
						}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 520 "sintatica.y"
    {
							functions_map* functionMap;
							functions_map::iterator i;
							function_struct* f;

							headMainTranslation += "{\n" + declarations + "\n";
							scopeMainTranslation = mallocTranslations + (yyvsp[(2) - (2)]).translation;

							declarations = "";
							mallocTranslations = "";
							freeArgsTranslation = "";

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();

							//functionMap = stackFunctionMap.front();
							//i = functionMap->find($1.idFunction);
							//f = &i->second;
							//freeMainTranslation += f->freeTranslation;

							//if(i != functionMap->end())
							//{
								//freeMainTranslation += f->freeTranslation;
							//}
						
						}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 556 "sintatica.y"
    {
							string id;
							string type;
							(yyval).idFunction = (yyvsp[(2) - (5)]).label + "(" + (yyvsp[(4) - (5)]).typesArgsFunction + ")";
							idOfCurrentFunction.push_front((yyval).idFunction);

							functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                                                        
                            if(isDeclaredFunctionInCurrentScope((yyval).idFunction) == false)
							{
									id = generateID();
                                    (*functionMap)[(yyval).idFunction].idFunction = (yyval).idFunction;
                                    (*functionMap)[(yyval).idFunction].label = id;
                                    (*functionMap)[(yyval).idFunction].typeOfReturn = (yyvsp[(1) - (5)]).type;
                                    (*functionMap)[(yyval).idFunction].modifierOfReturn = (yyvsp[(1) - (5)]).modifier;
                                    (*functionMap)[(yyval).idFunction].declared = true;
                                    (*functionMap)[(yyval).idFunction].defined = false;
                                    (*functionMap)[(yyval).idFunction].called = false;
									(*functionMap)[(yyval).idFunction].freeTranslation = freeArgsTranslation;
							}
							else
									id = (*functionMap)[(yyval).idFunction].label;

							if((yyvsp[(1) - (5)]).type == "string")
								type = "char*";
							else
								type = (yyvsp[(1) - (5)]).type;

							(yyval).label = id;
							(yyval).typesArgsFunction = (yyvsp[(4) - (5)]).typesArgsFunction;
							(yyval).translation = type + " " + id;
							(yyval).hasIdInArgs = (yyvsp[(4) - (5)]).hasIdInArgs;
							(yyval).hasIdSizeInVectArgs = (yyvsp[(4) - (5)]).hasIdSizeInVectArgs;
							(yyval).line = yylineno;
							(yyval).normalizedArgs = (yyvsp[(4) - (5)]).normalizedArgs;
						}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 593 "sintatica.y"
    {
							string id;
							(yyval).idFunction = (yyvsp[(1) - (4)]).label + "(" + (yyvsp[(3) - (4)]).typesArgsFunction + ")";
							idOfCurrentFunction.push_front((yyval).idFunction);

							functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                                                        
                            if(!isDeclaredFunctionInCurrentScope((yyval).idFunction))
							{
									id = generateID();
                                    (*functionMap)[(yyval).idFunction].idFunction = (yyval).idFunction;
                                    (*functionMap)[(yyval).idFunction].label = id;
                                    (*functionMap)[(yyval).idFunction].typeOfReturn = "void";
                                    (*functionMap)[(yyval).idFunction].modifierOfReturn = "";
                                    (*functionMap)[(yyval).idFunction].declared = true;
                                    (*functionMap)[(yyval).idFunction].defined = false;
                                    (*functionMap)[(yyval).idFunction].called = false;
									(*functionMap)[(yyval).idFunction].freeTranslation = freeArgsTranslation;
							}
							else
									id = (*functionMap)[(yyval).idFunction].label;

							(yyval).label = id;
							(yyval).typesArgsFunction = (yyvsp[(3) - (4)]).typesArgsFunction;
		                    (yyval).translation = "void " + id;
							(yyval).hasIdInArgs = (yyvsp[(3) - (4)]).hasIdInArgs;
							(yyval).hasIdSizeInVectArgs = (yyvsp[(3) - (4)]).hasIdSizeInVectArgs;
							(yyval).line = yylineno;
							(yyval).normalizedArgs = (yyvsp[(3) - (4)]).normalizedArgs;
						}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 628 "sintatica.y"
    {
							/*cria uma nova entrada na pilha
							para armazenar os argumentos da função*/
							openNewScope();
							inFunctionArgs = true;
						}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 638 "sintatica.y"
    {
							inFunctionArgs = false;
						}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 646 "sintatica.y"
    {
								unsigned int size = 1;
								string pointer = "";

								if((yyvsp[(4) - (4)]).label != "")							   	
								{
									identifiers_map* IDMap = stackIDMap.front();

		                            (*IDMap)[(yyvsp[(4) - (4)]).label].label = generateID();
		                            (*IDMap)[(yyvsp[(4) - (4)]).label].type = (yyvsp[(3) - (4)]).type;
		                            (*IDMap)[(yyvsp[(4) - (4)]).label].modifier = (yyvsp[(3) - (4)]).modifier;

									(yyval).label = (*IDMap)[(yyvsp[(4) - (4)]).label].label;
									(yyval).type = (*IDMap)[(yyvsp[(4) - (4)]).label].type;
									(yyval).modifier = (*IDMap)[(yyvsp[(4) - (4)]).label].modifier;

									if((yyvsp[(4) - (4)]).vectSizes.size() > 0)
									{
										for(int i = 0; i < (yyvsp[(4) - (4)]).vectSizes.size(); i++)
											size *= (yyvsp[(4) - (4)]).vectSizes.at(i);
									}

									if((yyvsp[(4) - (4)]).isConstant == false)
									{
										//addMalloc(dinamicallyVectDeclaration($$, $4, 1));
										size = 0; /*será declarado como ponteiro*/
									}

									/*chuta-se um tamanho para argumentos do tipo string*/
									if(((yyvsp[(3) - (4)]).type == "string") && (size > 0))
											size *= 100;
									else if((yyvsp[(3) - (4)]).type == "string")
											size = 1000;



									(yyval).translation = (yyvsp[(1) - (4)]).translation + ", " + (yyval).type + " " + (yyval).label + (yyvsp[(4) - (4)]).translation;
									(yyval).typesArgsFunction = (yyvsp[(1) - (4)]).typesArgsFunction + ", " + (yyval).type + (yyvsp[(4) - (4)]).translation;
									(yyval).hasIdInArgs = (yyvsp[(1) - (4)]).hasIdInArgs &&  true;
									(yyval).hasIdSizeInVectArgs = (yyvsp[(1) - (4)]).hasIdSizeInVectArgs && (yyvsp[(4) - (4)]).hasIdSizeInVectArgs;

									inFunctionArgs = false;
		                            if ((yyval).modifier != "")
		                                    declare((yyval).label, (yyval).modifier + " " + (yyval).type, size);
		                            else
		                                    declare((yyval).label, (yyval).type, size);
									inFunctionArgs = true;
								}
								else
								{
									(yyval).translation = (yyval).type + (yyvsp[(4) - (4)]).translation + ", " + (yyvsp[(1) - (4)]).translation;
									(yyval).typesArgsFunction = (yyval).type + (yyvsp[(4) - (4)]).translation + ", " + (yyvsp[(1) - (4)]).typesArgsFunction;
									(yyval).hasIdInArgs = false;
									(yyval).line = yylineno;
								}	 

								if((size == 0) || ((yyvsp[(3) - (4)]).type == "string"))
									pointer = "*";

								(yyval).normalizedArgs = (yyvsp[(1) - (4)]).normalizedArgs + ", " + (yyval).modifier + ((yyval).modifier != "" ? " " : "") + normalizedType((yyval).type) + pointer + + " " + (yyvsp[(4) - (4)]).label + (yyvsp[(4) - (4)]).translation;

						}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 709 "sintatica.y"
    {
							unsigned int size = 1;
							string pointer = "";

							if((yyvsp[(2) - (2)]).label != "")
							{
								identifiers_map* IDMap = stackIDMap.front();

		                        (*IDMap)[(yyvsp[(2) - (2)]).label].label = generateID();
		                        (*IDMap)[(yyvsp[(2) - (2)]).label].type = (yyvsp[(1) - (2)]).type;
		                        (*IDMap)[(yyvsp[(2) - (2)]).label].modifier = (yyvsp[(1) - (2)]).modifier;

								(yyval).label = (*IDMap)[(yyvsp[(2) - (2)]).label].label;
								(yyval).type = (*IDMap)[(yyvsp[(2) - (2)]).label].type;
								(yyval).modifier = (*IDMap)[(yyvsp[(2) - (2)]).label].modifier;

								if((yyvsp[(2) - (2)]).vectSizes.size() > 0)
								{
									for(int i = 0; i < (yyvsp[(2) - (2)]).vectSizes.size(); i++)
										size *= (yyvsp[(2) - (2)]).vectSizes.at(i);
								}

								if((yyvsp[(2) - (2)]).isConstant == false)
								{
									//addMalloc(dinamicallyVectDeclaration($$, $2, 1));
									size = 0; /*será declarado como ponteiro*/
								}

								/*chuta-se um tamanho para argumentos do tipo string*/
								if(((yyvsp[(1) - (2)]).type == "string") && (size > 0))
										size *= 100;
								else if((yyvsp[(1) - (2)]).type == "string")
										size = 1000;


								(yyval).translation = (yyval).type + " " + (yyval).label + (yyvsp[(2) - (2)]).translation;
								(yyval).typesArgsFunction = (yyvsp[(1) - (2)]).type + (yyvsp[(2) - (2)]).translation;
								(yyval).hasIdInArgs = ((yyvsp[(2) - (2)]).label != "");
								(yyval).hasIdSizeInVectArgs = (yyvsp[(2) - (2)]).hasIdSizeInVectArgs || ((yyvsp[(1) - (2)]).type == "void");

								inFunctionArgs = false;
		                        if ((yyval).modifier != "")
		                                declare((yyval).label, (yyval).modifier + " " + (yyval).type, size);
		                        else
		                                declare((yyval).label, (yyval).type, size);
								inFunctionArgs = true;
							}
							else
							{
									(yyval).translation = (yyval).type + (yyvsp[(2) - (2)]).translation;
									(yyval).typesArgsFunction = (yyval).translation + (yyvsp[(2) - (2)]).translation;
									(yyval).hasIdInArgs = false;
									(yyval).line = yylineno;
							}

							if((size == 0) || ((yyvsp[(1) - (2)]).type == "string"))
								pointer = "*";

							(yyval).normalizedArgs = (yyval).modifier + ((yyval).modifier != "" ? " " : "") + normalizedType((yyval).type) + pointer + " " + (yyvsp[(2) - (2)]).label + (yyvsp[(2) - (2)]).translation;

						}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 771 "sintatica.y"
    {
							(yyval).translation = "";
							(yyval).typesArgsFunction = "void";
							(yyval).hasIdInArgs = true;
							(yyval).hasIdSizeInVectArgs = true;
							(yyval).line = yylineno;

							(yyval).normalizedArgs = "";
						}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 785 "sintatica.y"
    {
							(yyval).vectSizes = (yyvsp[(2) - (2)]).vectSizes;
							(yyval).vectPositions = (yyvsp[(2) - (2)]).vectPositions;
							(yyval).isConstant = (yyvsp[(2) - (2)]).isConstant;
							(yyval).hasIdSizeInVectArgs = (yyvsp[(2) - (2)]).hasIdSizeInVectArgs;

							//if($2.isConstant == false)
								//yyerror("not allowed not constant in size args of function");

							(yyval).translation = (yyvsp[(2) - (2)]).translation;
						}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 797 "sintatica.y"
    {
							(yyval).label = "";

							(yyval).vectSizes = (yyvsp[(1) - (1)]).vectSizes;
							(yyval).vectPositions = (yyvsp[(1) - (1)]).vectPositions;
							(yyval).isConstant = (yyvsp[(1) - (1)]).isConstant;
							(yyval).hasIdSizeInVectArgs = (yyvsp[(1) - (1)]).hasIdSizeInVectArgs;

							//if($1.isConstant == false)
								//yyerror("not allowed not constant in size args of function");

							(yyval).translation = (yyvsp[(1) - (1)]).translation;
						}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 815 "sintatica.y"
    {
							(yyval).typesArgsFunction = "void";
							(yyval).label = "";
							(yyval).translation = "";
						}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 823 "sintatica.y"
    {
							(yyval).translation = (yyvsp[(1) - (3)]).translation + (yyvsp[(3) - (3)]).translation;
							(yyval).label = (yyvsp[(1) - (3)]).label + ", " + (yyvsp[(3) - (3)]).label;
							(yyval).typesArgsFunction = (yyvsp[(1) - (3)]).typesArgsFunction + ", " + (yyvsp[(3) - (3)]).type;

						}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 830 "sintatica.y"
    {
							(yyval).typesArgsFunction = (yyvsp[(1) - (1)]).type;
							(yyval).label = (yyvsp[(1) - (1)]).label;
							(yyval).translation = (yyvsp[(1) - (1)]).translation;
						}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 841 "sintatica.y"
    {
							function_struct* f;
							YYSTYPE* ass;
							string idFunction;
						
							idFunction = (yyvsp[(1) - (4)]).label + '(' + (yyvsp[(3) - (4)]).typesArgsFunction + ')';

							f = findFunction(idFunction);

							if(f != NULL)
							{
								(yyval).type = f->typeOfReturn;
								(yyval).modifier = f->modifierOfReturn;

								(yyval).translation = "\t/*----chamada de função----*/\n";
								(yyval).translation += (yyvsp[(3) - (4)]).translation;

								if((yyval).type != "void")
								{
									(yyval).label = generateID();

									ass = new YYSTYPE();
									ass->label = (yyval).label;
									ass->type = (yyval).type;
									ass->modifier = (yyval).modifier;
									declare(ass->label, ass->modifier + (ass->modifier == "" ? "" : " ") + ass->type, (f->typeOfReturn == "string" ? 0 : 1));

									(yyval).translation += "\t" + ass->label + " = " + f->label + "(" +  (yyvsp[(3) - (4)]).label + ");\n";
								}
								else
								{
									(yyval).label = f->label;
									(yyval).translation += "\t" + f->label + "(" +  (yyvsp[(3) - (4)]).label + ");\n";
								}

								(yyval).translation += "\t/*-------------------------*/\n";

								f->called = true;
								f->last_call_line = yylineno;
							}
							else
							{
								yyerror("implicit declaration of function ‘" + idFunction + "’");
							}
						}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 890 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(3) - (4)]).translation + "\n\tcout << ";
								(yyval).translation += (yyvsp[(3) - (4)]).label + ((yyvsp[(3) - (4)]).vectPositions.size() > 0 ? "[" + (yyvsp[(3) - (4)]).posLabel + "]" : "") + ";\n";
                        }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 895 "sintatica.y"
    {
								(yyval).translation = (yyvsp[(3) - (4)]).translation + "\n\tcout << ";
								(yyval).translation += (yyvsp[(3) - (4)]).label + ((yyvsp[(3) - (4)]).vectPositions.size() > 0 ? "[" + (yyvsp[(3) - (4)]).posLabel + "]" : "") + " << endl;\n";
                        }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 900 "sintatica.y"
    {
								(yyval).translation = "\n\tcout << endl;";
						}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 907 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(3) - (4)]).translation;
								(yyval).translation += "\n\tcin >> " + (yyvsp[(3) - (4)]).label + ((yyvsp[(3) - (4)]).vectPositions.size() > 0 ? "[" + (yyvsp[(3) - (4)]).posLabel + "]" : "") + ";\n";

								//redeclara, atualizando o tamanho da string*/
								if(((yyvsp[(3) - (4)]).type == "string") && (getDeclarationLength((yyvsp[(3) - (4)])) < 1000))
									declare((yyvsp[(3) - (4)]).label, (yyvsp[(3) - (4)]).modifier + ((yyvsp[(3) - (4)]).modifier != "" ? " " : "") + (yyvsp[(3) - (4)]).type, 1000);
                        }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 920 "sintatica.y"
    {
                                (yyval).translation =  (yyvsp[(1) - (3)]).translation + (yyvsp[(2) - (3)]).translation + (yyvsp[(3) - (3)]).translation;
                        }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 929 "sintatica.y"
    {
                                openNewScope();                        
                                (yyval).translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
								flagDeclarationNotAllowedAux = flagDeclarationNotAllowed;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 942 "sintatica.y"
    {
                                declarations += getDeclarations();
								mallocTranslations += getMallocs();
                                closeCurrentScope(); /*desempilha*/                                
                                (yyval).translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
                                flagDeclarationNotAllowed = flagDeclarationNotAllowedAux;

                        }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 957 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(1) - (2)]).translation + "\n" + (yyvsp[(2) - (2)]).translation;
                        }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 961 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 971 "sintatica.y"
    {
                                /*controle de declarações, quando tais não são permititdas (exemplo: if, for, ...)*/
                                if(flagDeclarationNotAllowed)
                                {
                                        yyerror("declarations not allowed.");
                                        flagDeclarationNotAllowed = false;
                                }
                        }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 985 "sintatica.y"
    {
							(yyval).translation = (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation;
							(yyval).label = (yyvsp[(2) - (2)]).label;
							(yyval).type = (yyvsp[(2) - (2)]).type;
							(yyval).modifier = (yyvsp[(2) - (2)]).modifier;
						}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 996 "sintatica.y"
    {
                                (yyval).translation = "";
                        }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 1004 "sintatica.y"
    {
								functions_map* functionMap;
								functions_map::iterator i;

								YYSTYPE* cast;
								YYSTYPE func;
								function_struct* f;
				
								string idMainFunction = "main (void)";
								YYSTYPE idReturn;

								functionMap = *next(stackFunctionMap.begin(), 2);
								string idFunction = idOfCurrentFunction.front();
								i = functionMap->find(idFunction);

								/*enxerta as traduções de free antes do return no main*/									
								if((i != functionMap->end()))
								{
									f = &(i->second);
									f->hasReturn = true;

									if(f->typeOfReturn != (yyvsp[(2) - (2)]).type)
									{
										func.type = f->typeOfReturn;										
										func.modifier = f->modifierOfReturn;	

										cast = runCast((yyvsp[(2) - (2)]), func);

										if(cast == NULL)
							            	yyerror("cast from " + (yyvsp[(2) - (2)]).type + " to " + func.modifier + " " + func.type + " not allowed");

										else if(f->typeOfReturn == "string")
										{
											idReturn.label = generateID();
											idReturn.translation = "";
											idReturn.type = cast->type;
											idReturn.modifier = cast->modifier;

											//declara a variável globalmente e realiza o malloc
											declarations_map* declarationsMap = stackDeclarationsMap.back();
											(*declarationsMap)[idReturn.label] = {(yyvsp[(2) - (2)]).type, 0};
											addMalloc(dinamicallyVectDeclaration(idReturn, (yyvsp[(2) - (2)]), 2));
											
											(yyval).translation = (yyvsp[(2) - (2)]).translation + cast->translation;
											(yyval).translation += "\t" + idReturn.label + " = (char*) realloc(" + idReturn.label + ", " + intToString(getDeclarationLength(*cast)) + ");\n";
											(yyval).translation += "\tstrcpy(" + idReturn.label + ", " + cast->label + ");\n";
											f->returnTranslation = "\n\t" + (yyvsp[(1) - (2)]).translation + " " + idReturn.label + ";";
											(yyval).translation += f->returnTranslation;

											freeMainTranslation += "if (" + idReturn.label + " != NULL)\n\t\tfree(" + idReturn.label + ");\n";
										}
										else
										{
											(yyval).translation = (yyvsp[(2) - (2)]).translation + cast->translation + "\n\t";
											f->returnTranslation = (yyvsp[(1) - (2)]).translation + " " + cast->label + ";";
											(yyval).translation += f->freeTranslation;
											(yyval).translation += f->returnTranslation;
										}
									}
									else if(f->typeOfReturn == "string")
									{
										idReturn.label = generateID();
										idReturn.translation = "";
										idReturn.type = (yyvsp[(2) - (2)]).type;
										idReturn.modifier = (yyvsp[(2) - (2)]).modifier;

										//declara a variável globalmente e realiza o malloc
										declarations_map* declarationsMap = stackDeclarationsMap.back();
										(*declarationsMap)[idReturn.label] = {idReturn.type, 0};
										addMalloc(dinamicallyVectDeclaration(idReturn, (yyvsp[(2) - (2)]), 2));

										(yyval).translation = (yyvsp[(2) - (2)]).translation + "\n";
										(yyval).translation += "\t" + idReturn.label + " = (char*) realloc(" + idReturn.label + ", " + intToString(getDeclarationLength((yyvsp[(2) - (2)]))) + ");\n";
										(yyval).translation += "\tstrcpy(" + idReturn.label + ", " + (yyvsp[(2) - (2)]).label + ");\n";
										f->returnTranslation = "\t" + (yyvsp[(1) - (2)]).translation + " " + idReturn.label + ";";
										(yyval).translation += f->returnTranslation;

										freeMainTranslation += "if (" + idReturn.label + " != NULL)\n\t\tfree(" + idReturn.label + ");\n";
									}
									else
									{
										(yyval).translation = (yyvsp[(2) - (2)]).translation + "\n";
	                                	f->returnTranslation = "\t" + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label+ ";";
										(yyval).translation += f->returnTranslation;
									}

								}
								else if(idFunction == idMainFunction)
								{
	                                returnMainTranslation = (yyvsp[(2) - (2)]).translation + "\n\t" + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";";
									(yyval).translation = returnMainTranslation;
								}
								else
									(yyval).translation = (yyvsp[(2) - (2)]).translation + "\n\t" + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";";
                        }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 1106 "sintatica.y"
    {
							/*controle de declaraçãoes*/
							flagDeclarationNotAllowed = true;
						}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 1113 "sintatica.y"
    {                                
                                YYSTYPE notE;
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression((yyvsp[(3) - (5)]));

                                (yyval).translation = (yyvsp[(3) - (5)]).translation; /*tradução da expressão E*/
                                (yyval).translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                (yyval).translation += "\t" + (yyvsp[(1) - (5)]).translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                (yyval).translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += (yyvsp[(5) - (5)]).translation + "\n"; /*tradução: STATEMENT*/
                                (yyval).translation += "\t" + labelEndIF + ":\n\t;\n"; /*tradução: labelEndIF:*/

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;

                        }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 1132 "sintatica.y"
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
                                (yyval).translation += "\t" + labelEndIF + ":\n\t;\n"; /*tradução: labelEndId:*/

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 1157 "sintatica.y"
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

  case 57:

/* Line 1806 of yacc.c  */
#line 1176 "sintatica.y"
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
                                (yyval).translation += "\t" + labelEndWhile + ":\n\t;\n"; /*tradução: labelEndWhile:*/


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

  case 58:

/* Line 1806 of yacc.c  */
#line 1209 "sintatica.y"
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

  case 59:

/* Line 1806 of yacc.c  */
#line 1228 "sintatica.y"
    {
                                string labelBeginDoWhile = stackBeginLabels.front();
                                string labelEndDoWhile = stackEndLabels.front();


                                (yyval).translation = "\n\t" + labelBeginDoWhile + ":\n"; /*tradução: labelBeginDoWhileIF:*/
                                (yyval).translation += (yyvsp[(2) - (7)]).translation + "\n"; /*tradução: STATEMENT*/
                                (yyval).translation += (yyvsp[(5) - (7)]).translation; /*tradução da expressão E*/
                                (yyval).translation += "\tif (" + (yyvsp[(5) - (7)]).label + ")\n"; /*tradução: if (E)*/
                                (yyval).translation += "\t\tgoto " + labelBeginDoWhile + ";\n"; /*tradução: goto labelEndIf*/
                                (yyval).translation += "\t" + labelEndDoWhile + ":\n\t;\n"; /*tradução: labelEndDoWhileIF:*/


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

  case 66:

/* Line 1806 of yacc.c  */
#line 1278 "sintatica.y"
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

  case 67:

/* Line 1806 of yacc.c  */
#line 1301 "sintatica.y"
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
                            (yyval).translation += "\t" + labelEndFor + ":\n\t;"; /*tradução: labelEndFor:*/


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

  case 68:

/* Line 1806 of yacc.c  */
#line 1344 "sintatica.y"
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
							(yyval).translation += "\n\t" + labelEndFor + ":\n\t;"; /*tradução: labelEndFor:*/                                


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

  case 69:

/* Line 1806 of yacc.c  */
#line 1411 "sintatica.y"
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

  case 70:

/* Line 1806 of yacc.c  */
#line 1433 "sintatica.y"
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

  case 71:

/* Line 1806 of yacc.c  */
#line 1462 "sintatica.y"
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

  case 72:

/* Line 1806 of yacc.c  */
#line 1488 "sintatica.y"
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

  case 73:

/* Line 1806 of yacc.c  */
#line 1506 "sintatica.y"
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

  case 74:

/* Line 1806 of yacc.c  */
#line 1521 "sintatica.y"
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

  case 75:

/* Line 1806 of yacc.c  */
#line 1536 "sintatica.y"
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

  case 76:

/* Line 1806 of yacc.c  */
#line 1556 "sintatica.y"
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
				(yyval).translation += "\t" + labelEndSwitch + ":\n\t;\n";


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

  case 77:

/* Line 1806 of yacc.c  */
#line 1601 "sintatica.y"
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

							/*if((inFunctionArgs == true) && ($1.isConstant == false))
								scopeMainTranslation = $$.translation + scopeMainTranslation;*/

						}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1622 "sintatica.y"
    {
                                (yyval).translation = (yyvsp[(2) - (3)]).translation;
                                (yyval).label = (yyvsp[(2) - (3)]).label;
                                (yyval).type = (yyvsp[(2) - (3)]).type;
                                (yyval).modifier = (yyvsp[(2) - (3)]).modifier;                
                                (yyval).isConstant = (yyvsp[(2) - (3)]).isConstant; 
                                (yyval).posLabel = (yyvsp[(2) - (3)]).posLabel;
								(yyval).intValue = (yyvsp[(2) - (3)]).intValue;
                        }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1635 "sintatica.y"
    {
	                        (yyval) = *runCast((yyvsp[(4) - (4)]), (yyvsp[(2) - (4)]));

							if((yyval).label == "")
			                	yyerror("cast from " + (yyvsp[(4) - (4)]).type + " to " + (yyvsp[(2) - (4)]).type + " not allowed");

							(yyval).translation = (yyvsp[(4) - (4)]).translation + (yyval).translation;
                        }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1644 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1648 "sintatica.y"
    {
                                 (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1652 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1656 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1660 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1664 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1668 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1672 "sintatica.y"
    {

                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1678 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1684 "sintatica.y"
    {                                
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1690 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1696 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1702 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
								(yyval).relationalCounter = (yyvsp[(1) - (3)]).relationalCounter + (yyvsp[(2) - (3)]).relationalCounter;
                                relationalControl(&(yyval), (yyvsp[(2) - (3)]));
                        }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1708 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1712 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1716 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1720 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1724 "sintatica.y"
    {
                                (yyval) = runBasicOperation((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]).translation);
                        }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1728 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";
								(yyval).posLabel = (yyvsp[(2) - (2)]).posLabel;

                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";\n";                                
                                
                                if((yyvsp[(2) - (2)]).type == "int")
                                	(yyval).intValue = !(yyvsp[(2) - (2)]).intValue;

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1742 "sintatica.y"
    {
                                 (yyval).label = generateID();

                                if(((yyvsp[(2) - (2)]).type != "int") && ((yyvsp[(2) - (2)]).type != "char"))
                                        yyerror("wrong type argument to bit-complement");

                                (yyval).translation = (yyvsp[(2) - (2)]).translation + "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + " " + (yyvsp[(2) - (2)]).label + ";\n";

                                (yyval).type = (yyvsp[(2) - (2)]).type;
                                (yyval).modifier = (yyvsp[(2) - (2)]).type;
								(yyval).posLabel = (yyvsp[(2) - (2)]).posLabel;
                                                             
                                if((yyvsp[(2) - (2)]).type == "int")
                                	(yyval).intValue = ~(yyvsp[(2) - (2)]).intValue;

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1767 "sintatica.y"
    {
                                id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;

								YYSTYPE pos;
								string posTranslation = "";

								(yyvsp[(1) - (3)]).vectPositions = (yyvsp[(2) - (3)]).vectPositions;
                        
                                if((id = findID((yyvsp[(1) - (3)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(1) - (3)]).label + "'  was not declared in this scope.");
                                else
                                {
										if (((yyvsp[(2) - (3)]).vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + (yyvsp[(1) - (3)]).label + (yyvsp[(2) - (3)]).translation + "' from type '" + (yyvsp[(1) - (3)]).type);
										else if (((yyvsp[(2) - (3)]).vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(((yyvsp[(2) - (3)]).vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, (yyvsp[(2) - (3)]).vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, (yyvsp[(2) - (3)]).vectPositions);
													

											(yyvsp[(1) - (3)]).posLabel = pos.label;
											posTranslation = pos.translation;
										}


                                        (yyvsp[(1) - (3)]).translation = "";
                                        (yyvsp[(1) - (3)]).type = id->type;
                                        (yyvsp[(1) - (3)]).modifier = id->modifier;

                                        (yyval).translation = posTranslation;
                                        (yyval).label = id->label;
                                        (yyval).type = (yyvsp[(1) - (3)]).type;
                                        (yyval).modifier = (yyvsp[(1) - (3)]).modifier;
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = (yyvsp[(1) - (3)]);
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ((yyvsp[(3) - (3)]).translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, (yyvsp[(1) - (3)]), op);

                                        auxIncreaseTranslation = posTranslation + ass.translation;
                                        flagIncreaseTranslation = true;
                                }
                        }
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1833 "sintatica.y"
    {
                                id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;

								YYSTYPE pos;
								string posTranslation = "";

								(yyvsp[(2) - (3)]).vectPositions = (yyvsp[(3) - (3)]).vectPositions;

                        
                                if((id = findID((yyvsp[(2) - (3)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(2) - (3)]).label + "'  was not declared in this scope.");
                                else
                                {
                                        (yyvsp[(2) - (3)]).translation = "";
                                        (yyvsp[(2) - (3)]).type = id->type;
                                        (yyvsp[(2) - (3)]).modifier = id->modifier;

										if (((yyvsp[(3) - (3)]).vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + (yyvsp[(1) - (3)]).label + (yyvsp[(2) - (3)]).translation + "' from type '" + (yyvsp[(1) - (3)]).type);
										else if (((yyvsp[(3) - (3)]).vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(((yyvsp[(3) - (3)]).vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, (yyvsp[(3) - (3)]).vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, (yyvsp[(3) - (3)]).vectPositions);

											(yyvsp[(2) - (3)]).posLabel = pos.label;
											posTranslation = pos.translation;
										}
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = (yyvsp[(2) - (3)]);
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ((yyvsp[(1) - (3)]).translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, (yyvsp[(2) - (3)]), op);
                                        
                                        (yyval).translation = posTranslation + ass.translation;
                                        (yyval).label = ass.label;
                                        (yyval).type = ass.type;
                                        (yyval).modifier = ass.modifier;
                                }
                        }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1896 "sintatica.y"
    {
								YYSTYPE pos;
								id_struct* id;

                                if((id = findID((yyvsp[(1) - (4)]).label)) == NULL)
                                        yyerror("identifier: '" + (yyvsp[(1) - (4)]).label + "' was not declared in this scope.");
                                else
								{
										if (((yyvsp[(2) - (4)]).vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + (yyvsp[(1) - (4)]).label + (yyvsp[(2) - (4)]).translation + "' from type '" + (yyvsp[(4) - (4)]).type);
										else if (((yyvsp[(2) - (4)]).vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(((yyvsp[(2) - (4)]).vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, (yyvsp[(2) - (4)]).vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, (yyvsp[(2) - (4)]).vectPositions);

											(yyvsp[(1) - (4)]).posLabel = pos.label;
		                                    (yyval) = assign(voidStr, (yyvsp[(1) - (4)]), (yyvsp[(4) - (4)]));
											(yyval).translation = pos.translation + (yyval).translation;
										}
								}
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1927 "sintatica.y"
    {
								YYSTYPE pos;
                                string operation;
                                id_struct* id;

                                YYSTYPE ass;
                                YYSTYPE op_id;
                                YYSTYPE op;

                                if((id = findID((yyvsp[(1) - (4)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(1) - (4)]).label + "'  was not declared in this scope.");
                                else
                                {
                                        
                                        (yyvsp[(1) - (4)]).translation = "";
                                        (yyvsp[(1) - (4)]).type = id->type;
                                        (yyvsp[(1) - (4)]).modifier = id->modifier;

										/*verifica qual operação deve ser realizada*/
										if ((yyvsp[(3) - (4)]).translation == "+=")
											operation = "+";
										else if ((yyvsp[(3) - (4)]).translation == "-=")
											operation = "-";
										else if ((yyvsp[(3) - (4)]).translation == "*=")
											operation = "*";
										else if ((yyvsp[(3) - (4)]).translation == "/=")
											operation = "/";
										else if ((yyvsp[(3) - (4)]).translation == "%=")
											operation = "%";
										else if ((yyvsp[(3) - (4)]).translation == "<<=")
											operation = "<<";
										else if ((yyvsp[(3) - (4)]).translation == ">>=")
											operation = ">>";
										else if ((yyvsp[(3) - (4)]).translation == "&=")
											operation = "&";
										else if ((yyvsp[(3) - (4)]).translation == "|=")
											operation = "|";
										else if ((yyvsp[(3) - (4)]).translation == "^=")
											operation = "^";

                                        /*Realiza as operações referentes a operação*/
                                        op_id = (yyvsp[(1) - (4)]);
                                        op_id.label = id->label;


										if (((yyvsp[(2) - (4)]).vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + (yyvsp[(1) - (4)]).label + "[" + (yyvsp[(2) - (4)]).translation + "]' from type '" + (yyvsp[(4) - (4)]).type);
										else if (((yyvsp[(2) - (4)]).vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(((yyvsp[(2) - (4)]).vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, (yyvsp[(2) - (4)]).vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, (yyvsp[(2) - (4)]).vectPositions);

											(yyvsp[(1) - (4)]).posLabel = pos.label;
											(yyvsp[(1) - (4)]).vectPositions = (yyvsp[(2) - (4)]).vectPositions;
											op_id.posLabel = (yyvsp[(1) - (4)]).posLabel;
											op_id.vectPositions = (yyvsp[(1) - (4)]).vectPositions;

		                                    op = runBasicOperation(op_id, (yyvsp[(4) - (4)]), operation);
		                                    ass = assign(voidStr, (yyvsp[(1) - (4)]), op);

		                                    (yyval).translation = pos.translation + ass.translation;
		                                    (yyval).label = ass.label;
		                                    (yyval).type = ass.type;
		                                    (yyval).modifier = ass.modifier;
										}											
                                }                                                                
                                
                        }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 2005 "sintatica.y"
    {
								int size = 1;
								string pointer = "";

                                identifiers_map* IDMap = stackIDMap.front();
                                                        
                                if(!isDeclaredCurrentScope((yyvsp[(3) - (4)]).label))
                                {
                                        (*IDMap)[(yyvsp[(3) - (4)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(3) - (4)]).label].type = (yyvsp[(1) - (4)]).type;
                                        (*IDMap)[(yyvsp[(3) - (4)]).label].modifier = (yyvsp[(1) - (4)]).modifier;
                                        (*IDMap)[(yyvsp[(3) - (4)]).label].vectSizes = (yyvsp[(4) - (4)]).vectSizes;
                                        (*IDMap)[(yyvsp[(3) - (4)]).label].vectSizesFromIds = (yyvsp[(4) - (4)]).vectPositions;
										(*IDMap)[(yyvsp[(3) - (4)]).label].hasSizes = (yyvsp[(4) - (4)]).isConstant;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(3) - (4)]).label + "'  previously declared here.");

                                
                                (yyval).label = (*IDMap)[(yyvsp[(3) - (4)]).label].label;
                                (yyval).type = (yyvsp[(1) - (4)]).type;//(*IDMap)[$3.label].type;
                                (yyval).modifier = (yyvsp[(1) - (4)]).modifier;//(*IDMap)[$3.label].modifier;
                                (yyval).translation = (yyvsp[(1) - (4)]).translation;

								//Calcula o tamanho do vetor, se for uma variável simples, o tamanho será 1
								//if(($4.vectSizes.size() > 0) && ($4.vectPositions.size() > 0))
								if((yyvsp[(4) - (4)]).isConstant == false)
								{
									pointer = "*";
									addMalloc(dinamicallyVectDeclaration((yyval), (yyvsp[(4) - (4)]), 2));
								}
								else if((yyvsp[(4) - (4)]).vectSizes.size() > 0)
								{
									for(int i = 0; i < (yyvsp[(4) - (4)]).vectSizes.size(); i++)
										size *= (yyvsp[(4) - (4)]).vectSizes.at(i);
								}

	                            if ((yyval).modifier != "")
	                                    declare((yyval).label, (yyval).modifier + " " + (yyval).type + pointer, size);
	                            else
	                                    declare((yyval).label, (yyval).type + pointer, size);


                        }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 2050 "sintatica.y"
    {
                                string ATTRIBUITION = "";
								unsigned int length;
                                
                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope((yyvsp[(3) - (5)]).label))
                                {
                                        (*IDMap)[(yyvsp[(3) - (5)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(3) - (5)]).label].type = (yyvsp[(1) - (5)]).type;
                                        (*IDMap)[(yyvsp[(3) - (5)]).label].modifier = (yyvsp[(1) - (5)]).modifier;
                                        (&(*IDMap)[(yyvsp[(3) - (5)]).label].vectSizes)->clear();
                                        (&(*IDMap)[(yyvsp[(3) - (5)]).label].vectSizesFromIds)->clear();
										(*IDMap)[(yyvsp[(3) - (5)]).label].hasSizes = true;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(3) - (5)]).label + "'  previously declared here.");
                  
                                (yyval) = assign((yyvsp[(1) - (5)]).translation, (yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));
								length = getDeclarationLength((yyval));

                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, length);
                                else
                                        declare((yyval).label, (yyval).type, length);
                                                        
                        }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 2078 "sintatica.y"
    {
								int size = 1;
								string pointer = "";
                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope((yyvsp[(2) - (3)]).label))
                                {
                                        (*IDMap)[(yyvsp[(2) - (3)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(2) - (3)]).label].type = (yyvsp[(1) - (3)]).type;
                                        (*IDMap)[(yyvsp[(2) - (3)]).label].modifier = (yyvsp[(1) - (3)]).modifier;
		
										if((yyvsp[(3) - (3)]).vectSizes.size() > 0)
										{
		                                    (*IDMap)[(yyvsp[(2) - (3)]).label].vectSizes = (yyvsp[(3) - (3)]).vectSizes;
		                                    (*IDMap)[(yyvsp[(2) - (3)]).label].vectSizesFromIds = (yyvsp[(3) - (3)]).vectPositions;
										}
										else
										{
											(&(*IDMap)[(yyvsp[(2) - (3)]).label].vectSizes)->clear();
		                                    (&(*IDMap)[(yyvsp[(2) - (3)]).label].vectSizesFromIds)->clear();
										}
										(*IDMap)[(yyvsp[(2) - (3)]).label].hasSizes = (yyvsp[(3) - (3)]).isConstant;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(2) - (3)]).label + "'  previously declared here.");


                                (yyval).label = (*IDMap)[(yyvsp[(2) - (3)]).label].label;
                                (yyval).translation = "";
                                (yyval).type = (*IDMap)[(yyvsp[(2) - (3)]).label].type;
                                (yyval).modifier = (*IDMap)[(yyvsp[(2) - (3)]).label].modifier;

								//Calcula o tamanho do vetor, se for uma variável simples, o tamanho será 1
								//if(($3.vectSizes.size() > 0) && ($3.vectPositions.size() > 0))
								if((yyvsp[(3) - (3)]).isConstant == false)
								{
									pointer = "*";
									(yyval).translation += dinamicallyVectDeclaration((yyval), (yyvsp[(3) - (3)]), 2);
								}
								else if((yyvsp[(3) - (3)]).vectSizes.size() > 0)
								{
									for(int i = 0; i < (yyvsp[(3) - (3)]).vectSizes.size(); i++)
										size *= (yyvsp[(3) - (3)]).vectSizes.at(i);
								}

	                            if ((yyval).modifier != "")
	                                    declare((yyval).label, (yyval).modifier + " " + (yyval).type + pointer, size);
	                            else
	                                    declare((yyval).label, (yyval).type + pointer, size);
                        }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 2129 "sintatica.y"
    {

								unsigned int length;
                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope((yyvsp[(2) - (4)]).label))
                                {
                                        (*IDMap)[(yyvsp[(2) - (4)]).label].label = generateID();
                                        (*IDMap)[(yyvsp[(2) - (4)]).label].type = (yyvsp[(1) - (4)]).type;
                                        (*IDMap)[(yyvsp[(2) - (4)]).label].modifier = (yyvsp[(1) - (4)]).modifier;
										(&(*IDMap)[(yyvsp[(2) - (4)]).label].vectSizes)->clear();
                                        (&(*IDMap)[(yyvsp[(2) - (4)]).label].vectSizesFromIds)->clear();
										(*IDMap)[(yyvsp[(2) - (4)]).label].hasSizes = true;
                                }
                                else
                                        yyerror("identifier: '" + (yyvsp[(2) - (4)]).label + "'  previously declared here.");

                                (yyval) = assign(voidStr, (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
								length = 1;
				
                                if ((yyval).modifier != "")
                                        declare((yyval).label, (yyval).modifier + " " + (yyval).type, length);
                                else
                                        declare((yyval).label, (yyval).type, length);
                        }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 2159 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 2165 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 2171 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 2177 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 2183 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 2189 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(1) - (1)]).translation;
                                (yyval).modifier = "";
                                (yyval).translation = "";
                        }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 2195 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = "unsigned short";
                                (yyval).translation = "";
                        }
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 2201 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 2207 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 2213 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 2219 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 2225 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 2231 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 2237 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(2) - (2)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (2)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 2243 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 2249 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (1)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 2255 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 2261 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 2267 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 2273 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 2279 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(3) - (3)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 2285 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + " " + (yyvsp[(3) - (4)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 2291 "sintatica.y"
    {
                                (yyval).type = (yyvsp[(4) - (4)]).translation;
                                (yyval).modifier = (yyvsp[(1) - (4)]).translation + " " + (yyvsp[(2) - (4)]).translation + " " + (yyvsp[(3) - (4)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 2297 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation + " " + (yyvsp[(3) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 2303 "sintatica.y"
    {
                                (yyval).type = "int";
                                (yyval).modifier = (yyvsp[(1) - (3)]).translation + " " + (yyvsp[(2) - (3)]).translation + " " + (yyvsp[(3) - (3)]).translation;
                                (yyval).translation = "";
                        }
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 2313 "sintatica.y"
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

  case 140:

/* Line 1806 of yacc.c  */
#line 2325 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
  
                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 2336 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
          

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 2348 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "char";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
              

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (1)]).translation + ";\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 2360 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "int";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
 

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 2372 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
  
                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 2383 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "float"; //poderia ser double
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
          

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + ";\n";

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 2395 "sintatica.y"
    {
                                (yyval).label = generateID();
                                (yyval).type = "char";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;
              

                                (yyval).translation = "\t" + (yyval).label + " = " + (yyvsp[(1) - (2)]).translation + (yyvsp[(2) - (2)]).translation + "\n";                                

                                declare((yyval).label, (yyval).type, 1);
                        }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 2407 "sintatica.y"
    {                        

			       				(yyval).label = generateID();
                                (yyval).type = "string";
                                (yyval).modifier = "";
                               	(yyval).isConstant = true;

								(yyval).translation = "\tstrcpy(" + (yyval).label + ", " + (yyvsp[(1) - (1)]).translation + ");\n";                           
								(yyval).translation += "\t" + (yyval).label + "[" + intToString((yyvsp[(1) - (1)]).translation.length() - 2) + "] = " + "'\\0';\n";

								/*comprimento da string '-2' por conta das aspas +1 por conta do '/0'*/
                                declare((yyval).label, (yyval).type, (yyvsp[(1) - (1)]).translation.length() - 2 + 1);
                        }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 2421 "sintatica.y"
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

  case 149:

/* Line 1806 of yacc.c  */
#line 2436 "sintatica.y"
    {
                                id_struct* id;
								YYSTYPE pos;
								string posLabel;
                        
                                if((id = findID((yyvsp[(1) - (2)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(1) - (2)]).label + "'  was not declared in this scope.");
                                else
                                {
								
                                        (yyval).label = id->label;
                                        (yyval).type = id->type;
                                        (yyval).modifier = id->modifier;
                                        (yyval).translation = "";

										if((yyvsp[(2) - (2)]).vectPositions.size() > 0)
										{
											if(id->hasSizes == true)
												pos = computingPosition(id->vectSizes, (yyvsp[(2) - (2)]).vectPositions);
											else
												pos = computingPositionFromIds(id->vectSizesFromIds, (yyvsp[(2) - (2)]).vectPositions);
											(yyval).translation = pos.translation;
											posLabel = pos.label;
										}

										(yyval).vectPositions = (yyvsp[(2) - (2)]).vectPositions;
										(yyval).posLabel = posLabel;
				                       	(yyval).isConstant = false;

                                }
                        }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 2468 "sintatica.y"
    {
                                id_struct* id;
								YYSTYPE pos;
								string posLabel;
                        
                                if((id = findID((yyvsp[(2) - (3)]).label)) == NULL)       
                                        yyerror("identifier: '" + (yyvsp[(2) - (3)]).label + "'  was not declared in this scope.");
                                else
                                {
										string modifier;
										(yyval).translation = "";

										if((yyvsp[(3) - (3)]).vectSizes.size() > 0)
										{
											if(id->hasSizes == true)
												pos = computingPosition(id->vectSizes, (yyvsp[(3) - (3)]).vectPositions);
											else
												pos = computingPositionFromIds(id->vectSizesFromIds, (yyvsp[(3) - (3)]).vectPositions);

											(yyval).translation = pos.translation;
											posLabel = pos.label;
										}

                                        (yyval).label = generateID();
										(yyval).vectPositions = (yyvsp[(3) - (3)]).vectPositions;
										(yyval).posLabel = posLabel;
                                        (yyval).type = id->type;
                                        (yyval).modifier = id->modifier;
                                        (yyval).translation += "\t" + (yyval).label + " = " + (yyvsp[(1) - (3)]).translation + id->label + posLabel + ";\n";

										modifier = (yyval).modifier;
										if(modifier != "")
											modifier+= " ";
			
										declare((yyval).label, modifier + (yyval).type, 1);
                                }

                               	(yyval).isConstant = false;
                        }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 2516 "sintatica.y"
    {
							if((yyvsp[(2) - (4)]).type != "int")
								yyerror("size of array has non-integer type");

							/*isso é utilizado nos casos que há algum tamanho não constante,
							para se realizar alocação dinâmica com malloc*/
							(yyval).vectPositions = (yyvsp[(4) - (4)]).vectPositions;
							(yyval).vectPositions.insert((yyval).vectPositions.begin(), (yyvsp[(2) - (4)]));
							
							(yyval).vectSizes = (yyvsp[(4) - (4)]).vectSizes;
							(yyval).vectSizes.insert((yyval).vectSizes.begin(), (yyvsp[(2) - (4)]).intValue);

							(yyval).isConstant = (yyvsp[(2) - (4)]).isConstant && (yyvsp[(4) - (4)]).isConstant;
							(yyval).hasIdSizeInVectArgs = (yyvsp[(4) - (4)]).hasIdSizeInVectArgs && true;
							(yyval).translation = "[]" + (yyvsp[(4) - (4)]).translation;
							//$$.translation = "[" + $2.label + "]" + $4.translation;;
						}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 2534 "sintatica.y"
    {
							(yyval).vectSizes = (yyvsp[(3) - (3)]).vectSizes;
							(yyval).vectPositions = (yyvsp[(3) - (3)]).vectPositions;
							(yyval).isConstant = true;
							(yyval).translation = "";
							(yyval).hasIdSizeInVectArgs = false;
							(yyval).translation = "[]" + (yyvsp[(3) - (3)]).translation;
						}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 2543 "sintatica.y"
    {
							(&(yyval).vectSizes)->clear();
							(&(yyval).vectPositions)->clear();
							(yyval).isConstant = true;
							(yyval).translation = "";
							(yyval).hasIdSizeInVectArgs = true;
						}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 2555 "sintatica.y"
    {
							if((yyvsp[(2) - (4)]).type != "int")
								yyerror("size of array has non-integer type");
							else
							{
								(yyval).vectPositions = (yyvsp[(4) - (4)]).vectPositions;
								(yyval).vectPositions.insert((yyval).vectPositions.begin(), (yyvsp[(2) - (4)]));
								(yyval).translation = "[]" + (yyvsp[(4) - (4)]).translation;
							}
						}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 2566 "sintatica.y"
    {
							(yyval).vectPositions.clear();
							(yyval).translation = "";
						}
    break;



/* Line 1806 of yacc.c  */
#line 4736 "y.tab.c"
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
#line 2575 "sintatica.y"


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
		mallocs_vector* mallocsVector = new mallocs_vector();

		IDMap->clear();
		declarationsMap->clear();
		functionMap->clear();
		mallocsVector->clear();

        stackIDMap.push_front(IDMap);
        stackDeclarationsMap.push_front(declarationsMap);
        stackFunctionMap.push_front(functionMap);
		stackMallocsMap.push_front(mallocsVector);
}

void closeCurrentScope()
{
        stackIDMap.pop_front();
        stackDeclarationsMap.pop_front();
		stackFunctionMap.pop_front();
		stackMallocsMap.pop_front();
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
		
		res->isConstant = operand1.isConstant & operand2.isConstant;

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
                res->translation += "\t" + res->label + " = ";
				res->translation += operand1.label + (operand1.vectPositions.size() > 0 ? "[" + operand1.posLabel + "]" : "" );
				res->translation += " " + operation + " ";
				res->translation += operand2.label + (operand2.vectPositions.size() > 0 ? "[" + operand2.posLabel + "]" : "" ) + ";\n";
        }
        else
        {	
				strongType = verifyStrongType(operand1.type, operand2.type);

                if(operand1.type == strongType)
                {
						keyOperand = *runCast(operand2, operand1);

						res->translation += keyOperand.translation;
                        res->translation += "\t" + res->label + " = ";
						res->translation += operand1.label + (operand1.vectPositions.size() > 0 ? "[" + operand1.posLabel + "]" : "" );
						res->translation += " " + operation + " " + keyOperand.label + ";\n";
                }
                else
                {
						keyOperand = *runCast(operand1, operand2);

						res->translation += keyOperand.translation;
                        res->translation += "\t" + res->label + " = " + keyOperand.label;
						res->translation += " " + operation + " ";
						res->translation += operand2.label + (operand2.vectPositions.size() > 0 ? "[" + operand2.posLabel + "]" : "" ) + ";\n";
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
			if(length == 0)
				length = 1000;
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
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", \"%d\", ";
		res->translation += n.label + (n.vectPositions.size() > 0 ? "[" + n.posLabel + "]" : "") + ");\n";
		res->translation += "\t" + res->label + "[" + intToString(length-1) + "] = " + "'\\0';\n";
	}
	else if(n.type == "char")
	{
		length = 2;
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%c\", ";
		res->translation += n.label + (n.vectPositions.size() > 0 ? "[" + n.posLabel + "]" : "") + ");\n";
		res->translation += "\t" + res->label + "[" + intToString(length-1) + "] = " + "'\\0';\n";
	}
	else if(n.type == "float")
	{
		length = 100;
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%f\", ";
		res->translation += n.label + (n.vectPositions.size() > 0 ? "[" + n.posLabel + "]" : "") + ");\n";
		res->translation += "\t" + res->label + "[" + intToString(length-1) + "] = " + "'\\0';\n";
	}
	else if(n.type == "double")
	{
		length = 100;
		res->translation += "\tsnprintf(" + res->label + ", " + intToString(length) + ", " + "\"%f\", ";
		res->translation += n.label + (n.vectPositions.size() > 0 ? "[" + n.posLabel + "]" : "") + ");\n";
		res->translation += "\t" + res->label + "[" + intToString(length-1) + "] = " + "'\\0';\n";
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

		res->translation = "\t" + res->label + " = (" + modifier + to.type + ") ";
		res->translation += from.label + (from.vectPositions.size() > 0 ? "[" + from.posLabel + "]" : "") + ";\n";

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


YYSTYPE computingPosition(vector<unsigned int> declaration, vector<YYSTYPE> call)
{
	YYSTYPE* res;
	YYSTYPE opMul;
	YYSTYPE opSum;
	YYSTYPE ass;
	YYSTYPE value;

	if(declaration.size() < call.size())
	{
		yyerror("subscripted value is neither array nor pointer nor vector");
		res = NULL;
	}
	else
	{	
		res = new YYSTYPE();
		opSum = generateIntValue(0);

		//Calcula a posição de acesso
		for(int i = 0; i < call.size(); i++)
		{
			opMul = call.at(i);

			for(int j = declaration.size() - 1; j > i; j--)
			{
				value = generateIntValue(declaration.at(j));
				opMul = runBasicOperation(opMul, value, "*");
			}

			if(i > 0)
			{
				opSum.translation = "";
			}

			opSum = runBasicOperation(opSum, opMul, "+");
			res->translation += opSum.translation;
		}

		res->label = opSum.label;
		res->type = opSum.type;
		res->modifier = opSum.modifier;	

		declare(res->label, res->modifier + (res->modifier != "" ? " " : "") + res->type, 1);
	}

	return *res;
}


YYSTYPE computingPositionFromIds(vector<YYSTYPE> declaration, vector<YYSTYPE> call)
{
	YYSTYPE* res;
	YYSTYPE opMul;
	YYSTYPE opSum;
	YYSTYPE ass;
	YYSTYPE value;

	if(declaration.size() < call.size())
	{
		yyerror("subscripted value is neither array nor pointer nor vector");
		res = NULL;
	}
	else
	{	
		res = new YYSTYPE();
		opSum = generateIntValue(0);

		//Calcula a posição de acesso
		for(int i = 0; i < call.size(); i++)
		{
			opMul = call.at(i);

			for(int j = declaration.size() - 1; j > i; j--)
			{
				value = declaration.at(j);
				opMul = runBasicOperation(opMul, value, "*");
			}

			if(i > 0)
			{
				opSum.translation = "";
			}

			opSum = runBasicOperation(opSum, opMul, "+");
			res->translation += opSum.translation;
		}

		res->label = opSum.label;
		res->type = opSum.type;
		res->modifier = opSum.modifier;	

		declare(res->label, res->modifier + (res->modifier != "" ? " " : "") + res->type, 1);
	}

	return *res;
}


string dinamicallyVectDeclaration(YYSTYPE id, YYSTYPE vector_sizes, unsigned int depth)
{
	string translation = "";

	/*tratamento de alocação "dinâmica"*/
	YYSTYPE sizesToMalloc;
	functions_map* functionMap;
	functions_map::iterator i;
	function_struct* f;

	string auxDeclarations = "";

	functionMap = *next(stackFunctionMap.begin(), depth);
	i = functionMap->find(idOfCurrentFunction.front());

	/*freeArgsTranslation += "\tfree(" + id.label + ");\n";

	if(i != functionMap->end())
	{
		f = &i->second;
		f->freeTranslation += freeArgsTranslation;
		//freeMainTranslation += "\tfree(" + id.label + ");\n";
	}*/


	/*if(depth == 1)
	{
		declarations_map* declarationsMap = stackDeclarationsMap.front();		
		declarations_map declarationsMapBkp;
		declarations_map::iterator iBkp;

		/*
		YYSTYPE intermediaryId;
		intermediaryId.label = generateID();
		intermediaryId.type = id.type;
		intermediaryId.modifier = id.modifier;*/

		//declarationsMapBkp = *declarationsMap;
		//declarationsMap->clear();

		//(*declarationsMap)[intermediaryId.label] = {intermediaryId.modifier + (intermediaryId.modifier != "" ? " " : "") + intermediaryId.type, 0};

		/*sizesToMalloc = generateIntValue(1);
		for(int i = 0; i < vector_sizes.vectSizes.size(); i++)
		{
			sizesToMalloc = runBasicOperation(sizesToMalloc, vector_sizes.vectPositions.at(i), "*");
		}

		auxDeclarations += getDeclarations();
		declarationsMap->clear();

		for(iBkp = declarationsMapBkp.begin(); iBkp != declarationsMapBkp.end(); iBkp++)
			(*declarationsMap)[iBkp->first] = {iBkp->second.dIType, iBkp->second.length};

		translation = auxDeclarations;
		translation += sizesToMalloc.translation;
		translation += "\t" + id.label + " = ";
		translation += "(" + id.modifier + " " + normalizedType(id.type) + "*) " + "malloc" + " (sizeof(" + normalizedType(id.type) + ")*" + sizesToMalloc.label+");\n";*

		/*translation += "\t" + intermediaryId.label + " = ";
		translation += "(" + intermediaryId.modifier + " " + normalizedType(intermediaryId.type) + "*) ";
		translation += "malloc (sizeof(" + normalizedType(intermediaryId.type) + ")*" + sizesToMalloc.label + ");\n";
		translation += "\t" + id.label + " = " + intermediaryId.label + ";\n";*/
	//}
	//else
	//{
		sizesToMalloc = generateIntValue(1);
		for(int i = 0; i < vector_sizes.vectSizes.size(); i++)
		{
			sizesToMalloc = runBasicOperation(sizesToMalloc, vector_sizes.vectPositions.at(i), "*");
		}

		translation += sizesToMalloc.translation;
		translation += "\t" + id.label + " = ";
		translation += "(" + id.modifier + " " + normalizedType(id.type) + "*) " + "malloc" + " (sizeof(" + normalizedType(id.type) + ")*" + sizesToMalloc.label+");\n";
	//}

	return translation;
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


function_struct* findFunction(string label)
{
        list<functions_map*>::iterator i;
        
        for(i = stackFunctionMap.begin(); i != stackFunctionMap.end(); i++)
        {
                functions_map* functionMap = *i;

                if(functionMap->find(label) != functionMap->end())
                {
                        return &(*functionMap)[label];
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

bool isDeclaredFunctionInCurrentScope(string idFunction)
{
        functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
		functions_map::iterator i;
		i = functionMap->find(idFunction);

        if(i == functionMap->end())
                return false;
		return true;           
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


			    res->translation = addtranslation + exp.translation + cast->translation;
				res->translation += "\t" + res->label + (id.posLabel != "" ? "[" + id.posLabel + "]" : "") + " = ";
				res->translation += cast->label + (cast->posLabel != "" ? "[" + cast->posLabel + "]" : "") + ";\n";
		    }
		else
		{
			res->translation = addtranslation + exp.translation;
			res->translation += "\t" + res->label + (id.posLabel != "" ? "[" + id.posLabel + "]" : "") + " = ";
			res->translation += exp.label + (exp.posLabel != "" ? "[" + exp.posLabel + "]" : "") + ";\n";
		}

        return *res;
}


YYSTYPE stringAssign(string addtranslation, YYSTYPE id, YYSTYPE exp)
{
	YYSTYPE* res; 
	YYSTYPE expStr; 
	unsigned int length;
	string modifier;

	declarations_map* declarationsMap = stackDeclarationsMap.front();

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
	res->translation += "\tstrcpy(" + id.label + (id.posLabel != "" ? "[" + id.posLabel + "]" : "") + ", ";
	res->translation += expStr.label + (expStr.posLabel != "" ? "[" + expStr.posLabel + "]" : "") + ");\n";
	res->translation += "\t" + id.label + (id.posLabel != "" ? "[" + id.posLabel + "]" : "") + "[" + intToString(length - 1) + "] = '\\0';\n";

	if(res->modifier != "")
		modifier += " ";

	setDeclarationLength(res->label, length);

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
        res->translation = "\t" + res->label + " = !";
		res->translation += expr.label + (expr.posLabel != "" ? "[" + expr.posLabel + "]" : "") + ";\n";

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

void verifyCallsFunctions()
{
    functions_map* functionMap = stackFunctionMap.front();
	functions_map::iterator i;
	function_struct* f;
	unsigned int line;

	for(i = functionMap->begin(); i != functionMap->end(); i++)
	{
		f = &i->second;

		if((f->called == true) && (f->defined == false))
		{
			line = yylineno;
			yylineno = f->last_call_line;
			yyerror("undefined reference to '" + f->idFunction + "'");
			yylineno = line;

			f->called = false; //apenas para não exibir o mesmo erro novamente
		}
	}     
}

void declare(string label, string dIType, unsigned int length)
{
        string finalType = dIType;
		declarations_map* declarationsMap;

		if(inFunctionArgs == false)
        {
		     declarationsMap = stackDeclarationsMap.front();
		}
		else
		{
			/*mapa global*/
		     declarationsMap = stackDeclarationsMap.back();
		}

        (*declarationsMap)[label] = {dIType, length};
}


void addMalloc(string translationMalloc)
{    
	mallocs_vector* mallocsVector = stackMallocsMap.front();
	mallocsVector->insert(mallocsVector->begin(), translationMalloc);
}

string getMallocs()
{
        string mallocs = "";

		mallocs_vector* mallocsVector = stackMallocsMap.front();

        for(int i = 0; i < mallocsVector->size(); i++)
        {                        
			mallocs += mallocsVector->at(i);
        }

        return mallocs;
}


string normalizedType(string type)
{
       if (type == "string")
       		return "char";
	
		return type;
}


string getDeclarations()
{
        string _declarations = "";

        declarations_map declarationsMap = *stackDeclarationsMap.front();
        declarations_map::iterator i;
		string type;
        
        for(i = declarationsMap.begin(); i != declarationsMap.end(); i++)
        {                        
			type = i->second.dIType;

			if(type == "string")
				type = "char";

			if (i->second.length == 0)
				type = type + "*";								

	            _declarations += "\t" + type + " " + i->first;

	            if ((i->second.dIType != "string") && (i->second.length > 1))
	                    _declarations += "[" + intToString(i->second.length) + "]";
				else if ((i->second.dIType == "string") && (i->second.length > 0))
	                    _declarations += "[" + intToString(i->second.length) + "]";

			_declarations += ";\n";
        }

        return _declarations;
}


string getFunctionArgs()
{
	string args = "";

        declarations_map declarationsMap = *stackDeclarationsMap.front();
        declarations_map::iterator i;
		string type;
        
        for(i = declarationsMap.begin(); i != declarationsMap.end(); i++)
        {                        
			type = i->second.dIType;
			if(type == "string")
				type = "char";

			if (i->second.length == 0)
				type = type + "*";								

	            args += type + " " + i->first;

	            if ((i->second.dIType != "string") && (i->second.length > 1))
	                    args += "[" + intToString(i->second.length) + "]";
				else if (i->second.dIType == "string")
	                    args += "[" + intToString(i->second.length) + "]";

			if(next(i , 1) != declarationsMap.end())
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

	return 1;
}

bool setDeclarationLength(string label, unsigned int newLength)
{
		declarations_map* declarationsMap;
		declarations_map::iterator i;
		list<declarations_map*>::iterator istack;
		unsigned int line;

		for(istack = stackDeclarationsMap.begin(); istack != stackDeclarationsMap.end(); istack++)
		{
			   	declarationsMap = *istack;
                if((i = declarationsMap->find(label)) != declarationsMap->end())
                {
					i->second.length = newLength;
					return true;
				}
		};

		return false;
}


void findAndReplace(string* source, const string find, const string replace)
{
    for(std::string::size_type i = 0; (i = source->find(find, i)) != std::string::npos;)
    {
        source->replace(i, find.length(), replace);
        i += replace.length() - find.length() + 1;
    }
}

string findAndReplaceR(string source, const string find, const string replace)
{
	string* res = new string();
	*res = source;

    for(std::string::size_type i = 0; (i = res->find(find, i)) != std::string::npos;)
    {
        res->replace(i, find.length(), replace);
        i += replace.length() - find.length() + 1;
    }

	return *res;
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

