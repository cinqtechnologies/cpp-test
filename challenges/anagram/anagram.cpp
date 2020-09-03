#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

#include <solver.hpp>

bool isAnagram(const std::string& firstWord, const std::string& secondWord) {

    // strings of different lengths can not be anagram of each other
    if (firstWord.size() != secondWord.size()) {
        return false;
    }

    // here we'll count each char of the words
    // incrementing when found in the first and
    // decrementing when found in the second
    std::unordered_map<char, int> charCount;

    const auto size = firstWord.size();
    for (int i = 0; i < size; i++) {
        charCount[firstWord[i]]++;
        charCount[secondWord[i]]--;
    }

    // by the end, if all chars count is equal to zero
    // then the words are anagram of each other
    return std::find_if(charCount.begin(), charCount.end(), [](auto entry) {
        return entry.second != 0;
    }) == charCount.end();
}

void solution(std::istream& in, std::ostream& out) {
    std::string firstWord, secondWord;
    in >> firstWord;
    in >> secondWord;

    out << firstWord;
    if (isAnagram(firstWord, secondWord)) {
        out << " is ";
    } else {
        out << " is not ";
    }
    out << "an anagram of " << secondWord << std::endl;
}

int main(int argc, char** argv)
{
    cpptest::solver::codejam(argc, argv).execute(solution);
    return 0;
}
