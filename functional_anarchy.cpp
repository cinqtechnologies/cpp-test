#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <list>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0, X = 0;
    list<int> numbers;

    cin >> N;

    if (N > 0) {
        for (int i = 0; i < N; i++) {
            cin >> X;
            numbers.push_back(X);
            numbers.sort();
        }
        cout << endl;
        for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
            cout << *it << endl;
        }
    }

	return 0;
}
