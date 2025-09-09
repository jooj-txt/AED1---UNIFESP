#include <iostream>
using namespace std;

int main() {
    int N;
    
    cout << "Insira o tamanho do vetor:(e seus numeros) " << endl;
    cin >> N; // Lê o tamanho do vetor

    // Aloca dinamicamente o vetor de inteiros
    int *X = new int[N];

    // Lê os valores do vetor usando ponteiro
    for (int i = 0; i < N; i++) {
        cin >> *(X + i);
    }

    // Inicializa o menor valor e posição
    int menor = *X;
    int posicao = 0;

    // Percorre o vetor com ponteiros
    for (int i = 1; i < N; i++) {
        if (*(X + i) < menor) {
            menor = *(X + i);
            posicao = i;
        }
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << posicao << endl;

    // Libera a memória alocada
    delete[] X;

    return 0;
}
