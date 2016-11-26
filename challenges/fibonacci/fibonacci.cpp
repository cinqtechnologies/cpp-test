/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Fibonacci
Processo Seletivo CINQ
************************************************************/
#include <iostream>

using namespace std;

unsigned long int fibonacci(int num);

int main(int argc, char** argv)
{
	int X;

	cin >> X;
	cout << fibonacci(X) << endl;	

	return 0;
}

unsigned long int fibonacci(int num)
{

	unsigned long int valor[num];

	valor[0] = 0;
	valor[1] = 1;
	for(int i = 2; i <= num; i++)
	{
		valor[i] = valor[i-1] + valor[i-2];
	}
	
	return valor[num];
}
