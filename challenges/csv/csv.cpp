#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector> 

int main(int argc, char** argv)
{
	unsigned const CSV_FIELDS = 5;
	unsigned totalReps;
	std::string rawData;
	std::vector<std::string> myVec;
	
	std::cin >> totalReps;
	std::cin.ignore();

	if (totalReps > 0)
	{
		for (int inputReps = 0; inputReps < totalReps; inputReps++)
		{
			for (int csvField = 0; csvField < CSV_FIELDS-1; csvField++) // read up to ',' until last field, then read until new line
			{
				std::getline(std::cin, rawData, ',');
				myVec.push_back(rawData);
			}
			std::getline(std::cin, rawData);
			myVec.push_back(rawData);
		}
		for (int outputReps = 0; outputReps < totalReps; outputReps++)
		{
			std::cout << myVec[outputReps*CSV_FIELDS] << " is " << myVec[outputReps*CSV_FIELDS + 4] << " years old and lives in " << myVec[outputReps*CSV_FIELDS + 2] << ", " << myVec[outputReps*CSV_FIELDS + 1] << ".\n";
		}
	}
	else
	{
		std::cout << "Invalid number of lines.\n";
	}
	return 0;
}
