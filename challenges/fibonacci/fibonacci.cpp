#include <iostream>


// Function: getFibonacci
//
// Returns the n-th fibonacci number defined at 0-based 'index'
// 
int64_t getFibonacci(int index)
{
	int64_t first = 0, second = 1;

	while (index > 1) // or index >= 2, which excludes seeds 'first' and 'second' (0 and 1)
	{
		first = first + second;
		second = second + first;

		index -= 2;
	}	

	return (index % 2 == 0 ? first : second);
}

int main(int argc, char** argv)
{
	int index = 0;

	std::cin >> index;

	if (index >= 0)
	{
		int64_t	fibonacci = getFibonacci(index);
		std::cout << fibonacci << std::endl;
	}

	return 0;
}
