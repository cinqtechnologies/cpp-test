#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
		int numberOfOperations = 0;
		vector<string> students;

		cin >> numberOfOperations;

		for(int op = numberOfOperations; op > 0; op--){
				int activity = 0;
				cin >> activity;

				if(activity == 1){
						int numberOfStudentsToAdd = 0;
						cin >> numberOfStudentsToAdd;

						for(int index = numberOfStudentsToAdd; index > 0; index--){
								string newStudent;
								while (newStudent.length()==0 )
										getline(cin, newStudent);

								students.push_back(newStudent);
						}
						sort(students.begin(), students.end());
				}
				else if(activity == 2){
						int numberOfStudentsToGet = 0;
						//Always 1
						cin >> numberOfStudentsToGet;
						int studentPosition = 0;
						cin >> studentPosition;

						// Is it allowed to query more than 1 student?
						for(int index = numberOfStudentsToGet; index > 0; index--){
								cout << students[studentPosition-1] << endl;
						}
				}
		}

	return 0;
}
