#include "../Tester.h"

#include <iostream>
#include <algorithm>
#include <string>

/**
 * This class represents a test case of the "dirty_bills" test, which has the goal of calculating
 * the amount of dirty bills from an input set of dirty and clean bills. 
 */
class DirtyBillsTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	DirtyBillsTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the number of bills that must be analyzed
		unsigned int billsCount = 0;
		if (inputLines.size() > 0)
		{
			std::string billsCountString = inputLines[0];
			try
			{
				billsCount = std::stoi(billsCountString);
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
		
		// Iterate through bills
		unsigned int dirtyBills = 0;
		for (unsigned int i = 0; i < billsCount; i++)
		{
			if (inputLines.size() > i + 1)
			{
				std::string billInformation = inputLines[i + 1];
				
				// Separate bill count and situation
				unsigned int countSpaces = std::count(billInformation.begin(), billInformation.end(), ' ');
				if (countSpaces != 1)
				{
					throw std::runtime_error("One of the lines of input file has an invalid format. Cannot perform test.");
				}
				std::string billCount = billInformation.substr(0, billInformation.find(' '));
				std::string billSituation = billInformation.substr(billInformation.find(' ') + 1);

				// Increase counter if current bills are dirty
				try
				{
					if (billSituation == "dirty")
					{
						dirtyBills += std::stoi(billCount);
					}
				}
				catch (const std::invalid_argument& e)
				{
					throw std::runtime_error("Bill count is not a valid integer. Cannot perform test.");
				}
				catch (const std::out_of_range& e)
				{
					throw std::runtime_error("Bill count is out of the range of possible integer values. Cannot perform test.");
				}
			}
			else
			{
				std::cerr << "Input file has a lower amount of bills than it is specified in the first line. Test results might be inconsistent." << std::endl;
				break;
			}
		}

		// Generate output
		if (dirtyBills > 0)
		{
			outputLines.push_back("There are " + std::to_string(dirtyBills) + " dirty bills.");
		}
		else
		{
			outputLines.push_back("There are no dirty bills.");
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
	DirtyBillsTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}