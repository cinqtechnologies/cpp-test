#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#define NFIELDS 5
#define INITIALSTR 0

using namespace std;

enum FIELDS
{
		name = 0,
		state,
		city,
		country,
		age
};

int main(int argc, char** argv) {

	int nLines;
	size_t comma;
	string line, fields[NFIELDS], auxStr;
	vector<string> list;

	cin >> nLines;
	cin.ignore();

	for(int i = 0; i < nLines; i++) {

		getline(cin,line);

		for(int i = 0; i < NFIELDS; i++) {

			comma = line.find(",");

			fields[i] = line.substr(INITIALSTR, comma);
			line.erase(INITIALSTR, fields[i].length()+1 );

		}

		auxStr = fields[name] + " Is " + fields[age] + " years old and lives in " + fields[city] + ", " + fields[state] + ".";
		list.push_back(auxStr);

	}

	for (unsigned n = 0; n < list.size(); n++) {
        cout << list.at(n) << endl;
  }

	return 0;
}
