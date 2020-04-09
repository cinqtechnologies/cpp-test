#include<iostream>
#include<cstring>
#include <vector>

using namespace std;

bool palindrome(char *str)
{
    int b=strlen(str);
    for(int i=0,b;i>=b;i++,b--)
        if(str[i]!=str[b])
            return false;
    return true;
}

int main()
{
    char str[200];
    int n;
    cin>>n;
    vector<string> input_buffer;
    vector<bool> result_buffer;

    for(int i=0;i<n;i++)
    {
        cin>>str;
        input_buffer.push_back(str);
        result_buffer.push_back(palindrome(str));
    }

    for (int i = 0; i < n; i++)
    {
       cout << input_buffer.at(i) << (result_buffer.at(i) ? " is " : " is not") << "palindrome" << endl;
    }
    return 0;
}
