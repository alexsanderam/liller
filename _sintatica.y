%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE args

using namespace std;

struct args
{
	string label;
	string traduction;
};

int yylex(void);
void yyerror(string);
%}

%token TK_NUM TK_ID 
%token TK_TYPE_INT TK_TYPE_VOID
%token TK_MAIN
%token TK_END TK_ERROR
%token TK_SUM TK_SUB TK_MUL TK_DIV TK_PL TK_PR

%start S

%left TK_SUM TK_SUB 
%left TK_MUL TK_DIV

%%

S 			: TK_TYPE_INT TK_MAIN '(' ')' BLOCK
			{
				cout << "/*Compilador Liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			|
			TK_TIPO_INT TK_MAIN '(' TK_VOID ')' BLOCK
			{
				cout << "/*Compilador Liller*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" 	<< $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCK		: '{' COMANDS '}'
			{
				$$.traduction = $2.traduction;
			}
			;

COMANDS	: COMAND COMANDS
			|
			;

COMAND 	: Exp ';'
			;

Exp 			: Exp TK_SUM Exp
			{
				$$.traduction = $1.traduction + $3.traduction + "\ta = b + c;\n";
			}
			| TK_NUM
			{
				$$.traducao = "\ta = " + $1.traducao + ";\n";
			}
			| TK_ID
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
	static int counter= 0;
	string label = "ltemp" + counter++;
	
	return label;
	
}			
