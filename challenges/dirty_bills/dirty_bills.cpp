#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	unsigned numLines;
	int dirtyBills = 0;
	std::string rawInput;
	std::cin >> numLines;
	while (numLines--)
	{
		std::cin >> rawInput;
		if (rawInput.find("dirty") != std::string::npos)
		{
			dirtyBills += std::stoi(rawInput);
		}
	}
	std::cout << "There are " << dirtyBills << " dirty bills.\n";
	return 0;
}
