#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;
	std::cin.get();

	for (int i = 0; i < n; i++) {
		std::string line;
		getline(std::cin, line);
		std::vector<std::string> fields;
		std::string field;
		std::stringstream stream(line);
		while(std::getline(stream, field, ','))
		{
			fields.push_back(field);
		}
		
		std::cout << fields[0] << " is " << fields[4] << " years old and lives in " << fields[2] << ", " << fields[1] << "." << std::endl;
	}

	return 0;
}
