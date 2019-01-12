#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

typedef std::vector<std::string> Students;

#define CLASSROOM_QUERY_INSERT	1
#define CLASSROOM_QUERY_FIND		2

// Function: insert_student
// 
// Inserts a student entry in the students vector
// 
// Params:
//   student: string with the name of the student
//   students: vector containing the students
//
void insert_student(const std::string& student, Students& students)
{
	students.push_back(student);
}

// Function: find_student
// 
// Retrieves the student entry and index 'index'
// 
// Params:
//   index: the index of the entry (1-based)
//   students: vector containing the students
bool find_student(int index, std::string& student, Students& students)
{
	size_t vector_size = students.size();

	if (index <= 0 || index > vector_size)
	{
		return false;
	}

	student.assign(students.at(index - 1));
	return true;
}

int main(int argc, char** argv)
{
	int operations = 0;

	int queries, query;
	int index = 0;

	std::string student;

	Students students;

	// Retrieves the query type and the number of queries
	std::cin >> operations;
	while (operations > 0)
	{
		std::cin >> query >> queries;

		switch (query)
		{
			case CLASSROOM_QUERY_INSERT:
			{
				// Clears the stdin buffer
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 0x0a);

				// Reads the entries and insert the new student
				while (queries > 0)
				{
					std::getline(std::cin, student);

					insert_student(student, students);

					--queries;
				}

				// Sorts the vector alphabetically
				std::sort(students.begin(), students.end());
				break;
			}

			case CLASSROOM_QUERY_FIND:
			{
				while (queries > 0)
				{
					std::cin >> index;

					if (find_student(index, student, students))
					{
						std::cout << student << std::endl;
					}

					--queries;
				}
				break;
			}

			default:
			{
				// Unknown query type
				break;
			}
		}

		--operations;
	} // while (operations > 0)

	return 0;
}
