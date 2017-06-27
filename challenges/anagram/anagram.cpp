#include <iostream>
#include <algorithm>
#include <string>
#include <istream>

bool isAnagram(std::string lhs, std::string rhs)
{
	if (lhs.size() != rhs.size())
		return false;

	std::sort(lhs.begin(), lhs.end());
	std::sort(rhs.begin(), rhs.end());
	return lhs == rhs;
}

std::string processAnagramWordPair(const std::string& lhs, const std::string& rhs)
{
	const std::string isAnAnagram = isAnagram(lhs, rhs) ? "" : " not";
	return lhs + " is" + isAnAnagram + " an anagram of " + rhs;
}

int main(int argc, char** argv)
{
	int numberOfLines;
	std::cin >> numberOfLines;

	std::string firstWord;
	std::string secondWord;

	while(numberOfLines-- > 0)
	{
		std::cin >> firstWord;
		std::cin >> secondWord;
		std::cout << processAnagramWordPair(firstWord, secondWord) << std::endl;
	}
}
