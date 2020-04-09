#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool isAnagram (string A, string B){

    int n1, n2, i;
    n1 = A.length();
    n2 = B.length();

    if(n1 != n2)
        return false;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(i =0 ; i<n1 ; i++){
        if( A[i] != B[i] )
            return false;
    }
    return true;
}

int main(){

    std::string str;
    bool result;
    //using char here because will use gets()
    char a[100];
    int num;
    cout << "Enter amout(number) of lines to analize: ";
    cin >> num;
    cin.ignore();
    int count =0;
    do {
        cout << "Enter two word to analize(separated by space): " << endl;
        //using getss() because cin does not accept empty spcace
        gets(a);
        std::istringstream buf(a);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> tokens(beg, end);
        vector<string> words;
        for(auto& s: tokens){
            words.push_back(s);
        }
        result = isAnagram(words.at(0), words.at(1));
        if(result == 1){
            cout << words.at(0) << " is an anagrams of " << words.at(1) << endl;
        }else{
            cout << words.at(0) << " is not an anagrams of " << words.at(1) << endl;
        }
        count ++;
    } while (count<num);
}
