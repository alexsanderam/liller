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
	char* _temp91;
/*-------------------------------*/

int main(void)
{
	int _temp7;
	char* _temp8;
	int _temp9;

	/*Atribuição de variáveis globais*/
	/*-------------------------------*/



	cin >> _temp7;

	/*----chamada de função----*/
	_temp8 = _temp1(_temp7);
	/*-------------------------*/

	cout << _temp8 << endl;

	_temp9 = 0;

	if (_temp91 != NULL)
		free(_temp91);

	return _temp9;

}

void _temp2()
{
	int _temp28;
	int _temp29;
	int _temp30;
	int _temp31;
	int _temp32;
	int _temp33;
	int _temp34;
	int _temp35;
	int _temp36;
	int _temp37;
	int _temp38;
	int _temp23;
	int _temp24;
	int _temp25;
	int _temp26;
	int _temp27;
	int _temp39;
	int _temp18;
	int _temp19;
	int _temp20;
	int _temp21;
	int _temp22;
	int _temp40;
	int _temp51;
	int _temp52;
	int _temp53;
	int _temp54;
	char _temp55[2];
	char _temp56[100];
	char _temp57[102];
	int _temp46;
	int _temp47;
	int _temp48;
	int _temp49;
	int _temp50;
	int _temp58;
	int _temp41;
	int _temp42;
	int _temp43;
	int _temp44;
	int _temp45;
	int _temp59;
	int _temp10;
	int _temp11;
	char _temp12[25];
	char _temp13[29];
	int* _temp14;
	int _temp15;
	int _temp16;
	int _temp17;



	strcpy(_temp12, "\nEnter the value to d: ");
	_temp12[24] = '\0';

	cout << _temp12;


	cin >> _temp10;

	strcpy(_temp13, "\nEnter the size of matrix: ");
	_temp13[28] = '\0';

	cout << _temp13;


	cin >> _temp11;

	_temp15 = 1;
	_temp16 = _temp15 * _temp11;
	_temp17 = _temp16 * _temp11;
	_temp14 = ( int*) malloc (sizeof(int)*_temp17);


	_temp18 = 0;
	_temp19 = _temp18;

	_tempLabel7:
	_temp20 = _temp19 < _temp11;
	_temp40 = !_temp20;

	if (_temp40)
		goto _tempLabel1;


	_temp23 = 0;
	_temp24 = _temp23;

	_tempLabel6:
	_temp25 = _temp24 < _temp11;
	_temp39 = !_temp25;

	if (_temp39)
		goto _tempLabel3;

	_temp28 = _temp19 == _temp24;
	_temp38 = !_temp28;

	if(_temp38)
		goto _tempLabel4;

	_temp29 = 0;
	_temp30 = _temp19 * _temp11;
	_temp31 = _temp29 + _temp30;
	_temp32 = _temp31 + _temp24;
	_temp14[_temp32] = _temp10;

		goto _tempLabel5;

	_tempLabel4:
	_temp34 = 0;
	_temp35 = _temp19 * _temp11;
	_temp36 = _temp34 + _temp35;
	_temp37 = _temp36 + _temp24;
	_temp33 = 0;
	_temp14[_temp37] = _temp33;

	_tempLabel5:
	;


	_tempLabel2:
	_temp26 = 1;
	_temp27 = _temp24 + _temp26;
	_temp24 = _temp27;

	goto _tempLabel6;
	_tempLabel3:
	;
	_tempLabel0:
	_temp21 = 1;
	_temp22 = _temp19 + _temp21;
	_temp19 = _temp22;

	goto _tempLabel7;
	_tempLabel1:
	;

	_temp41 = 0;
	_temp42 = _temp41;

	_tempLabel13:
	_temp43 = _temp42 < _temp11;
	_temp59 = !_temp43;

	if (_temp59)
		goto _tempLabel9;


	_temp46 = 0;
	_temp47 = _temp46;

	_tempLabel12:
	_temp48 = _temp47 < _temp11;
	_temp58 = !_temp48;

	if (_temp58)
		goto _tempLabel11;

	_temp51 = 0;
	_temp52 = _temp42 * _temp11;
	_temp53 = _temp51 + _temp52;
	_temp54 = _temp53 + _temp47;
	snprintf(_temp56, 100, "%d", _temp14[_temp54]);
	_temp56[99] = '\0';
	strcpy(_temp55, " ");
	_temp55[1] = '\0';
	strcpy(_temp57, _temp56);
	strcat(_temp57, _temp55);

	cout << _temp57;


	_tempLabel10:
	_temp49 = 1;
	_temp50 = _temp47 + _temp49;
	_temp47 = _temp50;

	goto _tempLabel12;
	_tempLabel11:
	;

	cout << endl;

	_tempLabel8:
	_temp44 = 1;
	_temp45 = _temp42 + _temp44;
	_temp42 = _temp45;

	goto _tempLabel13;
	_tempLabel9:
	;

}

