#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv)
{
	int numOfIntegers = 0;
	cin >> numOfIntegers;
	vector<int> numbers;

	for(int i=0; i<numOfIntegers;i++){
			int numberToBeAdded;
			cin >> numberToBeAdded;
			numbers.push_back(numberToBeAdded);
	}

	sort(numbers.begin(), numbers.end());

	for(auto it = numbers.begin(); it != numbers.end(); it++)
			cout << *it << endl;

	return 0;
}
