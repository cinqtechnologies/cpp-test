/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int num_lines;
	cin  >> num_lines;

	for(string s; getline(cin, s);)
	{
		if(s.size()>0)
		{
			if(s == string(s.rbegin(), s.rend())) cout << s << " is palindrome"   	<< endl;
			else															    cout << s << " is not palindrome" << endl;

			if(--num_lines <= 0) break;
		}
	}
	return 0;
}
