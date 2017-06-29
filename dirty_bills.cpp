#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    int N = 0, X = 0, dirtySum = 0;
    string str = "";
    cin >> N;
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> X >> str;
            if(str.compare("dirty") == 0)
                dirtySum += X;
        }
    }

    if (dirtySum > 0)
        cout << "There are " << dirtySum << " dirty bills.\n";
    else
        cout << "There are no dirty bills.\n";

	return 0;
}
