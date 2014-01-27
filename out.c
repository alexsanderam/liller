/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*============Variáveis globais==============*/
	int _temp0;
	int _temp1;

int main()
{
	int _temp5;
	int _temp6;
	int _temp7;
	int _temp10;
	float _temp3;
	int _temp4;
	int _temp8;
	int _temp9;
	int _temp11;
	int _temp2;

	_temp0 = 150;
	_temp1 = _temp0;


	_temp3 = 1.1;
	_temp2 = (int) _temp3;

	_tempLabel3:
	_temp4 = 9;
	_temp8 = _temp2 > _temp4;
	if (_temp8)
		goto _tempLabel1;

	_temp5 = 5;
	_temp6 = _temp2 == _temp5;
	_temp7 = !_temp6;

	if(_temp7)
		goto _tempLabel2;

	goto _tempLabel0;

	_tempLabel2:


	cout << _temp2 << endl;


	_tempLabel0:
	_temp9 = 1;
	_temp10 = _temp2 + _temp9;
	_temp2 = _temp10;
		goto _tempLabel3;

	_tempLabel1:

	_temp11 = 0;

	return _temp11;
}

