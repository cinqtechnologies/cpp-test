/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Dirty Bills
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{	
	int N;
	int dinheiro;
	int dinheiroSujo = 0;
	string dinheiroEstado;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> dinheiro;
		cin >> dinheiroEstado;

		if(dinheiroEstado == "dirty")
		{
			dinheiroSujo += dinheiro;
		}
		
	}
	

	if(dinheiroSujo != 0)
	{
		cout << "There are " << dinheiroSujo << " dirty bills." << endl;
	}
	else
	{
		cout << "There are no dirty bills." << endl;
	}

	return 0;
}
