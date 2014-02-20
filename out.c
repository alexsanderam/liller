/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*-----Cabeçalhos de funções-------*/
int _temp0(int );
char* _temp1(int );
void _temp2(void );
int _temp4(int n);
void _temp6(int n);
/*-------------------------------*/

/*--------Variáveis globais--------*/
	char* _temp124;
/*-------------------------------*/

int main(void)
{
	int _temp17;
	unsigned short int _temp18;
	int _temp19;
	int _temp20;
	char _temp21[22];
	int _temp22;
	char _temp23[3];
	char _temp24[100];
	char _temp25[103];
	char* _temp26;
	char _temp27[103];
	int _temp28;
	char _temp29[22];
	int _temp30;
	char _temp31[3];
	char _temp32[100];
	char _temp33[103];
	int _temp34;
	char _temp35[22];
	char _temp36[18];
	char _temp11[24];
	char _temp12[13];
	char _temp13[27];
	char _temp14[32];
	char _temp15[17];
	char _temp16[35];
	int _temp37;
	int _temp38;
	int _temp39;
	int _temp40;
	int _temp41;
	int _temp10;
	int _temp42;
	unsigned short int _temp7;
	unsigned short int _temp8;
	int _temp9;

	/*Atribuição de variáveis globais*/
	/*-------------------------------*/

	_temp7 = 1;
	_temp8 = _temp7;




	_tempLabel0:
	strcpy(_temp11, "Entre com uma opção: ");
	_temp11[23] = '\0';

	cout << _temp11 << endl;

	strcpy(_temp12, "\t[0] - Sair");
	_temp12[12] = '\0';

	cout << _temp12 << endl;

	strcpy(_temp13, "\t[1] - Diagonal de matriz");
	_temp13[26] = '\0';

	cout << _temp13 << endl;

	strcpy(_temp14, "\t[2] - Sequência de Fibonacci");
	_temp14[31] = '\0';

	cout << _temp14 << endl;

	strcpy(_temp15, "\t[3] - Fatorial");
	_temp15[16] = '\0';

	cout << _temp15 << endl;

	strcpy(_temp16, "\t[4] - Imprimir pares menores que");
	_temp16[34] = '\0';

	cout << _temp16 << endl;


	cin >> _temp9;

	_temp17 = 0;
	_temp37 = _temp9 == _temp17;
	if(_temp37)
		goto _tempLabel3;
	_temp19 = 1;
	_temp38 = _temp9 == _temp19;
	if(_temp38)
		goto _tempLabel4;
	_temp20 = 2;
	_temp39 = _temp9 == _temp20;
	if(_temp39)
		goto _tempLabel5;
	_temp28 = 3;
	_temp40 = _temp9 == _temp28;
	if(_temp40)
		goto _tempLabel6;
	_temp34 = 4;
	_temp41 = _temp9 == _temp34;
	if(_temp41)
		goto _tempLabel7;

	goto _default;
	_temp17 = 0;
	_tempLabel3:
	_temp18 = 0;
	_temp8 = _temp18;

	goto _tempLabel2;

	_temp19 = 1;
	_tempLabel4:
	/*----chamada de função----*/
	_temp2();
	/*-------------------------*/

	goto _tempLabel2;

	_temp20 = 2;
	_tempLabel5:
	strcpy(_temp21, "Entre com um inteiro:");
	_temp21[21] = '\0';

	cout << _temp21 << endl;


	cin >> _temp10;

	/*----chamada de função----*/
	_temp22 = _temp0(_temp10);
	/*-------------------------*/
	snprintf(_temp24, 100, "%d", _temp22);
	_temp24[99] = '\0';
	strcpy(_temp23, ": ");
	_temp23[2] = '\0';
	strcpy(_temp25, _temp24);
	strcat(_temp25, _temp23);
	/*----chamada de função----*/
	_temp26 = _temp1(_temp10);
	/*-------------------------*/
	strcpy(_temp27, _temp25);
	strcat(_temp27, _temp26);

	cout << _temp27;

	goto _tempLabel2;

	_temp28 = 3;
	_tempLabel6:
	strcpy(_temp29, "Entre com um inteiro:");
	_temp29[21] = '\0';

	cout << _temp29 << endl;


	cin >> _temp10;

	/*----chamada de função----*/
	_temp30 = _temp4(_temp10);
	/*-------------------------*/
	snprintf(_temp32, 100, "%d", _temp30);
	_temp32[99] = '\0';
	strcpy(_temp31, "\n");
	_temp31[2] = '\0';
	strcpy(_temp33, _temp32);
	strcat(_temp33, _temp31);

	cout << _temp33 << endl;

	goto _tempLabel2;

	_temp34 = 4;
	_tempLabel7:
	strcpy(_temp35, "Entre com um inteiro:");
	_temp35[21] = '\0';

	cout << _temp35 << endl;


	cin >> _temp10;

	/*----chamada de função----*/
	_temp6(_temp10);
	/*-------------------------*/

	goto _tempLabel2;

	_default:
	strcpy(_temp36, "Opção inválida");
	_temp36[17] = '\0';

	cout << _temp36 << endl;

	goto _tempLabel2;

	_tempLabel2:
	;


	if (_temp8)
		goto _tempLabel0;
	_tempLabel1:
	;

	_temp42 = 0;

	if (_temp124 != NULL)
		free(_temp124);

	return _temp42;

}

