#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i-1; j++) {
			std::cout << " ";
		}
		for (int j = 0; j < i+1; j++) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}	
	
	return 0;
}
