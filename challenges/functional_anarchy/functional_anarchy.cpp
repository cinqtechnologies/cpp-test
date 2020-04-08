#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv)
{
	int num_lines, number;
	vector<int> v_nums;

	cin >> num_lines;
	while (num_lines--) {
		cin >> number;
		v_nums.push_back(number);
	}

	sort(v_nums.begin(), v_nums.end());
	for_each(v_nums.begin(), v_nums.end(), [](int n) {
		cout << n << "\n";
	});

	return 0;
}
