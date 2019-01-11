#include <iostream>

long int get_fibonacci(int index)
{
	long int first = 0, second = 1;

	while (index > 1) /* or index >= 2 */
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
		std::cout << get_fibonacci(index) << std::endl;
	}

	return 0;
}
