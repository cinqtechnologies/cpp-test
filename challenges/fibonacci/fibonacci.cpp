/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{

	int index;
	long long result    = 0;
	long long res_prev  = 0;
	long long res_prev2 = 0;
	cin >> index;

	if(index == 0)
	{
			cout << result;
			return 0;
	}

	for(int i= 0; i<index; i++)
	{
		if (result == 0) result++;
		else
		{
			res_prev2 = res_prev;
			res_prev  = result;
			result    = res_prev + res_prev2;
		}
	}

	cout << result;
	return 0;
}
