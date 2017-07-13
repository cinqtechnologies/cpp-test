#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>

bool compareNC(std::string ls, std::string rs)
{
    std::transform(ls.begin(), ls.end(), ls.begin(), ::tolower);
    std::transform(rs.begin(), rs.end(), rs.begin(), ::tolower);

    return ls < rs;
}

void consult_routine(std::vector<std::string> &slist, int n)
{
    std::vector<std::string>::size_type index;
    std::cin.ignore();
    
    while(n--)
    {
	std::cin >> index;
	if(index > 0 && index <= slist.size() )
	    std::cout << slist[index-1] << std::endl;
    }
	
}

void insert_routine(std::vector<std::string> &slist, int n)
{
    std::string name;
    std::cin.ignore();
    
    while(n--)
    {
	std::getline(std::cin, name);
	slist.push_back(name);
    }
}

int main(int argc, char** argv)
{
    int nq = 0;            // number of queries
    int q_id, q_amount;    // q_id: 1 or 2 (1 insert, 2 consult)

    std::vector<std::string> students;
    std::cin >> nq;

    // The main loop
    while(nq--)
    {
	std::cin >> q_id >> q_amount;
	
	switch (q_id) {
	    case 1: // Insertion mode
		insert_routine(students, q_amount);
		std::sort(students.begin(), students.end(), compareNC);
		break;
	    case 2:
		consult_routine(students, q_amount);
		break;
	    default:
		std::cerr << "q_id not recognized\n";
	}
    }
    
    return 0;
}
