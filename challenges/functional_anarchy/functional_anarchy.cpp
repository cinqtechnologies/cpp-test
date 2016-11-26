/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Anarquia Funcional
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	int num;
	vector<int> vetor;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> num;
		vetor.push_back(num);
	}

	sort(vetor.begin(),vetor.end());

	for(int i = 0; i < N; i++)
	{
		cout << vetor[i] << endl;
	}

	return 0;
}

