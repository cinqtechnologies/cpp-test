#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


/**
 * @brief The Query struct.
 *
 * Each query has it's own type which can be one of the following 'Insert' or 'Consult'
 * and must be executed N times.
 */
struct Query
{
    int m_iType;
    int m_iAmount;
};

/**
 * @brief Process a single query.
 * @param query The query to be processed.
 * @param strVecStudents The student's list used in the query.
 */
void processQuery(const Query& query, std::vector<std::string>& strVecStudents);

/**
 * @brief Insert N students in the given list and keeps it alphabetically sorted.
 * @param strVecStudents The list of students.
 * @param iStudents Number of Students to be inserted.
 *
 * @note For performance issues we sorting our list after the elements insertions. Keep
 *       our list sorted while inserting elements takes O(n^2) (Insertion Sort), while
 *       sorting after insertion takes O(nlg(n)).
 */
void insertStudents(std::vector<std::string> &strVecStudents, const int iStudents);

/**
 * @brief Perform N consults in the given student's list.
 * @param strVecStudents The list of students.
 * @param iConsults Number of consults to performed.
 */
void consultStudents(const std::vector<std::string> &strVecStudents,
                     const int iConsults);

int main(int argc, char** argv)
{
    int iQueries = 0;
    std::cin >> iQueries;

    if(iQueries <= 0)
    {
        std::cerr << "Error: number of queries must be >0.";

        exit(1);
    }

    // students alphabetically sorted.
    std::vector<std::string> strVecStudents;

    for(int i = 0; i < iQueries; ++i)
    {
        Query query;
        std::cin >> query.m_iType >> query.m_iAmount;
        std::cin.ignore();

        processQuery(query, strVecStudents);
    }

    return 0;
}

void processQuery(const Query &query, std::vector<std::string> &vecStudents)
{
    switch(query.m_iType)
    {
    case 1:
    {
        insertStudents(vecStudents, query.m_iAmount);
        break;
    }
    case 2:
    {
        consultStudents(vecStudents, query.m_iAmount);
        break;
    }
    default:
        std::cerr << "Invalid query type: it should be 1 or 2.\n";
        exit(1);
    }
}

void insertStudents(std::vector<std::string> &strVecStudents, const int iStudents)
{
    std::string strStudent;
    std::vector<std::string> vecTmpStudents;

    for(int i = 0; i < iStudents; ++i)
    {
        std::getline(std::cin, strStudent);
        vecTmpStudents.push_back(strStudent);
    }

    std::sort(vecTmpStudents.begin(), vecTmpStudents.end());
    strVecStudents.insert(strVecStudents.end(),
                          vecTmpStudents.begin(), vecTmpStudents.end());
}

void consultStudents(const std::vector<std::string> &vecStudents,
                     const int iConsults)
{    
    for(int i = 0; i < iConsults; ++i)
    {
        int iStudentIndex = 0;
        std::cin >> iStudentIndex;

        std::cout << vecStudents[iStudentIndex - 1] << "\n";
    }
}
