#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <iterator>

#include <solver.hpp>

// separators to ignore whitespace between names
const std::ctype<char> *presenceListSeparators() {
    using char_ctype = std::ctype<char>;
    static std::vector<char_ctype::mask> separators;
    if (separators.empty()) {
        const auto baseTable = char_ctype::classic_table();
        std::vector<char_ctype::mask> customTable(baseTable, baseTable + char_ctype::table_size);
        customTable[' '] ^= std::ctype_base::space;
        separators.swap(customTable);
    }

    return new char_ctype(std::data(separators));;
}

const int INSERT = 1;
const int CONSULT = 2;

void solution(std::istream &in, std::ostream &out) {
    int N;
    in >> N;

    std::set<std::string> presenceList;

    while (N-- > 0) {
        // read operation and number of queries Q for that operation
        int operation, Q;
        in >> operation >> Q;

        if (operation == INSERT) {
            const auto baseLoc = in.getloc();
            // ignore whitespaces separators
            in.imbue(std::locale(baseLoc, presenceListSeparators()));

            // read Q names into the presence list
            std::copy_n(std::istream_iterator<std::string>(in), Q, std::inserter(presenceList, presenceList.begin()));

            in.imbue(baseLoc);

        } else if (operation == CONSULT) {
            // read Q operations
            int position;

            while (Q-- > 0) {
                in >> position;
                const auto index = position - 1;

                if (index >= presenceList.size()) {
                    return;
                }

                // get the name associated with the position
                auto result = presenceList.begin();
                std::advance(result, index);
                out << *result << std::endl;
            }
        }
    }

}

int main(int argc, char **argv) {
    cpptest::solver::basic(argc, argv).execute(solution);
    return 0;
}