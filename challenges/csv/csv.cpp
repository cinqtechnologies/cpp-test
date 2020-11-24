#include "../Tester.h"

#include <iostream>
#include <string>
#include <vector>

/**
 * This class represents a test case of the "csv" test, which has the goal of evaluating
 * tabular data from input in CSV format.
 */
class CsvTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	CsvTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the number of rows that must be read
		unsigned int dataCount = 0;
		if (inputLines.size() > 0)
		{
			std::string dataCountString = inputLines[0];
			try
			{
				dataCount = std::stoi(dataCountString);
			}
			catch (const std::invalid_argument& e)
			{
				throw std::runtime_error("First line of input file is not a valid integer. Cannot perform test.");
			}
			catch (const std::out_of_range& e)
			{
				throw std::runtime_error("Number of word pairs is out of the range of possible integer values. Cannot perform test.");
			}
		}
		else
		{
			throw std::runtime_error("Input file does not contain the number of word pairs to be evaluated. Cannot perform test.");
		}
		
		// Iterate through table rows
		for (unsigned int i = 0; i < dataCount; i++)
		{
			if (inputLines.size() > i + 1)
			{
				std::string tabularData = inputLines[i + 1];
				
				// Split tabular data using ',' as delimiter
				std::vector<std::string> dataFields;
				size_t pos = tabularData.find(',');
				while (pos != std::string::npos)
				{
					dataFields.push_back(tabularData.substr(0, pos));
					tabularData.erase(0, pos + 1);
					pos = tabularData.find(',');
				}
				dataFields.push_back(tabularData);
				
				// Check if number of fields equals 5
				if (dataFields.size() != 5)
				{
					throw std::runtime_error("Line from input file does not contain 5 data fields. Cannot perform test.");
				}

				// Generate output
				outputLines.push_back(dataFields[0] + " is " + dataFields[4] + " years old and lives in " + dataFields[2] + ", " + dataFields[1] + ".");
			}
			else
			{
				std::cerr << "Input file has a lower amount of rows than it is specified in the first line. Test results might be inconsistent." << std::endl;
				break;
			}
		}
	}
};

/**
 * Program main function, returns an output text based on received inputs.
 * 
 * @param argc Number of arguments received from command line
 * @param argv Array of arguments received from command line
 */
int main(int argc, char** argv)
{
	CsvTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}