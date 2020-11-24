#include "Tester.h"

#include <iostream>
#include <exception>

/**
 * Method for reading data from input file.
 */
void Tester::readInput()
{
    // Read data from standard input line by line
    std::string line;
    while (std::getline(std::cin, line))
    {
        inputLines.push_back(line);
    }
}

/**
 * Method for accessing output text from test.
 */
void Tester::printOutput()
{
    // Iterate through each line of generated output
    for (auto line = outputLines.begin(); line != outputLines.end(); line++)
    {
        // If this is the first line, print it as it is
        if (line == outputLines.begin())
        {
            std::cout << *line;
        }

        // Otherwise, break a single line before printing it
        else
        {
            std::cout << std::endl << *line;
        }
    }
}