#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check_is_palindrome(const string word){
    int i = 0;
    int size = word.size()-1;
    int last = size/2;
    while(i < last){
        if (word[size-i] == word[i])
            i++;
        else
            return false;
    }
    return true;
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
        if (check_is_palindrome(lines[i]))
            cout << lines[i] << " is palindrome" << endl;
        else
            cout << lines[i] << " is not palindrome" << endl;
    }

    return 0;
}
