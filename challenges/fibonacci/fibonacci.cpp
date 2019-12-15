#include <iostream>
#include <cmath>

using namespace std;

unsigned long int fibonacci(int n){

		long double fib[n];
		fib[0] = 0; fib[1] = 1;

		for(int i=2; i <= n;i++){
				fib[i] = fib[i-1] + fib[i-2];
		}

		return round(fib[n]);
}

int main(int argc, char* argv[])
{
		int n;
		cin >> n;
		cout << fibonacci(n) << endl;

		return 0;
}
