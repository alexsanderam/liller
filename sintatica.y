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
int block = 0;

struct args
{
	string label;
	string traduction;
};

int yylex(void);
void yyerror(string);

string generateLabel();

%}

%token TK_INT TK_FLOAT TK_SCIENTIFIC TK_CHAR TK_STRING
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

BLOCK		: '{' DECLARATIONS COMMANDS BLOCK RETURN '}'
			{
				//$$.traduction = "\n{\n" + $2.traduction + $3.traduction + $4.traduction + $5.traduction + "\n}";
				$$.traduction = "\n{\n" + declarations + "\n" + $3.traduction + $4.traduction + $5.traduction + "\n}";
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

DECLARATIONS	: DECLARATION  DECLARATIONS
			{
				$$.traduction = $1.traduction + $2.traduction;
				declarations = $$.traduction;
			}
			|
			{	
				$$.traduction = "\n";
			}	
			;

DECLARATION	: TYPE TK_ID ';'
			{
				if(IDMap.find($2.label) == IDMap.end())
				{
					IDMap[$2.label].label = generateLabel();
					IDMap[$2.label].type = $1.traduction;
				}

				$$.label = IDMap[$2.label].label;
				$$.traduction = "\t" + $1.traduction + " " + IDMap[$2.label].label + ";\n";
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
			| DECLARATION
			;


E 			: E ARITHMETIC_OPERATION E
			{
				string cast = "";
				$$.label = generateLabel();
				IDMap[$$.label].label = $$.label;

				if((IDMap[$1.label].type == "int") && (IDMap[$3.label].type == "int"))
				{
					IDMap[$$.label].type = "int";
					cast = "(int) ";
				}
				else if (((IDMap[$1.label].type == "int") && (IDMap[$3.label].type == "float")) || ((IDMap[$1.label].type == "float") && (IDMap[$3.label].type == "int")))
				{
					IDMap[$$.label].type = "float";
					cast = "(float) ";
				}
				else if (((IDMap[$1.label].type == "int") && (IDMap[$3.label].type == "char")) || ((IDMap[$1.label].type == "char") && (IDMap[$3.label].type == "int")))
				{
					IDMap[$$.label].type = "int";
					cast = "(int) ";
				}
				else if (((IDMap[$1.label].type == "int") && (IDMap[$3.label].type == "string")) || ((IDMap[$1.label].type == "string") && (IDMap[$3.label].type == "int")))
				{
					IDMap[$$.label].type = "string";
					cast = "(string) ";
				}
	
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + cast + $1.label + " " + $2.traduction + " " + $3.label + ";\n";

				declarations += "\t" + IDMap[$$.label].type + " " + IDMap[$$.label].label + ";\n";

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
			| TK_ID
			{
				//if(IDMap.find($1.label) == IDMap.end())	
					//IDMap[$1.label] = generateLabel();

				$$.label = IDMap[$1.label].label;
				$$.traduction = "";
			}
			| TK_ID TK_ASSIGN E
			{
				//if(IDMap.find($1.label) == IDMap.end())	
					//IDMap[$1.label].label = generateLabel();

				string cast = "";

				if (IDMap[$3.label].type != IDMap[$1.label].type)
					cast = "(" + IDMap[$1.label].type + ") ";

				$$.label = IDMap[$1.label].label;
				$$.traduction = $3.traduction + "\t" + $$.label + " = " + cast + $3.label + ";\n"; 
			}
			;

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
