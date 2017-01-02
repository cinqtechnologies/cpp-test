#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string word) {

	int lWord = word.length();
	bool isPal = true;

	for (int i = 0; i < (lWord / 2); i++)	{
		if (word[i] != word[lWord - 1 - i])	{

			isPal = false;
			break;
		}
	}

	return isPal;
}


int main(int argc, char** argv) {

	int n = 0;
	string wrd;

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)	{

		cin >> wrd;
		cin.ignore();

		if (isPalindrome(wrd)) {
			cout << wrd << " is palindrome.\n";

		}	else {
			cout << wrd << " is not palindrome.\n";
		}
	}

	return 0;
}
