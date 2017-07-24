#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(int argc, char** argv)
{
    int iLines;
    std::cin >> iLines;

    if(iLines <= 0)
    {
        std::cerr << "Error: lines to read must be >0.";

        exit(1);
    }

    std::vector<int>  iVecNumbers;

    while(iLines--)
    {
        int iNumber;
        std::cin >> iNumber;
        iVecNumbers.push_back(iNumber);
    }

    // sort list.
    std::sort(iVecNumbers.begin(), iVecNumbers.end());

    // prints the sorted list.
    std::copy(iVecNumbers.begin(), iVecNumbers.end(),
              std::ostream_iterator<int>(std::cout, "\n"));

    return 0;
}
