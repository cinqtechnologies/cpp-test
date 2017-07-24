#include <iostream>
#include <string>

/**
 * @brief Checks if the given string is palindrome.
 * @param strWord The string to be checked.
 * @return True if the given word is palindrome, false otherwise.
 */
bool isPalindrome(const std::string& strWord);

int main(int argc, char** argv)
{
    int iLines = 0;
    std::cin >> iLines;

    while(iLines--)
    {
        std::string strWord;

        std::cin  >> strWord;
        std::cout << strWord
                  << ( isPalindrome(strWord) ? " is palindrome\n" : "is not palindrome\n");
    }

    return 0;
}

bool isPalindrome(const std::string &strWord)
{
    // compares strWord with it backward string.
    return strWord == (std::string(strWord.rbegin(), strWord.rend()));
}