void _temp2()
{
	int _temp61;
	int _temp62;
	int _temp63;
	int _temp64;
	int _temp65;
	int _temp66;
	int _temp67;
	int _temp68;
	int _temp69;
	int _temp70;
	int _temp71;
	int _temp56;
	int _temp57;
	int _temp58;
	int _temp59;
	int _temp60;
	int _temp72;
	int _temp51;
	int _temp52;
	int _temp53;
	int _temp54;
	int _temp55;
	int _temp73;
	int _temp84;
	int _temp85;
	int _temp86;
	int _temp87;
	char _temp88[2];
	char _temp89[100];
	char _temp90[102];
	int _temp79;
	int _temp80;
	int _temp81;
	int _temp82;
	int _temp83;
	int _temp91;
	int _temp74;
	int _temp75;
	int _temp76;
	int _temp77;
	int _temp78;
	int _temp92;
	int _temp43;
	int _temp44;
	char _temp45[25];
	char _temp46[29];
	int* _temp47;
	int _temp48;
	int _temp49;
	int _temp50;



	strcpy(_temp45, "\nEnter the value to d: ");
	_temp45[24] = '\0';

	cout << _temp45;


	cin >> _temp43;

	strcpy(_temp46, "\nEnter the size of matrix: ");
	_temp46[28] = '\0';

	cout << _temp46;


	cin >> _temp44;

	_temp48 = 1;
	_temp49 = _temp48 * _temp44;
	_temp50 = _temp49 * _temp44;
	_temp47 = ( int*) malloc (sizeof(int)*_temp50);


	_temp51 = 0;
	_temp52 = _temp51;

	_tempLabel15:
	_temp53 = _temp52 < _temp44;
	_temp73 = !_temp53;

	if (_temp73)
		goto _tempLabel9;


	_temp56 = 0;
	_temp57 = _temp56;

	_tempLabel14:
	_temp58 = _temp57 < _temp44;
	_temp72 = !_temp58;

	if (_temp72)
		goto _tempLabel11;

	_temp61 = _temp52 == _temp57;
	_temp71 = !_temp61;

	if(_temp71)
		goto _tempLabel12;

	_temp62 = 0;
	_temp63 = _temp52 * _temp44;
	_temp64 = _temp62 + _temp63;
	_temp65 = _temp64 + _temp57;
	_temp47[_temp65] = _temp43;

		goto _tempLabel13;

	_tempLabel12:
	_temp67 = 0;
	_temp68 = _temp52 * _temp44;
	_temp69 = _temp67 + _temp68;
	_temp70 = _temp69 + _temp57;
	_temp66 = 0;
	_temp47[_temp70] = _temp66;

	_tempLabel13:
	;


	_tempLabel10:
	_temp59 = 1;
	_temp60 = _temp57 + _temp59;
	_temp57 = _temp60;

	goto _tempLabel14;
	_tempLabel11:
	;
	_tempLabel8:
	_temp54 = 1;
	_temp55 = _temp52 + _temp54;
	_temp52 = _temp55;

	goto _tempLabel15;
	_tempLabel9:
	;

	_temp74 = 0;
	_temp75 = _temp74;

	_tempLabel21:
	_temp76 = _temp75 < _temp44;
	_temp92 = !_temp76;

	if (_temp92)
		goto _tempLabel17;


	_temp79 = 0;
	_temp80 = _temp79;

	_tempLabel20:
	_temp81 = _temp80 < _temp44;
	_temp91 = !_temp81;

	if (_temp91)
		goto _tempLabel19;

	_temp84 = 0;
	_temp85 = _temp75 * _temp44;
	_temp86 = _temp84 + _temp85;
	_temp87 = _temp86 + _temp80;
	snprintf(_temp89, 100, "%d", _temp47[_temp87]);
	_temp89[99] = '\0';
	strcpy(_temp88, " ");
	_temp88[1] = '\0';
	strcpy(_temp90, _temp89);
	strcat(_temp90, _temp88);

	cout << _temp90;


	_tempLabel18:
	_temp82 = 1;
	_temp83 = _temp80 + _temp82;
	_temp80 = _temp83;

	goto _tempLabel20;
	_tempLabel19:
	;

	cout << endl;

	_tempLabel16:
	_temp77 = 1;
	_temp78 = _temp75 + _temp77;
	_temp75 = _temp78;

	goto _tempLabel21;
	_tempLabel17:
	;

}

