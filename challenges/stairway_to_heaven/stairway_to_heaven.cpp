#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  int N = 0;
  cin >> N;
  if (N <= 0) {
    cout << "Error." << endl;
    return 0;
  }
  string line(N, ' ');
  for (auto i = line.rbegin(); i != line.rend(); ++i) {
    *i = '#';
    cout << line << endl;
  }
  return 0;
}
