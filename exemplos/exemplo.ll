int fibonacci(int);
string printFibonacciSequence(int);
void printDiagonalMatrix(void);
int fat(int n);
printEven(int n);

int main(void)
{
	int n;
	cin(n);
	
	coutn(printFibonacciSequence(n));
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

	res += "\n[ ";

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

		cout(i);
	}
}
