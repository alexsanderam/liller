%{
#include <string>

%}

TypeChar "char"
TypeString "string"
TypeInt "int"
TypeVoid "void"
TypeFloat "float"
TypeDouble "double"
TypeUnsigned "unsigned"
TypeLong "long"
TypeBoolean "boolean"

Return "return"

Space [ \t\n]
Digit [0-9]
Num {Digit}+
Letter [A-Za-z_]

Delim {Space}+

Int ([-|+])?{Num}
Float {Int}(\.{Num})
Scientific ({Int}|{Float})[e|E][+|-]{Num}

Char \'({Letter}|{Num})\'
ID {Letter}({Letter}|{Num})*

OpSum [+]
OpSub [-]
OpMult [*]
OpDiv [/]
OpMod "%"

Assign "="

%%

{Delim} 	{}

"main"		{return TK_MAIN;}

[(){}[\];,]	{ return *yytext; }

{OpSum}		{ return TK_OP_SUM; }

{OpSub}		{ return TK_OP_SUB; }

{OpMult}	{ return TK_OP_MUL; }

{OpDiv}		{ return TK_OP_DIV; }

{OpMod}		{ return TK_OP_MOD; }


{Assign}	{ return TK_ASSIGN; }

{Int}		{ yylval.traduction = yytext; return TK_INT; }
{Float}		{ yylval.traduction = yytext; return TK_FLOAT; }
{Scientific}	{ yylval.traduction = yytext; return TK_SCIENTIFIC; }
{Char}		{ yylval.traduction = yytext; return TK_CHAR; }

{TypeChar} 	{ yylval.traduction = yytext; return TK_TYPE_CHAR; }
{TypeString} 	{ yylval.traduction = yytext; return TK_TYPE_STRING; }
{TypeInt} 	{ yylval.traduction = yytext; return TK_TYPE_INT; }
{TypeVoid} 	{ yylval.traduction = yytext; return TK_TYPE_VOID; }
{TypeFloat} 	{ yylval.traduction = yytext; return TK_TYPE_FLOAT; }
{TypeDouble} 	{ yylval.traduction = yytext; return TK_TYPE_DOUBLE; }
{TypeUnsigned} 	{ yylval.traduction = yytext; return TK_TYPE_UNSIGNED; }
{TypeLong} 	{ yylval.traduction = yytext; return TK_TYPE_LONG; }
{TypeBoolean} 	{ yylval.traduction = yytext; return TK_TYPE_BOOLEAN; }

{Return} 	{ yylval.traduction = yytext; return TK_RETURN; }


{ID}		{ yylval.label = yytext; return TK_ID; }

.				{ *yytext; }

%%
