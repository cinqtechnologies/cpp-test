#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

void printNumber(int value)
{
    std::cout << value << std::endl;
}

int readNumber(void)
{
    int number;
    std::cin >> number;
    return number;
}

int main(int argc, char** argv)
{
    int nin;
    std::cin >> nin;

    std::vector<int> vec(nin);
    std::generate(vec.begin(), vec.end(), readNumber);
    std::sort(vec.begin(), vec.end());

    std::vector<int>::iterator it;
    std::for_each(vec.begin(), vec.end(), printNumber);
    
    return 0;
}
