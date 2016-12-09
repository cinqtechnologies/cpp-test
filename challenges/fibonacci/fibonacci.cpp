#include <iostream>

int main(int argc, char** argv)
{
	unsigned fiboX, fiboLastLast = 0, fiboLast = 1, fiboCurrent = 0;
	std::cin >> fiboX;
	for (unsigned reps = 0; reps <= fiboX; reps++)
	{
		if (reps <= 1)
		{
			fiboCurrent = reps;
		}
		else
		{
			fiboCurrent = fiboLast + fiboLastLast;
			fiboLastLast = fiboLast;
			fiboLast = fiboCurrent;
		}
	}
	std::cout << fiboCurrent;
	return 0;
}
