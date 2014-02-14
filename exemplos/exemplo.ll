int main(void)
{

	int d;
	int size;
	
	cout("\nEnter the value to d: ");
	cin(d);

	int matrix[3][3];

	// fill the diagonal of matrix with d
	for (int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			if (i == j)
				matrix[i][j] = d;
			else
				matrix[i][j] = 0;
		}

	// print matrix
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout(matrix[i][j] + " ");
		}
		coutn();
	}

	return 0;
}


