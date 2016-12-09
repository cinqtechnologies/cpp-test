#include <iostream>
#include <string>

bool isPalindrome(std::string word)
{
	int l = word.length();
	bool retVal = true;
	for (int n = 0; n < (l/2); n++)
	{
		if (word[n] != word[l - 1 - n])
		{
			retVal = false;
			break;
		}
	}
	return retVal;
}

int main(int argc, char** argv)
{
	int numReps = 0;
	std::string inputWord;
	std::cin >> numReps;
	while (numReps--)
	{
		std::cin >> inputWord;
		if (isPalindrome(inputWord))
		{
			std::cout << inputWord << " is palindrome.\n";
		}
		else
		{
			std::cout << inputWord << " is not palindrome.\n";
		}
	}
	return 0;
}
