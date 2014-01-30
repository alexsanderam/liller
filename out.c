/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*============Variáveis globais==============*/

int main()
{
	char _temp10[12];
	int _temp4;
	int _temp5;
	int _temp6;
	int _temp7;
	int _temp8;
	int _temp9;
	int _temp0;
	int _temp1;
	int _temp11;
	int _temp12;
	int _temp13;
	int _temp14;
	int _temp2;
	int _temp3;


	_temp0 = 0;
	_temp1 = _temp0;

	_temp2 = 1;
	_temp3 = _temp1 + _temp2;
	_temp2 = 1;
	_temp3 = _temp1 + _temp2;
	_temp4 = 0;
	_temp11 = _temp3 == _temp4;
	if(_temp11)
		goto _tempLabel1;
	_temp2 = 1;
	_temp3 = _temp1 + _temp2;
	_temp6 = 1;
	_temp12 = _temp3 == _temp6;
	if(_temp12)
		goto _tempLabel2;
	_temp2 = 1;
	_temp3 = _temp1 + _temp2;
	_temp8 = 3;
	_temp13 = _temp3 == _temp8;
	if(_temp13)
		goto _tempLabel3;

	goto _default;
	_temp4 = 0;
	_tempLabel1:
	_temp5 = 22222222;

	cout << _temp5 << endl;

	_temp6 = 1;
	_tempLabel2:
	_temp7 = 333333;

	cout << _temp7 << endl;

	goto _tempLabel0;

	_temp8 = 3;
	_tempLabel3:
	_temp9 = 2;

	cout << _temp9 << endl;

	_default:
	strcpy(_temp10, "desconhecido");

	cout << _temp10 << endl;

	_tempLabel0:

	_temp14 = 0;

	return _temp14;
}

