#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool checkAnagram(string firstWord, string secondWord){
		int xor_ = 0;

		if(firstWord.length() != secondWord.length())
				return false;

		for(int index = 0; index < firstWord.length(); index++){
				xor_ ^= firstWord[index];
				xor_ ^= secondWord[index];
		}

		return xor_ == 0;
}

int main(int argc, char** argv)
{
		int n = 0;
		string firstWord, secondWord;

		cin >> n;

		for( ; n > 0; n--){
				cin >> firstWord;
				cin >> secondWord;

				if(checkAnagram(firstWord, secondWord))
						cout << firstWord << " is an anagram of " << secondWord << endl;
				else
						cout << firstWord << " is not an anagram of " << secondWord << endl;
		}

		return 0;
}
