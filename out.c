/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*========Variáveis globais========*/
	int _temp0;
	int _temp1;
	char _temp18[5];
	char _temp19[6];

int main()
{
	char _temp10[3];
	char _temp11[9];
	char _temp12[10];
	char _temp13[7];
	char _temp14[17];
	char _temp15[4];
	char _temp16[21];
	int _temp17;
	int _temp2;
	int _temp3;
	char _temp4;
	char _temp5;
	char _temp6[4];
	char _temp7;
	char _temp8[2];
	char _temp9[6];

	/*Atribuição de variáveis globais*/
	_temp0 = 150;
	_temp1 = _temp0;
	strcpy(_temp18, "chora");
	strcpy(_temp19, _temp18);
	_temp19[5] = '\0';
	/*-------------------------------*/

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
	strcpy(_temp15, "\n\n");
	strcpy(_temp16, _temp14);
	strcat(_temp16, _temp15);

	cout << _temp16;

	_temp17 = 0;

	return _temp17;
}


int _temp23(int _temp20, int _temp21)
{
	int _temp22;

	_temp22 = _temp20 + _temp21;

	return _temp22;
}

