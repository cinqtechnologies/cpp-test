#include <iostream>
#include <string>

// Function: isPalindrome
//
// Checks whether a word is palindrome
//
// Params:
//  word: the word to be checked
//
// Returns 
//  true when 'word' is palindrome, false otherwise
bool isPalindrome(const std::string& word)
{
	bool is_palindrome = false;
	size_t front = 0L, back = word.length();

	if (0L == back)
	{
		return false;
	}

	--back;
	while (back >= front)
	{
		is_palindrome = (word[front] == word[back]);
		if (!is_palindrome)
		{
			break;
		}

		front++;
		back--;
	}

	return is_palindrome;
}

int main(int argc, char** argv)
{
	int entries = 0;
	bool is_palindrome = false;

	std::string word;

	std::cin >> entries;

	std::cin.ignore();
	while (entries > 0)
	{
		std::cin >> word;

		is_palindrome = isPalindrome(word);
		std::cout << word  << " "
		          << (is_palindrome ? "is" : "is not") << " "
							<< "palindrome" 
							<< std::endl;

		--entries;
	}
	return 0;
}
