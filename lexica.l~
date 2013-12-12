%{
#include <string>

%}

TypeChar "char"
TypeString "string"
TypeInt "int"
TypeVoid "void"
TypeFloat "float"
TypeDouble "double"
TypeBoolean "bool"

ModifierUnsigned "unsigned"
ModifierSigned "signed"
ModifierShort "short"
ModifierLong "long"

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
String "\""([^\n\"\\]*(\\[.\n])*)*"\""

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

{OpSum}		{yylval.traduction = "+"; return TK_OP_SUM; }

{OpSub}		{yylval.traduction = "-"; return TK_OP_SUB; }

{OpMult}	{yylval.traduction = "*"; return TK_OP_MUL; }

{OpDiv}		{yylval.traduction = "/"; return TK_OP_DIV; }

{OpMod}		{yylval.traduction = "%"; return TK_OP_MOD; }


{Assign}	{ return TK_ASSIGN; }

{Int}		{ yylval.traduction = yytext; return TK_INT; }
{Float}		{ yylval.traduction = yytext; return TK_FLOAT; }
{Scientific}	{ yylval.traduction = yytext; return TK_SCIENTIFIC; }
{Char}		{ yylval.traduction = yytext; return TK_CHAR; }
{String}	{ yylval.traduction = yytext; return TK_STRING; }

{TypeChar} 	{ yylval.traduction = yytext; return TK_TYPE_CHAR; }
{TypeString} 	{ yylval.traduction = yytext; return TK_TYPE_STRING; }
{TypeInt} 	{ yylval.traduction = yytext; return TK_TYPE_INT; }
{TypeVoid} 	{ yylval.traduction = yytext; return TK_TYPE_VOID; }
{TypeFloat} 	{ yylval.traduction = yytext; return TK_TYPE_FLOAT; }
{TypeDouble} 	{ yylval.traduction = yytext; return TK_TYPE_DOUBLE; }
{TypeBoolean} 	{ yylval.traduction = yytext; return TK_TYPE_BOOLEAN; }

{ModifierUnsigned} 	{ yylval.traduction = yytext; return TK_MODIFIER_UNSIGNED; }
{ModifierSigned} 	{ yylval.traduction = yytext; return TK_MODIFIER_SIGNED; }
{ModifierShort} 	{ yylval.traduction = yytext; return TK_MODIFIER_SHORT; }
{ModifierLong} 	{ yylval.traduction = yytext; return TK_MODIFIER_LONG; }

{Return} 	{ yylval.traduction = yytext; return TK_RETURN; }


{ID}		{ yylval.label = yytext; return TK_ID; }

.				{ *yytext; }

%%
