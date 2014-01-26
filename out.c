/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp0;
	int _temp1;
	int _temp2;
	int _temp3;
	int _temp4;
	int _temp5;
	int _temp6;
	int _temp7;
	int _temp8;
	int _temp9;


	_temp0 = 0;
	_temp1 = _temp0;

	_temp2 = 0;
	_temp3 = _temp1 == _temp2;
	_temp4 = !_temp3;

	if(_temp4)
		goto _tempLabel1;

	goto _tempLabel0;

	_tempLabel1:

	_temp5 = 1;
	_temp6 = _temp1 + _temp5;
	_temp1 = _temp6;


	cout << _temp1 << endl;

	_tempLabel0:

	_temp7 = 1;
	_temp8 = _temp1 - _temp7;
	_temp1 = _temp8;


	cout << _temp1 << endl;

	_temp9 = 0;

	return _temp9;
}

