#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>

#include <solver.hpp>

void solution(std::istream& in, std::ostream& out) {

    auto eos = std::istream_iterator<int>();
    std::multiset<int> numbers(std::istream_iterator<int>(in), eos);
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(out, "\n"));

}

int main(int argc, char** argv)
{
    cpptest::solver::codejam(argc, argv).execute(solution);
    return 0;
}