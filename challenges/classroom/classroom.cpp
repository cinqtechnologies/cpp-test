#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

	list<string> listSt;
	int nQueries;

	cin >> nQueries;
	cin.ignore();

	if (nQueries > 0) {

		string name, strOperation, strNOperation, strPosition;
		int operation, nOperation, position;

		for (int i = 0; i < nQueries; i++) {

			getline(cin, strOperation, ' ');
			getline(cin, strNOperation);

			operation = atoi(strOperation.c_str());
			nOperation = atoi(strNOperation.c_str());

			if (nOperation <= 0) {

				cout << "Invalid number of operations.\n";

			}	else {

				switch(operation) {

					case 1: // Insert student
					for (int i = 0; i < nOperation; i++) {

						getline(cin, name);
						listSt.push_back(name);

					}
					listSt.sort();
					break;

					case 2: // Find student at position
					for (int i = 0; i < nOperation; i++) {

						getline(cin, strPosition);
						position = atoi(strPosition.c_str());

						if ((position > 0) && (position < listSt.size()))	{

							list<string>::iterator iList = listSt.begin();
							advance(iList, position-1);
							cout << *iList << "\n";

						}
					}
					break;

					default:
					cout << "Invalid operation.\n";
				}
			}
		}
	}	else {

		cout << "Invalid number of queries.\n";

	}

	return 0;

}
