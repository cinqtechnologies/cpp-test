#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

int main(int argc, char** argv)
{
	int numLines, inputNum;
	std::vector<int> myVec;
	std::cin >> numLines;
	for (int reps = 0; reps < numLines; reps++)
	{
		std::cin >> inputNum;
		myVec.push_back(inputNum);
	}
	std::sort(myVec.begin(), myVec.end());
	for (std::vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
	{
		std::cout << *it << "\n";
	}
	return 0;
}
