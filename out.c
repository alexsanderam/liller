/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp10;
	int _temp11;
	string _temp12;
	string _temp13;
	int _temp14;
	int _temp6;
	int _temp7;
	int _temp8;
	string _temp9;
	int _temp0;
	int _temp1;
	int _temp15;
	int _temp16;
	string _temp17;
	string _temp18;
	int _temp19;
	int _temp2;
	int _temp20;
	int _temp21;
	int _temp22;
	string _temp23;
	int _temp24;
	int _temp25;
	int _temp3;
	int _temp4;
	int _temp5;


	_temp0 = 1;
	_temp1 = _temp0;

	_temp2 = 0;
	_temp3 = _temp2;

	_temp4 = 2;
	_temp5 = _temp1 < _temp4;
	_temp20 = !_temp5;

	if(_temp20)
		goto _tempLabel4;


	_temp7 = 2;
	_temp8 = _temp3 + _temp7;
	_temp3 = _temp8;

	_temp9 = "Entrou no If(1)";

	cout << _temp9 << endl;

	_temp10 = 3;
	_temp11 = _temp3 > _temp10;
	_temp14 = !_temp11;

	if(_temp14)
		goto _tempLabel0;

	_temp12 = "Entrou no If(1.2)";

	cout << _temp12 << endl;

		goto _tempLabel1;

	_tempLabel0:
	_temp13 = "Entrou no Else(1.2)";

	cout << _temp13 << endl;

	_tempLabel1:


		goto _tempLabel5;

	_tempLabel4:
	_temp15 = 2;
	_temp16 = _temp1 == _temp15;
	_temp19 = !_temp16;

	if(_temp19)
		goto _tempLabel2;

	_temp17 = "Entrou no ElseIf(1.1)";

	cout << _temp17 << endl;

		goto _tempLabel3;

	_tempLabel2:
	_temp18 = "Entrou no Else(1)";

	cout << _temp18 << endl;

	_tempLabel3:

	_tempLabel5:

	_temp21 = 3;
	_temp22 = _temp1 != _temp21;
	_temp24 = !_temp22;

	if(_temp24)
		goto _tempLabel6;

	_temp23 = "Entrou no If(2), pois i == 3";

	cout << _temp23 << endl;

	_tempLabel6:

	_temp25 = 0;

	return _temp25;
}

