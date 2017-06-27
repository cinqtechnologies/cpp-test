#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main(int argc, char** argv)
{
	int numberOfIntegers;
	std::cin >> numberOfIntegers;

	std::vector<int> integers;
	while(numberOfIntegers-- > 0)
	{
		int line;
		std::cin >> line;
		integers.push_back(line);
	}

	std::sort(integers.begin(), integers.end());

	for (std::vector<int>::iterator it = integers.begin(); it != integers.end(); ++it)
		std::cout << *it << std::endl;
}
