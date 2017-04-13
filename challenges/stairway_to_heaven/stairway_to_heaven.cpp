/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, char** argv)
{

	int num_lines;
	cin  >> num_lines;

	if(num_lines && num_lines > 0)
	{
		for(int j = 0; j < num_lines; j++)
		{
			for(int i = 0; i < num_lines-1-j; i++) cout << " ";
			for(int k = 0; k < j+1; k++) 					 cout << "#";
			cout << endl;
		}

	}
	else cout << "Error.";

	return 0;
}
