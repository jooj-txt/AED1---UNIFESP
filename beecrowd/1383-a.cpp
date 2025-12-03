#include <iostream>
using namespace std;

// Função que verifica se um array de 9 elementos tem todos os números de 1 a 9
bool valido(int *valores) {
    int freq[10] = {0}; // de 0 até 9

    for (int i = 0; i < 9; i++) {
        int v = valores[i];
        if (v < 1 || v > 9) return false; // número inválido
        freq[v]++;
    }

    for (int i = 1; i <= 9; i++) {
        if (freq[i] != 1) return false; // cada número deve aparecer exatamente uma vez
    }

    return true;
}

int main() {
    int n;
    cin >> n; // número de instâncias

    for (int k = 1; k <= n; k++) {
        int matriz[9][9];

        // Lendo a matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> matriz[i][j];
            }
        }

        bool ok = true;
        int buffer[9]; // array auxiliar para linha, coluna ou bloco

        // Verifica as linhas
        for (int i = 0; i < 9 && ok; i++) {
            for (int j = 0; j < 9; j++) buffer[j] = matriz[i][j];
            if (!valido(buffer)) ok = false;
        }

        // Verifica as colunas
        for (int j = 0; j < 9 && ok; j++) {
            for (int i = 0; i < 9; i++) buffer[i] = matriz[i][j];
            if (!valido(buffer)) ok = false;
        }

        // Verifica as regiões 3x3
        for (int bi = 0; bi < 9 && ok; bi += 3) {
            for (int bj = 0; bj < 9 && ok; bj += 3) {
                int idx = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        buffer[idx++] = matriz[bi + i][bj + j];
                    }
                }
                if (!valido(buffer)) ok = false;
            }
        }

        // Saída
        cout << "Instancia " << k << endl;
        cout << (ok ? "SIM" : "NAO") << endl;
        cout << endl;
    }

    return 0;
}
