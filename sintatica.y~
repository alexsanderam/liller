%{
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
id_struct* defineKeyOperating(id_struct, id_struct, string);
void loadOpearationsMap(void);

%}

%token TK_INT TK_FLOAT TK_SCIENTIFIC TK_CHAR TK_STRING TK_BOOL
%token TK_TRUE TK_FALSE
%token TK_MAIN 
%token TK_ID 
%token TK_TYPE_CHAR TK_TYPE_STRING TK_TYPE_INT TK_TYPE_VOID TK_TYPE_FLOAT TK_TYPE_DOUBLE TK_TYPE_BOOLEAN
%token TK_MODIFIER_UNSIGNED TK_MODIFIER_SIGNED TK_MODIFIER_SHORT TK_MODIFIER_LONG
%token TK_END TK_ERROR
%token TK_OP_SUM TK_OP_SUB TK_OP_MUL TK_OP_DIV
%token TK_OP_REL_LESS TK_OP_REL_GREATER TK_OP_REL_EQLESS TK_OP_REL_EQGREATER TK_OP_REL_EQ TK_OP_REL_DIFF
%token TK_OP_LOGIC_AND TK_OP_LOGIC_OR TK_OP_LOGIC_NOT
%token TK_OP_BIN_AND TK_OP_BIN_OR TK_OP_BIN_XOR TK_OP_BIN_NOT TK_OP_BIN_SHIFTR TK_OP_BIN_SHIFTL

%token TK_ASSIGN
%token TK_RETURN



%start Begin

%left TK_ASSIGN
%left TK_OP_SUM TK_OP_SUB
%left TK_OP_MUL TK_OP_DIV TK_OP_MOD


%%

Begin 		: TK_TYPE_INT TK_MAIN '(' ')' BLOCK
			{
				if(!error)				
					cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()"  << $5.traduction << endl; 
				else
					exit(1);
			}
			|
			TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')' BLOCK
			{
				if(!error)
					cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)"  << $6.traduction << endl;
				else
					exit(1);
			}
			;

BLOCK		: '{' COMMANDS BLOCK RETURN '}'
			{
				$$.traduction = "\n{\n" + declarations + $2.traduction + $3.traduction + $4.traduction + "\n}";
			}
			|
			{
				$$.traduction = "";
			}
			;


RETURN		: TK_RETURN TK_INT ';'
			{
				$$.traduction = "\n\t" + $1.traduction + " " + $2.traduction + ";";
			}
			|
			{
				$$.traduction = "";
			}
			;


DECLARATION	: DECLARATION ',' TK_ID
			{

				if(IDMap.find($3.label) == IDMap.end())
				{
					IDMap[$3.label].label = generateLabel();
					IDMap[$3.label].type = $1.type;
					IDMap[$3.label].modifier = $1.modifier;
				}
				else
					yyerror("identifier: '" + $3.label + "' already declared.");
	
				
				if(IDMap[$3.label].modifier != "")
					declarations += "\t" + IDMap[$3.label].modifier + " ";
				else
					declarations += "\t";

				declarations += IDMap[$3.label].type + " " + IDMap[$3.label].label + ";\n";

				$$.label = IDMap[$3.label].label;
				$$.traduction = $1.traduction;
				$$.type = IDMap[$3.label].type;
			}
			| DECLARATION ',' TK_ID TK_ASSIGN E
			{
				string cast = "";
				string atribuition = "";

				if(IDMap.find($3.label) == IDMap.end())
				{
					IDMap[$3.label].label = generateLabel();
					IDMap[$3.label].type = $1.type;
					IDMap[$3.label].modifier = $1.modifier;
				}
				else
					yyerror("identifier: '" + $3.label + "' already declared.");

				if (IDMap[$5.label].type != IDMap[$3.label].type)
				{
					//aqui deve se verificar quais casts são possíveis.
					cast = "(" + IDMap[$3.label].type + ") ";
				}

				atribuition = $5.traduction + "\t" + IDMap[$3.label].label + " = " + cast + $5.label + ";\n";

				if(IDMap[$3.label].modifier != "")
					declarations += "\t" + IDMap[$3.label].modifier + " ";
				else
					declarations += "\t";

				declarations += IDMap[$3.label].type + " " + IDMap[$3.label].label + ";\n";

				$$.label = IDMap[$3.label].label;
				$$.traduction = "\n" + atribuition + "\n";
				$$.type = IDMap[$3.label].type;	
							
			}
			| TYPE TK_ID
			{

				if(IDMap.find($2.label) == IDMap.end())
				{
					IDMap[$2.label].label = generateLabel();
					IDMap[$2.label].type = $1.type;
					IDMap[$2.label].modifier = $1.modifier;
				}
				else
					yyerror("identifier: '" + $2.label + "' already declared.");

				if(IDMap[$2.label].modifier != "")
					declarations += "\t" + IDMap[$2.label].modifier + " ";
				else
					declarations += "\t";


				declarations += IDMap[$2.label].type + " " + IDMap[$2.label].label + ";\n";

				$$.label = IDMap[$2.label].label;
				$$.traduction = "";
				$$.type = IDMap[$2.label].type;

			}
			| TYPE TK_ID TK_ASSIGN E
			{
				string cast = "";
				string atribuition = "";

				if(IDMap.find($2.label) == IDMap.end())
				{
					IDMap[$2.label].label = generateLabel();
					IDMap[$2.label].modifier = $1.modifier;
					IDMap[$2.label].type = $1.modifier;
				}
				else
					yyerror("identifier: '" + $2.label + "' already declared.");

				if (IDMap[$4.label].type != IDMap[$2.label].type)
				{
					//aqui deve se verificar quais casts são possíveis.
					cast = "(" + IDMap[$2.label].type + ") ";
				}

				atribuition = $4.traduction + "\t" + IDMap[$2.label].label + " = " + cast + $4.label + ";\n";


				if(IDMap[$2.label].modifier != "")
					declarations += "\t" + IDMap[$2.label].modifier + " ";
				else
					declarations += "\t";


				declarations += IDMap[$2.label].type + " " + IDMap[$2.label].label + ";\n";

				$$.label = IDMap[$2.label].label;
				$$.traduction = "\n" + atribuition + "\n";
				$$.type = IDMap[$2.label].type;

			}
			;

			
