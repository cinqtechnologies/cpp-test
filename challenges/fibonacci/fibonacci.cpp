#include <iostream>

using namespace std;

// Recursive fibonacci was too slow for the high inputs of the program
// Using dynamic programing instead
ulong fibonacci(uint n) { 
  ulong f[n+2];

  f[0] = 0; 
  f[1] = 1; 
  
  for (int i = 2; i <= n; i++) { 
      f[i] = f[i-1] + f[i-2]; 
  } 
  
  return f[n]; 
} 

int main(int argc, char** argv)
{
	uint in;

	cin >> in;
	cout << fibonacci(in) << "\n";
	return 0;
}
