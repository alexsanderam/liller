int main()
{        
        /*Aqui é um comentário
        Este arquivo é de exemplo da Linguagem Liller
        e do Compilador prescot-liller.*/
        
	bool x = true;
	int y = 50, z = 20;
	bool k = true;

	//y+z = 70	z-y = -30; -0.1*k*y = -5
	k = y+z < 30 || (z-y < -0.1*k+y && 10 >= x*10);

	cout(k);

	//resultado esperado: verdadeiro
	
	
        return 0;
}
