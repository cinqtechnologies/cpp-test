#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_anagram(string first, string second) {
	for (const char& c : first) {
		auto itr = find(second.begin(), second.end(), c);
		if (itr == second.end())
			return false;

		second.erase(itr);
	}

	return true;
}

int main(int argc, char** argv)
{
	int num_anagrams;
	string first, second;

	cin >> num_anagrams;

	while (num_anagrams--) {
		cin >> first >> second;

		if (is_anagram(first, second))
			cout << first << " is an anagram of " << second << "\n";
		else
			cout << first << " is not an anagram of " << second << "\n";
	}
	return 0;
}
