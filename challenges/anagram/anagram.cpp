#include <iostream>
#include <algorithm>
#include <string>

// Function: is_anagram
//
// Checks whether the second string is an anagram of the first string
//
// Params:
//   first: first string
//   second: second string
//
// Returns:
//   true if the strings are anagrams, false otherwise
bool is_anagram(const std::string& first, const std::string& second)
{
	// Not the fastest way but works with the test cases
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

int main(int argc, char** argv)
{
	int queries = 0;
	bool anagram = false;

	std::string first_string, second_string;

	std::cin >> queries;
	while (queries > 0)
	{
		std::cin >> first_string;
		std::cin >> second_string;

		anagram = is_anagram(first_string, second_string);

		std::cout << first_string << " "
		     << (anagram ? "is" : "is not") << " "
				 << "an anagram of " << second_string
				 << std::endl;
		
		--queries;
	}

	return 0;
}
