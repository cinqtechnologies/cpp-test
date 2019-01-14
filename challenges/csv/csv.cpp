/**
 * @file csv.cpp
 * @brief csv challenge.
 */

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    int show_csv(std::vector<std::string> &vec_words);
}

/**
 * @brief this function shows a csv in a customized way.
 * @param vec_words a vector with some lines to be displayed.
 * @return success.
 */
int cinq_ht::show_csv(std::vector<std::string> &vec_words) {

    std::string token;
    std::vector<std::string> vec_csv;
    int i = 0;
    for (auto it_lw = vec_words.begin(); it_lw != vec_words.end(); ++it_lw) {
        std::istringstream str_stream(*it_lw);
        while (std::getline(str_stream, token, ',')) {
            vec_csv.push_back(token);
            if (i % 5 == 4) {
                std::cout << vec_csv[0] << " is " << vec_csv[4] << " years old "
                          << "and lives in " << vec_csv[2] << ", "
                          << vec_csv[1] << "." << std::endl;
                vec_csv.clear();
            }
            ++i;
        }
    }

    return 0;
}

int main(int argc, char** argv) {

    int total;
    std::string curr_word;
    std::vector<std::string> vec_words;

    // input...
    std::cin >> total;
    if (!std::cin || total <= 0) {
        std::cout << "Invalid integer (N > 0)... Exiting." << std::endl;
        return 1;
    }
    std::cin.ignore();
    for (int i = 0; i < total; ++i) {
        std::getline(std::cin, curr_word);
        vec_words.push_back(curr_word);
    }

    // output...
    cinq_ht::show_csv(vec_words);

	return 0;
}
