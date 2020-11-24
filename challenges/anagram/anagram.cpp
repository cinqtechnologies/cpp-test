#include "../Tester.h"

#include <iostream>
#include <algorithm>
#include <string>

/**
 * This class represents a test case of the "anagram" test, which has the goal of evaluating if
 * the received input words are anagrams of each other.
 */
class AnagramTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	AnagramTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the number of word pairs that must be evaluated
		unsigned int pairCount = 0;
		if (inputLines.size() > 0)
		{
			std::string pairCountString = inputLines[0];
			try
			{
				pairCount = std::stoi(pairCountString);
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
		
		// Iterate through word pairs
		for (unsigned int i = 0; i < pairCount; i++)
		{
			if (inputLines.size() > i + 1)
			{
				std::string line = inputLines[i + 1];
				
				// Separate first and second words
				unsigned int countSpaces = std::count(line.begin(), line.end(), ' ');
				if (countSpaces != 1)
				{
					throw std::runtime_error("One of the lines of input file does not have exactly two words. Cannot perform test.");
				}
				std::string firstWord = line.substr(0, line.find(' '));
				std::string secondWord = line.substr(line.find(' ') + 1);

				// Sort words by alphabetical order
				std::string originalFirstWord = firstWord;
				std::string originalSecondWord = secondWord;
				std::sort(firstWord.begin(), firstWord.end());
				std::sort(secondWord.begin(), secondWord.end());

				// If sorted strings are equal, they are anagrams
				if (firstWord == secondWord)
				{
					outputLines.push_back(originalFirstWord + " is an anagram of " + originalSecondWord);
				}
				else
				{
					outputLines.push_back(originalFirstWord + " is not an anagram of " + originalSecondWord);
				}		
			}
			else
			{
				std::cerr << "Input file has a lower amount of word pairs than it is specified in the first line. Test results might be inconsistent." << std::endl;
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
	AnagramTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}