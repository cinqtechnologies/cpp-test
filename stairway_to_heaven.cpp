#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void stairwayToHeaven(int N) {

    int spaces = N-1;
    int hashTags = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < spaces; j++)
            cout << ' ';
        for(int k = 0; k < hashTags; k++)
            cout << '#';
        cout << endl;
        spaces--;
        hashTags++;
    }

}

int main(int argc, char** argv)
{
    int N = 0;

    cin >> N;

    if (N <= 0) {
        cout << "Error.\n";
    } else {
        stairwayToHeaven(N);
    }

	return 0;
}
