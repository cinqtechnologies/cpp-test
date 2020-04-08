#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void is_palindrome(const string &word) {
	string pali;
	pali.resize(word.size());

	reverse_copy(word.begin(), word.end(), pali.begin());
	if (word.compare(pali) == 0)
		cout << word << " is palindrome\n";
	else
		cout << word << " not is palindrome\n";
}

int main(int argc, char** argv)
{
	int num_lines = 0;
	vector<string> words;
	cin >> num_lines;
	cin.ignore();

	while(num_lines--) {
		string name;
		cin >> name;
		words.push_back(name);
	}

	for_each(words.begin(), words.end(), is_palindrome);

	return 0;
}
