%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define YYSTYPE args

using namespace std;

typedef map<string, string> STRINGMAP;

STRINGMAP labelsMap;

struct args
{
	string label;
	string traduction;
};

int yylex(void);
void yyerror(string);

string generateLabel();

%}

%token TK_INT
%token TK_MAIN 
%token TK_ID 
%token TK_TYPE_INT TK_TYPE_VOID
%token TK_END TK_ERROR
%token TK_OP_SUM TK_OP_SUB TK_OP_MUL TK_OP_DIV
%token TK_ASSIGN


%start Begin

%left TK_ASSIGN
%left TK_OP_SUM TK_OP_SUB
%left TK_OP_MUL TK_OP_DIV TK_OP_MOD

%%

Begin 			: TK_TYPE_INT TK_MAIN '(' ')' BLOCK
			{
				cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n" << $5.traduction << "\treturn 0;\n}" << endl; 
			}
			|
			TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')' BLOCK
			{
			cout << "/*Compiler prescot-liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $6.traduction << "\treturn 0;\n}" << endl;
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
			| TK_ID
			{
				if(labelsMap.find($1.label) == labelsMap.end())	
					labelsMap[$1.label] = generateLabel();

				$$.label = labelsMap[$1.label];
				$$.traduction = "";
			}
			| TK_ID TK_ASSIGN E
			{
				if(labelsMap.find($1.label) == labelsMap.end())	
					labelsMap[$1.label] = generateLabel();

				$$.label = labelsMap[$1.label];
				$$.traduction = $3.traduction + "\t" + $$.label + " = " + $3.label + ";\n"; 
			}
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
