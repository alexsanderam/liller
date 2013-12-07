%{
#define TK_DIGIT	200
#define TK_INT	201
#define TK_FLOAT	202
#define TK_SCIENTIFIC	203
#define TK_LETTER	204
#define TK_STRING	205
#define TK_ID	206
#define TK_COMMENT	207
#define TK_WS	210


#define TK_IF	211
#define TK_ELSE	212
#define TK_SWITCH	213
#define TK_CASE	214
#define TK_FOR	215
#define TK_DO	216
#define TK_WHILE	217
#define TK_EACH	218
#define TK_GOTO	219
#define TK_TYPE_CHAR	220
#define TK_TYPE_STRING	300
#define TK_TYPE_INT	221
#define TK_TYPE_VOID	222
#define TK_TYPE_FLOAT	220
#define TK_TYPE_DOUBLE	221
#define TK_TYPE_UNSIGNED	222
#define TK_TYPE_LONG	223
#define TK_TYPE_BOOLEAN	224
#define TK_CONTINUE	225
#define TK_BREAK	226
#define TK_RETURN	227
#define TK_TRUE	228
#define TK_FALSE	229
#define TK_INCLUDE	230
#define TK_DEFINE	231
#define TK_OP_SUM	232
#define TK_OP_SUB	233
#define TK_OP_MULT	234
#define TK_OP_DIV	235
#define TK_OP_MOD	302
#define TK_OPLOGIC_AND	236
#define TK_OPLOGIC_OR	237
#define TK_OPLOGIC_NOT	238
#define TK_OPBIN_AND	239
#define TK_OPBIN_EXCLUSIVEOR	240
#define TK_OPBIN_OR	244
#define TK_OPBIN_NOT	246
#define TK_OPBIN_SHIFTR	247
#define TK_OPBIN_SHIFTL	248
#define TK_LESS	249
#define TK_GREATER	250
#define TK_EQLESS	251
#define TK_EQGREATER	252
#define TK_EQ	253
#define TK_DIFF	254
#define TK_PTSR	255
#define TK_PTSL	256
#define TK_BKTR	257
#define TK_BKTL	258
#define TK_BRCR	259
#define TK_BRCL	260
#define TK_COMMA	261
#define TK_SEMICOLON	262
#define TK_ASSIGN	263
#define TK_DELIMITER	264

#define TK_END	301
%}

If "if"
Else "else"
Switch "switch"
Case "case"
For "for"
Do "do"
While "while"
Each "each"
GoTo "goto"

TypeChar "char"
TypeString "string"
TypeInt "int"
TypeVoid "void"
TypeFloat "float"
TypeDouble "double"
TypeUnsigned "unsigned"
TypeLong "long"
TypeBoolean "boolean"

Continue "continue"
Break "break"
Return "return"

True "true"
False "false"

Include "include"
Define "define"

OpSum "+"
OpSub "-"
OpMult "*"
OpDiv "/"
OpMod "%"

OpLogicAnd "&&"
OpLogicOr "||"
OpLogicNot "!"
OpBinAnd "&"
OpBinOr "|"
OpBinExclusiveOr "^"
OpBinNot "~"
OpBinShiftR ">>"
OpBinShiftL "<<"

Less "<"
Greater ">"
EqLess "<="
EqGreater ">="
Eq "=="
Diff "!="

PtsR "("
PtsL ")"
BktR "["
BktL "]"
BrcR "{"
BrcL "}"

Comma ","
SemiColon ";"
Assign "="
Pound "#"

Digit [0-9]
Int ([-|+])?{Digit}+
Float {Int}(\.{Int})
Scientific ({Int}|{Float})[e|E][+|-]{Int}

