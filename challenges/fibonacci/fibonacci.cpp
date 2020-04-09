#include <iostream>

using namespace std;

int main (){
    unsigned int sequencia = 0;
    unsigned int a = 0 , b = 1;
    unsigned int limite = 0;

    cout << "Enter the amout of fibonaccinuber: " << endl;
    cin >> limite;

    cout << a << endl;
    cout << b << endl;

    for( int n = 1; n < limite; n++){
        sequencia = (a + b);
        cout << sequencia  << endl;
        a = b;
        b = sequencia;
    }
    return 0;
}
