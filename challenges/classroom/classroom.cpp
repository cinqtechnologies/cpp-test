#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

int main(int argc, char** argv)
{
	int numberQueries;
	std::list<std::string> studentsList;

	std::cin >> numberQueries;
	std::cin.ignore(); 
	if (numberQueries > 0)
	{
		std::string studentName, opTypeRaw, opRepsRaw, studentPosRaw;
		int opType, opReps, studentPos;
		while (numberQueries--)
		{
			std::getline(std::cin, opTypeRaw, ' ');				// get default input line until blankspace
			std::getline(std::cin, opRepsRaw);					// get rest of the input line until carret return
			opType = atoi(opTypeRaw.c_str());
			opReps = atoi(opRepsRaw.c_str());
			if (opReps <= 0)
			{
				std::cout << "Invalid number of operations.\n";
			}
			else
			{
				switch(opType)
				{
					case 1: // Insert student
					while (opReps--)
					{
						std::getline(std::cin, studentName);
						studentsList.push_back(studentName);
					}
					studentsList.sort();
					break;
					case 2: // Find student at position
					while (opReps--)
					{
						std::getline(std::cin, studentPosRaw);
						studentPos = atoi(studentPosRaw.c_str());
						if ((studentPos > 0) && (studentPos < studentsList.size()))
						{
							std::list<std::string>::iterator it = studentsList.begin();
							std::advance(it, studentPos-1);
							std::cout << *it << "\n";
						}
					}
					break;
					default:
					std::cout << "Invalid operation.\n";
				}
			}
		}
	}
	else
	{
		std::cout << "Invalid number of queries.\n";
	}
	return 0;
}
