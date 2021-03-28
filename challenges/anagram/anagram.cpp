#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_anagram(string word1, string word2) {
	for (const char& c : word1) {

		auto it = find(word2.begin(), word2.end(), c);

		if (it == word2.end())
			return false;

		word2.erase(it);
	}

	return true;
}

int main(int argc, char** argv)
{
	int anagr_count;
	string word1, word2;

	cin >> anagr_count;

	while (anagr_count--) {

		cin >> word1 >> word2;

		if (is_anagram(word1, word2)) {
			cout << word1 << " is an anagram of " << word2 << "\n";
		}
		else {
			cout << word1 << " is not an anagram of " << word2 << "\n";
		}
	}
	return 0;
}