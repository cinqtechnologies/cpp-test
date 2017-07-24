#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

enum Field
{
    Name    = 0,
    State   = 1,
    City    = 2,
    Country = 3,
    Age     = 4
};

int main(int argc, char** argv)
{

    int iLines = 0;
    std::cin >> iLines;

    std::cin.ignore();

    if(iLines  <= 0)
    {
        std::cerr << "Error: lines to read must be >0.";

        exit(1);
    }

    while(iLines--)
    {
        std::string              strInput;
        std::vector<std::string> vecInput;
        std::stringstream        issInput;

        std::getline(std::cin, strInput);
        issInput.str(strInput);

        // splits string using ',' delimiter.
        while(std::getline(issInput, strInput, ','))
        {
            vecInput.push_back(strInput);
        }

        std::cout << vecInput[Name]
                  << " is "
                  << vecInput[Age]
                  << " years old and lives in "
                  << vecInput[City]
                  << ", "
                  << vecInput[State]
                  << ".\n";

        issInput.clear();
        vecInput.clear();
    }

    return 0;
}
