#include <iostream>

long fibonacci (int x)
{
	long result = 0;
	long last = 1;

	for (int i = 0; i < x; i++) {
		result += last;
		last = result - last;
	}

	return result;
}

int main(int argc, char** argv)
{
	unsigned int n;
	std::cin >> n;

	std::cout << fibonacci(n) << std::endl;

	return 0;
}


