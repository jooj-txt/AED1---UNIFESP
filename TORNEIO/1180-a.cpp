#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
        
    cout << "Insira o tamanho do vetor:(e seus numeros) " << endl;
    cin >> N; // Lê o tamanho do vetor
    
    vector<int> X(N);
    
    for (int i = 0; i < N; i++) {
        cin >> X[i]; // Lê os elementos do vetor
    }
    
    int menor = X[0];
    int posicao = 0;
    
    for (int i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }
    
    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << posicao << endl;
    
    return 0;
}
