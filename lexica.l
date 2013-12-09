%{
#include <string>

%}

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

%%
