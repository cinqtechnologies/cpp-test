#include "../Tester.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

/**
 * This class represents a test case of the "functional_anarchy" test, which has the goal of sorting
 * the sequence of numbers received as input.
 */
class FunctionalAnarchyTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	FunctionalAnarchyTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// Read all numbers from file
		unsigned int sequenceLength = 0;
		std::vector<int> sequenceNumbers;
		for (auto iterator = inputLines.begin(); iterator != inputLines.end(); iterator++)
		{
			// Parse current line as an integer
			int number;
			std::string numberString = *iterator;
			try
			{
				number = std::stoi(numberString);
			}
			catch (const std::invalid_argument& e)
			{
				throw std::runtime_error("First line of input file is not a valid integer. Cannot perform test.");
			}
			catch (const std::out_of_range& e)
			{
				throw std::runtime_error("Sequence length is out of the range of possible integer values. Cannot perform test.");
			}

			// If this is the first line, number read is the sequence length
			if (iterator == inputLines.begin())
			{
				sequenceLength = number;
			}

			// Otherwise, append it to sequence
			else
			{
				sequenceNumbers.push_back(number);
			}
		}

		// Sort sequence and generate output
		std::sort(sequenceNumbers.begin(), sequenceNumbers.end());
		for (auto iterator = sequenceNumbers.begin(); iterator != sequenceNumbers.end(); iterator++)
		{
			outputLines.push_back(std::to_string(*iterator));
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
	FunctionalAnarchyTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}