#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> // Para memset

using namespace std;

#define MAX 10005 // Margem de segurança para números até 10000

// Array para guardar a distância mínima de A até cada número
// dist[i] = -1 significa que o número 'i' ainda não foi visitado
int dist[MAX];

// Função auxiliar para inverter o número
// Ex: 123 -> 321, 150 -> 51
int inverter(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;
    }
    return res;
}

int bfs(int inicio, int fim) {
    // Limpa o array de distâncias para o novo caso de teste
    memset(dist, -1, sizeof(dist));
    
    queue<int> q;
    
    // Configuração inicial
    q.push(inicio);
    dist[inicio] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Se chegamos ao destino
        if (u == fim) return dist[u];
        
        // Operação 1: Adicionar 1
        int v1 = u + 1;
        // Verificamos se está dentro do limite e se não foi visitado
        if (v1 < MAX && dist[v1] == -1) {
            dist[v1] = dist[u] + 1;
            q.push(v1);
        }
        
        // Operação 2: Inverter
        int v2 = inverter(u);
        // Verificamos se está dentro do limite e se não foi visitado
        if (v2 < MAX && dist[v2] == -1) {
            dist[v2] = dist[u] + 1;
            q.push(v2);
        }
    }
    return -1; // Caso não encontre (teoricamente impossível dado o problema)
}

int main() {
    // Otimização de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << bfs(A, B) << "\n";
    }
    
    return 0;
}