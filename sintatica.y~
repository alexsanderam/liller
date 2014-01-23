%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>

#define YYSTYPE args

using namespace std;

typedef struct idStruct
{
        string type;
        string modifier;
        string label;
} id_struct;

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
        //string label;
	unsigned int size; /*nos casos de string*/
} variable_declarations_struct;

typedef map<string, id_struct> identifiers_map;
typedef map<string, variable_declarations_struct> declarations_map;


list<identifiers_map*> stackIDMap;
list<declarations_map*> stackDeclarationsMap;

/*map<string, id_struct> IDMap;
map<string, variable_declaratino_struct> declarationsMap;*/

map<operation_struct, string> operationsMap;

const string voidStr = "";

bool error = false;
bool warning = false;

string declarations = "";

/*controle para alertar a recursão de operações relacionais*/
unsigned int relationalCounter = 0;


int yylex(void);
void yyerror(string);
void yywarning(string);

void openNewScope();
void closeCurrentScope();
YYSTYPE runBasicOperation(YYSTYPE, YYSTYPE, YYSTYPE);
YYSTYPE assigns(string, YYSTYPE, YYSTYPE);
string generateID();
void relationalControl(YYSTYPE);
id_struct* findID(string);
bool isDeclaredCurrentScope(string label);
void declare(string, string, unsigned int);
string getDeclarations();
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



%start BEGIN

%nonassoc TK_ASSIGN
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


%%

BEGIN                 	: START DECLARATIONS MAIN SCOPE
			{

				if(!error)
				{
					cout << "/*Compiler prescot-liller*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\nusing namespace std;\n\n" + $3.translation + "{\n" + declarations + "\n" + $2.translation + "\n" + $4.translation + "}\n" << endl;
					closeCurrentScope();
				}
				else
				{
					closeCurrentScope();
					exit(1);
				}
			}
			;


START			: 
			{
				openNewScope();	
			}
			;


MAIN			: TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')'
                        {
                               $$.translation = "int main(void)\n";

                        }
			| TK_TYPE_INT TK_MAIN '(' ')'
                        {
                               $$.translation = "int main()\n";
                        }
                        ;


SCOPE			: BEGIN_SCOPE COMMANDS END_SCOPE
			{
				$$.translation +=  $1.translation + $2.translation + $3.translation;
			}
			;



BEGIN_SCOPE		: '{'
			{
				openNewScope();			
				$$.translation = "";
			}
			;
			
	

END_SCOPE		: '}'
			{
				declarations += getDeclarations();
				closeCurrentScope(); /*desempilha*/				
				$$.translation = "";
			}
			;


COMMANDS        : 	COMMAND COMMANDS
                        {
                                $$.translation = $1.translation + "\n" + $2.translation;
                        }
                        |
                        {
                                $$.translation = "";
                        }
			;



COMMAND         	: E ';'
			{
				$$.translation = $1.translation;
				relationalCounter = 0; /*controle para alertar a recursão de operações relacionais*/
			}
			| RETURN ';'  
			| COUT ';'
                        | DECLARATION ';'
			| SCOPE
                        ;


RETURN                	: TK_RETURN E 
                        {
                                $$.translation = $2.translation + "\n\t" + $1.translation + " " + $2.label + ";";
                        }
                        ;


