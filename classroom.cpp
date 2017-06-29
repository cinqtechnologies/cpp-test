#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0, Q = 0, key = 0, pos = 0;
    string firstName = "", lastName = "", fullName = "";
    list<string> students;
    list<string>::iterator it = students.begin();
    cin >> N;
    if(N > 0) {
        for(int i = 0; i < N; i++) {
            cin >> Q >> key;
            if (Q == 1) {
                for (int j = 0; j < key; j++) {
                    cin >> firstName >> lastName;
                    fullName = firstName + " " + lastName;
                    students.push_back(fullName);
                }
                students.sort();
            } else if (Q == 2) {
                for (int k = 0; k < key; k++) {
                    cin >> pos;
                    it = students.begin();
                    for (int l = 0; l < pos-1; l++)
                        it++;
                    cout << *it << endl;
                }
            }
        }
    }
	return 0;
}
