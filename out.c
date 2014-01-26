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
	int _temp0;
	int _temp1;
	string _temp10;
	int _temp11;
	int _temp8;
	int _temp9;


	_temp0 = 0;
	_temp1 = _temp0;

	_tempLabel1:
	_temp2 = 0;
	_temp3 = _temp1 == _temp2;
	_temp5 = !_temp3;

	if(_temp5)
		goto _tempLabel0;

	_temp4 = 9;
	_temp1 = _temp4;

	_tempLabel0:


	cout << _temp1 << endl;

	_temp6 = 1;
	_temp7 = _temp1 - _temp6;
	_temp1 = _temp7;


	_temp8 = 0;
	_temp9 = _temp1 > _temp8;
	if (_temp9)
		goto _tempLabel1;

	_temp10 = "Fim do Do..While";

	cout << _temp10 << endl;

	_temp11 = 0;

	return _temp11;
}

