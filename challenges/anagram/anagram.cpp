#include <iostream>
#include <algorithm>
#include <string>

bool areAnagram(std::string a, std::string b)
{
	if (a.length() == b.length())
	{
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		return a == b;
	}
	else
	{
		return false;
	}
}

int main(int argc, char** argv)
{
	int linesToRead;
	std::cin >> linesToRead;
	std::cin.ignore(); 
	if (linesToRead > 0)
	{
		std::string firstWord, secondWord;
		while (linesToRead--)
		{
			std::getline(std::cin, firstWord, ' ');
			std::getline(std::cin, secondWord);
			if (areAnagram(firstWord, secondWord))
			{
				std::cout << firstWord << " is an anagram of " << secondWord << std::endl;
			}
			else
			{
				std::cout << firstWord << " is not an anagram of " << secondWord << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Invalid input";
	}

	return 0;
}
