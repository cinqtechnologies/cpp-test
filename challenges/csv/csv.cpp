#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    int num = 0;
    ifstream theFile("sample.csv");
    string v1, v2, v3, v4, v5;

    cout << "Enter the amount of lines to read:" << endl;
    cin >> num;
    cin.ignore();

    for (int i = 0; i <num; i++) {
        getline(theFile, v1, ',');
        getline(theFile, v2, ',');
        getline(theFile, v3, ',');
        getline(theFile, v4, ',');
        getline(theFile, v5, '\n');
        cout << v1 << " is " << v5 << " years old and lives in " << v3 << ", " << v2 << endl;
    }
    theFile.close();
    return 0;
}
