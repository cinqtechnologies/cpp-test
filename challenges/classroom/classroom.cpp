#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

const short INSERT = 1;
const short QUERY = 2;

void do_operation(vector<string> &students, int op, int num_ops) {
	switch (op)
	{
	case INSERT:
	{
		string name;
		cin.ignore(); // Removing blank line

		while (num_ops--) {
			getline(cin, name);
			students.push_back(name);
		}
		sort(students.begin(), students.end());
		break;
	}
	case QUERY:
	{
		while (num_ops--) {
			int index;

			cin >> index;
			cout << students.at(index-1) << "\n";
		}
		break;
	}

	default:
		break;
	}
}

int main(int argc, char** argv)
{
	int num_queries, op, num_ops;
	vector<string> students;

	cin >> num_queries;
	while (num_queries--) {
		cin >> op >> num_ops;
		do_operation(students, op, num_ops);
	}

	return 0;
}
