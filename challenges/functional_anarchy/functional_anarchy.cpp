/**
 * @file functional_anarchy.cpp
 * @brief functional_anarchy challenge.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    int show_sorted_list(std::vector<int> &vec_ints);
}

/**
 * @brief this function print a sorted vector.
 * @param vec_ints a vector with some integer numbers to be sorted.
 * @return success.
 */
int cinq_ht::show_sorted_list(std::vector<int> &vec_ints) {
    // sorting... Do I need create a mergetsort/quicksort? ;)
    std::sort(vec_ints.begin(), vec_ints.end());

    // printing...
    for (auto it = vec_ints.begin(); it != vec_ints.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}

int main(int argc, char** argv) {

    int total = 0, value = 0;
    std::vector<int> vec_ints;

    // input...
    std::cin >> total;
    if (!std::cin || total <= 0) {
        std::cout << "Invalid integer (N > 0)... Exiting." << std::endl;
    }
    for (int i = 0; i < total; ++i) {
        std::cin >> value;
        if (!std::cin) {
            std::cout << "Invalid integer... Exiting." << std::endl;
            return i;
        }
        vec_ints.push_back(value);
    }

    // output...
    cinq_ht::show_sorted_list(vec_ints);

	return 0;
}
