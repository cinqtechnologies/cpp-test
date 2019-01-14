/**
 * @file anagram.cpp
 * @brief anagram challenge.
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    typedef std::unordered_map<char, int> t_letter_map;

    bool compare_maps(t_letter_map umap_first, t_letter_map umap_second);
    int chk_anagram(std::vector<std::pair<std::string, std::string>> &vec_words);
}

/**
 * @brief this function compares two letter maps for equality.
 * @param umap_first a map of letters of first word.
 * @param umap_second a map of letters of second word.
 * @return true if the maps are equals, false otherwise.
 */
bool cinq_ht::compare_maps(t_letter_map umap_first, t_letter_map umap_second) {

    if (umap_first.size() != umap_second.size()) {
        return false;
    }

    for (auto it = umap_first.begin(); it != umap_first.end(); ++it) {
        if (it->second != umap_second[it->first]) {
            return false;
        }
    }

    return true;
}

/**
 * @brief this function checks for a list of possible anagrams.
 * @param vec_words a vector with pairs of words to be checked for anagrams.
 * @return success.
 */
int cinq_ht::chk_anagram(std::vector<std::pair<std::string, std::string>> &vec_words) {

    bool is_anagram = false;
    bool is_equal_size = false;
    t_letter_map umap_first, umap_second;
    t_letter_map::iterator umap_it;

    for (auto it_lw = vec_words.begin(); it_lw != vec_words.end(); ++it_lw) {

        // in case of different lengths, there is no anagram...
        is_anagram = true;
        is_equal_size = (it_lw->first.length() == it_lw->second.length());

        // If they have equal sizes, start mapping...
        if (is_equal_size) {

            // mapping first word... [ [first_word, second_word], [f, s], ... ]
            auto fw = it_lw->first;
            for (auto it_sw = fw.begin(); it_sw != fw.end(); ++it_sw) {
                // insert or update on umap_first...
                umap_it = umap_first.find(*it_sw);
                if (umap_it != umap_first.end()) {
                    umap_it->second++;
                } else {
                    umap_first.insert(std::make_pair(*it_sw, 1));
                }
            }

            // mapping second word... [ [first_word, second_word], [f, s], ... ]
            fw = it_lw->second;
            for (auto it_sw = fw.begin(); it_sw != fw.end(); ++it_sw) {
                // insert or update on umap_second...
                umap_it = umap_second.find(*it_sw);
                if (umap_it != umap_second.end()) {
                    umap_it->second++;
                } else {
                    umap_second.insert(std::make_pair(*it_sw, 1));
                }
            }

            is_anagram = compare_maps(umap_first, umap_second);
        } else {
            is_anagram = false;
        }

        if (is_anagram) {
            std::cout << it_lw->first << " is an anagram of "
                      << it_lw->second << std::endl;
        } else {
            std::cout << it_lw->first << " is not an anagram of "
                      << it_lw->second << std::endl;
        }

        umap_first.clear();
        umap_second.clear();
    }

    return 0;
}

int main(int argc, char** argv) {

    int total = 0;
    std::string first_word, second_word;
    std::vector<std::pair<std::string, std::string>> vec_words;

    // input...
    std::cin >> total;
    if (!std::cin || total <= 0) {
        std::cout << "Invalid unsigned integer (N > 0)... Exiting." << std::endl;
        return 1;
    }
    for (int i = 0; i < total; ++i) {
        std::cin >> first_word;
        std::cin >> second_word;
        vec_words.push_back({first_word, second_word});
    }

    // output...
    cinq_ht::chk_anagram(vec_words);

	return 0;
}
