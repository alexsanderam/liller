%{
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

%}

%token TK_INT TK_FLOAT TK_SCIENTIFIC TK_CHAR TK_STRING TK_BOOL
%token TK_MAIN
%token TK_ID
%token TK_TYPE_CHAR TK_TYPE_STRING TK_TYPE_INT TK_TYPE_VOID TK_TYPE_FLOAT TK_TYPE_DOUBLE TK_TYPE_BOOL
%token TK_MODIFIER_UNSIGNED TK_MODIFIER_SIGNED TK_MODIFIER_SHORT TK_MODIFIER_LONG
%token TK_END TK_ERROR
%token TK_OP_SUM TK_OP_SUB TK_OP_MUL TK_OP_DIV TK_OP_MOD
%token TK_OP_REL_LESS TK_OP_REL_GREATER TK_OP_REL_EQLESS TK_OP_REL_EQGREATER TK_OP_REL_EQ TK_OP_REL_DIFF
%token TK_OP_LOGIC_AND TK_OP_LOGIC_OR TK_OP_LOGIC_NOT
%token TK_OP_BIN_AND TK_OP_BIN_OR TK_OP_BIN_XOR TK_OP_BIN_NOT TK_OP_BIN_SHIFTR TK_OP_BIN_SHIFTL
%token TK_ASSIGN
%token TK_RETURN
%token TK_COUT TK_COUTN
%token TK_CIN
%token TK_IF TK_ELSE
%token TK_SWITCH TK_CASE TK_DEFAULT
%token TK_FOR TK_EACH TK_WHILE TK_DO
%token TK_BREAK TK_CONTINUE
%token TK_GOTO
%token TK_OP_INCREASE TK_OP_LESS_LESS 
%token TK_OP_ASSIGN
%token TK_DOT_DOT
%token TK_GO_LABEL


%start BEGIN

%nonassoc TK_ASSIGN
%nonassoc TK_OP_ASSIGN
%left TK_OP_INCREASE TK_OP_LESS_LESS 
%left TK_OP_LOGIC_OR TK_OP_LOGIC_AND
%left TK_OP_REL_EQ TK_OP_REL_DIFF
%left TK_OP_REL_LESS TK_OP_REL_GREATER TK_OP_REL_EQLESS TK_OP_REL_EQGREATER
%left TK_OP_BIN_AND TK_OP_BIN_OR TK_OP_BIN_XOR TK_OP_BIN_SHIFTR TK_OP_BIN_SHIFTL
%left TK_OP_SUM
%left TK_OP_SUB
%left TK_OP_MUL 
%left TK_OP_DIV
%left TK_OP_MOD
%left TK_OP_LOGIC_NOT
%left TK_OP_BIN_NOT
%nonassoc IFX
%nonassoc TK_ELSE
%%


BEGIN                   : START TRANSLATION_UNIT
                        {
							verifyLabels(); /*verifica se há erros relacionados à rótulos*/
							verifyMain(); /*verifica se há inconsistência com relação a main*/
							/*verifica se alguma função que foi chamada não foi definida*/
							verifyCallsFunctions();

							if(error)
								exit(1);

							string globalDeclarations = getDeclarations();

							$$.translation = "/*Compiler prescot-liller*/\n\n";
							$$.translation += "#include <stdio.h>\n#include <iostream>\n#include<string.h>\n#include<stdio.h>\n#include<stdlib.h>\n";
							$$.translation += "using namespace std;\n\n";


							$$.translation += "/*-----Cabeçalhos de funções-------*/\n";
							$$.translation += headersFunctions;
							$$.translation += "/*-------------------------------*/\n\n";

							$$.translation += "/*--------Variáveis globais--------*/\n";
							$$.translation += globalDeclarations;
							$$.translation += "/*-------------------------------*/\n\n";

							
							/*Tradução da main*/
							$$.translation += headMainTranslation;
							$$.translation += "\t/*Atribuição de variáveis globais*/\n";
							$$.translation += globalDeclarationsTranslation;
							$$.translation += "\t/*-------------------------------*/\n\n";
							$$.translation += findAndReplaceR(scopeMainTranslation, "return", freeMainTranslation + "\n\treturn");
							//$$.translation += freeMainTranslation;
							//$$.translation += returnMainTranslation;
							$$.translation += "\n}\n\n";

							$$.translation += $2.translation;

							cout <<  $$.translation << endl;

							//Fecha o escopo global
							closeCurrentScope();
                        }
                        ;



START                   : 
                        {
                                openNewScope();        
                        }
                        ;


MAIN_HEADER             : TK_TYPE_INT TK_MAIN OPEN_ARGS TK_TYPE_VOID CLOSE_ARGS
                        {
							$$.translation = "";
							$$.idFunction = $2.translation + " (void)";

							/*functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                            (*functionMap)[$$.idFunction].idFunction = $$.idFunction;
                            (*functionMap)[$$.idFunction].label = "main";
                            (*functionMap)[$$.idFunction].typeOfReturn = $1.type;
                            (*functionMap)[$$.idFunction].modifierOfReturn = "";
                            (*functionMap)[$$.idFunction].declared = true;
                            (*functionMap)[$$.idFunction].defined = false;
                            (*functionMap)[$$.idFunction].called = false;
							(*functionMap)[$$.idFunction].freeTranslation = freeMainTranslation;*/

                            headMainTranslation = $1.translation + " " + $2.translation + '(' + $4.translation + ')' + "\n";

							idOfCurrentFunction.push_front($$.idFunction);

							/*controle da função main
							verifica se há main, e quantos*/
							countMain++;
							verifyMain();
                        }
                        | TK_TYPE_INT TK_MAIN OPEN_ARGS CLOSE_ARGS
                        {
							$$.translation = "";
							$$.idFunction = $2.translation + " (void)";

							/*functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                            (*functionMap)[$$.idFunction].idFunction = $$.idFunction;
                            (*functionMap)[$$.idFunction].label = "main";
                            (*functionMap)[$$.idFunction].typeOfReturn = $1.type;
                            (*functionMap)[$$.idFunction].modifierOfReturn = "";
                            (*functionMap)[$$.idFunction].declared = true;
                            (*functionMap)[$$.idFunction].defined = false;
                            (*functionMap)[$$.idFunction].called = false;
							(*functionMap)[$$.idFunction].freeTranslation = freeMainTranslation;*/

                            headMainTranslation = $1.translation + " " + $2.translation + '(' + ')' + "\n";

							idOfCurrentFunction.push_front($$.idFunction);

							/*controle da função main
							verifica se há main, e quantos*/
							countMain++;
							verifyMain();
                        }
                        ;
                        

TRANSLATION_UNIT		: EXTERNAL_DECLARATION
						| TRANSLATION_UNIT EXTERNAL_DECLARATION
						{
							$$.translation = $1.translation + $2.translation;
						}
						;


EXTERNAL_DECLARATION	: DECLARATION ';'
						{
							globalDeclarationsTranslation += $1.translation;
							$$.translation = "";
						}
						| FUNCTION
						| FUNCTION_HEADER ';'
						{								
							$$.translation = "";
							headersFunctions += $1.translation;
							headersFunctions += "(" + $1.normalizedArgs + ");\n";

							/*desempilha o mapa que armazena
							os argumentos da função*/
							closeCurrentScope();

							/*desempilha o identificador da função corrente*/
							idOfCurrentFunction.pop_front();
						}
						;


