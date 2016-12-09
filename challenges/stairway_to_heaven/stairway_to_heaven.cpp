#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv)
{
	int nLines = 0;
	std::cin >> nLines;
	std::string step = "";
	for (int n = 0; n < nLines; n++)
	{
		step += '#';
		std::cout << std::setfill(' ') << std::setw(nLines);
		std::cout << step << std::endl;
	}
	return 0;
}
