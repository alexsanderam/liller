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

typedef struct
{
        string dIType; /*tipo com modificador das variáveis intermediárias*/
        //string label;
	unsigned int size; /*nos casos de string*/
} variable_declaratino_struct;


map<string, id_struct> IDMap;
map<string, variable_declaratino_struct> declarationsMap;

map<operation_struct, string> operationsMap;

//string declarations = "";
string voidStr = "";

bool error = false; /*flag utilizado para identificar se tem algum erro de compilação ou não*/

int yylex(void);
void yyerror(string);

YYSTYPE runBasicOperation(YYSTYPE, YYSTYPE, YYSTYPE);
YYSTYPE assigns(string, YYSTYPE, YYSTYPE);
string generateLabel();
string normalizedType(string);
void declare(string, string, unsigned int);
string declarations();
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



%start Begin

%left TK_ASSIGN
%left TK_OP_LOGIC_OR TK_OP_LOGIC_AND
%nonassoc TK_OP_REL_EQ TK_OP_REL_DIFF
%nonassoc TK_OP_REL_LESS TK_OP_REL_GREATER TK_OP_REL_EQLESS TK_OP_REL_EQGREATER
%left TK_OP_BIN_AND TK_OP_BIN_OR TK_OP_BIN_XOR TK_OP_BIN_SHIFTR TK_OP_BIN_SHIFTL
%left TK_OP_SUM 
%left TK_OP_SUB
%left TK_OP_MUL TK_OP_DIV TK_OP_MOD
%left TK_OP_LOGIC_NOT
%left TK_OP_BIN_NOT


%%

Begin                 : TK_TYPE_INT TK_MAIN '(' TK_TYPE_VOID ')' BLOCK
                        {
                                if(!error)
                                        cout << "/*Compiler prescot-liller*/\n\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing namespace std;\n int main(void)" << $6.traduction << endl;
                                else
                                        exit(1);
                        }
			| TK_TYPE_INT TK_MAIN '(' ')' BLOCK
                        {
                                if(!error)                                
                                        cout << "/*Compiler prescot-liller*/\n\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\nusing namespace std;\nint main()" << $5.traduction << endl;
                                else
                                        exit(1);
                        }
                        ;



BLOCK                : '{' COMMANDS BLOCK RETURN '}'
                        {
                                $$.traduction = "\n{\n" + declarations() + "\n" + $2.traduction + $3.traduction + $4.traduction + "\n}";
                        }
                        |
                        {
                                $$.traduction = "";
                        }
                        ;



RETURN                : TK_RETURN E ';'
                        {
                                $$.traduction = $2.traduction + "\n\t" + $1.traduction + " " + $2.label + ";";
                        }
                        |
                        {
                                $$.traduction = "";
                        }
                        ;



