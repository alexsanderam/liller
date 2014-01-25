/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	int _temp10;
	string _temp11;
	string _temp12;
	int _temp13;
	int _temp6;
	int _temp7;
	string _temp8;
	int _temp9;
	int _temp0;
	int _temp1;
	int _temp14;
	int _temp15;
	string _temp16;
	string _temp17;
	int _temp18;
	int _temp19;
	int _temp2;
	int _temp20;
	int _temp21;
	string _temp22;
	int _temp23;
	int _temp24;
	int _temp3;
	int _temp4;
	int _temp5;


	_temp0 = 1;
	_temp1 = _temp0;

	_temp2 = 0;
	_temp3 = _temp2;

	_temp4 = 2;
	_temp5 = _temp1 < _temp4;
	_temp19 = !_temp5;

	if(_temp19)
		goto _tempLabel4;

	_temp6 = 2;
	_temp7 = _temp3 + _temp6;
	_temp3 = _temp7;

	_temp8 = "Entrou no If(1)";

	cout << _temp8 << endl;

	_temp9 = 3;
	_temp10 = _temp3 > _temp9;
	_temp13 = !_temp10;

	if(_temp13)
		goto _tempLabel0;

	_temp11 = "Entrou no If(1.2)";

	cout << _temp11 << endl;

		goto _tempLabel1;

	_tempLabel0:
	_temp12 = "Entrou no Else(1.2)";

	cout << _temp12 << endl;

	_tempLabel1:


		goto _tempLabel5;

	_tempLabel4:
	_temp14 = 2;
	_temp15 = _temp1 == _temp14;
	_temp18 = !_temp15;

	if(_temp18)
		goto _tempLabel2;

	_temp16 = "Entrou no ElseIf(1.1)";

	cout << _temp16 << endl;

		goto _tempLabel3;

	_tempLabel2:
	_temp17 = "Entrou no Else(1)";

	cout << _temp17 << endl;

	_tempLabel3:

	_tempLabel5:

	_temp20 = 3;
	_temp21 = _temp1 != _temp20;
	_temp23 = !_temp21;

	if(_temp23)
		goto _tempLabel6;

	_temp22 = "Entrou no If(2), pois i == 3";

	cout << _temp22 << endl;

	_tempLabel6:

	_temp24 = 0;

	return _temp24;
}

