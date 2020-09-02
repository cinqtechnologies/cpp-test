#include <iostream>
#include <string>

#include <solver.hpp>

void solution(std::istream& in, std::ostream& out) {
    int N;
    in >> N;

    // here we'll count the bills
    long long dirtyBills = 0;

    int amount;
    std::string state;

    while (N-- > 0) {
        in >> amount;
        in >> state;

        if (state == "dirty") {
            dirtyBills += amount;
        }
    }

    if (dirtyBills > 0) {
        out << "There are " << dirtyBills <<" dirty bills." << std::endl;
    } else {
        out << "There are no dirty bills." << std::endl;
    }

}

int main(int argc, char** argv)
{
    cpptest::solver::basic(argc, argv).execute(solution);
    return 0;
}