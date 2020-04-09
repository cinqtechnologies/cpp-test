#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int i, j;
    int num;

    cout << "Enter the number os liner to print: ";
    cin >> num;
    if (num < 0){
        cout << "Error " << endl;
        return 1;
    }

    for ( i = 1; i <= num; i++ ) {
        cout << endl;
        for ( j = 1; j <= i; j++ )
            cout << "#";
    }
    return 0;
}
