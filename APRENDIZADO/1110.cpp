#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        queue<int> cartas;

        for (int i = 1; i <= n; i++)
            cartas.push(i); // 1 é o topo, n é a base

        cout << "Discarded cards:";
        bool primeiro = true;

        while (cartas.size() > 1) {
            if (primeiro) primeiro = false;
            else cout << ",";

            cout << " " << cartas.front(); // carta descartada
            cartas.pop();

            cartas.push(cartas.front()); // próxima vai pra base
            cartas.pop();
        }

        cout << "\nRemaining card: " << cartas.front() << "\n";
    }
    return 0;
}
