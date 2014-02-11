%{
#include <string>

%}

TypeChar "char"
TypeString "string"
TypeInt "int"
TypeVoid "void"
TypeFloat "float"
TypeDouble "double"
TypeBool "bool"

ModifierUnsigned "unsigned"
ModifierSigned "signed"
ModifierShort "short"
ModifierLong "long"

Return "return"
Cout "cout"
Coutn "coutn"

True "true"
False "false"
Bool {True}|{False}


If "if"
Else "else"
For "for"
Each "each"
Do "do"
While "while"
Break "break"
Continue "continue"
Goto "goto"
Switch "switch"
Case "case"
Default "default"


Space [ \t]
Delim {Space}+
Line [\n]

Digit [0-9]
Num {Digit}+
Letter [A-Za-z_]
Int {Num}
Float {Int}(\.{Num})
Scientific ({Int}|{Float})[e|E][+|-]{Num}

Char \'({Letter}|{Num})\'
ID {Letter}({Letter}|{Num})*
String "\""([^\n\"]*(\\[.\n])*)*"\""

OpPlusPlus "++"
OpLessLess "--"

OpSumAssign "+="
OpLessAssign "-="
OpMulAssign "*="
OpDivAssign "/="
OpModAssign "%="
OpLeftAssign "<<="
OpRightAssign ">>="
OpAndAssign "&="
OpOrAssign "|="
OpXorAssign "^="

GoLabel ":"
DotDot ".."

OpSum [+]
OpSub [-]
OpMult [*]
OpDiv [/]
OpMod "%"


OpRelLess "<"
OpRelGreater ">"
OpRelEqLess "<="
OpRelEqGreater ">="
OpRelEq "=="
OpRelDiff "!="

OpLogicAnd "&&"
OpLogicOr "||"
OpLogicNot "!"

OpLogicBinAnd "&"
OpLogicBinOr "|"
OpLogicBinXor "^"
OpLogicBinNot "~"
OpLogicBinShiftR ">>"
OpLogicBinShiftL "<<"

Assign "="

%x COMMENTS
%x COMMENTS_2
%%

"/*"                        {BEGIN(COMMENTS);}
<COMMENTS>"*"+"/"         {BEGIN(INITIAL);}
<COMMENTS>[^*\n]*        {}
<COMMENTS>"*"+[^*/\n]*        {}
<COMMENTS>\n             { ++yylineno; }


"//"                        {BEGIN(COMMENTS_2);}
<COMMENTS_2>[\0]         {; BEGIN(INITIAL);}
<COMMENTS_2>[\n]         { ++yylineno; BEGIN(INITIAL);}
<COMMENTS_2>[^\n]*        {}


{Delim}         {}
{Line}                {yylineno++;}

"main"                {yylval.translation = yytext; return TK_MAIN;}

[(){}[\];,]        { return *yytext; }

{OpPlusPlus}                {yylval.translation = yytext; return TK_OP_INCREASE; }
{OpLessLess}                {yylval.translation = yytext; return TK_OP_INCREASE; }
{OpSumAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpLessAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpMulAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpDivAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpModAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpLeftAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpRightAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpAndAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpOrAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }
{OpXorAssign}                {yylval.translation = yytext; return TK_OP_ASSIGN; }


{OpSum}                {yylval.translation = yytext; return TK_OP_SUM; }
{OpSub}                {yylval.translation = yytext; return TK_OP_SUB; }
{OpMult}        {yylval.translation = yytext; return TK_OP_MUL; }
{OpDiv}                {yylval.translation = yytext; return TK_OP_DIV; }
{OpMod}                {yylval.translation = yytext; return TK_OP_MOD; }

{OpRelLess}                        {yylval.translation = yytext; return TK_OP_REL_LESS; }
{OpRelGreater}                {yylval.translation = yytext; return TK_OP_REL_GREATER; }
{OpRelEqLess}                {yylval.translation = yytext; return TK_OP_REL_EQLESS; }
{OpRelEqGreater}        {yylval.translation = yytext; return TK_OP_REL_EQGREATER; }
{OpRelEq}                        {yylval.translation = yytext; return TK_OP_REL_EQ; }
{OpRelDiff}                        {yylval.translation = yytext; return TK_OP_REL_DIFF; }

{OpLogicAnd}                {yylval.translation = yytext; return TK_OP_LOGIC_AND; }
{OpLogicOr}                        {yylval.translation = yytext; return TK_OP_LOGIC_OR; }        
{OpLogicNot}                {yylval.translation = yytext; return TK_OP_LOGIC_NOT; }

{OpLogicBinAnd}                        {yylval.translation = yytext; return TK_OP_BIN_AND; }
{OpLogicBinOr}                        {yylval.translation = yytext; return TK_OP_BIN_OR; }
{OpLogicBinXor}                        {yylval.translation = yytext; return TK_OP_BIN_XOR; }
{OpLogicBinNot}                        {yylval.translation = yytext; return TK_OP_BIN_NOT; }
{OpLogicBinShiftR}                {yylval.translation = yytext; return TK_OP_BIN_SHIFTR; }
{OpLogicBinShiftL}                {yylval.translation = yytext; return TK_OP_BIN_SHIFTL; }

{DotDot}	{return TK_DOT_DOT;}

{GoLabel}	{return TK_GO_LABEL;}

{Assign}        { return TK_ASSIGN; }

{Int}                { yylval.intValue = atoi(yytext); yylval.translation = yytext; return TK_INT; }
{Float}                { yylval.translation = yytext; return TK_FLOAT; }
{Scientific}        { yylval.translation = yytext; return TK_SCIENTIFIC; }
{Char}                { yylval.translation = yytext; return TK_CHAR; }
{String}        { yylval.translation = yytext; return TK_STRING; }
{Bool}                { yylval.translation = yytext; return TK_BOOL; }

{TypeChar}         { yylval.translation = yytext; return TK_TYPE_CHAR; }
{TypeString}         { yylval.translation = yytext; return TK_TYPE_STRING; }
{TypeInt}         { yylval.translation = yytext; return TK_TYPE_INT; }
{TypeVoid}         { yylval.translation = yytext; return TK_TYPE_VOID; }
{TypeFloat}         { yylval.translation = yytext; return TK_TYPE_FLOAT; }
{TypeDouble}         { yylval.translation = yytext; return TK_TYPE_DOUBLE; }
{TypeBool}         { yylval.translation = yytext; return TK_TYPE_BOOL; }

{ModifierUnsigned}         { yylval.translation = yytext; return TK_MODIFIER_UNSIGNED; }
{ModifierSigned}         { yylval.translation = yytext; return TK_MODIFIER_SIGNED; }
{ModifierShort}         { yylval.translation = yytext; return TK_MODIFIER_SHORT; }
{ModifierLong}         { yylval.translation = yytext; return TK_MODIFIER_LONG; }

{Return}         { yylval.translation = yytext; return TK_RETURN; }
{Cout}                { yylval.translation = yytext; return TK_COUT; }
{Coutn}                { yylval.translation = yytext; return TK_COUTN; }
{If}                { yylval.translation = yytext; return TK_IF; }
{Else}                { yylval.translation = yytext; return TK_ELSE; }
{For}                { yylval.translation = yytext; return TK_FOR; }
{Each}                { yylval.translation = yytext; return TK_EACH; }
{Do}                { yylval.translation = yytext; return TK_DO; }
{While}                { yylval.translation = yytext; return TK_WHILE; }
{Break}                { yylval.translation = yytext; return TK_BREAK; }
{Continue}                { yylval.translation = yytext; return TK_CONTINUE; }
{Goto}                { yylval.translation = yytext; return TK_GOTO; }
{Switch}                { yylval.translation = yytext; return TK_SWITCH; }
{Case}                { yylval.translation = yytext; return TK_CASE; }
{Default}                { yylval.translation = yytext; return TK_DEFAULT; }


{ID}                { yylval.label = yytext; return TK_ID; }

.                        { *yytext; }

%%
