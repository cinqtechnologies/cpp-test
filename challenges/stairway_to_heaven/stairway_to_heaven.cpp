#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void stairway_to_heaven(int n) {
	if (n <= 0)
		cout << "Error.\n";

	for (int i = 1; i<=n; ++i) {
		cout << setfill(' ') << setw(n-i) << "";
		cout << setfill('#') << setw(i) << "#" << "\n";
	}
}

int main(int argc, char** argv)
{
	int stairs;
	cin >> stairs;

	stairway_to_heaven(stairs);
	return 0;
}
