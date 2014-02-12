/*Compiler prescot-liller*/

#include <stdio.h>
#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*-----Cabeçalhos de funções-------*/
int _temp2(int, int);
int _temp3(int, float);
string _temp6(int, string);
void _temp7(void);
/*-------------------------------*/

/*--------Variáveis globais--------*/
	int _temp0;
	int _temp1;
	char _temp37[5];
	char _temp38[6];
/*-------------------------------*/

int main()
{
	char _temp10;
	char _temp11;
	char _temp12[4];
	char _temp13;
	char _temp14[2];
	char _temp15[6];
	char _temp16[3];
	char _temp17[9];
	char _temp18[10];
	int _temp19;
	int _temp20;
	int _temp21;
	int _temp22;
	int _temp23;
	int _temp24;
	int _temp25;
	int _temp26;
	int _temp27;
	int _temp28;
	int _temp29;
	int _temp30;
	int _temp31;
	char _temp32[7];
	char _temp33[17];
	char _temp34[4];
	char _temp35[21];
	int _temp36;
	int _temp8;
	int _temp9;

	/*Atribuição de variáveis globais*/
	_temp0 = 150;
	_temp1 = _temp0;
	strcpy(_temp37, "chora");
	strcpy(_temp38, _temp37);
	_temp38[5] = '\0';
	/*-------------------------------*/

	_temp8 = 0;
	_temp9 = _temp8;

	_temp10 = 'a';
	_temp11 = _temp10;


	cout << _temp11 << endl;

	strcpy(_temp12, "oi: ");
	_temp13 = 'a';
	snprintf(_temp14, 2, "%c", _temp13);
	_temp14[1] = '\0';
	strcpy(_temp15, _temp12);
	strcat(_temp15, _temp14);
	strcpy(_temp16, "...");
	strcpy(_temp17, _temp15);
	strcat(_temp17, _temp16);
	strcpy(_temp18, _temp17);
	_temp18[9] = '\0';

	_temp19 = 0;
	_temp20 = _temp9 == _temp19;
	_temp24 = !_temp20;

	if(_temp24)
		goto _tempLabel2;

	/*----chamada de função----*/
	_temp7();
	/*-------------------------*/

		goto _tempLabel3;

	_tempLabel2:
	_temp21 = 3;
	_temp22 = _temp9 == _temp21;
	_temp23 = !_temp22;

	if(_temp23)
		goto _tempLabel0;

	/*----chamada de função----*/
	_temp7();
	/*-------------------------*/

		goto _tempLabel1;

	_tempLabel0:
	/*----chamada de função----*/
	_temp7();
	/*-------------------------*/

	_tempLabel1:

	_tempLabel3:

	/*----chamada de função----*/
	_temp25 = 1;
	_temp26 = 1;
	_temp27 = _temp2(_temp25, _temp26);
	/*-------------------------*/

	/*----chamada de função----*/
	_temp28 = 1;
	_temp29 = 2;
	_temp30 = _temp2(_temp28, _temp29);
	/*-------------------------*/
	_temp31 = _temp30;

	strcpy(_temp32, "teste: ");
	strcpy(_temp33, _temp32);
	strcat(_temp33, _temp18);
	strcpy(_temp34, "\n\n");
	strcpy(_temp35, _temp33);
	strcat(_temp35, _temp34);

	cout << _temp35;

	_temp36 = 0;

	return _temp36;
}

string _temp6(int _temp40, char _temp39[1])
{
	int _temp41;
	char _temp42[100];
	char _temp43[100];



	cout << _temp38 << endl;

	snprintf(_temp42, 100, "%d", _temp40);
	strcpy(_temp43, _temp42);
	strcat(_temp43, _temp39);

	return _temp43;
}

int _temp2(int _temp45, int _temp44)
{
	int _temp46;

	_temp46 = _temp45 + _temp44;

	return _temp46;
}

void _temp7()
{
	int _temp47;



	cin >> _temp47;


	cout << _temp47;

}


