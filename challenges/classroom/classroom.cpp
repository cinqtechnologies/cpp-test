#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <set>

using namespace std;

set<string> presence_list;

void print_name(int pos){
    for (auto it : presence_list) {
        if (pos == 1) {
            cout << it << endl;
            return;
        }
        else
            pos--;
    }
}


int main(int argc, char** argv)
{
    int actions_count;
    cin >> actions_count;

    cin.ignore();

    vector<string> lines;

    string line;
    int reads = 0;
	
    while(actions_count > 0) {
        getline(cin, line);

        if (isdigit(line[0])) {
            int pos = line.find(" ");

            if (pos > 0){ // check if insert or query
                if (reads == 0)
                    actions_count--;

                int req_type = stoi(line.substr(0, pos));
                int req_amount = stoi(line.substr(pos+1, line.size()));

                if (req_type == 1) { // type 1 == insert
                    reads = req_amount;
				}

                else if (req_type == 2) { // type 2 == query
                    int pos = -1;
                    cin >> pos;
                    print_name(pos);
                }
            }
        }
        else if (reads > 0) { // names
            presence_list.insert(line);
            reads--;
        }
    }
    return 0;
}