#include <string>
#include <vector>

/**
 * This class represents a generic test, implementing logic that is common to all tests,
 * such as I/O operations. 
 */
class Tester {

protected:

    /* Lines from test case input text. */
    std::vector<std::string> inputLines;

    /* Lines from output text generated for test case. */
    std::vector<std::string> outputLines;

public:

    /**
     * Public empty constructor.
     */
    Tester() {}

    /**
     * Method for reading data from input file.
     */
    void readInput();

    /**
     * This method contains the specific logic for the current test, and must be implemented
     * by every tester class.
     */
    virtual void logic() = 0;

    /**
     * Method for printing output text from test.
     */
    void printOutput();

};
