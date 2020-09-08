#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print_csv(const string input){
    int i = input.find(',');
    string name = input.substr(0, i);
    int j = input.find(',',i+1);
    string state = input.substr(i+1, j-i-1);
    i = j+1;
    j = input.find(',',i);
    string city = input.substr(i, j-i);
    i = j+1;
    j = input.find(',',i);
    string country = input.substr(i, j-i);
    i = j+1;
    string age = input.substr(i, input.size()-i);

    cout << name << " is " << age << " years old and lives in " << city << ", " << state << "." << endl;
}

int main(int argc, char** argv)
{
    int n;
    cin >> n;

    // avoid double ENTER in my machine
    cin.ignore();

    vector<string> lines;

    int i = 0;
    string line;
    for(i = 0; i < n; i++){
        getline(cin, line);
        lines.push_back(line);
    }

    for (i = 0; i < lines.size(); i++){
        line = lines[i];
        print_csv(line);
    }

    return 0;
}
