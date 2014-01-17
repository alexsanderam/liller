#ifndef AUXILIAR_FUNCTIONS_H
#define AUXILIAR_FUNCTIONS_H

	#include <iostream>
	#include <string>
	#include <sstream>
	#include <map>
	#include "lex.yy.c"

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
	int yyparse();
	void yyerror(string);

	string generateLabel();
	string verifyResultOperation(string, string, string);
	id_struct* defineKeyOperating(string, string, string, string);
	string 	verifyStrongType(string, string);
	void loadOpearationsMap(void);

#endif
