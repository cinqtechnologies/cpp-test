#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printSpaces(int n){
		for(int i =0; i < n; i++)
				cout << " ";
}

void printStairs(int n){
	for(int i =0; i < n; i++)
			cout << "#";
	cout << endl;
}

int main(int argc, char** argv)
{
		int numberOfLevels = 0;

		cin >> numberOfLevels;
		if(numberOfLevels <=0){
				cout << "Error." << endl;
				return 0;
		}

		for(int i = numberOfLevels-1; i >=0; i--){
				printSpaces(i);
				printStairs(numberOfLevels-i);
		}

		return 0;
}
