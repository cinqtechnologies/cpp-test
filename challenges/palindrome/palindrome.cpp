#include <iostream>
#include <string>
#include <algorithm>

#include <solver.hpp>

bool isPalindrome(const std::string& word) {
    return std::equal(word.begin(), word.begin() + word.size()/2, word.rbegin());
}

void solution(std::istream& in, std::ostream& out) {
    std::string word;
    in >> word;

    out << word;
    if (isPalindrome(word)) {
        out << " is palindrome";
    } else {
        out << " is not palindrome";
    }
    out << std::endl;
}

int main(int argc, char** argv)
{
    cpptest::solver::codejam(argc, argv).execute(solution);
	return 0;
}
