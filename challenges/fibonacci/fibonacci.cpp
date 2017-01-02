#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	int x;
	int lastLast = 0, current = 0, last = 1;

	cin >> x;

	for (int i = 0; i <= x; i++) {
		if (i <= 1) {

			current = i;

		}	else {

			current = last + lastLast;
			lastLast = last;
			last = current;

		}
	}

	cout << current;

	return 0;

}
