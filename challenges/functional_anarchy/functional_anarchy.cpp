#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main(int argc, char** argv)
{
	int itens = 0;
	int number = 0;

	std::vector<int> numbers;

	std::cin >> itens;

	while (itens > 0)
	{
		std::cin >> number;

		numbers.push_back(number);

		--itens;
	}

	std::sort(numbers.begin(), numbers.end());

	// Prints the set of numbers
	std::vector<int>::iterator it;
	for (it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}