E                       :'(' E ')'
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
			| ATRIBUITION
			{
                            	$$.translation = $1.translation;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
			}
			| E TK_OP_SUM E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
			| E TK_OP_SUB E
                        {
 				$$ = runBasicOperation($1, $3, $2);
                        }
			| E TK_OP_MUL E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
			| E TK_OP_DIV E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_MOD E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_LOGIC_OR E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_LOGIC_AND E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_REL_EQ E
                        {
				relationalControl($2);
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_REL_DIFF E
                        {
				relationalControl($2);
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_REL_LESS E
                        {				
				relationalControl($2);
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_REL_GREATER E
                        {
				relationalControl($2);
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_REL_EQLESS E
                        {
				relationalControl($2);
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_REL_EQGREATER E
                        {
				relationalControl($2);
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_BIN_AND E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_BIN_OR E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_BIN_XOR E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_BIN_SHIFTR E
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        | E TK_OP_BIN_SHIFTL E
                        {
				$$ = runBasicOperation($1, $3, $2);
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
			;




ATRIBUITION        : TK_ID TK_ASSIGN E
                        {
				if(findID($1.label) == NULL)
					yyerror("identifier: '" + $1.label + "' was not declared in this scope.");

				$$ = assigns(voidStr, $1, $3);
                        }
                        ;        


COUT			: TK_COUT '(' E ')'
			{
				$$.translation = $3.translation + "\n\tcout << " + $3.label + " << endl;\n";
			}
			;



DECLARATIONS		: DECLARATIONS DECLARATION ';' 
			{
				$$.translation = $1.translation + $2.translation;
				declarations += getDeclarations();
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
                                string atribuition = "";
				
				 identifiers_map* IDMap = stackIDMap.front();

                                if(!isDeclaredCurrentScope($3.label))
                                {
                                        (*IDMap)[$3.label].label = generateID();
                                        (*IDMap)[$3.label].type = $1.type;
                                        (*IDMap)[$3.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");
			

				$$ = assigns($1.translation, $3, $5);

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

				$$ = assigns(voidStr, $2, $4);


				if ($$.modifier != "")
					declare($$.label, $$.modifier + " " + $$.type, 1);
				else
					declare($$.label, $$.type, 1);

                        }
                        ;

                        
TYPE                	: TK_TYPE_CHAR
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
				declarations_map declarationsMap = *stackDeclarationsMap.front();
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
                               	identifiers_map* IDMap = stackIDMap.front();
			
				if(findID($1.label) == NULL)       
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");

                                $$.label = (*IDMap)[$1.label].label;
                                $$.type = (*IDMap)[$1.label].type;
                                $$.modifier = (*IDMap)[$1.label].modifier;
                                $$.translation = "";
                        }
                        ;


SIGNAL		:	TK_OP_SUM | TK_OP_SUB
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

YYSTYPE runBasicOperation(YYSTYPE operand1, YYSTYPE operand2, YYSTYPE operation)
{
	YYSTYPE* res;

	res = new YYSTYPE();
	
	string resultOperationType;
        id_struct* keyOperating;
        string weakOperatingLabel;
        string strongOperatingLabel;

        res->label = generateID();

        res->translation = operand1.translation + operand2.translation;

        resultOperationType = verifyResultOperation(operand1.type, operand2.type, operation.translation);

        /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
         mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
         no momento da atribuição, que deverá se fazer um cast, caso necessário*/

        res->type = resultOperationType;
        res->modifier = ""; /*desconsidera-se os modificadores*/

	declare(res->label, res->type, 1);

        if((operand1.modifier == operand2.modifier) && (operand1.type == operand2.type))
        {
                res->translation += "\t" + res->label + " = " + operand1.label + " " + operation.translation + " " + operand2.label + ";\n";
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
                        res->translation += "\t" + res->label + " = " + strongOperatingLabel + " " + operation.translation + " " + keyOperating->label + ";\n";
                }
                else
                {
                        weakOperatingLabel = operand1.label;
                        strongOperatingLabel = operand2.label;

                        res->translation += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                        res->translation += "\t" + res->label + " = " + keyOperating->label + " " + operation.translation + " " + strongOperatingLabel + ";\n";
                }


		declare(keyOperating->label, modifier + keyOperating->type, 1);
        }

	return *res;
}

id_struct* findID(string label)
{
	list<identifiers_map*>::iterator i;
	
	for(i = stackIDMap.begin(); i != stackIDMap.end(); i++)
	{
		identifiers_map* IDMap = *i;

		if(IDMap->find(label) != IDMap->end())
		{
			return 	&(*IDMap)[label];
		}
	}


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

YYSTYPE assigns(string addtranslation, YYSTYPE id, YYSTYPE exp)
{
	YYSTYPE* res;	
	res = new YYSTYPE();
        string cast = "";

	id_struct* identifier = findID(id.label);

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

string generateID()
{
        static int counter = 0;
        stringstream label;

        label << "_temp" << counter++;

        return label.str();
}          


void declare(string label, string dIType, unsigned int size)
{
	string finalType = dIType;
	
	declarations_map* declarationsMap = stackDeclarationsMap.front();

	if (dIType == "string")
		finalType = "char";

	 declarationsMap->insert(declarations_map::value_type(label, {finalType, size}));
	 //(*declarationsMap)[label] = {finalType, size};
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

