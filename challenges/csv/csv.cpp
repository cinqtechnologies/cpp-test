#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

#include <string.h>

#define CSV_FIELD_DELIMITER	','
#define CSV_FIELD_MAXLENGTH	256

class CSVEntry
{
	public:
		CSVEntry()
		{			
		};

		void parseString(const std::string& source)
		{
			char csv_field[CSV_FIELD_MAXLENGTH + 1];

			std::stringstream ss(source);

			_name.clear();
			_city.clear();
			_state.clear();
			_country.clear();
			_age = 0;

			// Retrieves the 'name' field
			memset(&(csv_field[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_field, CSV_FIELD_MAXLENGTH, CSV_FIELD_DELIMITER);
			_name.assign(csv_field);

			// Retrieves the 'state' field
			memset(&(csv_field[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_field, CSV_FIELD_MAXLENGTH, CSV_FIELD_DELIMITER);
			_state.assign(csv_field);

			// Retrieves the 'city' field
			memset(&(csv_field[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_field, CSV_FIELD_MAXLENGTH, CSV_FIELD_DELIMITER);
			_city.assign(csv_field);

			// Retrieves the 'country' field
			memset(&(csv_field[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_field, CSV_FIELD_MAXLENGTH, CSV_FIELD_DELIMITER);
			_country.assign(csv_field);

			// Retrieves the 'age' field
			memset(&(csv_field[0]), CSV_FIELD_MAXLENGTH + 1, 0x00);
			ss.getline(csv_field, CSV_FIELD_MAXLENGTH, CSV_FIELD_DELIMITER);
			_age = std::atoi(csv_field);
		};

		std::string toString() const
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

	// Clears the stdin buffer
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 0x0a);
	
	while (queries > 0)
	{
		std::getline(std::cin, entry);

		csv_entry.parseString(entry);

		std::cout << csv_entry.toString() << std::endl;

		--queries;
	}

	return 0;
}
