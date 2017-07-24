#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char** argv)
{
    int n  = 0;
    std::cin >> n;

    if(n <= 0)
    {
        std::cout << "Error.\n";

        return 1;
    }

    int         i = 0;
    std::string strStar;

    // performs staircase in O(n)
    while(i++ < n)
    {
        strStar.append("#");
        std::cout << std::setw(n) << strStar << "\n";
    }

    return 0;
}
