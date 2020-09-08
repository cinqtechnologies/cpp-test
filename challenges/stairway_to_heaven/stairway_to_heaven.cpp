#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void print_stairs(const int num, const int size){
    int i = 0;
    int len = size-num;
    for(i = 0; i < len; i++)
        cout << ' ';
    for(i = len; i <= size; i++)
        cout << '#';
    cout << endl;
}

int main(int argc, char** argv)
{
    int n = 0;
    cin >> n;

    if (n <= 0)
        cout << "Error." << endl;
    else {
        for(int i = 0; i < n; i++)
            print_stairs(i, n);
    }

    return 0;
}
