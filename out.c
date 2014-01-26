/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp6;
	int _temp7;
	int _temp14;
	int _temp15;
	int _temp0;
	int _temp1;
	int _temp10;
	int _temp11;
	int _temp12;
	float _temp13;
	int _temp16;
	float _temp17;
	int _temp18;
	int _temp19;
	int _temp2;
	int _temp20;
	int _temp21;
	int _temp3;
	int _temp4;
	float _temp5;
	int _temp8;
	float _temp9;


	_temp0 = 1;
	_temp1 = _temp0;

	_temp2 = 0;
	_temp3 = _temp2;

	_temp4 = 1;
	_temp1 = _temp4;

	_tempLabel0:
	_temp5 = 2.5;
	_temp9 = (float) _temp1;
	_temp8 = _temp9 > _temp5;
	if (_temp8)
		goto _tempLabel1;

	_temp6 = 1;
	_temp7 = _temp3 + _temp6;
	_temp3 = _temp7;


	cout << _temp3 << endl;

	_temp10 = 1;
	_temp11 = _temp1 + _temp10;
	_temp1 = _temp11;
		goto _tempLabel0;

	_tempLabel1:

	_temp12 = 1;

	_tempLabel2:
	_temp13 = 2.5;
	_temp17 = (float) _temp12;
	_temp16 = _temp17 > _temp13;
	if (_temp16)
		goto _tempLabel3;

	_temp14 = 1;
	_temp15 = _temp3 + _temp14;
	_temp3 = _temp15;


	cout << _temp3 << endl;

	_temp18 = 1;
	_temp19 = _temp12 + _temp18;
	_temp12 = _temp19;
		goto _tempLabel2;

	_tempLabel3:

	_temp20 = -_temp1;

	_temp21 = 0;

	return _temp21;
}

