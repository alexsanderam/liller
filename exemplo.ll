
int main()
{	
	int i = 1;
	int j = 0;

	if(i < 2)
	{
		j+= 2;
		cout("Entrou no If(1)");
		
		if(j > 3)
			cout("Entrou no If(1.2)");
		else
			cout("Entrou no Else(1.2)");
	}
	else if (i == 2)
		cout("Entrou no ElseIf(1.1)");
	else
		cout("Entrou no Else(1)");

	
	if(i != 3)
		cout("Entrou no If(2), pois i == 3");

	return 0;
}
