#include <iostream>
#include <algorithm>
#include <string>

bool is_anagram(std::string &, std::string &);

int main(int argc, char** argv)
{
    std::string str_1;
    std::string str_2;

    int lines = 0;
    std::cin >> lines;

    // Loop lines times
    while(lines--)
    {
	std::cin >> str_1 >> str_2;
	if ( is_anagram(str_1, str_2) )
	    std::cout << str_1 << " is an anagram of " << str_2 << std::endl;
	else
	    std::cout << str_1 << " is not an anagram of " << str_2 << std::endl;
    }
    return 0;
}

bool is_anagram(std::string & word1, std::string & word2)
{
    /* 
     * Word1 will be an anagram of Word2 if, and only if,
     * Word2 is a permutation of Word1 and both strings
     * has the same length.
     * 
     * We can use 'is_permutation' from the C++11 standard 
     * to check if one is a permutation of the other.
     */
    if (word1.length() != word2.length())
	return false;
	
    return std::is_permutation(word1.begin(), word1.end(), word2.begin());
}
