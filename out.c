/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp2;
	int _temp3;
	int _temp4;
	int _temp5;
	int _temp6;
	int _temp7;
	int _temp10;
	int _temp11;
	int _temp12;
	int _temp13;
	int _temp14;
	int _temp15;
	int _temp16;
	int _temp0;
	int _temp1;
	int _temp17;
	int _temp8;
	int _temp9;


	_temp0 = 0;
	_temp1 = _temp0;


	_temp2 = 0;
	_temp1 = _temp2;

	_tempLabel0:
	_temp3 = 10;
	_temp4 = _temp1 < _temp3;
	_temp7 = !_temp4;

	if (_temp7)
		goto _tempLabel1;


	cout << _temp1 << endl;
	_temp5 = 1;
	_temp6 = _temp1 + _temp5;
	_temp1 = _temp6;

	
		goto _tempLabel0;
	_tempLabel1:

	_temp8 = 0;
	_temp9 = _temp8;


	_temp10 = 10;
	_temp11 = _temp10;

	_tempLabel2:
	_temp12 = 20;
	_temp13 = _temp11 < _temp12;
	_temp16 = !_temp13;

	if (_temp16)
		goto _tempLabel3;


	cout << _temp11 << endl;
	_temp14 = 1;
	_temp15 = _temp11 + _temp14;
	_temp11 = _temp15;

	
		goto _tempLabel2;
	_tempLabel3:

	_temp17 = 0;

	return _temp17;
}

