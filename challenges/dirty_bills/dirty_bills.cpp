#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  int N = 0;
  cin >> N;
  int sum = 0;
  while (N--) {
    int a = 0;
    string s;
    cin >> a >> s;
    if (s.compare("dirty") == 0) {
      sum += a;
    }
  }
  if (sum <= 0) {
    cout << "There are no dirty bills." << endl;
  } else {
    cout << "There are " << sum << " dirty bills." << endl;
  }
  return 0;
}
