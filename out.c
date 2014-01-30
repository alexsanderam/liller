//null
//null
/*Compiler prescot-liller*/

#include <iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

/*============Variáveis globais==============*/

int main()
{
	char _temp0[2];
	char _temp1[2];
	char _temp2[2];
	char _temp3[4];
	char _temp4[7];
	char _temp5[3];
	char _temp6[7];
	int _temp7;


	strcpy(_temp0, "ab");
	strcpy(_temp1, _temp0);

	strcpy(_temp2, "cd");
	strcpy(_temp3, _temp1);
	strcat(_temp3, _temp2);
	strcpy(_temp4, _temp3);

	strcpy(_temp5, "  )");
	strcpy(_temp6, _temp4);
	strcat(_temp6, _temp5);
	strcpy(_temp4, _temp6);


	cout << _temp4 << endl;

	_temp7 = 0;

	return _temp7;
}

