#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    while (cin >> N >> D && !(N == 0 && D == 0)) {
        string num;
        cin >> num;

        string resultado = "";
        int apagar = D;

        for (int i = 0; i < N; i++) {
            char c = num[i];

            // Enquanto puder apagar e o último dígito for menor que o atual, apaga
            while (!resultado.empty() && apagar > 0 && resultado.back() < c) {
                resultado.pop_back();
                apagar--;
            }

            resultado.push_back(c);
        }

        // Se ainda faltarem dígitos para apagar, remove do final
        while (apagar > 0) {
            resultado.pop_back();
            apagar--;
        }

        // O resultado final deve ter N - D dígitos
        for (int i = 0; i < N - D; i++)
            cout << resultado[i];
        cout << "\n";
    }

    return 0;
}
