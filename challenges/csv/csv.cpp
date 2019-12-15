#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// John Doe,Washington,Olympia,USA,33
// Rachel Doe,Washington,Olympia,USA,19
// Mark Schmidtt,Oregon,Portland,USA,25
// Kelly Barber,California,San Diego,USA,12
// Anna Dalcol,Paraná,Curitiba,BRA,28

void printData(string name, string city, string state, string country, string age){
		//Renee Rice is 56 years old and lives in Atlanta, Georgia.
		cout << name << " is " << age << " years old and lives in " << city << ", " << state << "." << endl;
}

int main(int argc, char** argv)
{
	string numberOfEntries;
	getline(cin, numberOfEntries);
	stringstream ssEntries(numberOfEntries);
	int entries;
	ssEntries >> entries;
	
	for(int entry = 0; entry < entries; entry++){
			//cout << entry << endl;
			string name, city, state, country, age;
			getline(cin, name, ',');
			getline(cin, state, ',');
			getline(cin, city, ',');
			getline(cin, country, ',');
			getline(cin, age);

			printData(name, city, state, country, age);
	}

	return 0;
}