int _temp0(int _temp60)
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

	_temp61 = 1;
	_temp62 = _temp60 <= _temp61;
	_temp64 = !_temp62;

	if(_temp64)
		goto _tempLabel14;

	_temp63 = 1;

	return _temp63;
	_tempLabel14:
	;

	/*----chamada de função----*/
	_temp65 = 1;
	_temp66 = _temp60 - _temp65;
	_temp67 = _temp0(_temp66);
	/*-------------------------*/
	/*----chamada de função----*/
	_temp68 = 2;
	_temp69 = _temp60 - _temp68;
	_temp70 = _temp0(_temp69);
	/*-------------------------*/
	_temp71 = _temp67 + _temp70;

	return _temp71;

}

char* _temp1(int _temp72)
{
	int _temp83;
	char _temp84[2];
	char _temp85[100];
	char _temp86[102];
	char _temp87[103];
	int _temp78;
	int _temp79;
	int _temp80;
	int _temp81;
	int _temp82;
	int _temp88;
	int _temp73;
	char _temp74[1];
	char _temp75[107];
	char _temp76[5];
	char _temp77[6];
	char _temp89[2];
	char _temp90[106];
	int _temp92;
	_temp92 = 1;
	_temp91 = ( char*) malloc (sizeof(char)*_temp92);


	strcpy(_temp74, "");
	_temp74[0] = '\0';
	strcpy(_temp75, _temp74);
	_temp75[1] = '\0';

	strcpy(_temp76, "\n[ ");
	_temp76[4] = '\0';
	strcpy(_temp77, _temp75);
	strcat(_temp77, _temp76);
	strcpy(_temp75, _temp77);
	_temp75[6] = '\0';


	_temp78 = 1;
	_temp79 = _temp78;

	_tempLabel17:
	_temp80 = _temp79 <= _temp72;
	_temp88 = !_temp80;

	if (_temp88)
		goto _tempLabel16;

	/*----chamada de função----*/
	_temp83 = _temp0(_temp79);
	/*-------------------------*/
	snprintf(_temp85, 100, "%d", _temp83);
	_temp85[99] = '\0';
	strcpy(_temp84, " ");
	_temp84[1] = '\0';
	strcpy(_temp86, _temp85);
	strcat(_temp86, _temp84);
	strcpy(_temp87, _temp75);
	strcat(_temp87, _temp86);
	strcpy(_temp75, _temp87);
	_temp75[103] = '\0';


	_tempLabel15:
	_temp81 = 1;
	_temp82 = _temp79 + _temp81;
	_temp79 = _temp82;

	goto _tempLabel17;
	_tempLabel16:
	;
	strcpy(_temp89, "]");
	_temp89[1] = '\0';
	strcpy(_temp90, _temp75);
	strcat(_temp90, _temp89);
	strcpy(_temp75, _temp90);
	_temp75[106] = '\0';


	_temp91 = (char*) realloc(_temp91, 107);
	strcpy(_temp91, _temp75);
	return _temp91;

}

int _temp4(int _temp93)
{
	int _temp99;
	int _temp100;
	int _temp101;
	int _temp102;
	int _temp98;
	int _temp94;
	int _temp95;
	int _temp96;
	int _temp97;

	_temp94 = 1;
	_temp95 = _temp94;

	_temp96 = 1;
	_temp97 = _temp96;

	_temp98 = 1;
	_temp95 = _temp98;

	_tempLabel20:
	_temp100 = _temp95 > _temp93;
	if (_temp100)
		goto _tempLabel19;

	_temp99 = _temp97 * _temp95;
	_temp97 = _temp99;


	_tempLabel18:
	_temp101 = 1;
	_temp102 = _temp95 + _temp101;
	_temp95 = _temp102;
		goto _tempLabel20;

	_tempLabel19:
	;

	return _temp97;

}

void _temp6(int _temp103)
{
	int _temp107;
	int _temp108;
	int _temp109;
	int _temp110;
	int _temp111;
	int _temp112;
	int _temp113;
	int _temp104;
	int _temp105;
	int _temp106;
	int _temp114;

	_temp104 = 0;
	_temp105 = _temp104;


	_tempLabel21:
	_temp106 = _temp105 <= _temp103;
	_temp114 = !_temp106;

	if (_temp114)
		goto _tempLabel22;

	_temp107 = 1;
	_temp108 = _temp105 + _temp107;
	_temp105 = _temp108;

	_temp109 = 2;
	_temp110 = _temp105 % _temp109;
	_temp111 = 1;
	_temp112 = _temp110 == _temp111;
	_temp113 = !_temp112;

	if(_temp113)
		goto _tempLabel23;

	goto _tempLabel21;

	_tempLabel23:
	;


	cout << _temp105;


		goto _tempLabel21;
	_tempLabel22:
	;


}


