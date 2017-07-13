#include <iostream>
#include <string>
#include <iomanip>

void print_stairway(int size)
{
    int hashes = 1;

    for(hashes = 1; hashes <= size; hashes ++)
	std::cout << std::setw(size) << std::string(hashes, '#') << std::endl;
}

int main(int argc, char** argv)
{
    int size;
    std::cin >> size;

    if(size <= 0)
	std::cout << "Error." << std::endl;
    else
	print_stairway(size);
    
    return 0;
}
