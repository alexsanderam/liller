%{
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

%}

%token TK_INT TK_FLOAT TK_SCIENTIFIC TK_CHAR TK_STRING TK_BOOL
%token TK_TRUE TK_FALSE
%token TK_MAIN 
%token TK_ID 
%token TK_TYPE_CHAR TK_TYPE_STRING TK_TYPE_INT TK_TYPE_VOID TK_TYPE_FLOAT TK_TYPE_DOUBLE TK_TYPE_BOOLEAN
%token TK_MODIFIER_UNSIGNED TK_MODIFIER_SIGNED TK_MODIFIER_SHORT TK_MODIFIER_LONG
%token TK_END TK_ERROR
%token TK_OP_SUM TK_OP_SUB TK_OP_MUL TK_OP_DIV
%token TK_ASSIGN
%token TK_RETURN


%start Begin

%left TK_ASSIGN
%left TK_OP_SUM TK_OP_SUB
%left TK_OP_MUL TK_OP_DIV TK_OP_MOD


%%

Begin 		: TK_TYPE_INT TK_MAIN '(' ')' BLOCK
			{
				cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()"  << $5.traduction << endl; 
			}
			|
			TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')' BLOCK
			{
			cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)"  << $6.traduction << endl;
			}
			;

BLOCK		: '{' COMMANDS BLOCK RETURN '}'
			{
				//$$.traduction = "\n{\n" + $2.traduction + $3.traduction + $4.traduction + "\n}";
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
				}

				$$.label = IDMap[$3.label].label;
				$$.traduction = $1.traduction + "\t" + IDMap[$3.label].type + " " + IDMap[$3.label].label + ";\n";
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
				}

				if (IDMap[$5.label].type != IDMap[$3.label].type)
					cast = "(" + IDMap[$3.label].type + ") ";

				atribuition = $5.traduction + "\t" + IDMap[$3.label].label + " = " + cast + $5.label + ";\n";


				$$.label = IDMap[$3.label].label;
				$$.traduction = $1.traduction + "\t" + IDMap[$3.label].type + " " + IDMap[$3.label].label + ";\n\n" + atribuition + "\n";
				$$.type = IDMap[$3.label].type;	
							
			}
			| TYPE TK_ID
			{

				if(IDMap.find($2.label) == IDMap.end())
				{
					IDMap[$2.label].label = generateLabel();
					IDMap[$2.label].type = $1.traduction;
				}

				$$.label = IDMap[$2.label].label;
				$$.traduction = "\t" + IDMap[$2.label].type + " " + IDMap[$2.label].label + ";\n";
				$$.type = IDMap[$2.label].type;

			}
			| TYPE TK_ID TK_ASSIGN E
			{
				string cast = "";
				string atribuition = "";

				if(IDMap.find($2.label) == IDMap.end())
				{
					IDMap[$2.label].label = generateLabel();
					IDMap[$2.label].type = $1.traduction;
				}

				if (IDMap[$4.label].type != IDMap[$2.label].type)
					cast = "(" + IDMap[$2.label].type + ") ";

				atribuition = $4.traduction + "\t" + IDMap[$2.label].label + " = " + cast + $4.label + ";\n";


				$$.label = IDMap[$2.label].label;
				$$.traduction = "\t" + IDMap[$2.label].type + " " + IDMap[$2.label].label + ";\n\n" + atribuition + "\n";
				$$.type = IDMap[$2.label].type;

			}
			;

			
TYPE		: TK_TYPE_CHAR | TK_TYPE_STRING | TK_TYPE_INT | TK_TYPE_VOID | TK_TYPE_FLOAT | TK_TYPE_DOUBLE | TK_TYPE_BOOLEAN
			|
			TK_MODIFIER_UNSIGNED TK_TYPE_CHAR
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}
			| TK_MODIFIER_SIGNED TK_TYPE_CHAR
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}
			| TK_MODIFIER_UNSIGNED TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}			
			| TK_MODIFIER_SIGNED TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}
			| TK_MODIFIER_SHORT TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}
			| TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}
			| TK_MODIFIER_LONG TK_TYPE_DOUBLE
			{
				$$.traduction = $1.traduction + " " + $2.traduction;
			}
			| TK_MODIFIER_SHORT | TK_MODIFIER_LONG
			{
				$$.traduction = $1.traduction + " int";
			}
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_SHORT TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction;
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_SHORT TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction;
			}
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction;
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction;
			}
			| TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction;
			}
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction + " " + $4.traduction;
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction + " " + $4.traduction;
			}			
			| TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction + " int";
			}
			| TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
			{
				$$.traduction = $1.traduction + " " + $2.traduction + " " + $3.traduction + " int";
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
				declarations += $1.traduction;
				$$.traduction = "";
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
					keyOperating = defineKeyOperating(IDMap[$1.label], IDMap[$3.label]);

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
				//if(IDMap.find($1.label) == IDMap.end())	
					//IDMap[$1.label] = generateLabel();

				$$.label = IDMap[$1.label].label;
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
					IDMap[$1.label].label = generateLabel();

				string cast = "";

				if (IDMap[$3.label].type != IDMap[$1.label].type)
					cast = "(" + IDMap[$1.label].type + ") ";

				$$.label = IDMap[$1.label].label;
				$$.traduction = $3.traduction + "\t" + $$.label + " = " + cast + $3.label + ";\n"; 
			}



ARITHMETIC_OPERATION	: TK_OP_SUM | TK_OP_SUB | TK_OP_DIV | TK_OP_MUL | TK_OP_MOD
			;

%%

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
