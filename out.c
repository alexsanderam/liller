/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp4;
	int _temp5;
	int _temp0;
	int _temp1;
	int _temp2;
	int _temp3;
	int _temp6;
	string _temp7;
	int _temp8;


	_temp0 = 10;
	_temp1 = _temp0;

	_tempLabel0:
	_temp2 = 0;
	_temp3 = _temp1 > _temp2;
	_temp6 = !_temp3;

	while(_temp6)
		goto _tempLabel1;


	cout << _temp1 << endl;

	_temp4 = 1;
	_temp5 = _temp1 - _temp4;
	_temp1 = _temp5;


		goto _tempLabel0;
	_tempLabel1:

	_temp7 = "Fim do While";

	cout << _temp7 << endl;

	_temp8 = 0;

	return _temp8;
}

