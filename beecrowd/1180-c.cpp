#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N; 

    int X[1000]; // Vetor com tamanho fixo máximo de 1000

    // Lê os elementos do vetor
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    // Inicializa menor valor e posição
    int menor = X[0];
    int posicao = 0;

    // Procura o menor valor
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
