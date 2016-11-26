/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Classroom
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

void inserirEstudante(list<string> *t);
void consultarEstudante(list<string> *t);

int main(int argc, char** argv)
{
	list<string> turma;
	int N;
	int Q;

	cin >> N;

	for(int i  = 0; i < N; i++)
	{
		cin >> Q;

		if(Q == 1)
		{
			inserirEstudante(&turma);
		}

		if(Q == 2)
		{
			consultarEstudante(&turma);
		}
	}

	return 0;
}

void inserirEstudante(list<string> *t)
{
	int repeticoesQuerie;
	string aluno;
	string alunoSobrenome;

	cin >> repeticoesQuerie;

	for(int i = 0; i < repeticoesQuerie; i++)
	{
		cin >> aluno;
		cin >> alunoSobrenome;
		aluno.append(" ");
		aluno.append(alunoSobrenome);	

		t->push_back(aluno);
	}
	
	t->sort();
}

void consultarEstudante(list<string> *t)
{
	int repeticoesQuerie;
	int ordemConsulta;

	cin >> repeticoesQuerie;

	for(int i = 0; i < repeticoesQuerie; i++)
	{

		cin >> ordemConsulta;

		list<string>::iterator alunoConsultado;
		alunoConsultado = t->begin();
		for(int i = 1; i < ordemConsulta; i++)
		{
			alunoConsultado++;
		}

		cout <<*alunoConsultado << endl;
	}
}






