#include "../Tester.h"

#include <iostream>
#include <string>

/**
 * This class represents a test case of the "stairway_to_heaven" test, which has the goal of drawing
 * a staircase with a given number of steps.
 */
class StairwayToHeavenTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	StairwayToHeavenTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the number of steps for the staircase
		int steps = 0;
		if (inputLines.size() > 0)
		{
			std::string stepsString = inputLines[0];
			try
			{
				steps = std::stoi(stepsString);
			}
			catch (const std::invalid_argument& e)
			{
				throw std::runtime_error("First line of input file is not a valid integer. Cannot perform test.");
			}
			catch (const std::out_of_range& e)
			{
				throw std::runtime_error("Number is out of the range of possible integer values. Cannot perform test.");
			}
		}
		else
		{
			throw std::runtime_error("Input file does not contain a valid number. Cannot perform test.");
		}
		
		// Print error message for invalid inputs
		if (steps < 1)
		{
			outputLines.push_back("Error.");
		}
		else
		{
			// Draw staircase: starting from i = 1, the i-th line is the concatenation of (n-i) spaces and i '#' characters
			for (int i = 1; i <= steps; i++)
			{
				outputLines.push_back(std::string(steps - i, ' ') + std::string(i, '#'));
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
	StairwayToHeavenTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}