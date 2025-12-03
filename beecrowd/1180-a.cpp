#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N; // Lê o tamanho do vetor

    // Aloca dinamicamente o vetor
    int *X = new int[N];

    // Lê os elementos
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    // Inicializa com o primeiro valor
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

    // Libera a memória alocada
    delete[] X;

    return 0;
}
