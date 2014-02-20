int fibonacci(int);
void printFibonacciSequence(int);

int main(void)
{
	int n;
	cout("\nEnter the value for n: ");
	cin(n);

	coutn("Fibonacci(" + n + ") = " + fibonacci(n));

	printFibonacciSequence(n);

	return 0;
}

int fibonacci(int n)
{
	if (n <= 1)
		return 1;

	return fibonacci(n-1) + fibonacci(n-2);
}

void printFibonacciSequence(int n)
{
	
	cout("\n[ ");
	for (int i = 1; i <= n; i++)
	{
		cout(fibonacci(i) + " ");
	}

	coutn("]");
}
