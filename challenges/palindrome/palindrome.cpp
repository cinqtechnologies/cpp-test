#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char** argv)
{
	int numberOfWords;
	std::cin >> numberOfWords;

	std::string word;
	std::string reversedWord;
	while(numberOfWords-- > 0)
	{
		std::cin >> word;
		reversedWord = word;
		std::reverse(reversedWord.begin(), reversedWord.end());
		bool isPalindrome = word == reversedWord;
		std::cout << word << "is " << (isPalindrome ? "" : "not ") << " palindrome" << std::endl;
	}

	return 0;
}
