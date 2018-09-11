#include <algorithm>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

void insertQuery(int Q, vector<string> &V) {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string n;
  while (Q--) {
    getline(cin, n);
    V.push_back(n);
  }
  sort(V.begin(), V.end());
}

void consultQuery(int Q, const vector<string> &V) {
  int id;
  while (Q--) {
    cin >> id;
    cout << V[id - 1] << endl; // Assuming 1 <= ID <= V.size
  }
}

int main(int argc, char **argv) {
  int N = 0;
  cin >> N;
  vector<string> names;
  while (N--) {
    int T, Q;
    cin >> T >> Q;
    // Assuming T = [1,2]
    if (T == 1) {
      insertQuery(Q, names);
    } else {
      consultQuery(Q, names);
    }
  }
  return 0;
}
