/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Starway to Heaven
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	string andar("");
	
	cin >> N;

	if(N <= 0)
	{
		cout << "Error." << endl;
		return 0;
	}

	for(int i = 0; i < N; i ++)
	{
		cout << setfill (' ') << setw (N);
		andar.push_back('#');
		cout << andar << endl;		
	}

	return 0;
}
