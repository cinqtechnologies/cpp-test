/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Palíndromo
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	string str;
	string strInv;

	cin >> N;

	for(int i = 0; i < N; i ++)
	{
		cin >> str;
		
		strInv = str;
		reverse(strInv.begin(),strInv.end());
		if(str == strInv)
		{
			cout << str << " is palindrome" << endl;
		}
		else
		{
			cout << str << " is not palindrome" << endl;  
		}

	}

	return 0;
}
