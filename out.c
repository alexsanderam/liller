//0
//0
//0
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
	int _temp29;
	int _temp30;
	int _temp13;
	int _temp14;
	int _temp15;
	int _temp16;
	int _temp17;
	int _temp31;
	int _temp10;
	int _temp11;
	int _temp12;
	int _temp32;
	int _temp8;
	int _temp9;
	int _temp43;
	int _temp44;
	int _temp45;
	int _temp46;
	int _temp47;
	char _temp48[2];
	char _temp49[100];
	char _temp50[102];
	int _temp38;
	int _temp39;
	int _temp40;
	int _temp41;
	int _temp42;
	int _temp51;
	int _temp33;
	int _temp34;
	int _temp35;
	int _temp36;
	int _temp37;
	int _temp52;
	int _temp0;
	int _temp1;
	char _temp2[25];
	char _temp3[29];
	int* _temp4;
	int _temp5;
	int _temp53;
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
	_temp32 = !_temp10;

	if (_temp32)
		goto _tempLabel1;


	_temp13 = 0;
	_temp14 = _temp13;

	_tempLabel6:
	_temp15 = _temp14 < _temp1;
	_temp31 = !_temp15;

	if (_temp31)
		goto _tempLabel3;

	_temp18 = _temp9 == _temp14;
	_temp30 = !_temp18;

	if(_temp30)
		goto _tempLabel4;

	_temp19 = 0;
	_temp20 = 0;
	_temp21 = _temp9 * _temp20;
	_temp22 = _temp19 + _temp21;
	_temp23 = _temp22 + _temp14;
	_temp4[_temp23] = _temp0;

		goto _tempLabel5;

	_tempLabel4:
	_temp25 = 0;
	_temp26 = 0;
	_temp27 = _temp9 * _temp26;
	_temp28 = _temp25 + _temp27;
	_temp29 = _temp28 + _temp14;
	_temp24 = 0;
	_temp4[_temp29] = _temp24;

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


	_temp33 = 0;
	_temp34 = _temp33;

	_tempLabel13:
	_temp35 = _temp34 < _temp1;
	_temp52 = !_temp35;

	if (_temp52)
		goto _tempLabel9;


	_temp38 = 0;
	_temp39 = _temp38;

	_tempLabel12:
	_temp40 = _temp39 < _temp1;
	_temp51 = !_temp40;

	if (_temp51)
		goto _tempLabel11;

	_temp43 = 0;
	_temp44 = 0;
	_temp45 = _temp34 * _temp44;
	_temp46 = _temp43 + _temp45;
	_temp47 = _temp46 + _temp39;
	snprintf(_temp49, 100, "%d", _temp4[_temp47]);
	_temp49[99] = '\0';
	strcpy(_temp48, " ");
	_temp48[1] = '\0';
	strcpy(_temp50, _temp49);
	strcat(_temp50, _temp48);

	cout << _temp50;


	_tempLabel10:
	_temp41 = 1;
	_temp42 = _temp39 + _temp41;
	_temp39 = _temp42;

	goto _tempLabel12;
	_tempLabel11:


	cout << endl;

	_tempLabel8:
	_temp36 = 1;
	_temp37 = _temp34 + _temp36;
	_temp34 = _temp37;

	goto _tempLabel13;
	_tempLabel9:

	_temp53 = 0;

	return _temp53;

}


