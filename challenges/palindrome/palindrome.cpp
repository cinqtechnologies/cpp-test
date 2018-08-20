#include <iostream>
#include <string>
#include <string.h>

bool isPalindrome(const char* string)
{
	const char* reverse = string + strlen(string) - 1;
	while (string < reverse) {
		if (*string++ != *reverse--) {
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string word;
		std::cin >> word;
		if (isPalindrome(word.c_str())) {
			std::cout << word << " is palindrome" << std::endl;
		} else {
			std::cout << word << " is not palindrome" << std::endl;
		}		
	}

	return 0;
}


