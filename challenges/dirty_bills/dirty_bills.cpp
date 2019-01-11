#include <iostream>
#include <string>

#define DIRTY_BILLS_DIRTY	"dirty"

int main(int argc, char** argv)
{
	int queries = 0;
	int bills = 0;

	int dirty_bills = 0;

	std::string bill_state;

	std::cin >> queries;

	while (queries > 0)
	{
		std::cin >> bills;
		std::cin >> bill_state;

		if (bill_state.compare(DIRTY_BILLS_DIRTY) == 0)
		{
			dirty_bills += bills;
		}

		--queries;
	}

	if (0 >= dirty_bills)
	{
		std::cout << "There are no dirty bills.";
	}
	else
	{
		std::cout << "There are " << dirty_bills << " dirty bills.";
	}
	std::cout << std::endl;

	return 0;
}
