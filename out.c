/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp5;
	int _temp6;
	string _temp7;
	int _temp0;
	int _temp1;
	int _temp10;
	int _temp2;
	int _temp3;
	int _temp4;
	string _temp8;
	int _temp9;


	_temp0 = 1;
	_temp1 = _temp0;


	_temp3 = 2;
	_temp4 = _temp1 > _temp3;
	_temp9 = !_temp4;

	if(_temp9)
		goto _tempLabel0;

	_temp5 = 2;
	_temp6 = _temp2 + _temp5;
	_temp2 = _temp6;

	_temp7 = "Entrou no If";

	cout << _temp7 << endl;


		goto _tempLabel1;

	_tempLabel0:
	_temp8 = "Entrou no Else";

	cout << _temp8 << endl;

	_tempLabel1:

	_temp10 = 0;

	return _temp10;
}

