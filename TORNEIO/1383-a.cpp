#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool valido(vector<int> &valores) {
    set<int> s(valores.begin(), valores.end());
    return (s.size() == 9 && *s.begin() == 1 && *s.rbegin() == 9);
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

        for (int i = 0; i < 9 && ok; i++) {
            vector<int> linha;
            for (int j = 0; j < 9; j++) linha.push_back(matriz[i][j]);
            if (!valido(linha)) ok = false;
        }

        for (int j = 0; j < 9 && ok; j++) {
            vector<int> coluna;
            for (int i = 0; i < 9; i++) coluna.push_back(matriz[i][j]);
            if (!valido(coluna)) ok = false;
        }

        for (int bi = 0; bi < 9 && ok; bi += 3) {
            for (int bj = 0; bj < 9 && ok; bj += 3) {
                vector<int> bloco;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        bloco.push_back(matriz[bi + i][bj + j]);
                    }
                }
                if (!valido(bloco)) ok = false;
            }
        }

        cout << "Instancia " << k << endl;
        if (ok) cout << "SIM" << endl;
        else cout << "NAO" << endl;
        cout << endl;
    }

    return 0;
}
