#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main(int argc, char** argv)
{
	int n;
	std::vector<int> numbers;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int number;
		std::cin >> number;
		numbers.push_back(number);
	}

	std::sort (numbers.begin(), numbers.end());

	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
