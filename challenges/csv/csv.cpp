#include <iostream>
#include <string>
#include <vector>

#include <solver.hpp>


const std::ctype<char>* csvSeparators() {
    using char_ctype = std::ctype<char>;
    static std::vector<char_ctype::mask> separators;
    if (separators.empty()) {
        const auto baseTable = char_ctype::classic_table();
        std::vector<char_ctype::mask> customTable(baseTable, baseTable + char_ctype::table_size);
        customTable[' '] ^= std::ctype_base::space;
        customTable[','] ^= std::ctype_base::space;
        separators.swap(customTable);
    }

    return new char_ctype(std::data(separators));;
}

void solution(std::istream& in, std::ostream& out) {
    auto baseLoc = in.getloc();

    in.imbue(std::locale(in.getloc(), csvSeparators()));

    std::string name, state, city, country;
    int age;

    in >> name >> state >> city >> country >> age;
    out << name << " is " << age << " years old"
        << " and lives in " << city << ", " << state << "."
        << std::endl;

    in.imbue(baseLoc);
}

int main(int argc, char** argv)
{
    cpptest::solver::codejam(argc, argv).execute(solution);
    return 0;
}