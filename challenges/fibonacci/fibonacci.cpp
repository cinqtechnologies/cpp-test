#include <iostream>
#include <cmath>

using namespace std;

unsigned long int fibonacci(int n){

		long double phi = (1 + sqrt(5)) / 2;
		return round(pow(phi, n) / sqrt(5));
}

int main(int argc, char* argv[])
{
		int n;
		cin >> n;
		cout << fibonacci(n) << endl;
		return fibonacci(n);
}
