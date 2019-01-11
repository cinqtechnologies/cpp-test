#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#include <string.h>

using namespace std;

#define CSV_ENTRY_DELIMITER	','
#define CSV_FIELD_MAXLENGTH	256

class CSVEntry
{
	public:
		CSVEntry(){};

		void parse_string(const string& source)
		{
			char csv_entry[CSV_FIELD_MAXLENGTH + 1];

			stringstream ss(source);

			_name.clear();
			_city.clear();
			_state.clear();
			_country.clear();
			_age = 0;

			/* Retrieves the name */
			memset(&(csv_entry[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_entry, CSV_FIELD_MAXLENGTH, CSV_ENTRY_DELIMITER);
			_name.assign(csv_entry);

			/* Retrieves the state */
			memset(&(csv_entry[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_entry, CSV_FIELD_MAXLENGTH, CSV_ENTRY_DELIMITER);
			_state.assign(csv_entry);

			/* Retrieves the city */
			memset(&(csv_entry[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_entry, CSV_FIELD_MAXLENGTH, CSV_ENTRY_DELIMITER);
			_city.assign(csv_entry);

			/* Retrieves the country */
			memset(&(csv_entry[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_entry, CSV_FIELD_MAXLENGTH, CSV_ENTRY_DELIMITER);
			_country.assign(csv_entry);

			/* Retrieves the age */
			memset(&(csv_entry[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_entry, CSV_FIELD_MAXLENGTH, CSV_ENTRY_DELIMITER);
			_age = atoi(csv_entry);
		};

		string to_string()
		{
			stringstream ss;

			ss << _name << " is "
			   << _age  << " years old "
				 << "and lives in "
				 << _city << ", " << _state << ".";

			return ss.str();
		};

	private:
		string _name;
		string _city;
		string _state;
		string _country;
		int _age;
};

int main(int argc, char** argv)
{
	int queries = 0;

	string entry;

	CSVEntry csv_entry;

	cin >> queries;

	/* Clears the stdin buffer */
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), 0x0a);
	
	while (queries > 0)
	{
		getline(cin, entry);

		csv_entry.parse_string(entry);

		cout << csv_entry.to_string() << endl;

		--queries;
	}

	return 0;
}