Letter [A-Za-z]
String "\""([^\n\"\\]*(\\[.\n])*)*"\""

ID (("_"*)|{Letter}({Letter}|{Digit})*)+

Comment "//"({String}|{Delimiter})*|"/*"({String}|{Delimiter})*"*/"
Delimiter [\t\n]
WS ({Comment}|[" "])|({Delimiter})+



%%

{If}			{ printf("\nSe.\n"); return TK_IF; }
{Else}			{ printf("\nSenão.\n"); return TK_ELSE; }
{Switch}		{ return TK_SWITCH; }
{Case}			{ printf("\nCaso.\n"); return TK_CASE; }
{For}			{ printf("\nPara.\n"); return TK_FOR; }
{Do}			{ printf("\nFaça.\n"); return TK_DO; }
{While}			{ printf("\nEnquanto.\n"); return TK_WHILE; }
{Each}			{ printf("\nCada.\n"); return TK_EACH; }
{GoTo}			{ printf("\nVáPara.\n"); return TK_GOTO; }

{TypeChar}		{ printf("\nTipoChar.\n"); return TK_TYPE_CHAR; }
{TypeString}		{ printf("\nTipoString.\n"); return TK_TYPE_STRING; }
{TypeInt}		{ printf("\nTipoInt.\n"); return TK_TYPE_INT; }
{TypeVoid}		{ printf("\nTipoVoid.\n"); return TK_TYPE_VOID; }
{TypeFloat}		{ printf("\nTipoFloat.\n"); return TK_TYPE_FLOAT; }
{TypeDouble}		{ printf("\nTipoDouble.\n"); return TK_TYPE_DOUBLE; }
{TypeUnsigned}		{ printf("\nTipoSemSinal.\n"); return TK_TYPE_UNSIGNED; }
{TypeLong}		{ printf("\nTipoLongo.\n"); return TK_TYPE_LONG; }
{TypeBoolean}		{ printf("\nTipoLongo.\n"); return TK_TYPE_BOOLEAN; }

{Continue}		{ printf("\nContinue.\n"); return TK_CONTINUE; }
{Break}			{ printf("\nPare.\n"); return TK_BREAK; }
{Return}		{ printf("\nRetorne.\n"); return TK_RETURN; }

{Scientific}		{ printf("\nCientífico.\n"); return TK_SCIENTIFIC; }
{Float}			{ printf("\nFlutuante.\n"); return TK_FLOAT; }
{Int}			{ printf("\nInteiro.\n"); return TK_INT; }


{String}		{ printf("\nString.\n"); return TK_STRING; }
{Letter}		{ printf("\nCaracter.\n"); return TK_LETTER; }

{ID}			{ printf("\nIdentificador.\n"); return TK_ID; }

{OpSum}			{ printf("\nOpSoma.\n"); return TK_OP_SUM; }
{OpSub}			{ printf("\nOpSubtração.\n"); return TK_OP_SUB; }
{OpMult}		{ printf("\nOpMultiplicação.\n"); return TK_OP_MULT; }
{OpDiv}			{ printf("\nOpDivisão.\n"); return TK_OP_DIV; }
{OpMod}			{ printf("\nOpMod.\n"); return TK_OP_MOD; }

{OpLogicAnd}		{ printf("\nOpLogicoE.\n"); return TK_OPLOGIC_AND; }
{OpLogicOr}		{ printf("\nOpLogicoOu.\n"); return TK_OPLOGIC_OR; }
{OpLogicNot}		{ printf("\nOpLogicoNão.\n"); return TK_OPLOGIC_NOT; }
{OpBinAnd}		{ printf("\nOpBinE.\n"); return TK_OPBIN_AND; }
{OpBinOr}		{ printf("\nOpBinOu.\n"); return TK_OPBIN_OR; }
{OpBinExclusiveOr}	{ printf("\nOpBinOuExclusivo.\n"); return TK_OPBIN_EXCLUSIVEOR; }
{OpBinNot}		{ printf("\nOpBinNão.\n"); return TK_OPBIN_NOT; }
{OpBinShiftR}		{ printf("\nOpBinShitR.\n"); return TK_OPBIN_SHIFTR; }
{OpBinShiftL}		{ printf("\nOpBinShiftL.\n"); return TK_OPBIN_SHIFTL; }

{Less}			{ printf("\nOpMenor.\n"); return TK_LESS; }
{Greater}		{ printf("\nOpMaior.\n"); return TK_GREATER; }
{EqLess}		{ printf("\nOpMenorOuIgual.\n"); return TK_EQLESS; }
{EqGreater}		{ printf("\nOpMaiorOuIgual.\n"); return TK_EQGREATER; }
{Eq}			{ printf("\nOpIgual.\n"); return TK_EQ; }
{Diff}			{ printf("\nOpDiferente.\n"); return TK_DIFF; }

{PtsR}			{ printf("\nPR.\n"); return TK_PTSR; }
{PtsL}			{ printf("\nPL.\n"); return TK_PTSL; }
{BktR}			{ printf("\nBktR.\n"); return TK_BKTR; }
{BktL}			{ printf("\nBktL.\n"); return TK_BKTL; }
{BrcR}			{ printf("\nBrcR.\n"); return TK_BRCR; }
{BrcL}			{ printf("\nBrcL.\n"); return TK_BRCL; }

{Comma}			{ printf("\nVírgula.\n"); return TK_COMMA; }
{SemiColon}		{ printf("\nPontoEVírgula.\n"); return TK_SEMICOLON; }
{Assign}		{ printf("\nAtribuição.\n"); return TK_ASSIGN; }

{Delimiter}		{ }

{Comment}		{ }
{WS}			{ }


.			{ *yytext; }
<<EOF>>	 	  	{return TK_END; *yytext; }

%%

int main(int argc, char *argv[])
{
	FILE *f_in;
	int tipoToken;

	if(argc == 2)
	{
		if(f_in == fopen(argv[1], "r"))
		{
			yyin = f_in;
		}
		else
		{
			perror(argv[0]);
		}
	}
	else
	{
		fflush(stdin);
		yyin = stdin;
	}

	while((tipoToken = yylex()) != TK_END);

	return 0;
}
