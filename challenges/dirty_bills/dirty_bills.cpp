#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

    int dirties = 0;
    for (i = 0; i < lines.size(); i++){
        line = lines[i];
        int pos = line.find(" ");
        string state = line.substr(pos+1, line.size());
        if (state == "dirty"){
            string number = line.substr(0, pos);
            dirties += stoi(number);
        }

    }
    if (dirties > 0)
        cout << "There are " << dirties << " dirty bills." << endl;
    else
        cout << "There are no dirty bills." << endl;

    return 0;
}