TYPE		: TK_TYPE_CHAR
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_TYPE_STRING
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_TYPE_INT
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_TYPE_VOID
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_TYPE_FLOAT
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_TYPE_DOUBLE
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_TYPE_BOOLEAN
			{
				$$.type = $1.traduction;
				$$.modifier = "";
				$$.traduction = "";
			}
			| TK_MODIFIER_UNSIGNED TK_TYPE_CHAR
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SIGNED TK_TYPE_CHAR
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_UNSIGNED TK_TYPE_INT
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}			
			| TK_MODIFIER_SIGNED TK_TYPE_INT
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SHORT TK_TYPE_INT
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_LONG TK_TYPE_DOUBLE
			{
				$$.type = $2.traduction;
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SHORT
			{
				$$.type = "int";
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_LONG
			{
				$$.type = "int";
				$$.modifier = $1.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_SHORT TK_TYPE_INT
			{
				$$.type = $3.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_SHORT TK_TYPE_INT
			{
				$$.type = $3.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.type = $3.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.type = $3.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.type = $3.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.type = $4.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction + " " +  $3.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.type = $4.traduction;
				$$.modifier = $1.traduction + " " + $2.traduction + " " +  $3.traduction;
				$$.traduction = "";
			}			
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
			{
				$$.type = "int";
				$$.modifier = $1.traduction + " " + $2.traduction + " " +  $3.traduction;
				$$.traduction = "";
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
			{
				$$.type = "int";
				$$.modifier = $1.traduction + " " + $2.traduction + " " +  $3.traduction;
				$$.traduction = "";
			}
			;

COMMANDS	: COMMAND COMMANDS
			{
				$$.traduction = $1.traduction + "\n" + $2.traduction;
			}
			| 
			{
				$$.traduction = "";
			}

COMMAND 	: E 	';'	
			| DECLARATION ';'
			{
				$$.traduction = $1.traduction;;
			}
			;


E 			: E ARITHMETIC_OPERATION E
			{
				id_struct* keyOperating;
				id_struct* weakOperating;
				id_struct* strongOperating;

				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;

				$$.traduction = $1.traduction + $3.traduction;

				if(IDMap[$1.label].type == IDMap[$3.label].type)
				{
					IDMap[$$.label].type = IDMap[$1.label].type;
					$$.traduction += "\t" + $$.label + " = " + $1.label + " " + $2.traduction + " " + $3.label + ";\n";
					declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
				}
				else
				{
					keyOperating = defineKeyOperating(IDMap[$1.label], IDMap[$3.label], $2.traduction);

					IDMap[keyOperating->label].label = keyOperating->label;
					IDMap[keyOperating->label].type = keyOperating->type;
					IDMap[$$.label].type = keyOperating->type;


					if(keyOperating->type == IDMap[$1.label].type)
					{
						weakOperating = &(IDMap[$3.label]);
						strongOperating = &(IDMap[$1.label]);
	
						$$.traduction += "\t" + keyOperating->label + " = (" + keyOperating->type + ") " + weakOperating->label + ";\n";
						$$.traduction += "\t" + $$.label + " = " + keyOperating->label + " " + $2.traduction + " " + strongOperating->label + ";\n";
					}
					else
					{
						weakOperating = &(IDMap[$1.label]);
						strongOperating = &(IDMap[$3.label]);

						$$.traduction += "\t" + keyOperating->label + " = (" + keyOperating->type + ") " + weakOperating->label + ";\n";
						$$.traduction += "\t" + $$.label + " = " + strongOperating->label + " " + $2.traduction + " " + keyOperating->label + ";\n";
					}

					declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
					declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
				}

			}
			| E RELATIONAL_OPERATION E
			{
				

			}
			| E BIN_OPERATION E
			{


			}
			| TK_INT
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "int";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_FLOAT
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "float";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_SCIENTIFIC
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "float"; //poderia ser double

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_CHAR
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "char";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_STRING
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "string";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_BOOL
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "bool";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_ID
			{
				if(IDMap.find($1.label) == IDMap.end())	
					yyerror("identifier: '" + $1.label + "' not declared.");

				//$$.label = IDMap[$1.label].label;
				//$$.type = IDMap[$1.label].type;
				$$.traduction = "";
			}
			| ATRIBUITION
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
			}
			;


ATRIBUITION	: TK_ID TK_ASSIGN E
			{
				if(IDMap.find($1.label) == IDMap.end())	
					yyerror("identifier: '" + $1.label + "' not declared.");

				string cast = "";

				if (IDMap[$3.label].type != IDMap[$1.label].type)
				{
					//aqui deve-se verificar quais casts são possíveis
					cast = "(" + IDMap[$1.label].type + ") ";
				}

				$$.label = IDMap[$1.label].label;
				$$.traduction = $3.traduction + "\t" + $$.label + " = " + cast + $3.label + ";\n"; 
			}


LE			: LE LOGIC_OPERATION LE
			{
				
			}
			| TK_BOOL
			{

			}
			| TK_OP_LOGIC_NOT TK_BOOL
			{

			}


ARITHMETIC_OPERATION	: TK_OP_SUM | TK_OP_SUB | TK_OP_DIV | TK_OP_MUL | TK_OP_MOD
						;


RELATIONAL_OPERATION	: TK_OP_REL_LESS | TK_OP_REL_GREATER | TK_OP_REL_EQLESS | TK_OP_REL_EQGREATER | TK_OP_REL_EQ | TK_OP_REL_DIFF
						;
						


LOGIC_OPERATION 		: TK_OP_LOGIC_OR | TK_OP_LOGIC_AND
						;



BIN_OPERATION			: TK_OP_BIN_AND | TK_OP_BIN_OR | TK_OP_BIN_XOR | TK_OP_BIN_NOT | TK_OP_BIN_SHIFTR | TK_OP_BIN_SHIFTL
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

string generateLabel()
{
	static int counter = 0;
	stringstream label;

	label << "_temp" << counter++;

	return label.str();
}					

id_struct* defineKeyOperating(id_struct op1, id_struct op2, string sOperator)
{
	id_struct* keyOperating = new id_struct;
	operation_struct ops;

	ops.op1Type = op1.type;
	ops.op2Type = op2.type;
	ops.sOperator = sOperator;

	if(operationsMap.find(ops) == operationsMap.end())
	{		
		ops.op1Type = op2.type;
		ops.op2Type = op1.type;

		if(operationsMap.find(ops) == operationsMap.end())
			yyerror("operation types: '" + op1.type + " " + sOperator + " " + op2.type + "' not defined.");
	}
	
	keyOperating->label = generateLabel();
	keyOperating->type = operationsMap[ops];

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
	ops->op2Type = "char";
	ops->sOperator = "-";
	operationsMap[*ops] = "int";

	ops = new operation_struct;
	ops->op1Type = "char";
	ops->op2Type = "float";
	ops->sOperator = "-";
	operationsMap[*ops] = "float";		


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
	ops->op2Type = "char";
	ops->sOperator = "*";
	operationsMap[*ops] = "int";

	ops = new operation_struct;
	ops->op1Type = "char";
	ops->op2Type = "float";
	ops->sOperator = "*";
	operationsMap[*ops] = "float";		

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
	ops->op2Type = "char";
	ops->sOperator = "/";
	operationsMap[*ops] = "int";

	ops = new operation_struct;
	ops->op1Type = "char";
	ops->op2Type = "float";
	ops->sOperator = "/";
	operationsMap[*ops] = "float";		

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
	operationsMap[*ops] = "char";	

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
	operationsMap[*ops] = "char";	

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
	operationsMap[*ops] = "char";	

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
	operationsMap[*ops] = "char";	

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
	operationsMap[*ops] = "char";	

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
