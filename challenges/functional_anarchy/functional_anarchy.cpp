#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  int N = 0;
  cin >> N;
  vector<int> v;
  v.reserve(N);
  while (N--) {
    int a = 0;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (const auto a : v) {
    cout << a << endl;
  }
  return 0;
}
