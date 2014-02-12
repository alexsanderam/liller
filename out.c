/*func(int, int)*/
/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*-----Cabeçalhos de funções-------*/
int _temp2(int, int) ;
/*-------------------------------*/

/*--------Variáveis globais--------*/
	int _temp0;
	int _temp1;
	char _temp21[5];
	char _temp22[6];
/*-------------------------------*/

int main()
{
	char _temp10[6];
	char _temp11[3];
	char _temp12[9];
	char _temp13[10];
	int _temp14;
	int _temp15;
	char _temp16[7];
	char _temp17[17];
	char _temp18[4];
	char _temp19[21];
	int _temp20;
	int _temp3;
	int _temp4;
	char _temp5;
	char _temp6;
	char _temp7[4];
	char _temp8;
	char _temp9[2];

	/*Atribuição de variáveis globais*/
	_temp0 = 150;
	_temp1 = _temp0;
	strcpy(_temp21, "chora");
	strcpy(_temp22, _temp21);
	_temp22[5] = '\0';
	/*-------------------------------*/

	_temp3 = 0;
	_temp4 = _temp3;

	_temp5 = 'a';
	_temp6 = _temp5;


	cout << _temp6 << endl;

	strcpy(_temp7, "oi: ");
	_temp8 = 'a';
	snprintf(_temp9, 2, "%c", _temp8);
	_temp9[1] = '\0';
	strcpy(_temp10, _temp7);
	strcat(_temp10, _temp9);
	strcpy(_temp11, "...");
	strcpy(_temp12, _temp10);
	strcat(_temp12, _temp11);
	strcpy(_temp13, _temp12);
	_temp13[9] = '\0';

	/*----chamada de função----*/
	_temp14 = 1;
	_temp15 = 1;
	_temp2(_temp14, _temp15);
	/*-------------------------*/

	strcpy(_temp16, "teste: ");
	strcpy(_temp17, _temp16);
	strcat(_temp17, _temp13);
	strcpy(_temp18, "\n\n");
	strcpy(_temp19, _temp17);
	strcat(_temp19, _temp18);

	cout << _temp19;

	_temp20 = 0;

	return _temp20;
}

string _temp25(int _temp24, char _temp23[1])
{
	char _temp26[100];
	char _temp27[100];


	cout << _temp22 << endl;

	snprintf(_temp26, 100, "%d", _temp24);
	strcpy(_temp27, _temp26);
	strcat(_temp27, _temp23);

	return _temp27;
}

int _temp2(int _temp29, int _temp28)
{
	int _temp30;

	_temp30 = _temp29 + _temp28;

	return _temp30;
}

int _temp31()
{
	int _temp32;

	_temp32 = 87;

	return _temp32;
}


