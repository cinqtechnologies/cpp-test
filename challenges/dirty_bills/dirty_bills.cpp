/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int num_lines;
	int dirty_amount = 0;
	int count = 0;
	string first, second;

	cin >> num_lines;

	for(string s; getline(cin, s);)
	{
		if(s.size()>0)
		{
			count++;
			first  = s.substr(0,s.find_first_of(" "));
			second = s.substr(s.find_first_of(" ") + 1,s.size());

			int a    = atoi(first.c_str());
			string b = second;

			if(b == "dirty") dirty_amount += a;
		}
		if(count>=num_lines) break;
	}
	if(dirty_amount>0) cout << "There are " << dirty_amount << " dirty bills.";
	else               cout << "There are no dirty bills.";

	return 0;
}
