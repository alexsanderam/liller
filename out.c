/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*-----Cabeçalhos de funções-------*/
/*-------------------------------*/

/*--------Variáveis globais--------*/
/*-------------------------------*/

int main(void)
{
	int _temp18;
	int _temp19;
	int _temp20;
	int _temp21;
	int _temp22;
	int _temp23;
	int _temp24;
	int _temp25;
	int _temp26;
	int _temp27;
	int _temp28;
	int _temp13;
	int _temp14;
	int _temp15;
	int _temp16;
	int _temp17;
	int _temp29;
	int _temp10;
	int _temp11;
	int _temp12;
	int _temp30;
	int _temp8;
	int _temp9;
	int _temp41;
	int _temp42;
	int _temp43;
	int _temp44;
	char _temp45[2];
	char _temp46[100];
	char _temp47[102];
	int _temp36;
	int _temp37;
	int _temp38;
	int _temp39;
	int _temp40;
	int _temp48;
	int _temp31;
	int _temp32;
	int _temp33;
	int _temp34;
	int _temp35;
	int _temp49;
	int _temp0;
	int _temp1;
	char _temp2[25];
	char _temp3[29];
	int* _temp4;
	int _temp5;
	int _temp50;
	int _temp6;
	int _temp7;

	/*Atribuição de variáveis globais*/
	/*-------------------------------*/



	strcpy(_temp2, "\nEnter the value to d: ");
	_temp2[24] = '\0';

	cout << _temp2;


	cin >> _temp0;

	strcpy(_temp3, "\nEnter the size of matrix: ");
	_temp3[28] = '\0';

	cout << _temp3;


	cin >> _temp1;

	_temp5 = 1;
	_temp6 = _temp5 * _temp1;
	_temp7 = _temp6 * _temp1;
	_temp4 = ( int*) malloc (sizeof(int)*_temp7);


	_temp8 = 0;
	_temp9 = _temp8;

	_tempLabel7:
	_temp10 = _temp9 < _temp1;
	_temp30 = !_temp10;

	if (_temp30)
		goto _tempLabel1;


	_temp13 = 0;
	_temp14 = _temp13;

	_tempLabel6:
	_temp15 = _temp14 < _temp1;
	_temp29 = !_temp15;

	if (_temp29)
		goto _tempLabel3;

	_temp18 = _temp9 == _temp14;
	_temp28 = !_temp18;

	if(_temp28)
		goto _tempLabel4;

	_temp19 = 0;
	_temp20 = _temp9 * _temp1;
	_temp21 = _temp19 + _temp20;
	_temp22 = _temp21 + _temp14;
	_temp4[_temp22] = _temp0;

		goto _tempLabel5;

	_tempLabel4:
	_temp24 = 0;
	_temp25 = _temp9 * _temp1;
	_temp26 = _temp24 + _temp25;
	_temp27 = _temp26 + _temp14;
	_temp23 = 0;
	_temp4[_temp27] = _temp23;

	_tempLabel5:


	_tempLabel2:
	_temp16 = 1;
	_temp17 = _temp14 + _temp16;
	_temp14 = _temp17;

	goto _tempLabel6;
	_tempLabel3:

	_tempLabel0:
	_temp11 = 1;
	_temp12 = _temp9 + _temp11;
	_temp9 = _temp12;

	goto _tempLabel7;
	_tempLabel1:


	_temp31 = 0;
	_temp32 = _temp31;

	_tempLabel13:
	_temp33 = _temp32 < _temp1;
	_temp49 = !_temp33;

	if (_temp49)
		goto _tempLabel9;


	_temp36 = 0;
	_temp37 = _temp36;

	_tempLabel12:
	_temp38 = _temp37 < _temp1;
	_temp48 = !_temp38;

	if (_temp48)
		goto _tempLabel11;

	_temp41 = 0;
	_temp42 = _temp32 * _temp1;
	_temp43 = _temp41 + _temp42;
	_temp44 = _temp43 + _temp37;
	snprintf(_temp46, 100, "%d", _temp4[_temp44]);
	_temp46[99] = '\0';
	strcpy(_temp45, " ");
	_temp45[1] = '\0';
	strcpy(_temp47, _temp46);
	strcat(_temp47, _temp45);

	cout << _temp47;


	_tempLabel10:
	_temp39 = 1;
	_temp40 = _temp37 + _temp39;
	_temp37 = _temp40;

	goto _tempLabel12;
	_tempLabel11:


	cout << endl;

	_tempLabel8:
	_temp34 = 1;
	_temp35 = _temp32 + _temp34;
	_temp32 = _temp35;

	goto _tempLabel13;
	_tempLabel9:


	_temp50 = 0;

	return _temp50;
}


