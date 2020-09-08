#include <iostream>
//#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check_is_anagram(string first, string second){
    int size = first.size()-1;
    while (size >= 0){
        char c = first[size];
        char f = second.find(c);
        if (f >= 0) // found
            first.erase(size);
        else
            break; //not found
        size--;
    }

    if (first.empty())
        return true;
    else
        return false;
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
        int pos = line.find(" ");
        string first = line.substr(0, pos);
        string second = line.substr(pos+1, line.size());

        if (check_is_anagram(first, second))
            cout << first << " is an anagram of " << second << endl;
        else
            cout << first << " is not an anagram of " << second << endl;
    }

    return 0;
}
