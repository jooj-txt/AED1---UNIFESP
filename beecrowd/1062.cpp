#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0) {
        while (true) {
            int a;
            cin >> a;
            if (a == 0) break; // fim do bloco

            int target[1001];
            target[0] = a;
            for (int i = 1; i < n; i++) cin >> target[i];

            int pilha[1001];
            int topo = -1;
            int proximo = 1; // próximo vagão a entrar
            int i = 0;       // posição na sequência de saída

            while (i < n) {
                if (topo >= 0 && pilha[topo] == target[i]) {
                    topo--; // desempilha (sai para B)
                    i++;
                } else if (proximo <= n) {
                    pilha[++topo] = proximo++; // empilha próximo
                } else {
                    break; // não há mais vagões pra empilhar
                }
            }

            if (i == n) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << "\n"; // linha em branco entre blocos
    }

    return 0;
}
