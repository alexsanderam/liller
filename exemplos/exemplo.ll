int fibonacci(int);
string printFibonacciSequence(int);
void printDiagonalMatrix(void);
int fat(int n);
printEven(int n);

int main(void)
{
	bool menu = true;
	int op;
	int n;

	do
	{
		coutn("Entre com uma opção: ");
		coutn("\t[0] - Sair");
		coutn("\t[1] - Diagonal de matriz");
		coutn("\t[2] - Sequência de Fibonacci");
		coutn("\t[3] - Fatorial");
		coutn("\t[4] - Imprimir pares menores que");

		cin(op);

		switch (op)
		{
			case 0:
				menu = false;
				break;
			case 1:
				printDiagonalMatrix();
				break;
			case 2:
				coutn("Entre com um inteiro:");
				cin(n);
				cout(fibonacci(n) + ": " + printFibonacciSequence(n));
				break;
			case 3:
				coutn("Entre com um inteiro:");
				cin(n);
				coutn(fat(n) + "\n");
				break;
			case 4:
				coutn("Entre com um inteiro:");
				cin(n);
				printEven(n);
				break;
			default:
				coutn("Opção inválida");
				break;
		}

	} while(menu);

	return 0;
}

void printDiagonalMatrix()
{
	int d;
	int size;
	
	cout("\nEnter the value to d: ");
	cin(d);

	cout("\nEnter the size of matrix: ");
	cin(size);

	int matrix[size][size];

	// fill the diagonal of matrix with d
	for (int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
		{
			if (i == j)
				matrix[i][j] = d;
			else
				matrix[i][j] = 0;
		}

	// print matrix
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cout(matrix[i][j] + " ");
		}
	coutn();
	}
}

int fibonacci(int n)
{
	if (n <= 1)
		return 1;

	return fibonacci(n-1) + fibonacci(n-2);
}

string printFibonacciSequence(int n)
{
	int resd;
	string res = "";

	res += "[ ";

	for (int i = 1; i <= n; i++)
	{
		res += fibonacci(i) + " ";
	}

	res += "]";
	return res;
}

int fat(int n)
{
	int i = 1;
	int fat = 1;

	for(i = 1..n)
	{
		fat *= i;	
	}

	return fat;
}

printEven(int n)
{
	int i = 0;
	while(i <= n)
	{
		i++;
		if(i % 2 == 1)
			continue;

		cout(i + " ");
	}

	coutn();
}
