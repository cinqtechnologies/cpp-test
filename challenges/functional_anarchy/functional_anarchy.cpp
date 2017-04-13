/* @Author: Carlos Eduardo L. de S. Grell Silva
for Cinq Technologies' hiring test */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

int main(int argc, char** argv)
{

	vector<int> v;
	int num_lines;
	cin  >> num_lines;

	for(string s; getline(cin, s);)
	{
		if(s.size()>0) v.push_back(atoi(s.c_str()));
		if(--num_lines < 0) break;
	}

	sort(v.begin(), v.end());
	for(int i=0; i< v.size(); i++) cout << v[i] << endl;

	return 0;
}
