#include <iostream>


long long internFibonacci(size_t fibonacciIndex, long long previous, long long current)
{
	if (fibonacciIndex == 0)
		return current;

	return internFibonacci(fibonacciIndex - 1, current, current + previous);
}

long long fibonacci(size_t fibonacciIndex)
{
	if (fibonacciIndex < 2)
		return fibonacciIndex;

	long long current = 1;
	long long previous = 0;
	return internFibonacci(fibonacciIndex - 1, previous, current);
}

int main(int argc, char** argv)
{
	int fibonacciIndex;
	std::cin >> fibonacciIndex;
	std::cout << fibonacci(fibonacciIndex);
}
