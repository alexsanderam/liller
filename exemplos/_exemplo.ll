int main()
{	
	/*Aqui é um comentário
	Este arquivo é de exemplo da Linguagem Liller
	e do Compilador prescot-liller.*/
	
	unsigned short int k;
	int j;
	float z, v = 10;
	bool x;


	k = j = 1 / 1 + (v=20.5); //a primeira operação que ele está realizando é a soma, a não ser que se ponha parênteses
	k = 2;
	j = (2 - 5.0) * 3;

	z = k + j < (v = 7);
	
	x = v < 7 && 10 != 1 || 5==2;
	x = true && false || true;

	int p;
	//int j; //isto ocasiona um erro, esta variável já foi declarada antes
	
	z = k;

	1 - 50;
	3 % 3;

	//"aa" + 10;

	cout(x);

	return 0;
}
