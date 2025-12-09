#include <iostream>
using namespace std;

void quicksortCrescente(int v[], int inicio, int fim) {
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2];
    while (i <= j) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;
        if (i <= j) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if (inicio < j) quicksortCrescente(v, inicio, j);
    if (i < fim) quicksortCrescente(v, i, fim);
}

void quicksortDecrescente(int v[], int inicio, int fim) {
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2];
    while (i <= j) {
        while (v[i] > pivo) i++;
        while (v[j] < pivo) j--;
        if (i <= j) {
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    if (inicio < j) quicksortDecrescente(v, inicio, j);
    if (i < fim) quicksortDecrescente(v, i, fim);
}

int main() {
    int N;
    cin >> N;

    int pares[100000];
    int impares[100000];
    int qtdP = 0, qtdI = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0)
            pares[qtdP++] = x;
        else
            impares[qtdI++] = x;
    }

    // Ordena os pares em ordem crescente
    if (qtdP > 0) quicksortCrescente(pares, 0, qtdP - 1);
    // Ordena os ímpares em ordem decrescente
    if (qtdI > 0) quicksortDecrescente(impares, 0, qtdI - 1);

    // Saída
    for (int i = 0; i < qtdP; i++)
        cout << pares[i] << "\n";

    for (int i = 0; i < qtdI; i++)
        cout << impares[i] << "\n";

    return 0;
}
