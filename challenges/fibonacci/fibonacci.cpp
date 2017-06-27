#include <iostream>

long long fibonacci(size_t fibonacciIndex)
{
	if (fibonacciIndex < 2)
		return fibonacciIndex;

	long long current = 1;
	long long previous = 0;
	for (int i = 1; i < fibonacciIndex; i++)
	{
		long long sum = current + previous;
		previous = current;
		current = sum;
	}

	return current;
}

int main(int argc, char** argv)
{
	int fibonacciIndex;
	std::cin >> fibonacciIndex;
	std::cout << fibonacci(fibonacciIndex);
}
