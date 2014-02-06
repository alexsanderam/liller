/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*============Variáveis globais==============*/
	int _temp0;
	int _temp1;

int main()
{
	char _temp10[3];
	char _temp11[9];
	char _temp12[10];
	char _temp13[7];
	char _temp14[17];
	int _temp15;
	int _temp2;
	int _temp3;
	char _temp4;
	char _temp5;
	char _temp6[4];
	char _temp7;
	char _temp8[2];
	char _temp9[6];

	_temp0 = 150;
	_temp1 = _temp0;

	_temp2 = 0;
	_temp3 = _temp2;

	_temp4 = 'a';
	_temp5 = _temp4;


	cout << _temp5 << endl;

	strcpy(_temp6, "oi: ");
	_temp7 = 'a';
	snprintf(_temp8, 2, "%c", _temp7);
	_temp8[1] = '\0';
	strcpy(_temp9, _temp6);
	strcat(_temp9, _temp8);
	strcpy(_temp10, "...");
	strcpy(_temp11, _temp9);
	strcat(_temp11, _temp10);
	strcpy(_temp12, _temp11);
	_temp12[9] = '\0';

	strcpy(_temp13, "teste: ");
	strcpy(_temp14, _temp13);
	strcat(_temp14, _temp12);

	cout << _temp14 << endl;

	_temp15 = 0;

	return _temp15;
}

