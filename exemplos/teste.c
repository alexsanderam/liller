#include<stdio.h>

int main()
{	
	int i = 1;
	int j = 20;
	
	i+= 20 + 1 + j;
	//valor esperado: 42
	printf("\n%d\n",i);

	i-= 20 + 1 + j;
	//valor esperado: 1
	printf("\n%d\n",i);

	i-= 2;
	//valor esperado: -1
	printf("\n%d\n",i);

	i*= -1;
	//valor esperado: 1
	printf("\n%d\n",i);

	i/= 1/2;
	//valor esperado: 2
	printf("\n%d\n",i);

	1 + 2 + (int) 3.0 + 8;

	return 0;
}
