#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int n = 0;
    cin >> n;

    if (n == 0){
        cout << n << endl;
        return 0;
    }
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }

    unsigned long fibo = 1;
    if (n > 1){
        unsigned long n_a = 0;
        unsigned long n_b = 1;

        for(int i = 2; i <= n; i++){
            fibo = n_a + n_b;
            n_a = n_b;
            n_b = fibo;
        }
        cout << fibo << endl;
    }

    return 0;
}
