#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace Contact {
	enum Type {
		NAME, STATE, CITY, COUNTRY, AGE
	};
}

struct ContactInformation {
	std::string info[5];
};

void readContactInformation(ContactInformation& ci, std::istream& stream)
{
	for (int i = 0; i < 5; ++i) {
		std::string columnContent;
		if (i == 4)
			stream >> columnContent;
		else
			std::getline(stream, columnContent, ',');
		ci.info[i] = columnContent;
	}
}

int main(int argc, char** argv) {

	int numberOfEntries;
	std::cin >> numberOfEntries;
	std::cin.ignore();

	while (numberOfEntries-- > 0) {
		ContactInformation ci;

		readContactInformation(ci, std::cin);

		std::cout << ci.info[Contact::NAME] << " is " << ci.info[Contact::AGE]
				<< " years old and lives in " << ci.info[Contact::CITY] << ", "
				<< ci.info[Contact::STATE] << ".";
	}

	std::cout << std::endl;
	return 0;
}
