/**
 * @file palindrome.cpp
 * @brief palindrome challenge.
 */

#include <iostream>
#include <string>
#include <vector>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    int check_palindrome(std::vector<std::string> &vec_words);
}

/**
 * @brief this function checks for a palindrome.
 * @param vec_words a vector with some possible palindromes. 
 * @return success.
 */
int cinq_ht::check_palindrome(std::vector<std::string> &vec_words) {

    bool is_palindrome;
    for (auto it_lw = vec_words.begin(); it_lw != vec_words.end(); ++it_lw) {
        is_palindrome = true; // guilt until proven innocent...

        // Using iterator is faster and doesn't require additional memory...
        std::string::iterator ptr_beg = (*it_lw).begin();
        std::string::iterator ptr_end = (*it_lw).end() - 1;

        unsigned int j = 0;
        while (is_palindrome && j < (*it_lw).length() / 2) {
            // loop for word.length() / 2. In case of an odd length,
            // the character in the middle will not make any difference.
            //std::cout << *ptr_beg << " = " << *ptr_end << std::endl;
            if (*ptr_beg != *ptr_end) {
                is_palindrome = false;
            }
            ++ptr_beg; // go forward...
            --ptr_end; // come back...
            ++j;
        }

        if (is_palindrome) {
            std::cout << *it_lw << " is palindrome" << std::endl;
        } else {
            std::cout << *it_lw << " is not palindrome" << std::endl;
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
    for (int i = 0; i < total; ++i) {
        std::cin >> curr_word;
        vec_words.push_back(curr_word);
    }

    // output...
    cinq_ht::check_palindrome(vec_words);

	return 0;
}
