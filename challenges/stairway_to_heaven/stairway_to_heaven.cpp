#include <iostream>
#include <string>
#include <iomanip>

#include <solver.hpp>

void solution(std::istream& in, std::ostream& out) {
    int N;
    in >> N;

    if (N < 1) {
        out << "Error." << std::endl;
        return;
    }

    // print the stairway
    for (int i = 0; i < N; i++) {
        out << std::setfill(' ') << std::setw(N - 1 - i) << "";
        out << std::setfill('#') << std::setw(i+1) << '#';
        out << std::endl;
    }
}

int main(int argc, char** argv)
{
    cpptest::solver::basic(argc, argv).execute(solution);
    return 0;
}