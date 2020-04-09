#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int toInteger(string str){
    cout << "tointeger received: " << str<<endl;
    int num = 0,size = str.size();
    for(int i = 0, j = size; i < size; i++){
        num+=(str[--j]-'0'*pow(10,i));
    }
    cout << "return: " << num << endl;
    return num;
}

int main()
{
    int num, position, type_query;
    char a[50];
    string str;
    vector<string> v_string;
    vector<string> data_input;
    vector<vector<string>> queries;
    int dirty=0;
    int val, b, x=0;

    cout << "Enter the amount of lines to read:" << endl;
    cin >> num;
    cin.ignore();

    for(int i=0; i<num; i++){
        cout << "--Enter amount of bill and type--" << endl;
        //using gets() because cin does not accept empty spcace
        gets(a);
        std::istringstream buf(a);
        std::istream_iterator<string> beg(buf), end;
        std::vector<string> tokens(beg, end);
        for(auto& s: tokens){
            data_input.push_back(s);
            cout << "token: " << s << endl;
        }
        queries.push_back(data_input);
        if (queries.at(i).at(1) == "dirty"){
            cout << "dirty" << endl;
            cout << "value of i: " << i << endl;
            string buff = queries.at(i).at(0);
            std::istringstream(buff) >> b;
            cout << b << endl;
            b =0;
            /*val = stoi(queries.at(i).at(0));
            x = toInteger(queries.at(i).at(0));
            cout << x << endl;
            dirty = dirty + x;
            x, val=0;*/
        }
    }
    cout << "There are " << dirty << " dirty bills";
    return 0;
}
