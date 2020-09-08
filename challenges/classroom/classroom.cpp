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
    for (auto it : presence_list){
        if (pos == 1){
            cout << it << endl;
            return;
        }
        else
            pos--;
    }
}


int main(int argc, char** argv)
{
    int queries_n;
    cin >> queries_n;

    // avoid double ENTER in my machine
    cin.ignore();

    vector<string> lines;

    string line;
    int seq_reads = 0;
    while(queries_n > 0){
        getline(cin, line);
        if (isdigit(line[0])){
            int pos = line.find(" ");
            if (pos > 0){ // insert or query
                if (seq_reads == 0)
                    queries_n--;
                int first = stoi(line.substr(0, pos));
                int second = stoi(line.substr(pos+1, line.size()));
                if (first == 1) // is insert
                    seq_reads = second;
                else if (first == 2){ // is query
                    int pos = -1;
                    cin >> pos;
                    print_name(pos);
                }
            }
        }
        else if (seq_reads > 0) { //names
            presence_list.insert(line);
            seq_reads--;
        }
    }
    return 0;
}

