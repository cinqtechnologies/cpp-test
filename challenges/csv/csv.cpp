#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
#include <vector>

int main(int argc, char** argv)
{
    std::vector<std::string> vec (5);
    std::vector<std::string>::iterator it;

    int nlines = 0;
    std::cin >> nlines;

    // Ignore CR
    std::cin.ignore();

    // Loop nlines
    while (nlines--)
    {
	// The first 4 columns ends with ,
	for(it = vec.begin(); it != vec.end() - 1; ++it)
	    std::getline(std::cin, *it, ',');
	
	// The last column ends with a CR
	std::getline(std::cin, *it, '\n');

	std::cout << vec.at(0) << " is "
		  << vec.at(4) << " years old and lives in "
		  << vec.at(2) << ", "
		  << vec.at(1) << "." << std::endl;
    }
    
    return 0;
}
