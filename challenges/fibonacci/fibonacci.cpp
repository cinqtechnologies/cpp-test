#include "../Tester.h"

#include <iostream>
#include <string>

/**
 * This class represents a test case of the "fibonacci" test, which has the goal of evaluating the
 * n-th term of the Fibonacci sequence.
 */
class FibonacciTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	FibonacciTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the desired ordinal number for the Fibonacci sequence
		unsigned int n = 0;
		if (inputLines.size() > 0)
		{
			std::string nString = inputLines[0];
			try
			{
				n = std::stoi(nString);
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
		
		// Compute Fibonacci sequence until given number
		/* Variables are declared as "unsigned long int" because the fibonacci sequence may larger results than
			the "unsigned int" maximum value. */
		unsigned long int secondLast = 0;
		unsigned long int last = (n == 0) ? 0 : 1;
		while (n-- > 1)
		{
			unsigned long int temp = secondLast;
			secondLast = last;
			last += temp;
		}
		outputLines.push_back(std::to_string(last));
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
	FibonacciTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}