#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{

	int nLevel;
	string stairLevel = "";

	cin >> nLevel;
	cin.ignore();

	for(int i = 0; i < nLevel; i ++) {

		stairLevel += '#';
		cout << std::setfill(' ') << std::setw(nLevel);
		cout << stairLevel << endl;

	}

	return 0;
}
