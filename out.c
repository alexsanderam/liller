/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*-----Cabeçalhos de funções-------*/
/*-------------------------------*/

/*--------Variáveis globais--------*/
/*-------------------------------*/

int main(void)
{
	int _temp0;
	int _temp1;
	char _temp2[24];
	char _temp3[28];
	float* _temp4;
	int _temp5;
	int _temp6;
	int _temp7;
	int _temp8;

	/*Atribuição de variáveis globais*/
	/*-------------------------------*/



	strcpy(_temp2, "\nEnter the value to d: ");

	cout << _temp2;


	cin >> _temp0;

	strcpy(_temp3, "\nEnter the size of matrix: ");

	cout << _temp3;


	cin >> _temp1;

	_temp5 = 1;
	_temp6 = _temp5 * _temp1;
	_temp7 = _temp6 * _temp1;
	_temp4 = ( float*)malloc(sizeof(float)*_temp7);

	 free(_temp4);
	_temp8 = 0;

	return _temp8;
}


