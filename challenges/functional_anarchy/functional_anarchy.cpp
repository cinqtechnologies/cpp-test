#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv) {

	int nLines, num;
	vector<int> array;

	cin >> nLines;

	for (int i = 0; i < nLines; i++)	{
		cin >> num;
		array.push_back(num);
	}

	sort(array.begin(), array.end());

	vector<int>::iterator iArray;
	iArray = array.begin();

	while (iArray != array.end()) {

		cout << *iArray << "\n";

		iArray++;
	}


	return 0;
}
