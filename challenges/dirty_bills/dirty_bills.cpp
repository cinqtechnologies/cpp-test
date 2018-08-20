#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	int n, dirty = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int number;
		std::string dirtyOrClean;
		std::cin >> number;
		std::cin >> dirtyOrClean;
		if (dirtyOrClean.compare("dirty") == 0) {
			dirty += number;
		}
	}

	if (dirty == 0) {
		std::cout << "There are no dirty bills." << std::endl;
	} else {
		std::cout << "There are " << dirty << " dirty bills." << std::endl;
	}	
	

	return 0;
}
