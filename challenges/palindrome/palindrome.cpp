#include <iostream>
#include <string>
#include <iterator>

using namespace std;

void isPalindrome(string word){
		int begin = 0, end = word.length()-1;
		while(begin < end){
				if(word[begin]==word[end]){
						begin++;
						end--;
				}
				else{
						cout << word << " is not palindrome" << endl;
						return;
				}
		}
		cout << word << " is palindrome" << endl;
}

int main(int argc, char** argv)
{
		int numOfWords = 0;

		cin >> numOfWords;

		for(int i =0; i<numOfWords; i++){
				string tmp;
				cin >> tmp;
				isPalindrome(tmp);
		}

		return 0;
}
