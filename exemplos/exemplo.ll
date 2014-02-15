int main(void)
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

	return 0;
}


