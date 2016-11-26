/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Csv
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#define CAMPOS_NUM 5
#define STRING_INICIO 0
using namespace std;

enum CAMPO
{
	nome = 0,
	estado,
	cidade,
	pais,
	idade
};

int main(int argc, char** argv)
{
	int N;
	size_t virgula;
	string linha;
	string campo[CAMPOS_NUM];

	cin >> N;
	cin.ignore();

	for(int i = 0; i < N; i++)
	{
		getline(cin,linha);

		for(int i = 0; i < CAMPOS_NUM; i++)
		{
			virgula = linha.find(",");
			campo[i] = linha.substr(STRING_INICIO,virgula);
			linha.erase(STRING_INICIO,campo[i].length()+1);
		}

		cout << campo[nome] << " is " << campo[idade] << " years old and lives in " << campo[cidade] << ", " << campo[estado] << "." << endl;
	}

	return 0;
}

