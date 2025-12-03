#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // limpar \n

    while (N--) {
        string linha;
        getline(cin, linha);

        stringstream ss(linha);
        vector<string> palavras;
        string p;

        while (ss >> p)
            palavras.push_back(p);

        // Ordenação estável por tamanho (decrescente)
        stable_sort(palavras.begin(), palavras.end(),
            [](const string& a, const string& b) {
                return a.size() > b.size();
            }
        );

        for (int i = 0; i < (int)palavras.size(); i++) {
            if (i > 0) cout << " ";
            cout << palavras[i];
        }
        cout << "\n";
    }
    return 0;
}
