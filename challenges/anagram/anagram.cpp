#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;
	for (int i=0; i < n; i++) {
		std::string word1, word2;
		std::cin >> word1;
		std::cin >> word2;
		
		if ( std::is_permutation (word1.begin(), word1.end(), word2.begin())) {
			std::cout << word1 << " is an anagram of " << word2 << std::endl;
		} else {
			std::cout << word1 << " is not an anagram of " << word2 << std::endl;
		}
	}

	return 0;
}
