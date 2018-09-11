#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Assuming simple ASCII strings containing no numbers or special characters
vector<int> lettersHistogram(string s) {
  vector<int> h(26, 0);
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  for (const char c : s) {
    const int i = c - 'a';
    h[i] += 1;
  }
  return h;
}

int main(int argc, char **argv) {
  int N = 0;
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    string w1, w2;
    cin >> w1 >> w2;
    const auto hist_w1 = lettersHistogram(w1);
    const auto hist_w2 = lettersHistogram(w2);
    if (std::equal(hist_w1.begin(), hist_w1.end(), hist_w2.begin(),
                   hist_w2.end())) {
      cout << w1 << " is an anagram of " << w2 << endl;
    } else {
      cout << w1 << " is not an anagram of " << w2 << endl;
    }
  }
  return 0;
}
