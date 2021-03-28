#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void staircase(int n) {

    int spaces = n-1;
    int hashes = 1;

    for(int i = 0; i < n; i++) {
		
        for(int j = 0; j < spaces; j++)
            cout << ' ';

        for(int k = 0; k < hashes; k++)
            cout << '#';
			
        cout << endl;
        spaces--;
        hashes++;
    }

}

int main(int argc, char** argv)
{
    int n = 0;
    cin >> n;

    if (n <= 0) {
        cout << "Error.\n";
    } else {
        staircase(n);
    }

	return 0;
}
