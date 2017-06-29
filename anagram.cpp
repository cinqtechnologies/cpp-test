#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int checkAnagram(string word1, string word2) {

    // if lengths are different, they're not anagrams
    if (word1.length() != word2.length())
        return 1;

    // sorting characters in both strings
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    // if words are different after sorting, they're not anagrams
    if (word1 != word2)
        return 1;

    return 0;
}

int main(int argc, char** argv)
{
    int N = 0;
    string word1 = "", word2 = "";
    cin >> N;
    if (N > 0){
        for (int i = 0; i < N; i++) {
            cin >> word1 >> word2;
            if (checkAnagram(word1,word2) == 0)
                cout << word1 << " is an anagram of " << word2 << endl;
            else
                cout << word1 << " is not an anagram of " << word2 << endl;
        }
    }
	return 0;
}
