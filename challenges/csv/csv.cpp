#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const short COLUMNS = 5;
const char NEWLINE = '\n';
const char DELIMITER = ',';

void insert_line(vector<string> &user) {
	string line, data;
	getline(cin, line, NEWLINE);
	istringstream iss(line);

	for (int i = 0; i < COLUMNS; ++i) {
		getline(iss, data, DELIMITER);
		user.push_back(data);
	}
}

void print_user(vector<string> &user) {
	cout << user.at(0) << " is " << user.at(4)
		 << " years old and lives in " << user.at(2)
		 << ", " << user.at(1) << ".\n";
}

int main(int argc, char** argv)
{
	int num_lines; cin >> num_lines;
	vector<string> users[num_lines];

	cin.ignore(); // removing blank line after N
	for (vector<string> &user : users) {
		insert_line(user);
		print_user(user);
	}

	return 0;
}
