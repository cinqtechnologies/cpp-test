/**
 * @file dirty_bills.cpp
 * @brief dirty_bills challenge.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    int check_bills(std::vector<std::pair<int, std::string>> &vec_bills);
}

/**
 * @brief this function aggregate bills by type and shows total dirty bills.
 * @param vec_bills a vector with a list of bills to be handled.
 * @return success.
 */
int cinq_ht::check_bills(std::vector<std::pair<int, std::string>> &vec_bills) {

    std::unordered_map<std::string, int> umap_bills;
    std::unordered_map<std::string, int>::iterator umap_it;

    for (auto it_bl = vec_bills.begin(); it_bl != vec_bills.end(); ++it_bl) {
        // mapping bills...
        auto bill_type = it_bl->second;
        // set to lowercase first...
        std::transform(bill_type.begin(), bill_type.end(), bill_type.begin(),
                       tolower);

        // there is no need to store non-dirty bills, but anyway I'm storing
        // them for eventual future use ;)
        // insert or update on umap_bills...
        umap_it = umap_bills.find(bill_type);
        if (umap_it != umap_bills.end()) {
            umap_it->second = umap_it->second + it_bl->first;
        } else {
            umap_bills.insert(std::make_pair(bill_type, it_bl->first));
        }
    }

    if (umap_bills["dirty"] > 0) {
        std::cout << "There are " << umap_bills["dirty"] << " dirty bills."
                  << std::endl;
    } else {
        std::cout << "There are no dirty bills." << std::endl;
    }

    umap_bills.clear();

    return 0;
}

int main(int argc, char** argv) {

    int total = 0, value = 0;
    std::string bill_type;
    std::vector<std::pair<int, std::string>> vec_bills;

    // input...
    std::cin >> total;
    if (!std::cin || total < 0) {
        std::cout << "Invalid integer (N > 0)... Exiting." << std::endl;
        return 1;
    }
    for (int i = 0; i < total; ++i) {
        std::cin >> value;
        std::cin >> bill_type;
        vec_bills.push_back({value, bill_type});
    }

    // output...
    cinq_ht::check_bills(vec_bills);

	return 0;
}
