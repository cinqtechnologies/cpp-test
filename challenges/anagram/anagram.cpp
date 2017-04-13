/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare_pair(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1==str2;
}

int main(int argc, char** argv)
{
	int num_lines;
	string first, second;
	cin  >> num_lines;

  for (string s; getline(cin, s);)
  {
    if (s.size() > 0)
    {
      first = s.substr(0,s.find_first_of(" "));
      second = s.substr(s.find_first_of(" ") + 1,s.size());

      if(compare_pair(first, second))
        cout << first << " is an anagram of " << second << endl;
      else
        cout << first << " is not an anagram of " << second << endl;

      num_lines--;
    }
    if (num_lines == 0) break;
  }

	return 0;
}
