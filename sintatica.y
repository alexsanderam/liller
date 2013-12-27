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
string verifyResultOperation(string, string, string);
id_struct* defineKeyOperating(id_struct, id_struct);
string 	verifyStrongType(string, string);
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
%left TK_OP_REL_LESS TK_OP_REL_GREATER TK_OP_REL_EQLESS TK_OP_REL_EQGREATER TK_OP_REL_EQ TK_OP_REL_DIFF
%left TK_OP_BIN_AND TK_OP_BIN_OR TK_OP_BIN_XOR TK_OP_BIN_NOT TK_OP_BIN_SHIFTR TK_OP_BIN_SHIFTL
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


RETURN		: TK_RETURN E ';'
			{
				$$.traduction = $2.traduction + "\n\t" + $1.traduction + " " + $2.label + ";";
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
				$$.modifier = IDMap[$3.label].modifier;

				IDMap[$$.label] = IDMap[$3.label];
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

				if ((IDMap[$5.label].modifier != IDMap[$3.label].modifier) || (IDMap[$5.label].type != IDMap[$3.label].type))
				{
					//aqui deve se verificar quais casts são possíveis.
					cast = "(" + IDMap[$3.label].modifier + (IDMap[$3.label].modifier != "" ? " " : "") + IDMap[$3.label].type + ") ";
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
				$$.modifier = IDMap[$3.label].modifier;

				IDMap[$$.label] = IDMap[$3.label];
							
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
				$$.modifier = IDMap[$2.label].modifier;

				IDMap[$$.label] = IDMap[$2.label];

			}
			| TYPE TK_ID TK_ASSIGN E
			{
				string cast = "";
				string atribuition = "";

				if(IDMap.find($2.label) == IDMap.end())
				{
					IDMap[$2.label].label = generateLabel();
					IDMap[$2.label].type = $1.type;
					IDMap[$2.label].modifier = $1.modifier;
				}
				else
					yyerror("identifier: '" + $2.label + "' already declared.");

				if ((IDMap[$4.label].modifier != IDMap[$2.label].modifier) || (IDMap[$4.label].type != IDMap[$2.label].type))
				{
					//aqui deve se verificar quais casts são possíveis.
					cast = "(" + IDMap[$2.label].modifier + (IDMap[$2.label].modifier != "" ? " " : "") + IDMap[$2.label].type + ") ";
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
				$$.modifier = IDMap[$2.label].modifier;

				IDMap[$$.label] = IDMap[$2.label];
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
			| RELATIONAL_E ';'
			| DECLARATION ';'
			| LOGIC_E ';'
			| ATRIBUITION ';'
			;


E 			: E ARITHMETIC_OPERATION E
			{
				string resultOperationType;
				id_struct* keyOperating;
				id_struct* weakOperating;
				id_struct* strongOperating;

				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;

				$$.traduction = $1.traduction + $3.traduction;

				resultOperationType = verifyResultOperation(IDMap[$1.label].type, IDMap[$3.label].type, $2.traduction);

				/*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
				  mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
			          no momento da atribuição, que deverá se fazer um cast, caso necessário*/

				IDMap[$$.label].type = resultOperationType;
				IDMap[$$.label].modifier = ""; /*desconsidera-se os modificadores*/

				declarations += "\t" + resultOperationType + " " + IDMap[$$.label].label + ";\n";

				if(IDMap[$1.label].type == IDMap[$3.label].type)
				{
					$$.traduction += "\t" + $$.label + " = " + $1.label + " " + $2.traduction + " " + $3.label + ";\n";
				}
				else
				{
					keyOperating = defineKeyOperating(IDMap[$1.label], IDMap[$3.label]);

					IDMap[keyOperating->label].label = keyOperating->label;
					IDMap[keyOperating->label].type = keyOperating->type;
					IDMap[keyOperating->label].modifier = keyOperating->modifier;

					string modifier = keyOperating->modifier;
					modifier += (modifier != "" ? " " : "");

					if(keyOperating->type == IDMap[$1.label].type)
					{
						weakOperating = &(IDMap[$3.label]);
						strongOperating = &(IDMap[$1.label]);

						$$.traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperating->label + ";\n";
						$$.traduction += "\t" + $$.label + " = " + strongOperating->label + " " + $2.traduction + " " + keyOperating->label + ";\n";
					}
					else
					{
						weakOperating = &(IDMap[$1.label]);
						strongOperating = &(IDMap[$3.label]);

						$$.traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperating->label + ";\n";
						$$.traduction += "\t" + $$.label + " = " + keyOperating->label + " " + $2.traduction + " " + strongOperating->label + ";\n";
					}

					declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
				}

			}
			| TK_INT
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "int";
				IDMap[$$.label].modifier = "";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_FLOAT
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "float";
				IDMap[$$.label].modifier = "";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_SCIENTIFIC
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "float"; //poderia ser double
				IDMap[$$.label].modifier = "";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_CHAR
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "char";
				IDMap[$$.label].modifier = "";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_STRING
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "string";
				IDMap[$$.label].modifier = "";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_BOOL
			{
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = "bool";
				IDMap[$$.label].modifier = "";

				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_ID
			{
				if(IDMap.find($1.label) == IDMap.end())	
					yyerror("identifier: '" + $1.label + "' not declared.");

				$$.label = IDMap[$1.label].label;
				$$.type = IDMap[$1.label].type;
				$$.modifier = IDMap[$1.label].modifier;
				$$.traduction = "";
			}
			| '(' E ')'
			{
				$$.traduction = $2.traduction;
				$$.label = $2.label;
				$$.type = $2.type;
				$$.modifier = $2.modifier;
			}
			;


ATRIBUITION	: TK_ID TK_ASSIGN ATRIBUITION
		{
			if(IDMap.find($1.label) == IDMap.end())	
				yyerror("identifier: '" + $1.label + "' not declared.");

			string cast = "";

			if (((IDMap[$3.label].modifier != IDMap[$1.label].modifier)) || (IDMap[$3.label].type != IDMap[$1.label].type))
			{

				//aqui deve-se verificar quais casts são possíveis
				if(IDMap[$1.label].modifier != "")
					cast = "(" + IDMap[$1.label].modifier + " " + IDMap[$1.label].type + ") ";
				else
					cast += "(" + IDMap[$1.label].type + ") ";
			}

			$$.label = IDMap[$1.label].label;
			$$.traduction = $3.traduction + "\t" + $$.label + " = " + cast + $3.label + ";\n"; 
			$$.type = $1.type;
			$$.modifier = $1.modifier;
		}
		| E
		{
			$$.traduction = $1.traduction;
			$$.label = $1.label;
			$$.type = $1.type;
			$$.modifier = $1.modifier;
		}
		| RELATIONAL_E
		{
			$$.traduction = $1.traduction;
			$$.label = $1.label;
			$$.type = $1.type;
			$$.modifier = $1.modifier;
		}
		| LOGIC_E
		{
			$$.traduction = $1.traduction;
			$$.label = $1.label;
			$$.type = $1.type;
			$$.modifier = $1.modifier;
		}
		;


RELATIONAL_E 	: OPERAND RELATIONAL_OPERATION OPERAND
			{
				string resultOperationType;
				id_struct* keyOperating;
				id_struct* weakOperating;
				id_struct* strongOperating;

				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;

				$$.traduction = $1.traduction + $3.traduction;

				resultOperationType = verifyResultOperation(IDMap[$1.label].type, IDMap[$3.label].type, $2.traduction);

				/*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
				  mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
				  no momento da atribuição, que deverá se fazer um cast, caso necessário*/

				IDMap[$$.label].type = resultOperationType;
				IDMap[$$.label].modifier = ""; /*desconsidera-se os modificadores*/

				declarations += "\t" + resultOperationType + " " + IDMap[$$.label].label + ";\n";

				if(IDMap[$1.label].type == IDMap[$3.label].type)
				{
					$$.traduction += "\t" + $$.label + " = " + $1.label + " " + $2.traduction + " " + $3.label + ";\n";
				}
				else
				{
					keyOperating = defineKeyOperating(IDMap[$1.label], IDMap[$3.label]);

					IDMap[keyOperating->label].label = keyOperating->label;
					IDMap[keyOperating->label].type = keyOperating->type;
					IDMap[keyOperating->label].modifier = keyOperating->modifier;

					string modifier = keyOperating->modifier;
					modifier += (modifier != "" ? " " : "");

					if(keyOperating->type == IDMap[$1.label].type)
					{
						weakOperating = &(IDMap[$3.label]);
						strongOperating = &(IDMap[$1.label]);

						$$.traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperating->label + ";\n";
						$$.traduction += "\t" + $$.label + " = " + strongOperating->label + " " + $2.traduction + " " + keyOperating->label + ";\n";
					}
					else
					{
						weakOperating = &(IDMap[$1.label]);
						strongOperating = &(IDMap[$3.label]);

						$$.traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperating->label + ";\n";
						$$.traduction += "\t" + $$.label + " = " + keyOperating->label + " " + $2.traduction + " " + strongOperating->label + ";\n";
					}

					declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
				}

			}
			| '(' RELATIONAL_E ')'
			{
				$$.traduction = $2.traduction;
				$$.label = $2.label;
				$$.type = $2.type;
				$$.modifier = $2.modifier;
			}
			;


OPERAND			: E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
			| '(' ATRIBUITION ')'
			{
				$$.traduction = $2.traduction;
				$$.label = $2.label;
				$$.type = $2.type;
				$$.modifier = $2.modifier;			
			}
			;
			


LOGIC_E			: LOGIC_E LOGIC_OPERATION LOGIC_E
			{
				$$.label = generateLabel();
				$$.type = "bool";
				$$.modifier = "";
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " " + $2.traduction + " " + $3.label;

				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = $$.type;
				IDMap[$$.label].type = $$.modifier;


				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| '(' LOGIC_E LOGIC_OPERATION LOGIC_E ')'
			{
				$$.label = generateLabel();
				$$.type = "bool";
				$$.modifier = "";
				$$.traduction = $2.traduction + $4.traduction + "\t" + $$.label + " = " + $2.label + " " + $3.traduction + " " + $4.label;

				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = $$.type;
				IDMap[$$.label].type = $$.modifier;

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_BOOL
			{
				$$.label = generateLabel();
				$$.type = "bool";
				$$.modifier = "";
				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";				

				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = $$.type;
				IDMap[$$.label].type = $$.modifier;

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";
			}
			| TK_OP_LOGIC_NOT LOGIC_E
			{
				$$.label = generateLabel();
				$$.type = "bool";
				$$.modifier = "";
				$$.traduction = $2.traduction + "\t" + $$.label + " = " + $1.traduction + " " + $2.label + ";\n";				

				IDMap[$$.label].label = $$.label;
				IDMap[$$.label].type = $$.type;
				IDMap[$$.label].type = $$.modifier;

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";				
			}
			;


ARITHMETIC_OPERATION	: TK_OP_SUM | TK_OP_SUB | TK_OP_DIV | TK_OP_MUL | TK_OP_MOD
				;


RELATIONAL_OPERATION	: TK_OP_REL_LESS | TK_OP_REL_GREATER | TK_OP_REL_EQLESS | TK_OP_REL_EQGREATER | TK_OP_REL_EQ | TK_OP_REL_DIFF
				;
						


LOGIC_OPERATION 	: TK_OP_LOGIC_OR | TK_OP_LOGIC_AND
				;



BIN_OPERATION		: TK_OP_BIN_AND | TK_OP_BIN_OR | TK_OP_BIN_XOR | TK_OP_BIN_NOT | TK_OP_BIN_SHIFTR | TK_OP_BIN_SHIFTL
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

id_struct* defineKeyOperating(id_struct op1, id_struct op2)
{
	id_struct* keyOperating = new id_struct;
	
	keyOperating->label = generateLabel();

	keyOperating->type = verifyStrongType(op1.type, op2.type);

	if(keyOperating->type == op1.type)
		keyOperating->modifier = op1.modifier;
	else
		keyOperating->modifier = op2.modifier;

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

string 	verifyStrongType(string op1Type, string op2Type)
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
