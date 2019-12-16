#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv)
{
	int numberOfHoles = 0;
	unordered_map<string, int> bills;

	cin >> numberOfHoles;

	if(numberOfHoles <= 0){
			cout << "There are no dirty bills." << endl;
			return 0;
	}

	for(int i=0; i < numberOfHoles; i++){
			string stateOfBills;
			int numberOfBills;

			cin >> numberOfBills;
			cin >> stateOfBills;

			if (bills.find(stateOfBills) != bills.end()) {
					//std::cout << "Key found";
					bills[stateOfBills] += numberOfBills;
			}
			else {
					//std::cout << "Key not found";
					bills[stateOfBills] = numberOfBills;
			}
	}

	cout << "There are " << bills["dirty"] << " dirty bills." << endl;
	return 0;
}
