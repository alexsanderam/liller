%{
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

/*pilhas (na verdade lsitas) de rótulos - usado nos comandos break e continue*/
list<string> stackBeginLabels;
list<string> stackEndLabels;

/*mapa de operações permititdas*/
map<operation_struct, string> operationsMap;


/*constante string vazia*/
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

/*controle do uso do continue e do break*/
bool flagContinue = false;
bool flagBreak = false;
bool exprBeforeContinue = false; /*somente no caso do for*/
string translationContinue = ""; /*somente no caso do for*/



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
%token TK_COUT
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
%nonassoc ELSE
%%

BEGIN                   : START DECLARATIONS MAIN SCOPE
                        {
				string globalDeclarations = "/*========Variáveis globais============*/\n" + getDeclarations();
				verifyLabels(); /*verifica se há erros relacionados aos rótulos*/

				closeCurrentScope(); /*desempilha o escopo global*/

				if(!error)
                                        cout << "/*Compiler prescot-liller*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\nusing namespace std;\n\n" + globalDeclarations + "\n" + $3.translation + "{\n" + declarations + "\n" + $2.translation + "\n" + $4.translation + "}\n" << endl;
                                else
                                        exit(1);
                        }
                        ;


START                   : 
                        {
                                openNewScope();        
                        }
                        ;


MAIN                    : TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')'
                        {
                               $$.translation = "int main(void)\n";

                        }
                        | TK_TYPE_INT TK_MAIN '(' ')'
                        {
                               $$.translation = "int main()\n";
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
                                closeCurrentScope(); /*desempilha*/                                
                                $$.translation = "";

                                /*controle de declarações, neste caso é permitido realizar declarações*/
                                flagDeclarationNotAllowed = flagDeclarationNotAllowedAux;

                        }
                        ;



COMMANDS        	: STATEMENT COMMANDS
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
                        | COUT ';'
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
			| LABEL
			| GOTO ';'
			| CONTINUE ';'
			| BREAK ';'
                        | ';'
                        {
                                $$.translation = "";
                        }
                        ;



RETURN                  : TK_RETURN E_C 
                        {
                                $$.translation = $2.translation + "\n\t" + $1.translation + " " + $2.label + ";";
                        }
                        ;


                        


IF_C			: TK_IF
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
                                $$.translation += "\t" + labelEndIF + ":\n"; /*tradução: labelEndIF:*/

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
                                $$.translation += "\t" + labelEndIF + ":\n"; /*tradução: labelEndId:*/

				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
                        ;


WHILE_C			: TK_WHILE
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
                                $$.translation += "\t" + labelEndWhile + ":\n"; /*tradução: labelEndWhile:*/


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
                                $$.translation += "\t" + labelEndDoWhile + ":\n\n"; /*tradução: labelEndDoWhileIF:*/


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
				{
					$$.translation = $1.translation;
					$$.label = $1.label;
					$$.type = $1.type;
					$$.modifier = $1.modifier;
				}
				| TERMINAL
				{
					$$.translation = $1.translation;
					$$.label = $1.label;
					$$.type = $1.type;
					$$.modifier = $1.modifier;
				}
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

                                string labelBeginFor = generateLabel();
                                string labelEndFor = generateLabel();

				/*empilha os labels*/
				stackBeginLabels.push_front(labelBeginFor);
				stackEndLabels.push_front(labelEndFor);

			}
			;


