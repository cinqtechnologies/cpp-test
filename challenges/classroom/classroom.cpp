#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <limits>

class ClassList;

namespace Query
{
	enum Type
	{
		INSERT_STUDENT = 1,
		LOOKUP_STUDENT = 2
	};
}

struct ClassListQuery
{
	Query::Type type;
	int queryArgument;
};

class ClassList
{
public:
	ClassList() : isSorted(false) { }

	void addStudent(const std::string& student) {
		isSorted = false;
		students.push_back(student);
	}

	const std::string& lookupStudent(int classIndex) {

		if (!isSorted)
		{
			std::sort(students.begin(), students.end());
			isSorted = true;
		}

		return students.at(classIndex);
	}

private:
	std::vector<std::string> students;
	bool isSorted;
};

ClassListQuery pullQuery(std::istream& stream)
{
	int queryType;
	int queryArgument;
	std::cin >> queryType;
	std::cin >> queryArgument;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	ClassListQuery query = { static_cast<Query::Type>(queryType), queryArgument };
	return query;
}

void executeQueryFromStream(ClassList& classList)
{
	ClassListQuery query = pullQuery(std::cin);

	if (query.type != Query::INSERT_STUDENT && query.type != Query::LOOKUP_STUDENT)
	{
		std::cout << "Query do tipo inválida: " << query.type << std::endl;
		return;
	}

	for (int i = 0; i < query.queryArgument; i++)
	{
		if (query.type == Query::INSERT_STUDENT)
		{
			std::string studentName;
			std::getline(std::cin, studentName);
			classList.addStudent(studentName);
		}
		else /* if (query.type == Query::LOOKUP_STUDENT) */
		{
			unsigned int index;
			std::cin >> index;
			std::cout << classList.lookupStudent(index - 1) << std::endl;
		}
	}
}

int main(int argc, char** argv)
{
	int numOfQueries;
	std::cin >> numOfQueries;

	ClassList classList;
	int typeOfQuery;
	while(numOfQueries-- > 0)
		executeQueryFromStream(classList);
}
