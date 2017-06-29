#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void splitString(string firstName, string str) {

    stringstream ss(str);
    vector<string> vect;
    string aux = "";

    while (ss.good()) {

        getline(ss, aux, ',');
        vect.push_back(aux);

    }

    cout << firstName << " " << vect.at(0)
         << " is " << vect.at(4) << " years old and lives in "
         << vect.at(2) << ", " << vect.at(1) << "." << endl;
}

int main(int argc, char** argv)
{
    int N = 0;
    string firstName = "", str = "";

    cin >> N;
    if (N > 0) {
        for (int i = 0; i < N; i++) {
            cin >> firstName >> str;

            cout << "firstName: " << firstName << endl;
            cout << "str: " << str << endl;

            splitString(firstName,str);

        }
    }
	return 0;
}
