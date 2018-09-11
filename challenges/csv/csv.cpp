#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
  int N;
  cin >> N;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while (N--) {
    string line;
    getline(cin, line);

    vector<string> tokens;
    boost::split(tokens, line, boost::is_any_of(","));

    // rtrim and ltrim would be usefull in the case of malformated inputs
    cout << tokens[0] << " is " << tokens[4] << " years old and lives in "
         << tokens[2] << ", " << tokens[1] << "." << endl;
  }
  return 0;
}
