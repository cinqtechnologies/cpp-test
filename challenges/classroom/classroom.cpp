/**
 * @file classroom.cpp
 * @brief classroom challenge.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

//ToDo: Put cinq_ht types and functions declarations in a header file...
/**
 * @brief cinq_ht namespace contains types and functions of solution.
 */
namespace cinq_ht {
    #define QUERY_TYPE_INSERT 1
    #define QUERY_TYPE_RETRIEVE 2

    int handle_query(std::vector<std::string> &vec_students,
                     int query_type, int query_qty);
}

/**
 * @brief: this function handles a specific type of query.
 * @param vec_students vector containing a list of students.
 * @param query_type the type of query (inserting/retrieving).
 * @param query_qty the number of queries to be executed.
 * @return true if query was successful, false otherwise.
 */
int cinq_ht::handle_query(std::vector<std::string> &vec_students,
                          int query_type, int query_qty) {
    if (query_type == QUERY_TYPE_INSERT) {
        std::string name;
        std::cin.ignore();
        for (int i = 0; i < query_qty; ++i) {
            std::getline(std::cin, name);
            vec_students.push_back(name);
        }
        std::sort(vec_students.begin(), vec_students.end());
    } else if (query_type == QUERY_TYPE_RETRIEVE) {
        int query_index = 0;
        for (int i = 0; i < query_qty; ++i) {
            std::cin >> query_index;
            if (!std::cin || query_index < 0) {
                std::cout << "Invalid integer (N > 0)... Exiting." << std::endl;
                return 1;
            }
            if (vec_students.size() < (unsigned int) query_index) {
                std::cout << "There is not such position in the list."
                          << std::endl;
            } else {
                std::cout << vec_students[query_index - 1] << std::endl;
            }
        }
    } else {
        std::cout << "Unknown query type..." << std::endl;
    }

    return 0;
}

int main(int argc, char** argv) {

    int total = 0;
    int query_type = 0, query_qty = 0;
    std::vector<std::string> vec_students;

    // input...
    std::cin >> total;
    if (!std::cin || total <= 0) {
        std::cout << "Invalid integer (N > 0)... Exiting." << std::endl;
        return 1;
    }
    for (int i = 0; i < total; ++i) {
        std::cin >> query_type;
        std::cin >> query_qty;
        if (!std::cin || query_qty <= 0) {
            std::cout << "Invalid integer... Exiting." << std::endl;
            return 2;
        }
        // output...
        int ret = cinq_ht::handle_query(vec_students, query_type, query_qty);
        // in case of error, exit program...
        if (ret) {
            return ret;
        }
    }

	return 0;
}
