#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>

int main(int argc, char** argv)
{
	int queries;
	std::cin >> queries;

	std::list<std::string> list;

	while (queries > 0) {
		int Q, N;
		std::cin >> Q;
		std::cin >> N;
		std::cin.get();
		for (int i = 0; i < N; i++) {
			if (Q == 1) {
				std::string name;
				getline(std::cin, name);
				list.push_front(name);
			} else if (Q == 2) {
				int pos;
				list.sort();
				std::vector<std::string> vector { std::begin(list), std::end(list) };
				std::cin >> pos;
				std::cout << vector.at(pos-1) << std::endl;
			}
		}
		queries--;
	}

	return 0;
}
