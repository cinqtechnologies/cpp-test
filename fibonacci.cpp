#include <iostream>

using namespace std;

long long fibonacci(int X) {

    long long fib[X+1];

    if(X >= 0)
        fib[0] = 0;
    if (X >= 1)
        fib[1] = 1;
    if (X > 1) {
        for(int i = 2; i <= X; i++)
            fib[i] = fib[i-1]+fib[i-2];
    }

    return fib[X];

}

int main(int argc, char** argv)
{
    int X = 0;
    cin >> X;
    if (X >= 0)
        cout << fibonacci(X);
	return 0;
}
