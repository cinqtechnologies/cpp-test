#include <iostream>
#include <string>
#include <iomanip>

#define MAX_STAIR_STEP	23
#define STAIR_STEP_SPACE	' '
#define STAIR_STEP_HASH		'#'

int main(int argc, char** argv)
{
	int steps = 0, step = 0;
	int spaces = 0;

	std::cin >> steps;

	if (steps <= 0 || steps > MAX_STAIR_STEP)
	{
		std::cout << "Error." << std::endl;
		return EXIT_FAILURE;
	}

	/*
	 * Prints the actual stair using setfill and setw
	 */

	for (step = 1; step <= steps; step++)
	{
		/* Calculates the number of spaces within the current step */
		spaces = steps - step;

		/* Prints the spaces within the current step */
		std::cout << std::setfill(STAIR_STEP_SPACE);
		if (spaces > 0)
		{
			std::cout << std::setw(spaces);
			std::cout << STAIR_STEP_SPACE;
		}

		/* Prints the hashs in the current step */
		std::cout << std::setfill(STAIR_STEP_HASH) << std::setw(step);
		std::cout << STAIR_STEP_HASH;
		std::cout << std::endl;
	}

	return 0;
}
