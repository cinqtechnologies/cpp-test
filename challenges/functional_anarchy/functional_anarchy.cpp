#include <iostream>
#include <vector>

using namespace std;

void selecao(int vetor[], int n){
    int menor, aux;
    for(int i = 0; i < n-1; i++){
        menor = i;
        for(int j = 1 + 1; j < n; j++){
            if(vetor[menor] > vetor[j])
                menor = j;
        }
        if(i != menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

int main(){
    int n;
    vector<int> numbers;
    cout << " Enter the number os numbers to read: " << endl;
    cin >> n;
    int vetor[n];
    int aux;
    for(int x = 0; x < n; x++){
        cout << " Enter the number " << x+1 << endl;
        cin >> vetor[x];
    }
    selecao(vetor, n);

    for(int i = 0; i < n ; i++){
        cout << vetor[i] << " - ";
    }
    return 0;
}
