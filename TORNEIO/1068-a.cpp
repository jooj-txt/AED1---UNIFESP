#include <iostream>
using namespace std;

int main() {
    char linha[1001];

    while (cin.getline(linha, 1001)) {
        int pilha[1000];
        int topo = 0;
        bool ok = true;

        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '(') {
                pilha[topo++] = '(';
            } else if (linha[i] == ')') {
                if (topo == 0) {
                    ok = false;
                    break;
                }
                topo--;
            }
        }

        if (topo != 0) ok = false;

        cout << (ok ? "correct" : "incorrect") << endl;
    }

    return 0;
}
