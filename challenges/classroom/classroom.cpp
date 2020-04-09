#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    int num, position;
    int type_query;
    char a[50];
    string str;
    vector<string> v_string;
    vector<int> data_input;
    vector<vector<int>> queries;

    cout << "Enter the queries amount:" << endl;
    cin >> num;
    cin.ignore();

    for(int i=0; i<num; i++){

        cout << "--Enter the query type--" << endl;
        cout << "1 - Insert student in the presence list\n2 - Consult student in the presence list in the given position" << endl;
        cout << "  -- If wanna 1 add the amount to insert (example 1 10, insert and position 10)" << endl;
        cout << "  -- If wanna 2 add the amount to check " << endl;
        //using gets() because cin does not accept empty spcace
        gets(a);
        std::istringstream buf(a);
        std::istream_iterator<int> beg(buf), end;
        std::vector<int> tokens(beg, end);
        for(auto& s: tokens){
            data_input.push_back(s);
        }
        queries.push_back(data_input);
        if (queries.at(i).at(i) == 1){
            for(int i=0; i< data_input.at(1); i++ ){
                cout << "Enter student name: " << endl;
                getline(cin, str);
                v_string.push_back(str);
            }
        }else{
            cout << "Enter position of student:  ";
            cin >> position;
            cin.ignore();
            cout << v_string.at(position);
        }
    }
    return 0;
}
