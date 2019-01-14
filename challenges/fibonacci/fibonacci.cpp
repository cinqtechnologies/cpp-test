/**
 * @file fibonacci.cpp
 * @brief fibonacci challenge.
 */

#include <iostream>
#include <cmath>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    long long unsigned int fib_iterative(unsigned int n);
}

/**
 * @brief this function calculates a fibonacci series.
 *        Fibonacci works faster with iterative, since it reduces stacking
 *        functions for every call, reducing considerably the final
 *        computation/memory usage.
 * @param n number of iterative steps.
 * @return fibonacci result.
 */
long long unsigned int cinq_ht::fib_iterative(unsigned int n) {

    long unsigned int first = 0;
    long unsigned int second = 1;
    long unsigned int aux = 0;

    for (unsigned int i = 0; i < n; ++i) {
        aux = first;
        first = second;
        second = aux + second;
    }

    return first;
}

int main(int argc, char** argv) {

    unsigned int n = 0;

    // input...
    std::cin >> n;
    if (!std::cin || n < 0) {
        std::cout << "Invalid integer (N >= 0) range... Exiting." << std::endl;
        return 1;
    }

    std::cout << cinq_ht::fib_iterative(n) << std::endl;

	return 0;
}
