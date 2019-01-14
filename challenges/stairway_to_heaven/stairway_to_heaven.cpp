/**
 * @file stairway_to_heaven.cpp
 * @brief stairway_to_heaven challenge.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>

int main(int argc, char** argv) {

    int total = 0, len = 0;

    // input...
    std::cin >> total;
    if (!std::cin || total <= 0) {
        std::cout << "Error." << std::endl;
        return 1;
    }

    // output...
    for (int i = 0; i < total; ++i) {
        len = total - i;
        std::cout << std::setw(len);
        for (int j = 0; j < i + 1; ++j) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }

    return 0;
}
