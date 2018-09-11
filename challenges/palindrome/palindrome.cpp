#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string &s) {
  return equal(s.begin(), s.begin() + (s.size() / 2), s.rbegin());
}

int main(int argc, char **argv) {
  int N = 0;
  cin >> N;
  while (N--) {
    string w;
    cin >> w;
    cout << w << (isPalindrome(w) ? " is " : " is not ") << "palindrome"
         << endl;
  }
  return 0;
}
