#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#include <string.h>

#define CSV_ENTRY_DELIMITER	','
#define CSV_FIELD_MAXLENGTH	256

class CSVEntry
{
	public:
		CSVEntry(){};

		void parse_string(const std::string& source)
		{
			char csv_entry[CSV_FIELD_MAXLENGTH + 1];

			std::stringstream ss(source);

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

		std::string to_string()
		{
			std::stringstream ss;

			ss << _name << " is "
			   << _age  << " years old "
				 << "and lives in "
				 << _city << ", " << _state << ".";

			return ss.str();
		};

	private:
		std::string _name;
		std::string _city;
		std::string _state;
		std::string _country;
		int _age;
};

int main(int argc, char** argv)
{
	int queries = 0;

	std::string entry;

	CSVEntry csv_entry;

	std::cin >> queries;

	/* Clears the stdin buffer */
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 0x0a);
	
	while (queries > 0)
	{
		std::getline(std::cin, entry);

		csv_entry.parse_string(entry);

		std::cout << csv_entry.to_string() << std::endl;

		--queries;
	}

	return 0;
}