FUNCTION				: FUNCTION_HEADER SCOPE
						{
							functions_map* functionMap;
							functions_map::iterator i;
							function_struct* f;
							int line;
							string arguments = "";
							string mallocArguments = "";

							if(($1.hasIdInArgs == false) && ($1.type != "void"))
							{
								line = yylineno;
								yylineno = $1.line;							
								yyerror("parameter name omitted");
								yylineno = line;
							}

							if($1.hasIdSizeInVectArgs == false)
							{
								line = yylineno;
								yylineno = $1.line;							
								yyerror("size not defined in vect args of fuction '" + $1.idFunction + "'");
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
							i = functionMap->find($1.idFunction);
							f = &i->second;

							$$.translation = $1.translation;
							$$.translation += "(" + arguments + ")";
							$$.translation += "\n{\n" + declarations + mallocArguments + mallocTranslations + "\n";
							$$.translation += $2.translation;
							//$$.translation += f->freeTranslation;
							//$$.translation += f->returnTranslation;
							$$.translation += "\n}\n\n";

							declarations = "";
							mallocTranslations = "";
							freeArgsTranslation = "";


							/*muda o estado da função para definida*/
							if((*functionMap)[$1.idFunction].defined == false)
                				(*functionMap)[$1.idFunction].defined = true;
							else
							{
								line = yylineno;
								yylineno = $1.line;
								yyerror("'" + $$.idFunction + "' previously defined here");
								yylineno = line;
							}

							/*verifica se a função tem retorno quando essa necessita*/
							if(((*functionMap)[$1.idFunction].typeOfReturn != "void") && ((*functionMap)[$1.idFunction].hasReturn == false))
								yywarning("control reaches end of non-void function: '" + $1.idFunction + "' [-Wreturn-type]");
						}
						| MAIN_HEADER SCOPE
						{
							functions_map* functionMap;
							functions_map::iterator i;
							function_struct* f;

							headMainTranslation += "{\n" + declarations + "\n";
							scopeMainTranslation = mallocTranslations + $2.translation;

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
						;


                        
                        
FUNCTION_HEADER			: TYPE TK_ID OPEN_ARGS ARGS CLOSE_ARGS
						{
							string id;
							string type;
							$$.idFunction = $2.label + "(" + $4.typesArgsFunction + ")";
							idOfCurrentFunction.push_front($$.idFunction);

							functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                                                        
                            if(isDeclaredFunctionInCurrentScope($$.idFunction) == false)
							{
									id = generateID();
                                    (*functionMap)[$$.idFunction].idFunction = $$.idFunction;
                                    (*functionMap)[$$.idFunction].label = id;
                                    (*functionMap)[$$.idFunction].typeOfReturn = $1.type;
                                    (*functionMap)[$$.idFunction].modifierOfReturn = $1.modifier;
                                    (*functionMap)[$$.idFunction].declared = true;
                                    (*functionMap)[$$.idFunction].defined = false;
                                    (*functionMap)[$$.idFunction].called = false;
									(*functionMap)[$$.idFunction].freeTranslation = freeArgsTranslation;
							}
							else
									id = (*functionMap)[$$.idFunction].label;

							if($1.type == "string")
								type = "char*";
							else
								type = $1.type;

							$$.label = id;
							$$.typesArgsFunction = $4.typesArgsFunction;
							$$.translation = type + " " + id;
							$$.hasIdInArgs = $4.hasIdInArgs;
							$$.hasIdSizeInVectArgs = $4.hasIdSizeInVectArgs;
							$$.line = yylineno;
							$$.normalizedArgs = $4.normalizedArgs;
						}
						| TK_ID OPEN_ARGS ARGS CLOSE_ARGS
						{
							string id;
							$$.idFunction = $1.label + "(" + $3.typesArgsFunction + ")";
							idOfCurrentFunction.push_front($$.idFunction);

							functions_map* functionMap = *next(stackFunctionMap.begin(), 1);
                                                        
                            if(!isDeclaredFunctionInCurrentScope($$.idFunction))
							{
									id = generateID();
                                    (*functionMap)[$$.idFunction].idFunction = $$.idFunction;
                                    (*functionMap)[$$.idFunction].label = id;
                                    (*functionMap)[$$.idFunction].typeOfReturn = "void";
                                    (*functionMap)[$$.idFunction].modifierOfReturn = "";
                                    (*functionMap)[$$.idFunction].declared = true;
                                    (*functionMap)[$$.idFunction].defined = false;
                                    (*functionMap)[$$.idFunction].called = false;
									(*functionMap)[$$.idFunction].freeTranslation = freeArgsTranslation;
							}
							else
									id = (*functionMap)[$$.idFunction].label;

							$$.label = id;
							$$.typesArgsFunction = $3.typesArgsFunction;
		                    $$.translation = "void " + id;
							$$.hasIdInArgs = $3.hasIdInArgs;
							$$.hasIdSizeInVectArgs = $3.hasIdSizeInVectArgs;
							$$.line = yylineno;
							$$.normalizedArgs = $3.normalizedArgs;
						}
						;

						

OPEN_ARGS				: '('
						{
							/*cria uma nova entrada na pilha
							para armazenar os argumentos da função*/
							openNewScope();
							inFunctionArgs = true;
						}
						;


CLOSE_ARGS				: ')'
						{
							inFunctionArgs = false;
						}
						;


						
ARGS					: ARGS ',' TYPE OPTIONAL_ID
						{
								unsigned int size = 1;
								string pointer = "";

								if($4.label != "")							   	
								{
									identifiers_map* IDMap = stackIDMap.front();

		                            (*IDMap)[$4.label].label = generateID();
		                            (*IDMap)[$4.label].type = $3.type;
		                            (*IDMap)[$4.label].modifier = $3.modifier;

									$$.label = (*IDMap)[$4.label].label;
									$$.type = (*IDMap)[$4.label].type;
									$$.modifier = (*IDMap)[$4.label].modifier;

									if($4.vectSizes.size() > 0)
									{
										for(int i = 0; i < $4.vectSizes.size(); i++)
											size *= $4.vectSizes.at(i);
									}

									if($4.isConstant == false)
									{
										//addMalloc(dinamicallyVectDeclaration($$, $4, 1));
										size = 0; /*será declarado como ponteiro*/
									}

									/*chuta-se um tamanho para argumentos do tipo string*/
									if(($3.type == "string") && (size > 0))
											size *= 100;
									else if($3.type == "string")
											size = 1000;



									$$.translation = $1.translation + ", " + $$.type + " " + $$.label + $4.translation;
									$$.typesArgsFunction = $1.typesArgsFunction + ", " + $$.type + $4.translation;
									$$.hasIdInArgs = $1.hasIdInArgs &&  true;
									$$.hasIdSizeInVectArgs = $1.hasIdSizeInVectArgs && $4.hasIdSizeInVectArgs;

									inFunctionArgs = false;
		                            if ($$.modifier != "")
		                                    declare($$.label, $$.modifier + " " + $$.type, size);
		                            else
		                                    declare($$.label, $$.type, size);
									inFunctionArgs = true;
								}
								else
								{
									$$.translation = $$.type + $4.translation + ", " + $1.translation;
									$$.typesArgsFunction = $$.type + $4.translation + ", " + $1.typesArgsFunction;
									$$.hasIdInArgs = false;
									$$.line = yylineno;
								}	 

								if((size == 0) || ($3.type == "string"))
									pointer = "*";

								$$.normalizedArgs = $1.normalizedArgs + ", " + $$.modifier + ($$.modifier != "" ? " " : "") + normalizedType($$.type) + pointer + + " " + $4.label + $4.translation;

						}
						| TYPE OPTIONAL_ID
						{
							unsigned int size = 1;
							string pointer = "";

							if($2.label != "")
							{
								identifiers_map* IDMap = stackIDMap.front();

		                        (*IDMap)[$2.label].label = generateID();
		                        (*IDMap)[$2.label].type = $1.type;
		                        (*IDMap)[$2.label].modifier = $1.modifier;

								$$.label = (*IDMap)[$2.label].label;
								$$.type = (*IDMap)[$2.label].type;
								$$.modifier = (*IDMap)[$2.label].modifier;

								if($2.vectSizes.size() > 0)
								{
									for(int i = 0; i < $2.vectSizes.size(); i++)
										size *= $2.vectSizes.at(i);
								}

								if($2.isConstant == false)
								{
									//addMalloc(dinamicallyVectDeclaration($$, $2, 1));
									size = 0; /*será declarado como ponteiro*/
								}

								/*chuta-se um tamanho para argumentos do tipo string*/
								if(($1.type == "string") && (size > 0))
										size *= 100;
								else if($1.type == "string")
										size = 1000;


								$$.translation = $$.type + " " + $$.label + $2.translation;
								$$.typesArgsFunction = $1.type + $2.translation;
								$$.hasIdInArgs = ($2.label != "");
								$$.hasIdSizeInVectArgs = $2.hasIdSizeInVectArgs || ($1.type == "void");

								inFunctionArgs = false;
		                        if ($$.modifier != "")
		                                declare($$.label, $$.modifier + " " + $$.type, size);
		                        else
		                                declare($$.label, $$.type, size);
								inFunctionArgs = true;
							}
							else
							{
									$$.translation = $$.type + $2.translation;
									$$.typesArgsFunction = $$.translation + $2.translation;
									$$.hasIdInArgs = false;
									$$.line = yylineno;
							}

							if((size == 0) || ($1.type == "string"))
								pointer = "*";

							$$.normalizedArgs = $$.modifier + ($$.modifier != "" ? " " : "") + normalizedType($$.type) + pointer + " " + $2.label + $2.translation;

						}
						|
						{
							$$.translation = "";
							$$.typesArgsFunction = "void";
							$$.hasIdInArgs = true;
							$$.hasIdSizeInVectArgs = true;
							$$.line = yylineno;

							$$.normalizedArgs = "";
						}
						;



OPTIONAL_ID				: TK_ID VECTOR_SIZES
						{
							$$.vectSizes = $2.vectSizes;
							$$.vectPositions = $2.vectPositions;
							$$.isConstant = $2.isConstant;
							$$.hasIdSizeInVectArgs = $2.hasIdSizeInVectArgs;

							//if($2.isConstant == false)
								//yyerror("not allowed not constant in size args of function");

							$$.translation = $2.translation;
						}
						| VECTOR_SIZES
						{
							$$.label = "";

							$$.vectSizes = $1.vectSizes;
							$$.vectPositions = $1.vectPositions;
							$$.isConstant = $1.isConstant;
							$$.hasIdSizeInVectArgs = $1.hasIdSizeInVectArgs;

							//if($1.isConstant == false)
								//yyerror("not allowed not constant in size args of function");

							$$.translation = $1.translation;
						}
						;


OPTIONAL_PARAMETERS		: PARAMETERS
						|
						{
							$$.typesArgsFunction = "void";
							$$.label = "";
							$$.translation = "";
						}
						;

PARAMETERS				: PARAMETERS ',' E
						{
							$$.translation = $1.translation + $3.translation;
							$$.label = $1.label + ", " + $3.label;
							$$.typesArgsFunction = $1.typesArgsFunction + ", " + $3.type;

						}
						| E
						{
							$$.typesArgsFunction = $1.type;
							$$.label = $1.label;
							$$.translation = $1.translation;
						}
						; 


CALL_FUNCTION			: COUT
						| CIN
						| TK_ID '(' OPTIONAL_PARAMETERS ')'
						{
							function_struct* f;
							YYSTYPE* ass;
							string idFunction;
						
							idFunction = $1.label + '(' + $3.typesArgsFunction + ')';

							f = findFunction(idFunction);

							if(f != NULL)
							{
								$$.type = f->typeOfReturn;
								$$.modifier = f->modifierOfReturn;

								$$.translation = "\t/*----chamada de função----*/\n";
								$$.translation += $3.translation;

								if($$.type != "void")
								{
									$$.label = generateID();

									ass = new YYSTYPE();
									ass->label = $$.label;
									ass->type = $$.type;
									ass->modifier = $$.modifier;
									declare(ass->label, ass->modifier + (ass->modifier == "" ? "" : " ") + ass->type, (f->typeOfReturn == "string" ? 0 : 1));

									$$.translation += "\t" + ass->label + " = " + f->label + "(" +  $3.label + ");\n";
								}
								else
								{
									$$.label = f->label;
									$$.translation += "\t" + f->label + "(" +  $3.label + ");\n";
								}

								$$.translation += "\t/*-------------------------*/\n";

								f->called = true;
								f->last_call_line = yylineno;
							}
							else
							{
								yyerror("implicit declaration of function ‘" + idFunction + "’");
							}
						}
						;
		                        
                        
COUT                    : TK_COUT '(' E_C ')'
                        {
                                $$.translation = $3.translation + "\n\tcout << ";
								$$.translation += $3.label + ($3.vectPositions.size() > 0 ? "[" + $3.posLabel + "]" : "") + ";\n";
                        }
                        | TK_COUTN '(' E_C ')'
                        {
								$$.translation = $3.translation + "\n\tcout << ";
								$$.translation += $3.label + ($3.vectPositions.size() > 0 ? "[" + $3.posLabel + "]" : "") + " << endl;\n";
                        }
						| TK_COUTN '(' ')'
						{
								$$.translation = "\n\tcout << endl;";
						}
                        ;


CIN                    : TK_CIN '(' E_C ')'
                        {
                                $$.translation = $3.translation;
								$$.translation += "\n\tcin >> " + $3.label + ($3.vectPositions.size() > 0 ? "[" + $3.posLabel + "]" : "") + ";\n";

								//redeclara, atualizando o tamanho da string*/
								if(($3.type == "string") && (getDeclarationLength($3) < 1000))
									declare($3.label, $3.modifier + ($3.modifier != "" ? " " : "") + $3.type, 1000);
                        }
                        ;



SCOPE                   : BEGIN_SCOPE COMMANDS END_SCOPE
                        {
                                $$.translation =  $1.translation + $2.translation + $3.translation;
                        }
                        ;




BEGIN_SCOPE             : '{'
                        {
                                openNewScope();                        
                                $$.translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
								flagDeclarationNotAllowedAux = flagDeclarationNotAllowed;
                                flagDeclarationNotAllowed = false;
                        }	
                        ;
                        
        

END_SCOPE                : '}'
                        {
                                declarations += getDeclarations();
								mallocTranslations += getMallocs();
                                closeCurrentScope(); /*desempilha*/                                
                                $$.translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
                                flagDeclarationNotAllowed = flagDeclarationNotAllowedAux;

                        }
                        ;



COMMANDS        		: STATEMENT COMMANDS
                        {
                                $$.translation = $1.translation + "\n" + $2.translation;
                        }
                        | 
                        {
                                $$.translation = "";
                        }
                        ;



STATEMENT               : E_C ';'
                        | RETURN ';'
                        | DECLARATION ';'
                        {
                                /*controle de declarações, quando tais não são permititdas (exemplo: if, for, ...)*/
                                if(flagDeclarationNotAllowed)
                                {
                                        yyerror("declarations not allowed.");
                                        flagDeclarationNotAllowed = false;
                                }
                        }
                        | SCOPE
                        | IF
                        | WHILE
                        | DO_WHILE
                        | FOR
						| LABEL STATEMENT
						{
							$$.translation = $1.translation + $2.translation;
							$$.label = $2.label;
							$$.type = $2.type;
							$$.modifier = $2.modifier;
						}
						| GOTO ';'
						| CONTINUE ';'
						| BREAK ';'
						| SWITCH
                        | ';'
                        {
                                $$.translation = "";
                        }
                        ;



RETURN                  : TK_RETURN E_C 
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

									if(f->typeOfReturn != $2.type)
									{
										func.type = f->typeOfReturn;										
										func.modifier = f->modifierOfReturn;	

										cast = runCast($2, func);

										if(cast == NULL)
							            	yyerror("cast from " + $2.type + " to " + func.modifier + " " + func.type + " not allowed");

										else if(f->typeOfReturn == "string")
										{
											idReturn.label = generateID();
											idReturn.translation = "";
											idReturn.type = cast->type;
											idReturn.modifier = cast->modifier;

											//declara a variável globalmente e realiza o malloc
											declarations_map* declarationsMap = stackDeclarationsMap.back();
											(*declarationsMap)[idReturn.label] = {$2.type, 0};
											addMalloc(dinamicallyVectDeclaration(idReturn, $2, 2));
											
											$$.translation = $2.translation + cast->translation;
											$$.translation += "\t" + idReturn.label + " = (char*) realloc(" + idReturn.label + ", " + intToString(getDeclarationLength(*cast)) + ");\n";
											$$.translation += "\tstrcpy(" + idReturn.label + ", " + cast->label + ");\n";
											f->returnTranslation = "\n\t" + $1.translation + " " + idReturn.label + ";";
											$$.translation += f->returnTranslation;

											freeMainTranslation += "if (" + idReturn.label + " != NULL)\n\t\tfree(" + idReturn.label + ");\n";
										}
										else
										{
											$$.translation = $2.translation + cast->translation + "\n\t";
											f->returnTranslation = $1.translation + " " + cast->label + ";";
											$$.translation += f->freeTranslation;
											$$.translation += f->returnTranslation;
										}
									}
									else if(f->typeOfReturn == "string")
									{
										idReturn.label = generateID();
										idReturn.translation = "";
										idReturn.type = $2.type;
										idReturn.modifier = $2.modifier;

										//declara a variável globalmente e realiza o malloc
										declarations_map* declarationsMap = stackDeclarationsMap.back();
										(*declarationsMap)[idReturn.label] = {idReturn.type, 0};
										addMalloc(dinamicallyVectDeclaration(idReturn, $2, 2));

										$$.translation = $2.translation + "\n";
										$$.translation += "\t" + idReturn.label + " = (char*) realloc(" + idReturn.label + ", " + intToString(getDeclarationLength($2)) + ");\n";
										$$.translation += "\tstrcpy(" + idReturn.label + ", " + $2.label + ");\n";
										f->returnTranslation = "\t" + $1.translation + " " + idReturn.label + ";";
										$$.translation += f->returnTranslation;

										freeMainTranslation += "if (" + idReturn.label + " != NULL)\n\t\tfree(" + idReturn.label + ");\n";
									}
									else
									{
										$$.translation = $2.translation + "\n";
	                                	f->returnTranslation = "\t" + $1.translation + " " + $2.label+ ";";
										$$.translation += f->returnTranslation;
									}

								}
								else if(idFunction == idMainFunction)
								{
	                                returnMainTranslation = $2.translation + "\n\t" + $1.translation + " " + $2.label + ";";
									$$.translation = returnMainTranslation;
								}
								else
									$$.translation = $2.translation + "\n\t" + $1.translation + " " + $2.label + ";";
                        }
                        ;


                        


