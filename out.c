/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp10;
	int _temp6;
	int _temp7;
	int _temp8;
	int _temp9;
	int _temp11;
	float _temp12;
	int _temp13;
	int _temp14;
	int _temp4;
	float _temp5;
	int _temp17;
	int _temp18;
	int _temp15;
	float _temp16;
	int _temp19;
	float _temp20;
	int _temp21;
	int _temp22;
	int _temp0;
	int _temp1;
	int _temp2;
	int _temp23;
	int _temp24;
	int _temp3;


	_temp0 = 1;
	_temp1 = _temp0;

	_temp2 = 0;
	_temp3 = _temp2;

	_temp4 = 1;
	_temp1 = _temp4;

	_tempLabel0:
	_temp5 = 2.5;
	_temp12 = (float) _temp1;
	_temp11 = _temp12 > _temp5;
	if (_temp11)
		goto _tempLabel1;

	_temp6 = 1;
	_temp7 = _temp1 == _temp6;
	_temp8 = !_temp7;

	if(_temp8)
		goto _tempLabel2;

	_temp13 = 1;
	_temp14 = _temp1 + _temp13;
	_temp1 = _temp14;


	goto _tempLabel0;

	_tempLabel2:

	_temp9 = 1;
	_temp10 = _temp3 + _temp9;
	_temp3 = _temp10;


	cout << _temp1 << endl;

	_temp13 = 1;
	_temp14 = _temp1 + _temp13;
	_temp1 = _temp14;
		goto _tempLabel0;

	_tempLabel1:

	_temp15 = 1;

	_tempLabel3:
	_temp16 = 2.5;
	_temp20 = (float) _temp15;
	_temp19 = _temp20 > _temp16;
	if (_temp19)
		goto _tempLabel4;

	_temp17 = 1;
	_temp18 = _temp3 + _temp17;
	_temp3 = _temp18;


	cout << _temp3 << endl;


	_temp21 = 1;
	_temp22 = _temp15 + _temp21;
	_temp15 = _temp22;
		goto _tempLabel3;

	_tempLabel4:

	_temp23 = -_temp1;

	_temp24 = 0;

	return _temp24;
}

