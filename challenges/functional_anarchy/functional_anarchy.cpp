#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv)
{
	int lines_to_read = 0;
	cin >> lines_to_read;
	vector<int> numbers;

	for(int i=0; i<lines_to_read; i++) {
			int next_number;
			cin >> next_number;
			numbers.push_back(next_number);
	}

	sort(numbers.begin(), numbers.end());

	for(auto it = numbers.begin(); it != numbers.end(); it++) {
			cout << *it << endl;
	}
	
	return 0;
}
