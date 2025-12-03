#include <iostream>
using namespace std;

bool valido(int valores[9]) {
    int freq[10] = {0}; 

    for (int i = 0; i < 9; i++) {
        int v = valores[i];
        if (v < 1 || v > 9) return false; 
        freq[v]++;
    }

    for (int i = 1; i <= 9; i++) {
        if (freq[i] != 1) return false; 
    }

    return true;
}

int main() {
    int n;
    cin >> n; 

    for (int k = 1; k <= n; k++) {
        int matriz[9][9];   
        int buffer[9];    

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> matriz[i][j];
            }
        }

        bool ok = true;

        for (int i = 0; i < 9 && ok; i++) {
            for (int j = 0; j < 9; j++) buffer[j] = matriz[i][j];
            if (!valido(buffer)) ok = false;
        }

        for (int j = 0; j < 9 && ok; j++) {
            for (int i = 0; i < 9; i++) buffer[i] = matriz[i][j];
            if (!valido(buffer)) ok = false;
        }

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

        
        cout << "Instancia " << k << endl;
        cout << (ok ? "SIM" : "NAO") << endl;
        cout << endl;
    }

    return 0;
}
