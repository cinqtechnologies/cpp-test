#include "../Tester.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Enumeration with possible query types.
 */
enum ClassroomQueryType
{
	INSERT = 1,
	CONSULT
};

/**
 * This class represents a test case of the "classroom" test, which has the goal of generating
 * a queriable list of the present students from an input file.
 */
class ClassroomTester : public Tester
{

public:

	/**
	 * Class constructor.
	 */
	ClassroomTester() : Tester() {}
	
	/**
     * Method that performs specific logic for "anagram" test cases.
     */
    void logic()
	{
		// First line is the number of queries
		unsigned int nQueries = 0;
		if (inputLines.size() > 0)
		{
			std::string nQueriesString = inputLines[0];
			try
			{
				nQueries = std::stoi(nQueriesString);
			}
			catch (const std::invalid_argument& e)
			{
				throw std::runtime_error("First line of input file is not a valid integer. Cannot perform test.");
			}
			catch (const std::out_of_range& e)
			{
				throw std::runtime_error("Number of queries is out of the range of possible integer values. Cannot perform test.");
			}
		}
		else
		{
			throw std::runtime_error("Input file does not contain the number of queries to be evaluated. Cannot perform test.");
		}

		// Class presence list
		std::vector<std::string> presenceList;
		
		// Execute each query
		unsigned int currentLine = 1;
		for (unsigned int i = 0; i < nQueries; i++)
		{
			if (inputLines.size() > currentLine)
			{
				std::string queryLine = inputLines[currentLine++];
				
				// Separate query type and amount
				unsigned int countSpaces = std::count(queryLine.begin(), queryLine.end(), ' ');
				if (countSpaces != 1)
				{
					throw std::runtime_error("Query line does not have exactly two entries. Cannot perform test.");
				}
				std::string queryTypeString = queryLine.substr(0, queryLine.find(' '));
				std::string queryAmountString = queryLine.substr(queryLine.find(' ') + 1);

				// Parse query line data
				try
				{
					unsigned int queryType = std::stoi(queryTypeString);
					unsigned int queryAmount = std::stoi(queryAmountString);

					// Process queries
					switch (queryType)
					{

					// Insertion queries
					case INSERT:

						// Read next lines with students to be inserted in class list
						for (unsigned int i = 0; i < queryAmount; i++)
						{
							if (inputLines.size() > currentLine)
							{
								std::string studentName = inputLines[currentLine++];

								// Student is first presumed to be absent
								insert_sorted(presenceList, studentName);
							}
							else
							{
								std::cerr << "Unexpected end of input data has been reached. Test results might be inconsistent." << std::endl;
								break;
							}
						}

						break;

					// Consult queries
					case CONSULT:

						if (inputLines.size() > currentLine)
						{
							std::string studentIndexString = inputLines[currentLine++];
							unsigned int studentIndex = std::stoi(studentIndexString);

							// Consult presence list at given index
							outputLines.push_back(presenceList[studentIndex - 1]);
						}
						else
						{
							std::cerr << "Unexpected end of input data has been reached. Test results might be inconsistent." << std::endl;
							break;
						}

						break;

					// Unknown query type
					default:
						std::cerr << "Unknown query type will be ignored. Test results might be inconsistent." << std::endl;
						break;
					}
				}
				catch (const std::invalid_argument& e)
				{
					throw std::runtime_error("One of query entries is not a valid integer. Cannot perform test.");
				}
				catch (const std::out_of_range& e)
				{
					throw std::runtime_error("One of query entries is out of the range of possible integer values. Cannot perform test.");
				}
			}
			else
			{
				std::cerr << "Unexpected end of input data has been reached. Test results might be inconsistent." << std::endl;
				break;
			}
		}
	}

private:

	/**
	 * Auxiliary method for keeping insertion order in a STL vector of strings
	 * 
	 * @param vector Vector that will be modified
	 * @param element Item to be inserted in vector
	 */
	void insert_sorted(std::vector<std::string>& vector, std::string const& element)
	{
		vector.insert(std::upper_bound(vector.begin(), vector.end(), element), element);
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
	ClassroomTester tester;
	tester.readInput();
	tester.logic();
	tester.printOutput();
	return 0;
}