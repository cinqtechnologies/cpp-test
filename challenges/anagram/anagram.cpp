#include <iostream>
#include <algorithm>
#include <string>

#define ANAGRAM_NUMBER_OF_CHARS	(26 + 10)

// Function: getCharIndex
//
// Retrieves the index in the char map for a character
//
// Params:
//  ch: the character to determine the index
//
// Returns:
//  the calculated index for a valid character, -1 otherwise
int getCharIndex(char ch)
{
	int index = -1;

	if (ch >= '0' && ch <= '9')
	{
		index = ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		index = (ch - 'A') + 10;
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		index = (ch - 'a') + 10;
	}

	return index;
}

// Function: isAnagram
//
// Checks whether the second string is an anagram of the first string
//
// Params:
//   first: first string
//   second: second string
//
// Returns:
//   true if the strings are anagrams, false otherwise
bool isAnagram(const std::string& first, const std::string& second)
{
	int index = 0;
	int first_index = 0, second_index = 0;

	bool is_anagram = false;

	size_t string_len = 0L, string_index = 0L;

	int char_map[ANAGRAM_NUMBER_OF_CHARS] = {0};

	// Check if the two strings have the same size
	if (first.length() != second.length())
	{
		return false;
	}

	// Initializes the char map
	for (index = 0; index < ANAGRAM_NUMBER_OF_CHARS; index++)
	{
		char_map[index] = 0;
	}

	// Fills our char map with the occurences of each char
	string_len = first.length();
	for (string_index = 0; string_index < string_len; string_index++)
	{
		first_index = getCharIndex(first[string_index]);
		second_index = getCharIndex(second[string_index]);

		if (-1 == first_index || -1 == second_index)
		{
			is_anagram = false;
			break;
		}

		char_map[first_index]++;
		char_map[second_index]--;
	}

	// Check if our char map is balanced with zeroes, which means
	// the two words are anagrams
	is_anagram = true;
	for (index = 0; index < ANAGRAM_NUMBER_OF_CHARS; index++)
	{
		if (char_map[index] != 0)
		{
			is_anagram = false;
			break;
		}
	}

	return is_anagram;
}
/*
bool isAnagram(const std::string& first, const std::string& second)
{
	// Not the fastest way but works with the test cases
	// ! Updated to a faster version
	std::string s_one(first);
	std::string s_two(second);

	if (s_one.length() != s_two.length())
	{
		return false;
	}

	std::sort(s_one.begin(), s_one.end());
	std::sort(s_two.begin(), s_two.end());

	return (s_one.compare(s_two) == 0);
}
*/

int main(int argc, char** argv)
{
	int queries = 0;
	bool is_anagram = false;

	std::string first_string, second_string;

	std::cin >> queries;
	while (queries > 0)
	{
		std::cin >> first_string;
		std::cin >> second_string;

		is_anagram = isAnagram(first_string, second_string);

		std::cout << first_string << " "
		     << (is_anagram ? "is" : "is not") << " "
				 << "an anagram of " << second_string
				 << std::endl;
		
		--queries;
	}

	return 0;
}
