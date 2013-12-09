%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define YYSTYPE args

using namespace std;

<<<<<<< HEAD
typedef struct{
	string type;
	string label;
} id_struct;

typedef map<string, id_struct> VARIABLESMAP;

VARIABLESMAP IDMap;
=======
typedef map<string, string> STRINGMAP;

STRINGMAP labelsMap;
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593

struct args
{
	string label;
	string traduction;
};

int yylex(void);
void yyerror(string);

string generateLabel();

%}

<<<<<<< HEAD
%token TK_INT TK_FLOAT TK_SCIENTIFIC TK_CHAR
%token TK_MAIN 
%token TK_ID 
%token TK_TYPE_CHAR TK_TYPE_STRING TK_TYPE_INT TK_TYPE_VOID TK_TYPE_FLOAT TK_TYPE_DOUBLE TK_TYPE_UNSIGNED TK_TYPE_LONG TK_TYPE_BOOLEAN
=======
%token TK_INT
%token TK_MAIN 
%token TK_ID 
%token TK_TYPE_INT TK_TYPE_VOID
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
%token TK_END TK_ERROR
%token TK_OP_SUM TK_OP_SUB TK_OP_MUL TK_OP_DIV
%token TK_ASSIGN


%start Begin

%left TK_ASSIGN
%left TK_OP_SUM TK_OP_SUB
%left TK_OP_MUL TK_OP_DIV TK_OP_MOD

<<<<<<< HEAD

%%

Begin 		: TK_TYPE_INT TK_MAIN '(' ')' BLOCK
			{
				cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n"  << $5.traduction << "\treturn 0;\n}" << endl; 
=======
%%

Begin 			: TK_TYPE_INT TK_MAIN '(' ')' BLOCK
			{
				cout << "/*Compiler Liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n" << $5.traduction << "\treturn 0;\n}" << endl; 
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
			}
			|
			TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')' BLOCK
			{
<<<<<<< HEAD
			cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n"  << $6.traduction << "\treturn 0;\n}" << endl;
=======
			cout << "/*Compiler Liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $6.traduction << "\treturn 0;\n}" << endl;
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
			}
			;

BLOCK		: '{' COMMANDS '}'
			{
				$$.traduction = $2.traduction;
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
<<<<<<< HEAD
			| 
			DECLARATION ';'
=======
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
			;

E 			: E TK_OP_SUM E
			{
				$$.label = generateLabel();
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
			}
			| E TK_OP_SUB E
			{
				$$.label = generateLabel();
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}
			| E TK_OP_MUL E
			{
				$$.label = generateLabel();
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}
			| E TK_OP_DIV E
			{
				$$.label = generateLabel();
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}
			| E TK_OP_MOD E
			{
				$$.label = generateLabel();
				$$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " % " + $3.label + ";\n";
			}
			| TK_INT
			{
				$$.label = generateLabel();
				$$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";
			}
<<<<<<< HEAD

			| TK_ID
			{
				//if(IDMap.find($1.label) == IDMap.end())	
					//IDMap[$1.label] = generateLabel();

				$$.label = IDMap[$1.label].label;
=======
			| TK_ID
			{
				if(labelsMap.find($1.label) == labelsMap.end())	
					labelsMap[$1.label] = generateLabel();

				$$.label = labelsMap[$1.label];
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
				$$.traduction = "";
			}
			| TK_ID TK_ASSIGN E
			{
<<<<<<< HEAD
				//if(IDMap.find($1.label) == IDMap.end())	
					//IDMap[$1.label].label = generateLabel();

				$$.label = IDMap[$1.label].label;
=======
				if(labelsMap.find($1.label) == labelsMap.end())	
					labelsMap[$1.label] = generateLabel();

				$$.label = labelsMap[$1.label];
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
				$$.traduction = $3.traduction + "\t" + $$.label + " = " + $3.label + ";\n"; 
			}
			;

<<<<<<< HEAD
DECLARATION	: TYPE TK_ID
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
			
TYPE		: TK_TYPE_CHAR | TK_TYPE_STRING | TK_TYPE_INT | TK_TYPE_VOID | TK_TYPE_FLOAT | TK_TYPE_DOUBLE | TK_TYPE_UNSIGNED | TK_TYPE_LONG | TK_TYPE_BOOLEAN
			;
=======
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
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
<<<<<<< HEAD

=======
	
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593
	return label.str();
	
}					
