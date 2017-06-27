#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv)
{

	int sizeOfStaircase;
	std::cin >> sizeOfStaircase;

	if (sizeOfStaircase <= 0)
	{
		std::cout << "Error." << std::endl;
		return -1;
	}

	for (int i = sizeOfStaircase - 1; i >= 0; --i)
		std::cout << std::string(i, ' ') << std::string(sizeOfStaircase - i, '#') << std::endl;
}
