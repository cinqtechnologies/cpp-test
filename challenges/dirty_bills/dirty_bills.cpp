#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

	int nDirty = 0;
	unsigned nLines;
	string strInput;

	cin >> nLines;

	for (int i = 0; i < nLines; i++) {

		cin >> strInput;

		if (strInput.find("dirty") != string::npos)	{

			nDirty += stoi(strInput);

		}
	}

	cout << "There are " << nDirty << " dirty bills.\n";


	return 0;

}