FOR                     : FOR_C '(' OPTIONAL_E_OR_DECLARATION ';' OPTIONAL_E ';' OPTIONAL_E ')' STATEMENT
                        {
                                YYSTYPE notE;
                                string labelBeginFor = stackBeginLabels.front();
                                string labelEndFor = stackEndLabels.front();

				size_t pos;
				string stat = $9.translation;
				string afterContinue;


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

				if(exprBeforeContinue == true)
				{
					pos = $9.translation.find(translationContinue);
					stat = $9.translation.substr(0,  (pos == 0 ? pos : pos - 1));
					afterContinue = $9.translation.substr(pos, $9.translation.size());
				}

                                $$.translation += stat + "\n"; /*tradução: STATEMENT*/

				if(exprBeforeContinue == true)
				{
	                                $$.translation += $7.translation + "\n"; /*tradução do incremento, que pode ser vazia*/
					$$.translation += afterContinue; /*tradução do continue e dos comandos após (quando há)*/
				}

                                $$.translation += $7.translation + "\n"; /*tradução do incremento, que pode ser vazia*/
                                $$.translation += "\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginFor*/
                                $$.translation += "\t" + labelEndFor + ":\n"; /*tradução: labelEndFor:*/


				/*desempilha os labels*/
				stackBeginLabels.pop_front();
				stackEndLabels.pop_front();

				/*controle do continue e do break*/
				flagContinue = false;
				flagBreak = false;
				exprBeforeContinue = false;

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

                                string labelBeginFor = stackBeginLabels.front();
                                string labelEndFor = stackEndLabels.front();

				size_t pos;
				string stat = $7.translation;
				string afterContinue;

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


				if(exprBeforeContinue == true)
				{
					pos = $7.translation.find(translationContinue);
					stat = $7.translation.substr(0,  pos = (pos == 0 ? pos : pos - 1));

					afterContinue = $7.translation.substr(pos, $7.translation.size());
				}

                                $$.translation += stat + "\n"; /*tradução: STATEMENT*/

				if(exprBeforeContinue == true)
				{
	                                $$.translation += ass.translation + "\n"; /*tradução: da atualização do identicador (atribuição)*/
					$$.translation += afterContinue; /*tradução do continue e dos comandos após (quando há)*/
				}

				$$.translation += ass.translation; /*tradução: da atualização do identicador (atribuição)*/
				$$.translation += "\t\tgoto " + labelBeginFor + ";\n"; /*tradução: goto labelBeginWhile*/
				$$.translation += "\n\t" + labelEndFor + ":\n"; /*tradução: labelEndWhile:*/                                


				/*desempilha os labels*/
				stackBeginLabels.pop_front();
				stackEndLabels.pop_front();

				/*controle do continue e do break*/
				flagContinue = false;
				flagBreak = false;
				exprBeforeContinue = false;

				/*desempilha o escopo (para os casos de declaração dentro do for)*/
                                declarations += getDeclarations();
				closeCurrentScope(); /*desempilha*/


				/*controle de declaraçãoes*/
				flagDeclarationNotAllowedAux = false;
                                flagDeclarationNotAllowed = false;
                        }
			;


LABEL			: TK_ID TK_GO_LABEL
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

					exprBeforeContinue = true;
					translationContinue = $$.translation;
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


/*SWITCH_C		: TK_SWITCH
			{
				/*controle do break*/
/*				flagBreak = true;
			}
			;


SWITCH			: TK_SWITCH '(' E_C ')' CASES
			{
				/*controle do break*/
/*				flagBreak = false;
			}
			;


CASES			: CASES CASE
			| TK_DEFAULT ':' COMMANDS
			| STATEMENT
			;

CASE			: TK_CASE E_C ':' COMMANDS
			|
			;
*/


E_C			: E
			{
				/*controle para alertar a recursão de operações relacionais*/
                                relationalCounter = 0;     

                                /*controle da tradução do incremento/decremento*/
                                if(flagIncreaseTranslation)
                                {
                                        $$.translation += auxIncreaseTranslation;
                                        flagIncreaseTranslation = false;
                                        auxIncreaseTranslation = "";
                                }

			}
			;



