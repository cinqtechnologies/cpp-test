#include <iostream>
#include <string>

using namespace std;

void isPalindrome(string str) {

    string rev = string(str.rbegin(), str.rend());
    if (str.compare(rev) == 0)
        cout << str << " is palindrome\n";
    else
        cout << str << " is not palindrome\n";

}

int main(int argc, char** argv)
{
    int N = 0;
    string str;

    cin >> N;

    if (N > 0) {
        for (int i = 0; i < N; i++) {
            cin >> str;
            isPalindrome(str);
        }
    }

	return 0;
}
