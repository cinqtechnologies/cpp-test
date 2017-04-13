/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

bool compareAlpha(string a, string b) {
    return a.compare(b) < 0;
}

int main(int argc, char** argv)
{

	vector<string> l;
	int num_queries;
	int a,b;
	string first, second;
	int count = 0;

	cin >> num_queries;

		for(string s; getline(cin, s);)
		{
			if(s.size()>0)
			{
				count++;
				first  = s.substr(0,s.find_first_of(" "));
				second = s.substr(s.find_first_of(" ") + 1,s.size());

				a = atoi(first.c_str());
				b = atoi(second.c_str());

				if(a == 1)
				{
					for(int j=0; j<b ;j++)
					{
						string entry;
						getline(cin, entry);
						l.push_back(entry);
					}
					sort(l.begin(), l.end(), compareAlpha);
				}
				else if(a == 2)
				{
					for(int j=0; j<b ;j++)
					{
						int index;
						cin >> index;
						index--;
						if(l.size() > index)
						{
							cout << l[index] << endl;
						}
					}
				}

			}
			if(count>=num_queries) break;
		}


	return 0;
}
