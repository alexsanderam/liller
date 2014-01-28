/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*============Variáveis globais==============*/

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
	int _temp8;


	_temp0 = 0;
	_temp1 = _temp0;



	_tempLabel2:
	_temp3 = 10;
	_temp4 = _temp2 < _temp3;
	_temp7 = !_temp4;

	if (_temp7)
		goto _tempLabel1;


	_tempLabel0:
	_temp5 = 1;
	_temp6 = _temp2 + _temp5;
	_temp2 = _temp6;

	goto _tempLabel2;
	_tempLabel1:

	_temp8 = 0;

	return _temp8;
}

