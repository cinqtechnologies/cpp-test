#include <iostream>
#include <string>
#include <iomanip>

#define MAX_STAIR_STEP	23
#define STAIR_STEP_SPACE	' '
#define STAIR_STEP_HASH		'#'

using namespace std;

int main(int argc, char** argv)
{
	int steps = 0, step = 0;
	int spaces = 0;

	cin >> steps;

	if (steps <= 0 || steps > MAX_STAIR_STEP)
	{
		cout << "Error." << endl;
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
		cout << setfill(STAIR_STEP_SPACE);
		if (spaces > 0)
		{
			cout << setw(spaces);
			cout << STAIR_STEP_SPACE;
		}

		/* Prints the hashs in the current step */
		cout << setfill(STAIR_STEP_HASH) << setw(step);
		cout << STAIR_STEP_HASH;
		cout << endl;
	}

	return 0;
}