E                       : '(' E ')'
                        {
                                $$.translation = $2.translation;
                                $$.label = $2.label;
                                $$.type = $2.type;
                                $$.modifier = $2.modifier;                
                        }
                        | TERMINAL
                        {
                                $$.translation = $1.translation;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
                        | ATTRIBUITION
                        {
                                    $$.translation = $1.translation;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
                        | '(' TYPE ')' TERMINAL /*cast*/
                        {
                                $$ = runCast($4, $2);
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
                                relationalControl($2);
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_DIFF E
                        {
                                relationalControl($2);
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_LESS E
                        {                                
                                relationalControl($2);
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_GREATER E
                        {
                                relationalControl($2);
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_EQLESS E
                        {
                                relationalControl($2);
                                $$ = runBasicOperation($1, $3, $2.translation);
                        }
                        | E TK_OP_REL_EQGREATER E
                        {
                                relationalControl($2);
                                $$ = runBasicOperation($1, $3, $2.translation);
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

                                $$.translation = $2.translation + "\t" + $$.label + " = " + $1.translation + " " + $2.label + ";\n";                                

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

                                declare($$.label, $$.type, 1);
                        }
                        | INCREASE
                        {
                                $$.translation = $1.translation;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
                        | PREV_INCREASE
                        {
                                       $$.translation = $1.translation;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
                        ;



INCREASE                : TK_ID TK_OP_INCREASE
                        {
                                       id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;
                        
                                if((id = findID($1.label)) == NULL)       
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");
                                else
                                {
                                        $1.translation = "";
                                        $1.type = id->type;
                                        $1.modifier = id->modifier;

                                        $$.translation = $1.translation;
                                        $$.label = id->label;
                                        $$.type = $1.type;
                                        $$.modifier = $1.modifier;
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = $1;
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ($2.translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, $1, op);

                                        auxIncreaseTranslation = ass.translation;
                                        flagIncreaseTranslation = true;
                                }
                        }
                        ;



PREV_INCREASE                : TK_OP_INCREASE TK_ID
                        {
                                id_struct* id;
                                string operation;

                                YYSTYPE ass;
                                YYSTYPE op;
                                YYSTYPE op_id;
                                YYSTYPE value;
                        
                                if((id = findID($2.label)) == NULL)       
                                        yyerror("identifier: '" + $2.label + "'  was not declared in this scope.");
                                else
                                {
                                        $2.translation = "";
                                        $2.type = id->type;
                                        $2.modifier = id->modifier;
                                
                                        /*Realiza as operações referentes ao incremento*/

                                        op_id = $2;
                                        op_id.label = id->label;

                                        value = generateIntValue(1);

                                        operation = ($1.translation == "++" ? "+" : "-");
        
                                        op = runBasicOperation(op_id, value, operation);
                                        ass = assign(voidStr, $2, op);
                                        
                                        $$.translation = ass.translation;
                                        $$.label = ass.label;
                                        $$.type = ass.type;
                                        $$.modifier = ass.modifier;
                                }
                        }
                        ;




ATTRIBUITION        : TK_ID TK_ASSIGN E
                        {
                                if(findID($1.label) == NULL)
                                        yyerror("identifier: '" + $1.label + "' was not declared in this scope.");
                                else
                                        $$ = assign(voidStr, $1, $3);
                        }
                        | OP_ASSIGN
                        {
                                $$.translation = $1.translation;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
                        ;      


OP_ASSIGN                : TK_ID TK_OP_ASSIGN E
                        {
                                string operation;
                                id_struct* id;

                                YYSTYPE ass;
                                YYSTYPE op_id;
                                YYSTYPE op;

                                if((id = findID($2.label)) == NULL)       
                                        yyerror("identifier: '" + $2.label + "'  was not declared in this scope.");
                                else
                                {
                                        
                                        $1.translation = "";
                                        $1.type = id->type;
                                        $1.modifier = id->modifier;

					/*verifica qual operação deve ser realizada*/
					if ($2.translation == "+=")
						operation = "+";
					else if ($2.translation == "-=")
						operation = "-";
					else if ($2.translation == "*=")
						operation = "*";
					else if ($2.translation == "/=")
						operation = "/";
					else if ($2.translation == "%=")
						operation = "%";
					else if ($2.translation == "<<=")
						operation = "<<";
					else if ($2.translation == ">>=")
						operation = ">>";
					else if ($2.translation == "&=")
						operation = "&";
					else if ($2.translation == "|=")
						operation = "|";
					else if ($2.translation == "^=")
						operation = "^";

                                        /*Realiza as operações referentes a operação*/
                                        op_id = $1;
                                        op_id.label = id->label;
                                        

                                        op = runBasicOperation(op_id, $3, operation);
                                        ass = assign(voidStr, $1, op);

                                        $$.translation = ass.translation;
                                        $$.label = ass.label;
                                        $$.type = ass.type;
                                        $$.modifier = ass.modifier;
                                }                                                                
                                
                        }
                        ;  


COUT                        : TK_COUT '(' E_C ')'
                        {
                                $$.translation = $3.translation + "\n\tcout << " + $3.label + " << endl;\n";
                        }
                        ;



DECLARATIONS            : DECLARATIONS DECLARATION ';' 
                        {
                                $$.translation = $1.translation + $2.translation;
                                //declarations += getDeclarations();
                        }
                        |
                        {
                                $$.translation = "";
                        }
                        ;



DECLARATION        : DECLARATION ',' TK_ID
                        {
                                
                                identifiers_map* IDMap = stackIDMap.front();
                                                        
                                if(!isDeclaredCurrentScope($3.label))
                                {
                                        (*IDMap)[$3.label].label = generateID();
                                        (*IDMap)[$3.label].type = $1.type;
                                        (*IDMap)[$3.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");

                                
                                $$.label = (*IDMap)[$3.label].label;
                                $$.type = (*IDMap)[$3.label].type;
                                $$.modifier = (*IDMap)[$3.label].modifier;
                                $$.translation = $1.translation;

                                if ($$.modifier != "")
                                        declare($$.label, $$.modifier + " " + $$.type, 1);
                                else
                                        declare($$.label, $$.type, 1);

                        }
                        | DECLARATION ',' TK_ID TK_ASSIGN E
                        {
                                string cast = "";
                                string ATTRIBUITION = "";
                                
                                 identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($3.label))
                                {
                                        (*IDMap)[$3.label].label = generateID();
                                        (*IDMap)[$3.label].type = $1.type;
                                        (*IDMap)[$3.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");
                        

                                $$ = assign($1.translation, $3, $5);

                                if ($$.modifier != "")
                                        declare($$.label, $$.modifier + " " + $$.type, 1);
                                else
                                        declare($$.label, $$.type, 1);
                                                        
                        }
                        | TYPE TK_ID
                        {

                                 identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($2.label))
                                {
                                        (*IDMap)[$2.label].label = generateID();
                                        (*IDMap)[$2.label].type = $1.type;
                                        (*IDMap)[$2.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $2.label + "'  previously declared here.");


                                $$.label = (*IDMap)[$2.label].label;
                                $$.translation = "";
                                $$.type = (*IDMap)[$2.label].type;
                                $$.modifier = (*IDMap)[$2.label].modifier;


                                if ($$.modifier != "")
                                        declare($$.label, $$.modifier + " " + $$.type, 1);
                                else
                                        declare($$.label, $$.type, 1);

                        }
                        | TYPE TK_ID TK_ASSIGN E
                        {

                                identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($2.label))
                                {
                                        (*IDMap)[$2.label].label = generateID();
                                        (*IDMap)[$2.label].type = $1.type;
                                        (*IDMap)[$2.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $2.label + "'  previously declared here.");

                                $$ = assign(voidStr, $2, $4);


                                if ($$.modifier != "")
                                        declare($$.label, $$.modifier + " " + $$.type, 1);
                                else
                                        declare($$.label, $$.type, 1);

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
 

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | TK_FLOAT
                        {
                                $$.label = generateID();
                                $$.type = "float";
                                $$.modifier = "";
  
                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | TK_SCIENTIFIC
                        {
                                $$.label = generateID();
                                $$.type = "float"; //poderia ser double
                                $$.modifier = "";
          

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | TK_CHAR
                        {
                                $$.label = generateID();
                                $$.type = "char";
                                $$.modifier = "";
              

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";                                

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_INT
                        {
                                $$.label = generateID();
                                $$.type = "int";
                                $$.modifier = "";
 

                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_FLOAT
                        {
                                $$.label = generateID();
                                $$.type = "float";
                                $$.modifier = "";
  
                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_SCIENTIFIC
                        {
                                $$.label = generateID();
                                $$.type = "float"; //poderia ser double
                                $$.modifier = "";
          

                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";

                                declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_CHAR
                        {
                                $$.label = generateID();
                                $$.type = "char";
                                $$.modifier = "";
              

                                $$.translation = "\t" + $$.label + " = " + $1.translation + $2.translation + ";\n";                                

                                declare($$.label, $$.type, 1);
                        }
                        | TK_STRING
                        {
                                $$.label = generateID();
                                $$.type = "string";
                                $$.modifier = "";

                                $$.translation = "\t" + $$.label + " = " + $1.translation + ";\n";                                

                                declare($$.label, $$.type, 1);
                        }
                        | TK_BOOL
                        {
                                $$.label = generateID();
                                $$.type = "int";
                                $$.modifier = "unsigned short";


                                if ($1.translation == "true")                        
                                        $$.translation = "\t" + $$.label + " = 1;\n"; /*true*/
                                else
                                        $$.translation = "\t" + $$.label + " = 0;\n"; /*false*/

                                declare($$.label, $$.type, 1);
                        }
                        | TK_ID
                        {
                                id_struct* id;
                        
                                if((id = findID($1.label)) == NULL)       
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");
                                else
                                {
                                        $$.label = id->label;
                                        $$.type = id->type;
                                        $$.modifier = id->modifier;
                                        $$.translation = "";
                                }
                        }
                        | SIGNAL TK_ID
                        {
                                id_struct* id;
                        
                                if((id = findID($2.label)) == NULL)       
                                        yyerror("identifier: '" + $2.label + "'  was not declared in this scope.");
                                else
                                {
					string modifier;					

                                        $$.label = generateID();
                                        $$.type = id->type;
                                        $$.modifier = id->modifier;
                                        $$.translation = "\t" + $$.label + " = " + $1.translation + id->label + ";\n";

					modifier = $$.modifier;
					if(modifier != "")
						modifier+= " ";
			
					declare($$.label, modifier + $$.type, 1);
                                }
                        }
                        ;


SIGNAL                :        TK_OP_SUM | TK_OP_SUB
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