int _temp0(int _temp93)
{
	int _temp100;
	int _temp101;
	int _temp102;
	int _temp103;
	int _temp104;
	int _temp94;
	int _temp95;
	int _temp96;
	int _temp97;
	int _temp98;
	int _temp99;

	_temp94 = 1;
	_temp95 = _temp93 <= _temp94;
	_temp97 = !_temp95;

	if(_temp97)
		goto _tempLabel22;

	_temp96 = 1;

	return _temp96;
	_tempLabel22:
	;

	/*----chamada de função----*/
	_temp98 = 1;
	_temp99 = _temp93 - _temp98;
	_temp100 = _temp0(_temp99);
	/*-------------------------*/
	/*----chamada de função----*/
	_temp101 = 2;
	_temp102 = _temp93 - _temp101;
	_temp103 = _temp0(_temp102);
	/*-------------------------*/
	_temp104 = _temp100 + _temp103;

	return _temp104;

}

char* _temp1(int _temp105)
{
	int _temp116;
	char _temp117[2];
	char _temp118[100];
	char _temp119[102];
	char _temp120[103];
	int _temp111;
	int _temp112;
	int _temp113;
	int _temp114;
	int _temp115;
	int _temp121;
	int _temp106;
	char _temp107[1];
	char _temp108[107];
	char _temp109[3];
	char _temp110[4];
	char _temp122[2];
	char _temp123[106];
	int _temp125;
	_temp125 = 1;
	_temp124 = ( char*) malloc (sizeof(char)*_temp125);


	strcpy(_temp107, "");
	_temp107[0] = '\0';
	strcpy(_temp108, _temp107);
	_temp108[1] = '\0';

	strcpy(_temp109, "[ ");
	_temp109[2] = '\0';
	strcpy(_temp110, _temp108);
	strcat(_temp110, _temp109);
	strcpy(_temp108, _temp110);
	_temp108[4] = '\0';


	_temp111 = 1;
	_temp112 = _temp111;

	_tempLabel25:
	_temp113 = _temp112 <= _temp105;
	_temp121 = !_temp113;

	if (_temp121)
		goto _tempLabel24;

	/*----chamada de função----*/
	_temp116 = _temp0(_temp112);
	/*-------------------------*/
	snprintf(_temp118, 100, "%d", _temp116);
	_temp118[99] = '\0';
	strcpy(_temp117, " ");
	_temp117[1] = '\0';
	strcpy(_temp119, _temp118);
	strcat(_temp119, _temp117);
	strcpy(_temp120, _temp108);
	strcat(_temp120, _temp119);
	strcpy(_temp108, _temp120);
	_temp108[103] = '\0';


	_tempLabel23:
	_temp114 = 1;
	_temp115 = _temp112 + _temp114;
	_temp112 = _temp115;

	goto _tempLabel25;
	_tempLabel24:
	;
	strcpy(_temp122, "]");
	_temp122[1] = '\0';
	strcpy(_temp123, _temp108);
	strcat(_temp123, _temp122);
	strcpy(_temp108, _temp123);
	_temp108[106] = '\0';


	_temp124 = (char*) realloc(_temp124, 107);
	strcpy(_temp124, _temp108);
	return _temp124;

}

int _temp4(int _temp126)
{
	int _temp132;
	int _temp131;
	int _temp133;
	int _temp134;
	int _temp135;
	int _temp127;
	int _temp128;
	int _temp129;
	int _temp130;

	_temp127 = 1;
	_temp128 = _temp127;

	_temp129 = 1;
	_temp130 = _temp129;

	_temp131 = 1;
	_temp128 = _temp131;

	_tempLabel28:
	_temp133 = _temp128 > _temp126;
	if (_temp133)
		goto _tempLabel27;

	_temp132 = _temp130 * _temp128;
	_temp130 = _temp132;


	_tempLabel26:
	_temp134 = 1;
	_temp135 = _temp128 + _temp134;
	_temp128 = _temp135;
		goto _tempLabel28;

	_tempLabel27:
	;

	return _temp130;

}

void _temp6(int _temp136)
{
	int _temp140;
	int _temp141;
	int _temp142;
	int _temp143;
	int _temp144;
	int _temp145;
	int _temp146;
	char _temp147[2];
	char _temp148[100];
	char _temp149[102];
	int _temp137;
	int _temp138;
	int _temp139;
	int _temp150;

	_temp137 = 0;
	_temp138 = _temp137;


	_tempLabel29:
	_temp139 = _temp138 <= _temp136;
	_temp150 = !_temp139;

	if (_temp150)
		goto _tempLabel30;

	_temp140 = 1;
	_temp141 = _temp138 + _temp140;
	_temp138 = _temp141;

	_temp142 = 2;
	_temp143 = _temp138 % _temp142;
	_temp144 = 1;
	_temp145 = _temp143 == _temp144;
	_temp146 = !_temp145;

	if(_temp146)
		goto _tempLabel31;

	goto _tempLabel29;

	_tempLabel31:
	;

	snprintf(_temp148, 100, "%d", _temp138);
	_temp148[99] = '\0';
	strcpy(_temp147, " ");
	_temp147[1] = '\0';
	strcpy(_temp149, _temp148);
	strcat(_temp149, _temp147);

	cout << _temp149;


		goto _tempLabel29;
	_tempLabel30:
	;


	cout << endl;

}


