#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;


void sorted_insert(vector<int> &list, const int value)
{
    int size = list.size();
    if (size == 0){
        list.push_back(value);
        return;
    }

    int i = 0;
    while(i < size) {
        if (value <= list[i]){
            list.insert(list.begin()+i, value);
            break;
        }
        else
            i++;
    }
    if (i == size)
        list.push_back(value);
}

int main(int argc, char** argv)
{
    int n;
    cin >> n;

    // avoid double ENTER in my machine
    cin.ignore();

    vector<int> list;

    int i = 0;
    int num = 0;
    for(i = 0; i < n; i++){
        cin >> num;
        sorted_insert(list,num);
    }

    for(i=0; i < list.size(); i++)
        cout << list[i] << endl;

    return 0;
}