IF_C					: TK_IF
						{
							/*controle de declaraçãoes*/
							flagDeclarationNotAllowed = true;
						}
						;

IF                      : IF_C '(' E_C ')' STATEMENT %prec IFX
                        {                                
                                YYSTYPE notE;
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression($3);

                                $$.translation = $3.translation; /*tradução da expressão E*/
                                $$.translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                $$.translation += "\t" + $1.translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                $$.translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                $$.translation += $5.translation + "\n"; /*tradução: STATEMENT*/
                                $$.translation += "\t" + labelEndIF + ":\n\t;\n"; /*tradução: labelEndIF:*/

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;

                        }
                        | IF_C '(' E_C ')' STATEMENT TK_ELSE STATEMENT
                        {
                                YYSTYPE notE;
                                string labelEndCmd1 = generateLabel();
                                string labelEndIF = generateLabel();
        
                                notE = assignNotExpression($3);

                                $$.translation = $3.translation; /*tradução da expressão E*/
                                $$.translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                $$.translation += "\t" + $1.translation + "("        + notE.label + ")\n"; /*tradução: if (!E)*/
                                $$.translation += "\t\tgoto " + labelEndCmd1 + ";\n\n"; /*tradução: goto labelCmd1*/
                                $$.translation += $5.translation + "\n"; /*tradução: STATEMENT*/
                                $$.translation += "\t\tgoto " + labelEndIF + ";\n\n"; /*tradução: goto labelEndIf*/
                                $$.translation += "\t" + labelEndCmd1 + ":\n"; /*tradução: labelEndCmd1:*/
                                $$.translation += $7.translation + "\n"; /*tradução: COMMAND (2)*/
                                $$.translation += "\t" + labelEndIF + ":\n\t;\n"; /*tradução: labelEndId:*/

								/*controle de declaraçãoes*/
								flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
                        ;


WHILE_C					: TK_WHILE
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
						;


WHILE                   : WHILE_C '(' E_C ')' STATEMENT
                        {
                                YYSTYPE notE;
                                string labelBeginWhile = stackBeginLabels.front();
                                string labelEndWhile = stackEndLabels.front();
        
                                notE = assignNotExpression($3);

                                $$.translation = "\n\t" + labelBeginWhile + ":\n"; /*tradução: labelBeginWhile:*/
                                $$.translation += $3.translation; /*tradução da expressão E*/
                                $$.translation += notE.translation + "\n"; /*atribui a negação da expressão E*/
                                $$.translation += "\tif (" + notE.label + ")\n"; /*tradução: if (!E)*/
                                $$.translation += "\t\tgoto " + labelEndWhile + ";\n\n"; /*tradução: goto labelEndWhile*/
                                $$.translation += $5.translation + "\n"; /*tradução: STATEMENT*/
                                $$.translation += "\t\tgoto " + labelBeginWhile + ";\n"; /*tradução: goto labelBeginWhile*/
                                $$.translation += "\t" + labelEndWhile + ":\n\t;\n"; /*tradução: labelEndWhile:*/


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
                        ;


DO_WHILE_C		: TK_DO
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
				;


DO_WHILE                : DO_WHILE_C STATEMENT TK_WHILE '(' E_C ')' ';'
                        {
                                string labelBeginDoWhile = stackBeginLabels.front();
                                string labelEndDoWhile = stackEndLabels.front();


                                $$.translation = "\n\t" + labelBeginDoWhile + ":\n"; /*tradução: labelBeginDoWhileIF:*/
                                $$.translation += $2.translation + "\n"; /*tradução: STATEMENT*/
                                $$.translation += $5.translation; /*tradução da expressão E*/
                                $$.translation += "\tif (" + $5.label + ")\n"; /*tradução: if (E)*/
                                $$.translation += "\t\tgoto " + labelBeginDoWhile + ";\n"; /*tradução: goto labelEndIf*/
                                $$.translation += "\t" + labelEndDoWhile + ":\n\t;\n"; /*tradução: labelEndDoWhileIF:*/


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
                        ;




OPTIONAL_E              : E_C
                        |
                        ;


OPTIONAL_E_OR_DECLARATION	: OPTIONAL_E
							| DECLARATION
							;




ATTRIBUITION_OR_TERMINAL:	ATTRIBUITION
							| TERMINAL
							;



FOR_C			: TK_FOR
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
				;


FOR                 : FOR_C '(' OPTIONAL_E_OR_DECLARATION ';' OPTIONAL_E ';' OPTIONAL_E ')' STATEMENT
                    {
                            YYSTYPE notE;
                            string labelBeginFor = generateLabel();
                            string labelIncreaseFor = stackBeginLabels.front();
                            string labelEndFor = stackEndLabels.front();


                            $$.translation =  "\n" + $3.translation + "\n"; /*tradução da inicialização do For, que pode ser vazia*/
                            $$.translation += "\t" + labelBeginFor + ":\n"; /*tradução: labelBeginFor:*/
                            if ($5.translation != "") /* caso haja um teste */                                                                
                            {
                                    notE = assignNotExpression($5);
                                    $$.translation += $5.translation; /*tradução da expressão de teste E*/
                                    $$.translation += notE.translation + "\n"; /*atribui a negação da expressão de teste E*/
                                    $$.translation += "\tif (" + notE.label + ")\n"; /*tradução: if (!E)*/
                                    $$.translation += "\t\tgoto " + labelEndFor + ";\n\n"; /*tradução: goto labelEndFor*/
                            }

							$$.translation += $9.translation + "\n"; /*tradução: STATEMENT*/
                            $$.translation += "\t" + labelIncreaseFor + ":\n"; /*tradução: labelIncreaseFor:*/
                            $$.translation += $7.translation + "\n"; /*tradução do incremento, que pode ser vazia*/
                            $$.translation += "\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginFor*/
                            $$.translation += "\t" + labelEndFor + ":\n\t;"; /*tradução: labelEndFor:*/


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
                    | FOR_C '(' ATTRIBUITION_OR_TERMINAL TK_DOT_DOT TERMINAL ')' STATEMENT
                    {
                            YYSTYPE expr; /*expressão que controla a parada do for*/
						  	YYSTYPE value; /*constante 1*/
							YYSTYPE op; /*operação de incremento*/
							YYSTYPE ass; /*atribuição*/

                            string labelBeginFor = generateLabel();
                            string labelIncreaseFor = stackBeginLabels.front();
                            string labelEndFor = stackEndLabels.front();


							/*notifica caso os limitantes não sejam inteiros*/
							if(($3.type != "int") || ($5.type != "int"))
								yywarning("counter is not an integer");

							/*realiza o teste lógico (negado)*/
							expr = runBasicOperation($3, $5, ">");


							/*realiza o incremento*/
							value = generateIntValue(1);
							op = runBasicOperation($3, value, "+");
							ass.label = $3.label;
							ass.type = op.type;
							ass.modifier = op.modifier;
							ass.translation = op.translation + "\t" + ass.label + " = " + op.label + ";\n";
			

							findAndReplace(&(expr.translation), $3.translation, voidStr);
							findAndReplace(&(ass.translation), $3.translation, voidStr);


							$$.translation = $3.translation; /*tradução da atribuição*/
							$$.translation += "\n\t" + labelBeginFor + ":\n"; /*tradução: labelBeginFor:*/
							$$.translation += expr.translation; /*tradução da expressão que controla a parada do for*/
							$$.translation += "\tif (" + expr.label + ")\n"; /*tradução: if (!E1)*/
							$$.translation += "\t\tgoto " + labelEndFor + ";\n\n"; /*tradução: goto labelEndFor*/


							$$.translation += $7.translation + "\n"; /*tradução: STATEMENT*/
							                $$.translation += "\t" + labelIncreaseFor + ":\n"; /*tradução: labelIncreaseFor:*/
							$$.translation += ass.translation; /*tradução: da atualização do identicador (atribuição)*/
							$$.translation += "\t\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginFor*/
							$$.translation += "\n\t" + labelEndFor + ":\n\t;"; /*tradução: labelEndFor:*/                                


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
			;


LABEL		: TK_ID TK_GO_LABEL
			{
				label_struct* l;

				if(((l = findLabel($1.label)) != NULL) && (l->found == true))
					yyerror("duplicate label " + $1.label);
				else if(l == NULL)
				{
					$$.label = generateLabel();
					labelMap[$1.label].found = false;
					labelMap[$1.label].label = $$.label;
				}
				else
				{
					labelMap[$1.label].found = true;
					$$.label = labelMap[$1.label].label;
				}

				labelMap[$1.label].line = yylineno;

				$$.translation = "\t" + $$.label + ":\n";
			}
			| TK_CASE E_C TK_GO_LABEL
			{
				case_label_map* caseLabelMap = stackCaseLabel.front();
				string newLabel;
				string key;
			
				/*chave do mapa de cases (labels) é dado por intValue*/
				key = intToString($2.intValue);


				/*verifica-se a presença de uma não constante na expressão*/
				if($2.isConstant == false)
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

					$$.translation = $2.translation + "\t" + newLabel + ":\n";
					caseLabelMap->insert(case_label_map::value_type(key, {newLabel, $2}));
				}
			}
			| TK_DEFAULT TK_GO_LABEL
			{
				case_label_map* caseLabelMap = stackCaseLabel.front();
				string newLabel;

				/*verifica se o default está dentro de um switch*/
				if (flagWithinSwitch == false)
					yyerror("‘default’ label not within a switch statement");

				/*verifica se já existe um outro default no switch*/
				else if (caseLabelMap->find($1.translation) != caseLabelMap->end())
					yyerror("multiple default labels in one switch");

				else
				{
					newLabel = "_default";				
					
					$$.translation = "\t" + newLabel + ":\n"; 
					caseLabelMap->insert(case_label_map::value_type($1.translation, {newLabel, $1}));
				}
			}
			;




GOTO			: TK_GOTO TK_ID
			{
				label_struct* l;

				if((l = findLabel($2.label)) != NULL)
					$$.label = l->label;
                else
					$$.label = generateLabel();

				labelMap[$2.label].found = false;
				labelMap[$2.label].label = $$.label;
				labelMap[$2.label].line = yylineno;
                $$.translation = "\tgoto " + $$.label + ";\n";
			}
			;



CONTINUE		: TK_CONTINUE
			{
				if(!flagContinue)
					yyerror("continue statement not within a loop");
				else
				{			

					/*obtém o primeiro label da pilha de Begins*/
					string label = stackBeginLabels.front();
					$$.translation = "\tgoto " + label + ";\n";
				}
			}
			;


BREAK			: TK_BREAK
			{
				if(!flagBreak)
					yyerror("break statement not within loop or switch");
				else
				{	
					/*obtém o primeiro label da pilha de Begins*/
					string label = stackEndLabels.front();

					$$.translation = "\tgoto " + label + ";\n";
				}
			}
			;


SWITCH_C		: TK_SWITCH
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
			;


SWITCH		: SWITCH_C '(' E_C ')' STATEMENT
			{
				YYSTYPE ass;
				YYSTYPE op;

				string labelEndSwitch = stackEndLabels.front();

				$$.translation = $3.translation;

				case_label_map* caseLabelMap = stackCaseLabel.front();
				case_label_map::iterator i;
        
				for(i = caseLabelMap->begin(); i != caseLabelMap->end(); i++)
				{                        
					if(i->first != "default")
					{
						op = runBasicOperation($3, i->second.defCase, "==");
	  									
						$$.translation += op.translation + "\tif(" + op.label + ")\n";
						$$.translation += "\t\tgoto " + i->second.newLabel + ";\n";
					}
					else
						$$.translation += "\n\tgoto " + i->second.newLabel + ";\n";
				}

				$$.translation += $5.translation; /*tradução do statement*/
				$$.translation += "\t" + labelEndSwitch + ":\n\t;\n";


				/*desempilha o label de fim*/
				stackEndLabels.pop_front();
	
				/*desempilha o case*/
				stackCaseLabel.pop_front();

				/*controle do break*/
				flagBreak = false;

				/*controle do case e do default*/
				flagWithinSwitch = false;
			}
			;



E_C						: E
						{
							/*controle para alertar a recursão de operações relacionais*/
		                   	$$.relationalCounter = 0;

		                    /*controle da tradução do incremento/decremento*/
		                    if(flagIncreaseTranslation)
		                    {
		                            $$.translation += auxIncreaseTranslation;
		                            flagIncreaseTranslation = false;
		                            auxIncreaseTranslation = "";
		                    }

							/*if((inFunctionArgs == true) && ($1.isConstant == false))
								scopeMainTranslation = $$.translation + scopeMainTranslation;*/

						}
						;



E                       : '(' E ')'
                        {
                                $$.translation = $2.translation;
                                $$.label = $2.label;
                                $$.type = $2.type;
                                $$.modifier = $2.modifier;                
                                $$.isConstant = $2.isConstant; 
                                $$.posLabel = $2.posLabel;
								$$.intValue = $2.intValue;
                        }
						| CALL_FUNCTION
                        | TERMINAL
                        | ATTRIBUITION
                        | '(' TYPE ')' TERMINAL /*cast*/
                        {
	                        $$ = *runCast($4, $2);

							if($$.label == "")
			                	yyerror("cast from " + $4.type + " to " + $2.type + " not allowed");

							$$.translation = $4.translation + $$.translation;
                        }
                        | E TK_OP_SUM E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_SUB E
                        {
                                 $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_MUL E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_DIV E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_MOD E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_LOGIC_OR E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_LOGIC_AND E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_EQ E
                        {

                                relationalControl(&$$, $2);
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_DIFF E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
								$$.relationalCounter = $1.relationalCounter + $2.relationalCounter;
                                relationalControl(&$$, $2);
                        }
                        | E TK_OP_REL_LESS E
                        {                                
                                $$ = runBasicOperation($1, $3, $2.translation);
								$$.relationalCounter = $1.relationalCounter + $2.relationalCounter;
                                relationalControl(&$$, $2);
                        }
                        | E TK_OP_REL_GREATER E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
								$$.relationalCounter = $1.relationalCounter + $2.relationalCounter;
                                relationalControl(&$$, $2);
                        }
                        | E TK_OP_REL_EQLESS E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
								$$.relationalCounter = $1.relationalCounter + $2.relationalCounter;
                                relationalControl(&$$, $2);
                        }
                        | E TK_OP_REL_EQGREATER E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
								$$.relationalCounter = $1.relationalCounter + $2.relationalCounter;
                                relationalControl(&$$, $2);
                        }
                        | E TK_OP_BIN_AND E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_BIN_OR E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_BIN_XOR E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_BIN_SHIFTR E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_BIN_SHIFTL E
                        {
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | TK_OP_LOGIC_NOT E
                        {
                                $$.label = generateID();
                                $$.type = "int";
                                $$.modifier = "unsigned short";
								$$.posLabel = $2.posLabel;

                                $$.translation = $2.translation + "\t" + $$.label + " = " + $1.translation + " " + $2.label + ";\n";                                
                                
                                if($2.type == "int")
                                	$$.intValue = !$2.intValue;

                                declare($$.label, $$.type, 1);
                        }
                        | TK_OP_BIN_NOT E
                        {
                                 $$.label = generateID();

                                if(($2.type != "int") && ($2.type != "char"))
                                        yyerror("wrong type argument to bit-complement");

                                $$.translation = $2.translation + "\t" + $$.label + " = " + $1.translation + " " + $2.label + ";\n";

                                $$.type = $2.type;
                                $$.modifier = $2.type;
								$$.posLabel = $2.posLabel;
                                                             
                                if($2.type == "int")
                                	$$.intValue = ~$2.intValue;

                                declare($$.label, $$.type, 1);
                        }
                        | INCREASE
                        | PREV_INCREASE
                        ;




INCREASE                : TK_ID VECTOR_P TK_OP_INCREASE
                        {
                                id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;

								YYSTYPE pos;
								string posTranslation = "";

								$1.vectPositions = $2.vectPositions;
                        
                                if((id = findID($1.label)) == NULL)       
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");
                                else
                                {
										if (($2.vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + $1.label + $2.translation + "' from type '" + $1.type);
										else if (($2.vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(($2.vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, $2.vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, $2.vectPositions);
													

											$1.posLabel = pos.label;
											posTranslation = pos.translation;
										}


                                        $1.translation = "";
                                        $1.type = id->type;
                                        $1.modifier = id->modifier;

                                        $$.translation = posTranslation;
                                        $$.label = id->label;
                                        $$.type = $1.type;
                                        $$.modifier = $1.modifier;
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = $1;
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ($3.translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, $1, op);

                                        auxIncreaseTranslation = posTranslation + ass.translation;
                                        flagIncreaseTranslation = true;
                                }
                        }
                        ;



PREV_INCREASE                : TK_OP_INCREASE TK_ID VECTOR_P
                        {
                                id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;

								YYSTYPE pos;
								string posTranslation = "";

								$2.vectPositions = $3.vectPositions;

                        
                                if((id = findID($2.label)) == NULL)       
                                        yyerror("identifier: '" + $2.label + "'  was not declared in this scope.");
                                else
                                {
                                        $2.translation = "";
                                        $2.type = id->type;
                                        $2.modifier = id->modifier;

										if (($3.vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + $1.label + $2.translation + "' from type '" + $1.type);
										else if (($3.vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(($3.vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, $3.vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, $3.vectPositions);

											$2.posLabel = pos.label;
											posTranslation = pos.translation;
										}
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = $2;
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ($1.translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, $2, op);
                                        
                                        $$.translation = posTranslation + ass.translation;
                                        $$.label = ass.label;
                                        $$.type = ass.type;
                                        $$.modifier = ass.modifier;
                                }
                        }
                        ;




ATTRIBUITION       	: TK_ID VECTOR_P TK_ASSIGN E
                        {
								YYSTYPE pos;
								id_struct* id;

                                if((id = findID($1.label)) == NULL)
                                        yyerror("identifier: '" + $1.label + "' was not declared in this scope.");
                                else
								{
										if (($2.vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + $1.label + $2.translation + "' from type '" + $4.type);
										else if (($2.vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(($2.vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, $2.vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, $2.vectPositions);

											$1.posLabel = pos.label;
		                                    $$ = assign(voidStr, $1, $4);
											$$.translation = pos.translation + $$.translation;
										}
								}
                        }
                        | OP_ASSIGN
                        ;      


OP_ASSIGN                : TK_ID VECTOR_P TK_OP_ASSIGN E
                        {
								YYSTYPE pos;
                                string operation;
                                id_struct* id;

                                YYSTYPE ass;
                                YYSTYPE op_id;
                                YYSTYPE op;

                                if((id = findID($1.label)) == NULL)       
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");
                                else
                                {
                                        
                                        $1.translation = "";
                                        $1.type = id->type;
                                        $1.modifier = id->modifier;

										/*verifica qual operação deve ser realizada*/
										if ($3.translation == "+=")
											operation = "+";
										else if ($3.translation == "-=")
											operation = "-";
										else if ($3.translation == "*=")
											operation = "*";
										else if ($3.translation == "/=")
											operation = "/";
										else if ($3.translation == "%=")
											operation = "%";
										else if ($3.translation == "<<=")
											operation = "<<";
										else if ($3.translation == ">>=")
											operation = ">>";
										else if ($3.translation == "&=")
											operation = "&";
										else if ($3.translation == "|=")
											operation = "|";
										else if ($3.translation == "^=")
											operation = "^";

                                        /*Realiza as operações referentes a operação*/
                                        op_id = $1;
                                        op_id.label = id->label;


										if (($2.vectPositions.size() == 0) && (id->vectSizes.size() > 0))
											yyerror("incompatible types when assigning to '" + $1.label + "[" + $2.translation + "]' from type '" + $4.type);
										else if (($2.vectPositions.size() > 0) && (id->vectSizes.size() == 0))
											yyerror("subscripted value is neither array nor pointer nor vector");
										else
										{
											if(($2.vectPositions.size() > 0) && (id->vectSizes.size() > 0))
												if(id->hasSizes == true)
													pos = computingPosition(id->vectSizes, $2.vectPositions);
												else
													pos = computingPositionFromIds(id->vectSizesFromIds, $2.vectPositions);

											$1.posLabel = pos.label;
											$1.vectPositions = $2.vectPositions;
											op_id.posLabel = $1.posLabel;
											op_id.vectPositions = $1.vectPositions;

		                                    op = runBasicOperation(op_id, $4, operation);
		                                    ass = assign(voidStr, $1, op);

		                                    $$.translation = pos.translation + ass.translation;
		                                    $$.label = ass.label;
		                                    $$.type = ass.type;
		                                    $$.modifier = ass.modifier;
										}											
                                }                                                                
                                
                        }
                        ;



DECLARATION        		: DECLARATION ',' TK_ID VECTOR_SIZES
                        {
								int size = 1;
								string pointer = "";

                                identifiers_map* IDMap = stackIDMap.front();
                                                        
                                if(!isDeclaredCurrentScope($3.label))
                                {
                                        (*IDMap)[$3.label].label = generateID();
                                        (*IDMap)[$3.label].type = $1.type;
                                        (*IDMap)[$3.label].modifier = $1.modifier;
                                        (*IDMap)[$3.label].vectSizes = $4.vectSizes;
                                        (*IDMap)[$3.label].vectSizesFromIds = $4.vectPositions;
										(*IDMap)[$3.label].hasSizes = $4.isConstant;
                                }
                                else
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");

                                
                                $$.label = (*IDMap)[$3.label].label;
                                $$.type = $1.type;//(*IDMap)[$3.label].type;
                                $$.modifier = $1.modifier;//(*IDMap)[$3.label].modifier;
                                $$.translation = $1.translation;

								//Calcula o tamanho do vetor, se for uma variável simples, o tamanho será 1
								//if(($4.vectSizes.size() > 0) && ($4.vectPositions.size() > 0))
								if($4.isConstant == false)
								{
									pointer = "*";
									addMalloc(dinamicallyVectDeclaration($$, $4, 2));
								}
								else if($4.vectSizes.size() > 0)
								{
									for(int i = 0; i < $4.vectSizes.size(); i++)
										size *= $4.vectSizes.at(i);
								}

	                            if ($$.modifier != "")
	                                    declare($$.label, $$.modifier + " " + $$.type + pointer, size);
	                            else
	                                    declare($$.label, $$.type + pointer, size);


                        }
                        | DECLARATION ',' TK_ID TK_ASSIGN E
                        {
                                string ATTRIBUITION = "";
								unsigned int length;
                                
                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($3.label))
                                {
                                        (*IDMap)[$3.label].label = generateID();
                                        (*IDMap)[$3.label].type = $1.type;
                                        (*IDMap)[$3.label].modifier = $1.modifier;
                                        (&(*IDMap)[$3.label].vectSizes)->clear();
                                        (&(*IDMap)[$3.label].vectSizesFromIds)->clear();
										(*IDMap)[$3.label].hasSizes = true;
                                }
                                else
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");
                  
                                $$ = assign($1.translation, $3,$5);
								length = getDeclarationLength($$);

                                if ($$.modifier != "")
                                        declare($$.label, $$.modifier + " " + $$.type, length);
                                else
                                        declare($$.label, $$.type, length);
                                                        
                        }
                        | TYPE TK_ID VECTOR_SIZES
                        {
								int size = 1;
								string pointer = "";
                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($2.label))
                                {
                                        (*IDMap)[$2.label].label = generateID();
                                        (*IDMap)[$2.label].type = $1.type;
                                        (*IDMap)[$2.label].modifier = $1.modifier;
		
										if($3.vectSizes.size() > 0)
										{
		                                    (*IDMap)[$2.label].vectSizes = $3.vectSizes;
		                                    (*IDMap)[$2.label].vectSizesFromIds = $3.vectPositions;
										}
										else
										{
											(&(*IDMap)[$2.label].vectSizes)->clear();
		                                    (&(*IDMap)[$2.label].vectSizesFromIds)->clear();
										}
										(*IDMap)[$2.label].hasSizes = $3.isConstant;
                                }
                                else
                                        yyerror("identifier: '" + $2.label + "'  previously declared here.");


                                $$.label = (*IDMap)[$2.label].label;
                                $$.translation = "";
                                $$.type = (*IDMap)[$2.label].type;
                                $$.modifier = (*IDMap)[$2.label].modifier;

								//Calcula o tamanho do vetor, se for uma variável simples, o tamanho será 1
								//if(($3.vectSizes.size() > 0) && ($3.vectPositions.size() > 0))
								if($3.isConstant == false)
								{
									pointer = "*";
									$$.translation += dinamicallyVectDeclaration($$, $3, 2);
								}
								else if($3.vectSizes.size() > 0)
								{
									for(int i = 0; i < $3.vectSizes.size(); i++)
										size *= $3.vectSizes.at(i);
								}

	                            if ($$.modifier != "")
	                                    declare($$.label, $$.modifier + " " + $$.type + pointer, size);
	                            else
	                                    declare($$.label, $$.type + pointer, size);
                        }
                        | TYPE TK_ID TK_ASSIGN E
                        {

								unsigned int length;
                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($2.label))
                                {
                                        (*IDMap)[$2.label].label = generateID();
                                        (*IDMap)[$2.label].type = $1.type;
                                        (*IDMap)[$2.label].modifier = $1.modifier;
										(&(*IDMap)[$2.label].vectSizes)->clear();
                                        (&(*IDMap)[$2.label].vectSizesFromIds)->clear();
										(*IDMap)[$2.label].hasSizes = true;
                                }
                                else
                                        yyerror("identifier: '" + $2.label + "'  previously declared here.");

                                $$ = assign(voidStr, $2, $4);
								length = 1;
				
                                if ($$.modifier != "")
                                        declare($$.label, $$.modifier + " " + $$.type, length);
                                else
                                        declare($$.label, $$.type, length);
                        }
                        ;


                        
TYPE                    : TK_TYPE_CHAR
                        {
                                $$.type = $1.translation;
                                $$.modifier = "";
                                $$.translation = "";
                        }
                        | TK_TYPE_STRING
                        {
                                $$.type = $1.translation;
                                $$.modifier = "";
                                $$.translation = "";
                        }
                        | TK_TYPE_INT
                        {
                                $$.type = $1.translation;
                                $$.modifier = "";
                                $$.translation = "";
                        }
                        | TK_TYPE_VOID
                        {
                                $$.type = $1.translation;
                                $$.modifier = "";
                                $$.translation = "";
                        }
                        | TK_TYPE_FLOAT
                        {
                                $$.type = $1.translation;
                                $$.modifier = "";
                                $$.translation = "";
                        }
                        | TK_TYPE_DOUBLE
                        {
                                $$.type = $1.translation;
                                $$.modifier = "";
                                $$.translation = "";
                        }
                        | TK_TYPE_BOOL
                        {
                                $$.type = "int";
                                $$.modifier = "unsigned short";
                                $$.translation = "";
                        }
                        | TK_MODIFIER_UNSIGNED TK_TYPE_CHAR
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SIGNED TK_TYPE_CHAR
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_UNSIGNED TK_TYPE_INT
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }                        
                        | TK_MODIFIER_SIGNED TK_TYPE_INT
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SHORT TK_TYPE_INT
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_LONG TK_TYPE_DOUBLE
                        {
                                $$.type = $2.translation;
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SHORT
                        {
                                $$.type = "int";
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_LONG
                        {
                                $$.type = "int";
                                $$.modifier = $1.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_UNSIGNED TK_MODIFIER_SHORT TK_TYPE_INT
                        {
                                $$.type = $3.translation;
                                $$.modifier = $1.translation + " " + $2.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SIGNED TK_MODIFIER_SHORT TK_TYPE_INT
                        {
                                $$.type = $3.translation;
                                $$.modifier = $1.translation + " " + $2.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $3.translation;
                                $$.modifier = $1.translation + " " + $2.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $3.translation;
                                $$.modifier = $1.translation + " " + $2.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $3.translation;
                                $$.modifier = $1.translation + " " + $2.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $4.translation;
                                $$.modifier = $1.translation + " " + $2.translation + " " + $3.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $4.translation;
                                $$.modifier = $1.translation + " " + $2.translation + " " + $3.translation;
                                $$.translation = "";
                        }                        
                        | TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
                        {
                                $$.type = "int";
                                $$.modifier = $1.translation + " " + $2.translation + " " + $3.translation;
                                $$.translation = "";
                        }
                        | TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
                        {
                                $$.type = "int";
                                $$.modifier = $1.translation + " " + $2.translation + " " + $3.translation;
                                $$.translation = "";
                        }
                        ;



TERMINAL        :       TK_INT
                        {
                                $$.label = generateID();
                                $$.type = "int";
                                $$.modifier = "";
                               	$$.isConstant = true;
								$$.intValue = $1.intValue;

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | TK_FLOAT
                        {
                                $$.label = generateID();
                                $$.type = "float";
                                $$.modifier = "";
                               	$$.isConstant = true;
  
                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | TK_SCIENTIFIC
                        {
                                $$.label = generateID();
                                $$.type = "float"; //poderia ser double
                                $$.modifier = "";
                               	$$.isConstant = true;
          

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | TK_CHAR
                        {
                                $$.label = generateID();
                                $$.type = "char";
                                $$.modifier = "";
                               	$$.isConstant = true;
              

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";                                

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_INT
                        {
                                $$.label = generateID();
                                $$.type = "int";
                                $$.modifier = "";
                               	$$.isConstant = true;
 

                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_FLOAT
                        {
                                $$.label = generateID();
                                $$.type = "float";
                                $$.modifier = "";
                               	$$.isConstant = true;
  
                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_SCIENTIFIC
                        {
                                $$.label = generateID();
                                $$.type = "float"; //poderia ser double
                                $$.modifier = "";
                               	$$.isConstant = true;
          

                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_CHAR
                        {
                                $$.label = generateID();
                                $$.type = "char";
                                $$.modifier = "";
                               	$$.isConstant = true;
              

                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + "\n";                                

                                declare($$.label, $$.type, 1);
                        }
                        | TK_STRING
                        {                        

			       				$$.label = generateID();
                                $$.type = "string";
                                $$.modifier = "";
                               	$$.isConstant = true;

								$$.translation = "\tstrcpy(" + $$.label + ", " + $1.translation + ");\n";                           
								$$.translation += "\t" + $$.label + "[" + intToString($1.translation.length() - 2) + "] = " + "'\\0';\n";

								/*comprimento da string '-2' por conta das aspas +1 por conta do '/0'*/
                                declare($$.label, $$.type, $1.translation.length() - 2 + 1);
                        }
                        | TK_BOOL
                        {
                                $$.label = generateID();
                                $$.type = "int";
                                $$.modifier = "unsigned short";
                               	$$.isConstant = true;


                                if ($1.translation == "true")                        
                                        $$.translation = "\t" + $$.label + " = 1;\n"; /*true*/
                                else
                                        $$.translation = "\t" + $$.label + " = 0;\n"; /*false*/

                                declare($$.label, $$.modifier + " " + $$.type, 1);
                        }
                        | TK_ID VECTOR_P
                        {
                                id_struct* id;
								YYSTYPE pos;
								string posLabel;
                        
                                if((id = findID($1.label)) == NULL)       
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");
                                else
                                {
								
                                        $$.label = id->label;
                                        $$.type = id->type;
                                        $$.modifier = id->modifier;
                                        $$.translation = "";

										if($2.vectPositions.size() > 0)
										{
											if(id->hasSizes == true)
												pos = computingPosition(id->vectSizes, $2.vectPositions);
											else
												pos = computingPositionFromIds(id->vectSizesFromIds, $2.vectPositions);
											$$.translation = pos.translation;
											posLabel = pos.label;
										}

										$$.vectPositions = $2.vectPositions;
										$$.posLabel = posLabel;
				                       	$$.isConstant = false;

                                }
                        }
                        | SIGNAL TK_ID VECTOR_P
                        {
                                id_struct* id;
								YYSTYPE pos;
								string posLabel;
                        
                                if((id = findID($2.label)) == NULL)       
                                        yyerror("identifier: '" + $2.label + "'  was not declared in this scope.");
                                else
                                {
										string modifier;
										$$.translation = "";

										if($3.vectSizes.size() > 0)
										{
											if(id->hasSizes == true)
												pos = computingPosition(id->vectSizes, $3.vectPositions);
											else
												pos = computingPositionFromIds(id->vectSizesFromIds, $3.vectPositions);

											$$.translation = pos.translation;
											posLabel = pos.label;
										}

                                        $$.label = generateID();
										$$.vectPositions = $3.vectPositions;
										$$.posLabel = posLabel;
                                        $$.type = id->type;
                                        $$.modifier = id->modifier;
                                        $$.translation += "\t" + $$.label + " = " + $1.translation + id->label + posLabel + ";\n";

										modifier = $$.modifier;
										if(modifier != "")
											modifier+= " ";
			
										declare($$.label, modifier + $$.type, 1);
                                }

                               	$$.isConstant = false;
                        }
                        ;


SIGNAL                	: TK_OP_SUM | TK_OP_SUB
                        ;



VECTOR_SIZES			: '[' E_C ']' VECTOR_SIZES
						{
							if($2.type != "int")
								yyerror("size of array has non-integer type");

							/*isso é utilizado nos casos que há algum tamanho não constante,
							para se realizar alocação dinâmica com malloc*/
							$$.vectPositions = $4.vectPositions;
							$$.vectPositions.insert($$.vectPositions.begin(), $2);
							
							$$.vectSizes = $4.vectSizes;
							$$.vectSizes.insert($$.vectSizes.begin(), $2.intValue);

							$$.isConstant = $2.isConstant && $4.isConstant;
							$$.hasIdSizeInVectArgs = $4.hasIdSizeInVectArgs && true;
							$$.translation = "[]" + $4.translation;
							//$$.translation = "[" + $2.label + "]" + $4.translation;;
						}
						| '[' ']' VECTOR_SIZES
						{
							$$.vectSizes = $3.vectSizes;
							$$.vectPositions = $3.vectPositions;
							$$.isConstant = true;
							$$.translation = "";
							$$.hasIdSizeInVectArgs = false;
							$$.translation = "[]" + $3.translation;
						}
						|
						{
							(&$$.vectSizes)->clear();
							(&$$.vectPositions)->clear();
							$$.isConstant = true;
							$$.translation = "";
							$$.hasIdSizeInVectArgs = true;
						}
						;



VECTOR_P				: '[' E_C ']' VECTOR_P
						{
							if($2.type != "int")
								yyerror("size of array has non-integer type");
							else
							{
								$$.vectPositions = $4.vectPositions;
								$$.vectPositions.insert($$.vectPositions.begin(), $2);
								$$.translation = "[]" + $4.translation;
							}
						}
						|
						{
							$$.vectPositions.clear();
							$$.translation = "";
						}
						;




%%

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
