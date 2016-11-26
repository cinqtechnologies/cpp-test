/***********************************************************
Desenvolvedor: Thiago Moreira
Engenheiro Eletrônico
thiagofrosty@hotmail.com
Programa: Anagrama
Processo Seletivo CINQ
************************************************************/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool verificaAnagrama(string s1, string s2);

int main(int argc, char** argv)
{

	int n;
	string palavra1, palavra2;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> palavra1;
		cin >> palavra2;
		if(verificaAnagrama(palavra1,palavra2))
		{
			cout << palavra1 <<" is an anagram of "<< palavra2 << endl;
		}

		else
		{
			cout << palavra1 <<" is not an anagram of "<< palavra2 << endl;
		}

	} 

return 0;
}

bool verificaAnagrama(string s1, string s2)
{
	size_t f;

	if(s1.size() != s2.size())
	{
		return false;
	}

	for(int i = 0; i < s1.size(); i++)
	{
		f = s2.find(s1[i]); 
		if (f == string::npos)  
		{
			return false;
		}
	}


return true;
}