DECLARATION        : DECLARATION ',' TK_ID
                        {
				
				if(IDMap.find($3.label) == IDMap.end())
                                {
                                        IDMap[$3.label].label = generateLabel();
                                        IDMap[$3.label].type = $1.type;
                                        IDMap[$3.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");


                                /*if(IDMap[$3.label].modifier != "")
                                        declarations += "\t" + IDMap[$3.label].modifier + " ";
                                else
                                        declarations += "\t";

                                declarations += IDMap[$3.label].type + " " + IDMap[$3.label].label + ";\n";*/
                                
                                $$.label = IDMap[$3.label].label;
                                $$.traduction = $1.traduction;
                                $$.type = IDMap[$3.label].type;
                                $$.modifier = IDMap[$3.label].modifier;

				if ($$.modifier != "")
					declare($$.label, $$.modifier + " " + $$.type, 1);
				else
					declare($$.label, $$.type, 1);

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
                                        yyerror("identifier: '" + $3.label + "'  previously declared here.");

                                /*if (($5.modifier != IDMap[$3.label].modifier) || ($5.type != IDMap[$3.label].type))
                                {
                                        //aqui deve se verificar quais casts são possíveis.
                                        cast = "(" + IDMap[$3.label].modifier + (IDMap[$3.label].modifier != "" ? " " : "") + IDMap[$3.label].type + ") ";
                                }*/

                                atribuition = $5.traduction + "\t" + IDMap[$3.label].label + " = " + cast + $5.label + ";\n";

                                /*if(IDMap[$3.label].modifier != "")
                                        //declarations += "\t" + IDMap[$3.label].modifier + " ";
                                else
                                        //declarations += "\t";

                                declarations += IDMap[$3.label].type + " " + IDMap[$3.label].label + ";\n";*/

                                /*$$.label = IDMap[$3.label].label;
                                $$.traduction = "\n" + atribuition + "\n";
                                $$.type = IDMap[$3.label].type;        
                                $$.modifier = IDMap[$3.label].modifier;*/
			

				$$ = assigns($1.traduction, $3, $5);

				if ($$.modifier != "")
					declare($$.label, $$.modifier + " " + $$.type, 1);
				else
					declare($$.label, $$.type, 1);
                                                        
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
                                        yyerror("identifier: '" + $2.label + "'  previously declared here.");

                                /*if(IDMap[$2.label].modifier != "")
                                        declarations += "\t" + IDMap[$2.label].modifier + " ";
                                else
                                        declarations += "\t";


                                declarations += IDMap[$2.label].type + " " + IDMap[$2.label].label + ";\n";*/

                                $$.label = IDMap[$2.label].label;
                                $$.traduction = "";
                                $$.type = IDMap[$2.label].type;
                                $$.modifier = IDMap[$2.label].modifier;


				if ($$.modifier != "")
					declare($$.label, $$.modifier + " " + $$.type, 1);
				else
					declare($$.label, $$.type, 1);

                        }
                        | TYPE TK_ID TK_ASSIGN E
                        {
                                //string cast = "";
                                //string atribuition = "";

                                if(IDMap.find($2.label) == IDMap.end())
                                {
                                        IDMap[$2.label].label = generateLabel();
                                        IDMap[$2.label].type = $1.type;
                                        IDMap[$2.label].modifier = $1.modifier;
                                }
                                else
                                        yyerror("identifier: '" + $2.label + "'  previously declared here.");

                                /*if (($4.modifier != IDMap[$2.label].modifier) || ($4.type != IDMap[$2.label].type))
                                {
                                        //aqui deve se verificar quais casts são possíveis.
                                        cast = "(" + IDMap[$2.label].modifier + (IDMap[$2.label].modifier != "" ? " " : "") + IDMap[$2.label].type + ") ";
                                }

                                atribuition = $4.traduction + "\t" + IDMap[$2.label].label + " = " + cast + $4.label + ";\n";*/


                               /* if(IDMap[$2.label].modifier != "")
                                        declarations += "\t" + IDMap[$2.label].modifier + " ";
                                else
                                        declarations += "\t";


                                declarations += IDMap[$2.label].type + " " + IDMap[$2.label].label + ";\n";*/

                                /*$$.label = IDMap[$2.label].label;
                                $$.traduction = "\n" + atribuition + "\n";
                                $$.type = IDMap[$2.label].type;
                                $$.modifier = IDMap[$2.label].modifier;*/

				$$ = assigns(voidStr, $2, $4);


				if ($$.modifier != "")
					declare($$.label, $$.modifier + " " + $$.type, 1);
				else
					declare($$.label, $$.type, 1);

                        }
                        ;

                        
TYPE                	: TK_TYPE_CHAR
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
                        | TK_TYPE_BOOL
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
                                $$.modifier = $1.traduction + " " + $2.traduction + " " + $3.traduction;
                                $$.traduction = "";
                        }
                        | TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG TK_TYPE_INT
                        {
                                $$.type = $4.traduction;
                                $$.modifier = $1.traduction + " " + $2.traduction + " " + $3.traduction;
                                $$.traduction = "";
                        }                        
                        | TK_MODIFIER_UNSIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
                        {
                                $$.type = "int";
                                $$.modifier = $1.traduction + " " + $2.traduction + " " + $3.traduction;
                                $$.traduction = "";
                        }
                        | TK_MODIFIER_SIGNED TK_MODIFIER_LONG TK_MODIFIER_LONG
                        {
                                $$.type = "int";
                                $$.modifier = $1.traduction + " " + $2.traduction + " " + $3.traduction;
                                $$.traduction = "";
                        }
                        ;



TERMINAL        :       TK_INT
                        {
                                $$.label = generateLabel();
                                $$.type = "int";
                                $$.modifier = "";
 

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);

                        }
                        | TK_FLOAT
                        {
                                $$.label = generateLabel();
                                $$.type = "float";
                                $$.modifier = "";
  
                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | TK_SCIENTIFIC
                        {
                                $$.label = generateLabel();
                                $$.type = "float"; //poderia ser double
                                $$.modifier = "";
          

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | TK_CHAR
                        {
                                $$.label = generateLabel();
                                $$.type = "char";
                                $$.modifier = "";
              

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";                                

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
			| SIGNAL TK_INT
                        {
                                $$.label = generateLabel();
                                $$.type = "int";
                                $$.modifier = "";
 

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + $2.traduction + ";\n";

                               // declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_FLOAT
                        {
                                $$.label = generateLabel();
                                $$.type = "float";
                                $$.modifier = "";
  
                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + $2.traduction + ";\n";

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_SCIENTIFIC
                        {
                                $$.label = generateLabel();
                                $$.type = "float"; //poderia ser double
                                $$.modifier = "";
          

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + $2.traduction + ";\n";

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | SIGNAL TK_CHAR
                        {
                                $$.label = generateLabel();
                                $$.type = "char";
                                $$.modifier = "";
              

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + $2.traduction + ";\n";                                

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | TK_STRING
                        {
                                $$.label = generateLabel();
                                $$.type = "string";
                                $$.modifier = "";

                                $$.traduction = "\t" + $$.label + " = " + $1.traduction + ";\n";                                

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | TK_BOOL
                        {
                                $$.label = generateLabel();
                                $$.type = "bool";
                                $$.modifier = "";

				if ($1.traduction == "true")			
	                                $$.traduction = "\t" + $$.label + " = 1;\n"; /*true*/
				else
	                                $$.traduction = "\t" + $$.label + " = 0;\n"; /*false*/

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
                        }
                        | TK_ID
                        {
                                if(IDMap.find($1.label) == IDMap.end())        
                                        yyerror("identifier: '" + $1.label + "'  was not declared in this scope.");

                                $$.label = IDMap[$1.label].label;
                                $$.type = IDMap[$1.label].type;
                                $$.modifier = IDMap[$1.label].modifier;
                                $$.traduction = "";
                        }
                        ;


SIGNAL		:	TK_OP_SUM | TK_OP_SUB
			;


COMMANDS        : 	COMMAND COMMANDS
                        {
                                $$.traduction = $1.traduction + "\n" + $2.traduction;
                        }
                        |
                        {
                                $$.traduction = "";
                        }
			;


COMMAND         : 	E ';'        
                        | DECLARATION ';'
			| COUT ';'
                        ;


E                       :'(' E ')'
			{
                             	$$.traduction = $2.traduction;
                                $$.label = $2.label;
                                $$.type = $2.type;
                                $$.modifier = $2.modifier;        	
			}
			| SUM_E
                        {
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
			| SUB_E
                        {
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
			| MUL_DIV_E
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
			| NOT_LOGIC_E
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
                        | BIN_E
                        {
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
			| BITWISE_E
			{
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
			}
                        | TERMINAL
                        {
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
			| ATRIBUITION
			{
                            	$$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
			}
			;


SUM_E        : SUM_OPERAND TK_OP_SUM SUM_OPERAND
		{
			$$ = runBasicOperation($1, $3, $2);
		}
		;


SUM_OPERAND	   : TERMINAL
		    {
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
		    }
		    | SUM_E
		    {
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
		    }
		    | SUB_E
		    {
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
		    }
		    | MUL_DIV_E
		    {
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
		    }
		    | NOT_LOGIC_E
		    {
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
		    }
		    | BITWISE_E
		    {
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
		    }
		    | '(' E ')'
		    {
			    $$.traduction = $2.traduction;
			    $$.label = $2.label;
			    $$.type = $2.type;
			    $$.modifier = $2.modifier;                        
		    }  
		    ;


SUB_E	        : SUB_OPERAND TK_OP_SUB SUB_OPERAND
		{
			$$ = runBasicOperation($1, $3, $2);
		}
		;

		

SUB_OPERAND	   : TERMINAL
                    {
                            $$.traduction = $1.traduction;
                            $$.label = $1.label;
                            $$.type = $1.type;
                            $$.modifier = $1.modifier;
                    }
                    | SUB_E
                    {
                            $$.traduction = $1.traduction;
                            $$.label = $1.label;
                            $$.type = $1.type;
                            $$.modifier = $1.modifier;
                    }
                    | MUL_DIV_E
                    {
                            $$.traduction = $1.traduction;
                            $$.label = $1.label;
                            $$.type = $1.type;
                            $$.modifier = $1.modifier;
                    }
                    | NOT_LOGIC_E
                    {
                            $$.traduction = $1.traduction;
                            $$.label = $1.label;
                            $$.type = $1.type;
                            $$.modifier = $1.modifier;
                    }
                    | BITWISE_E
                    {
                            $$.traduction = $1.traduction;
                            $$.label = $1.label;
                            $$.type = $1.type;
                            $$.modifier = $1.modifier;
                    }
                    | '(' E ')'
                    {
                            $$.traduction = $2.traduction;
                            $$.label = $2.label;
                            $$.type = $2.type;
                            $$.modifier = $2.modifier;                        
                    }  
                    ;


MUL_DIV_E			: MUL_DIV_OPERAND TK_OP_MUL MUL_DIV_OPERAND
				{
					$$ = runBasicOperation($1, $3, $2);
				}
				| MUL_DIV_OPERAND TK_OP_DIV MUL_DIV_OPERAND
				{
					$$ = runBasicOperation($1, $3, $2);
				}
				| MUL_DIV_OPERAND TK_OP_MOD MUL_DIV_OPERAND
				{
					$$ = runBasicOperation($1, $3, $2);
				}
				;


MUL_DIV_OPERAND		    	   : TERMINAL
		                    {
		                            $$.traduction = $1.traduction;
		                            $$.label = $1.label;
		                            $$.type = $1.type;
		                            $$.modifier = $1.modifier;
		                    }
		                    | MUL_DIV_E
		                    {
		                            $$.traduction = $1.traduction;
		                            $$.label = $1.label;
		                            $$.type = $1.type;
		                            $$.modifier = $1.modifier;
		                    }
		                    | NOT_LOGIC_E
		                    {
		                            $$.traduction = $1.traduction;
		                            $$.label = $1.label;
		                            $$.type = $1.type;
		                            $$.modifier = $1.modifier;
		                    }
		                    | BITWISE_E
		                    {
		                            $$.traduction = $1.traduction;
		                            $$.label = $1.label;
		                            $$.type = $1.type;
		                            $$.modifier = $1.modifier;
		                    }
		                    | '(' E ')'
		                    {
		                            $$.traduction = $2.traduction;
		                            $$.label = $2.label;
		                            $$.type = $2.type;
		                            $$.modifier = $2.modifier;                        
		                    }  
		                    ;



LOGIC_E                : LOGIC_OPERAND LOGIC_OPERATION LOGIC_OPERAND
                        {
                                $$.label = generateLabel();
                                $$.type = "bool";
                                $$.modifier = "";
                                $$.traduction = $1.traduction + $3.traduction + "\t" + $$.label + " = " + $1.label + " " + $2.traduction + " " + $3.label + ";\n";

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
				//$$ = runBasicOperation($1, $2, $2);
                        }
			;


LOGIC_OPERAND          : TERMINAL
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
		        | RELATIONAL_E
		        {
		                $$.traduction = $1.traduction;
		                $$.label = $1.label;
		                $$.type = $1.type;
		                $$.modifier = $1.modifier;
		        }
			| NOT_LOGIC_E
			{
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
			}
			| BITWISE_E
			{
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
			}
		        | BIN_E
		        {
		                $$.traduction = $1.traduction;
		                $$.label = $1.label;
		                $$.type = $1.type;
		                $$.modifier = $1.modifier;
		        }
			| SUM_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
		        | '(' E ')'
		        {
		                $$.traduction = $2.traduction;
		                $$.label = $2.label;
		                $$.type = $2.type;
		                $$.modifier = $2.modifier;                        
		        }
		        ;


NOT_LOGIC_E		: TK_OP_LOGIC_NOT NOT_LOGIC_OPERAND
			{
                                $$.label = generateLabel();
                                $$.type = "bool";
                                $$.modifier = "";
                                $$.traduction = $2.traduction + "\t" + $$.label + " = " + $1.traduction + " " + $2.label + ";\n";                                

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";                                
				declare($$.label, $$.type, 1);
			}
                        ;


NOT_LOGIC_OPERAND	: TERMINAL
                        {
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
                        }
			| NOT_LOGIC_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
			| BITWISE_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
			| '(' E ')'
                        {
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
                        }
			;


BIN_E                : BIN_OPERAND BIN_OPERATION BIN_OPERAND
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
		 	;



BIN_OPERAND             : TERMINAL
		        {
		                $$.traduction = $1.traduction;
		                $$.label = $1.label;
		                $$.type = $1.type;
		                $$.modifier = $1.modifier;
		        }
		        | BIN_E
		        {
		                $$.traduction = $1.traduction;
		                $$.label = $1.label;
		                $$.type = $1.type;
		                $$.modifier = $1.modifier;
		        }
			| NOT_LOGIC_E
			{
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
			}
			| BITWISE_E
			{
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
			}
		        | SUM_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
		        | '(' E ')'
		        {
		                $$.traduction = $2.traduction;
		                $$.label = $2.label;
		                $$.type = $2.type;
		                $$.modifier = $2.modifier;                        
		        }
		        ;



BITWISE_E		: TK_OP_BIN_NOT BITWISE_OPERAND
			{
                                $$.label = generateLabel();

				if(($2.type != "int") && ($2.type != "char"))
					yyerror("wrong type argument to bit-complement");

                                $$.traduction = $2.traduction + "\t" + $$.label + " = " + $1.traduction + " " + $2.label + ";\n";

                                $$.type = $2.type;
                                $$.modifier = $2.type;

                                //declarations += "\t" + $$.type + " " + $$.label + ";\n";
				declare($$.label, $$.type, 1);
			}
			;


BITWISE_OPERAND         : TERMINAL
		        {
			     	$$.traduction = $1.traduction;
			        $$.label = $1.label;
			        $$.type = $1.type;
			        $$.modifier = $1.modifier;
		        }
			| NOT_LOGIC_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
			| BITWISE_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
		        | '(' E ')'
		        {
		                $$.traduction = $2.traduction;
		                $$.label = $2.label;
		                $$.type = $2.type;
		                $$.modifier = $2.modifier;                        
		        }
		        ;



RELATIONAL_E         : RELATIONAL_OPERAND RELATIONAL_OPERATION RELATIONAL_OPERAND
                        {
				$$ = runBasicOperation($1, $3, $2);
                        }
                        ;



RELATIONAL_OPERAND      : TERMINAL
                        {
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
			| NOT_LOGIC_E
			{
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
			}
			| BITWISE_E
			{
			    $$.traduction = $1.traduction;
			    $$.label = $1.label;
			    $$.type = $1.type;
			    $$.modifier = $1.modifier;
			}
                        | BIN_E
                        {
                                $$.traduction = $1.traduction;
                                $$.label = $1.label;
                                $$.type = $1.type;
                                $$.modifier = $1.modifier;
                        }
                        | SUM_E
			{
				$$.traduction = $1.traduction;
				$$.label = $1.label;
				$$.type = $1.type;
				$$.modifier = $1.modifier;
			}
                        | '(' E ')'
                        {
                                $$.traduction = $2.traduction;
                                $$.label = $2.label;
                                $$.type = $2.type;
                                $$.modifier = $2.modifier;                        
                        }
                        ;



ATRIBUITION        : TK_ID TK_ASSIGN E
                        {
                                if(IDMap.find($1.label) == IDMap.end())        
                                        yyerror("identifier: '" + $1.label + "' was not declared in this scope.");

				$$ = assigns(voidStr, $1, $3);
                        }
                        ;        

RELATIONAL_OPERATION        : TK_OP_REL_LESS | TK_OP_REL_GREATER | TK_OP_REL_EQLESS | TK_OP_REL_EQGREATER | TK_OP_REL_EQ | TK_OP_REL_DIFF
                                ;
                                                


LOGIC_OPERATION         : TK_OP_LOGIC_OR | TK_OP_LOGIC_AND
                        ;



BIN_OPERATION           : TK_OP_BIN_AND | TK_OP_BIN_OR | TK_OP_BIN_XOR | TK_OP_BIN_SHIFTR | TK_OP_BIN_SHIFTL
                        ;


COUT				: TK_COUT '(' E ')'
				{
					$$.traduction = $3.traduction + "\n\tcout << " + $3.label + " << endl;\n";
				}
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

YYSTYPE runBasicOperation(YYSTYPE operand1, YYSTYPE operand2, YYSTYPE operation)
{
	YYSTYPE* res;
	
	string resultOperationType;
        id_struct* keyOperating;
        string weakOperatingLabel;
        string strongOperatingLabel;

        res->label = generateLabel();

        res->traduction = operand1.traduction + operand2.traduction;

        resultOperationType = verifyResultOperation(operand1.type, operand2.type, operation.traduction);

        /*Neste caso, não se considera o modificador. A variável auxiliar temporária, armazenará o tipo
         mais genérico possível, ou seja, desconsiderando-se os modificadores. Tais serão considerados apenas
         no momento da atribuição, que deverá se fazer um cast, caso necessário*/

        res->type = resultOperationType;
        res->modifier = ""; /*desconsidera-se os modificadores*/


        //declarations += "\t" + resultOperationType + " " + res->label + ";\n";
	declare(res->label, res->type, 1);

        if(normalizedType(operand1.type) == normalizedType(operand2.type))
        {
                res->traduction += "\t" + res->label + " = " + operand1.label + " " + operation.traduction + " " + operand2.label + ";\n";
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

                        res->traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                        res->traduction += "\t" + res->label + " = " + strongOperatingLabel + " " + operation.traduction + " " + keyOperating->label + ";\n";
                }
                else
                {
                        weakOperatingLabel = operand1.label;
                        strongOperatingLabel = operand2.label;

                        res->traduction += "\t" + keyOperating->label + " = (" + modifier + keyOperating->type + ") " + weakOperatingLabel + ";\n";
                        res->traduction += "\t" + res->label + " = " + keyOperating->label + " " + operation.traduction + " " + strongOperatingLabel + ";\n";
                }

                //declarations += "\t" + keyOperating->type + " " + keyOperating->label + ";\n";
		declare(keyOperating->label, modifier + keyOperating->type, 1);
        }

	return *res;
}

YYSTYPE assigns(string addTraduction, YYSTYPE id, YYSTYPE exp)
{
	YYSTYPE* res;	

        string cast = "";

        if (((exp.modifier != IDMap[id.label].modifier)) || (exp.type != IDMap[id.label].type))
        {
                //aqui deve-se verificar quais casts são possíveis
                if(id.modifier != "")
                        cast = "(" + IDMap[id.label].modifier + " " + IDMap[id.label].type + ") ";
                else
                        cast += "(" + IDMap[id.label].type + ") ";
        }

        res->label = IDMap[id.label].label;
        res->traduction = addTraduction + exp.traduction + "\t" + res->label + " = " + cast + exp.label + ";\n";
        res->type = IDMap[id.label].type;
        res->modifier = IDMap[id.label].modifier;

	return *res;

}

string generateLabel()
{
        static int counter = 0;
        stringstream label;

        label << "_temp" << counter++;

        return label.str();
}          


string normalizedType(string type)
{
	if (type == "bool")
		return "int";
	else
		return type;
	
}

void declare(string label, string dIType, unsigned int size)
{
	string finalType = dIType;

	if (dIType == "bool")
		finalType = "unsigned short int";
	else if (dIType == "string")
		finalType = "char";

	 declarationsMap[label] = {finalType, size};
} 

string declarations()
{
	stringstream declarations;

	for (auto iterator : declarationsMap)
	{
		declarations << "\t" + iterator.second.dIType; /*tipo com modificadores*/

		declarations << " " + iterator.first; /*label*/
		
		if (iterator.second.size > 1)
			declarations << "[" + iterator.second.size << "]"; /*tamanho*/

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
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "+";
        operationsMap[*ops] = "int";

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
        ops->op1Type = "int";
        ops->op2Type = "bool";
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
        ops->op1Type = "char";
        ops->op2Type = "bool";
        ops->sOperator = "+";
        operationsMap[*ops] = "char";       

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
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "-";
        operationsMap[*ops] = "int";

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
        ops->op1Type = "int";
        ops->op2Type = "bool";
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
        ops->op1Type = "char";
        ops->op2Type = "bool";
        ops->sOperator = "-";
        operationsMap[*ops] = "char";      

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
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "*";
        operationsMap[*ops] = "bool";

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
        ops->op1Type = "int";
        ops->op2Type = "bool";
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
        ops->op1Type = "char";
        ops->op2Type = "bool";
        ops->sOperator = "*";
        operationsMap[*ops] = "bool";    

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
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "/";
        operationsMap[*ops] = "bool";

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
        ops->op1Type = "int";
        ops->op2Type = "bool";
        ops->sOperator = "/";
        operationsMap[*ops] = "bool";

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
        ops->op1Type = "char";
        ops->op2Type = "bool";
        ops->sOperator = "/";
        operationsMap[*ops] = "bool";         

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "+";
        operationsMap[*ops] = "double";          

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "bool";
        ops->sOperator = "+";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "bool";
        ops->sOperator = "+";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "-";
        operationsMap[*ops] = "double";                        

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "bool";
        ops->sOperator = "-";
        operationsMap[*ops] = "float";

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "bool";
        ops->sOperator = "-";
        operationsMap[*ops] = "double";

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "*";
        operationsMap[*ops] = "double";                

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "bool";
        ops->sOperator = "*";
        operationsMap[*ops] = "bool";                

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "bool";
        ops->sOperator = "*";
        operationsMap[*ops] = "bool";    

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "double";
        ops->sOperator = "/";
        operationsMap[*ops] = "double";                

        ops = new operation_struct;
        ops->op1Type = "float";
        ops->op2Type = "bool";
        ops->sOperator = "/";
        operationsMap[*ops] = "bool";                

        ops = new operation_struct;
        ops->op1Type = "double";
        ops->op2Type = "bool";
        ops->sOperator = "/";
        operationsMap[*ops] = "bool";  

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "int";
        ops->sOperator = "%";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "bool";
        ops->op2Type = "bool";
        ops->sOperator = "%";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "char";
        ops->sOperator = "%";
        operationsMap[*ops] = "char";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "bool";
        ops->sOperator = "%";
        operationsMap[*ops] = "bool";

        ops = new operation_struct;
        ops->op1Type = "int";
        ops->op2Type = "char";
        ops->sOperator = "%";
        operationsMap[*ops] = "int";

        ops = new operation_struct;
        ops->op1Type = "char";
        ops->op2Type = "bool";
        ops->sOperator = "%";
        operationsMap[*ops] = "bool";


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

string   verifyStrongType(string op1Type, string op2Type)
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
                return "int";

        if ((op1Type == "char" && op2Type == "float") || (op1Type == "float" && op2Type == "char"))
                return "float";
        if ((op1Type == "char" && op2Type == "double") || (op1Type == "double" && op2Type == "char"))
                return "double";
        if ((op1Type == "char" && op2Type == "string") || (op1Type == "string" && op2Type == "char"))
                return "string";
        if ((op1Type == "char" && op2Type == "bool") || (op1Type == "bool" && op2Type == "char"))
                return "char";

        if ((op1Type == "float" && op2Type == "string") || (op1Type == "string" && op2Type == "float"))
                return "string";
        if ((op1Type == "float" && op2Type == "double") || (op1Type == "double" && op2Type == "float"))
                return "double";
        if ((op1Type == "float" && op2Type == "bool") || (op1Type == "bool" && op2Type == "float"))
                return "float";

        if ((op1Type == "double" && op2Type == "string") || (op1Type == "string" && op2Type == "double"))
                return "string";
        if ((op1Type == "double" && op2Type == "bool") || (op1Type == "bool" && op2Type == "double"))
                return "double";

        if ((op1Type == "bool" && op2Type == "string") || (op1Type == "string" && op2Type == "bool"))
                return "string";


        yyerror("relation between the types: '" + op1Type + "' and '" + op2Type + "' not defined.");
        return "";

}

