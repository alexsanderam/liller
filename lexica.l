%{
#include <string>

%}

<<<<<<< HEAD
TypeChar "char"
TypeString "string"
TypeInt "int"
TypeVoid "void"
TypeFloat "float"
TypeDouble "double"
TypeUnsigned "unsigned"
TypeLong "long"
TypeBoolean "boolean"

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

{Int}			{ yylval.traduction = yytext; return TK_INT; }
{Float}			{ yylval.traduction = yytext; return TK_FLOAT; }
{Scientific}	{ yylval.traduction = yytext; return TK_SCIENTIFIC; }
{Char}			{ yylval.traduction = yytext; return TK_CHAR; }

{TypeChar} 		{ yylval.traduction = yytext; return TK_TYPE_CHAR; }
{TypeString} 	{ yylval.traduction = yytext; return TK_TYPE_STRING; }
{TypeInt} 		{ yylval.traduction = yytext; return TK_TYPE_INT; }
{TypeVoid} 		{ yylval.traduction = yytext; return TK_TYPE_VOID; }
{TypeFloat} 	{ yylval.traduction = yytext; return TK_TYPE_FLOAT; }
{TypeDouble} 	{ yylval.traduction = yytext; return TK_TYPE_DOUBLE; }
{TypeUnsigned} 	{ yylval.traduction = yytext; return TK_TYPE_UNSIGNED; }
{TypeLong} 		{ yylval.traduction = yytext; return TK_TYPE_LONG; }
{TypeBoolean} 	{ yylval.traduction = yytext; return TK_TYPE_BOOLEAN; }


{ID}			{ yylval.label = yytext; return TK_ID; }

.				{ *yytext; }
=======
ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TYPE_INT;}

[(){}[\];,]	{ return *yytext; }

[+]		{ return TK_OP_SUM; }

[-]		{ return TK_OP_SUB; }

[*]		{ return TK_OP_MUL; }

[/]		{ return TK_OP_DIV; }

"%"		{ return TK_OP_MOD; }


"="		{ return TK_ASSIGN; }

{NUM}		{ yylval.traduction = yytext; return TK_INT; }
{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }
>>>>>>> 19c3c5e67bc7712b835794a025d927eb1a14d593

%%
