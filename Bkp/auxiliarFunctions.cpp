#include "auxiliarFunctions.h"

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

id_struct* defineKeyOperating(string op1Type, string op1Modifier, string op2Type, string op2Modifier)
{
	id_struct* keyOperating = new id_struct;
	
	keyOperating->label = generateLabel();

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
