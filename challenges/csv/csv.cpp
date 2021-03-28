#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	string entry_count;
	getline(cin, entry_count);
	stringstream ss_entries(entry_count);
	int entries;
	ss_entries >> entries;

	for(int entry = 0; entry < entries; entry++){
			//cout << entry << endl;
			string name, city, state, country, age;
			getline(cin, name, ',');
			getline(cin, state, ',');
			getline(cin, city, ',');
			getline(cin, country, ',');
			getline(cin, age);

			cout << name << " is " << age << " years old and lives in " << city << ", " << state << "." << endl;
	}

	return 0;
}
