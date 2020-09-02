#include <iostream>

#include <solver.hpp>

void solution(std::istream& in, std::ostream& out) {
    int X;
    in >> X;

    // fibonacci(0) = 0
    if (X == 0) {
        out << 0 << std::endl;
        return;
    }

    // fibonacci(1), fibonacci(2) = 1
    if (X < 3) {
        out << 1 << std::endl;
        return;
    }
    // the current and previous values holders initialized with first two elements of the sequence
    unsigned long long previous = 0, current = 1;

    // calculate the X element of the sequence
    for (int i = 2; i <= X; i++) {
        const auto temp = current;
        current = current + previous;
        previous = temp;
    }
    out << current << std::endl;
}

int main(int argc, char** argv)
{
    cpptest::solver::basic(argc, argv).execute(solution);
	return 0;
}
