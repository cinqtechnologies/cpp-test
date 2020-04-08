#include <iostream>
#include <string>

using namespace std;

void read_line(ulong &db, ulong &cb) {
	int bills;
	string type;

	cin >> bills >> type;
	if (type.compare("dirty") == 0)
		db += bills;
	else
		cb += bills;
}

int main(int argc, char** argv)
{
	int num_lines;
	ulong dirty_bills = 0, clean_bills = 0;

	cin >> num_lines;
	while (num_lines--) {
		read_line(dirty_bills, clean_bills);
	}

	if (dirty_bills)
		cout << "There are " << dirty_bills << " dirty bills.\n";
	else
		cout << "There are no dirty bills.\n";

	return 0;
}
