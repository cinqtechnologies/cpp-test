/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int num_lines;
	cin  >> num_lines;
	string name, state, city, country, age;

	for (string s; getline(cin, s);)
  {
    if (s.size() > 0)
    {
      name    = s.substr(0,s.find_first_of(","));
      s       = s.substr(s.find_first_of(",") + 1, s.size());

			state   = s.substr(0,s.find_first_of(","));
			s       = s.substr(s.find_first_of(",") + 1, s.size());

			city    = s.substr(0,s.find_first_of(","));
		  s       = s.substr(s.find_first_of("," )+ 1, s.size());

			country = s.substr(0,s.find_first_of(","));
			s       = s.substr(s.find_first_of(",") + 1, s.size());

			age     = s;

      cout << name << " is " << age << " years old and lives in ";
			cout << city << ", " << state << "." << endl;

			if (--num_lines <= 0 ) break;
    }
  }

	return 0;
}
