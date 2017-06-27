#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	int numberOfBills;
	std::cin >> numberOfBills;

	int sumOfDirtyBills = 0;
	int number;
	std::string billType;
	while(numberOfBills-- > 0)
	{
		std::cin >> number;
		std::cin >> billType;

		if (billType == "dirty")
			sumOfDirtyBills += number;
	}


	if (sumOfDirtyBills > 0)
		std::cout << "There are " << sumOfDirtyBills << " dirty bills.";
	else
		std::cout << "There are no dirty bills.";

	std::cout << std::endl;
}
