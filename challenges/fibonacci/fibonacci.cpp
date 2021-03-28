#include <iostream>

using namespace std;

long fibonacci(int n) { 
  long f[n+2];

  f[0] = 0; 
  f[1] = 1; 

  for (int i = 2; i <= n; i++) { 
      f[i] = f[i-1] + f[i-2]; 
  } 

  return f[n]; 
} 

int main(int argc, char** argv)
{
	int in;

	cin >> in;
	cout << fibonacci(in) << "\n";
	return 0;
}
