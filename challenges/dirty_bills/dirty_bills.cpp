#include <iostream>
#include <string>

using namespace std;

void count_dirty_bills(long &db) {
	int bills;
	string type;

	cin >> bills >> type;
	if (type.compare("dirty") == 0)
		db += bills;
}

int main(int argc, char** argv)
{
	int line_count;
	long dirty = 0;

	cin >> line_count;
	while (line_count--) {
		count_dirty_bills(dirty);
	}

	if (dirty)
		cout << "There are " << dirty << " dirty bills.\n";
	else
		cout << "There are no dirty bills.\n";

	return 0;
}
