#include "../Tester.h"

#include <iostream>
#include <algorithm>
#include <string>

/**
 * This class represents a test case of the "palindrome" test, which has the goal of evaluating if
 * the received input words are palindromes.
 */
class PalindromeTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	PalindromeTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the number of words that must be evaluated
		unsigned int wordCount = 0;
		if (inputLines.size() > 0)
		{
			std::string wordCountString = inputLines[0];
			try
			{
				wordCount = std::stoi(wordCountString);
			}
			catch (const std::invalid_argument& e)
			{
				throw std::runtime_error("First line of input file is not a valid integer. Cannot perform test.");
			}
			catch (const std::out_of_range& e)
			{
				throw std::runtime_error("Number of words is out of the range of possible integer values. Cannot perform test.");
			}
		}
		else
		{
			throw std::runtime_error("Input file does not contain the number of words to be evaluated. Cannot perform test.");
		}
		
		// Iterate through word pairs
		for (unsigned int i = 0; i < wordCount; i++)
		{
			if (inputLines.size() > i + 1)
			{
				std::string word = inputLines[i + 1];
				
				// Sort words by alphabetical order
				std::string inverseWord = word;
				std::reverse(inverseWord.begin(), inverseWord.end());

				// If word equals its reverse, then it is a palindrome
				if (word == inverseWord)
				{
					outputLines.push_back(word + " is palindrome");
				}
				else
				{
					outputLines.push_back(word + " is not palindrome");
				}
				
			}
			else
			{
				std::cerr << "Input file has less words than it is specified in the first line. Test results might be inconsistent." << std::endl;
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
	PalindromeTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}