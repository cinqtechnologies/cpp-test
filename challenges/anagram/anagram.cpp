#include <iostream>
#include <algorithm>
#include <string>

/**
 * @brief Check wheter two strings are anagrams.
 * @param strWord1 first string.
 * @param strWord2 second string.
 * @return true if the given strings are anagrams, false otherwise.
 */
bool isAnagram(const std::string& strWord1, const std::string& strWord2);

int main(int argc, char** argv)
{
    int iLines = 0;
    std::cin >> iLines;

    if(iLines <= 0)
    {
        std::cerr << "Error: lines to read must be >0.";

        exit(1);
    }


    while(iLines--)
    {
        std::string strWord1;
        std::string strWord2;

        std::cin >> strWord1 >> strWord2;

        bool bAnagram = isAnagram(strWord1, strWord2);

        std::cout << strWord1
                  << (bAnagram ? " is an anagram of " : " is not an anagram of ")
                  << strWord2 << std::endl;
    }

    return 0;
}

bool isAnagram(const std::string &strWord1, const std::string &strWord2)
{
    if(strWord1.size() != strWord2.size())
        return false;

    // keeps function parameters const.
    std::string str1 = strWord1;
    std::string str2 = strWord2;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}
