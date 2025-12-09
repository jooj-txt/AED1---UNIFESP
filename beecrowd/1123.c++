#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // Valor para representar infinito

struct Edge {
    int v, w;
};

int main() {
    int N, M, C, K;
    
    // Loop de leitura até encontrar a linha com zeros
    while (cin >> N >> M >> C >> K && (N || M || C || K)) {
        vector<vector<Edge>> adj(N);
        
        // Leitura das estradas
        for (int i = 0; i < M; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        // 1. Pré-calcular os custos dentro da rota de serviço (de i até C-1)
        // A rota é 0 -> 1 -> ... -> C-1.
        // route_cost[i] armazenará o custo acumulado de i até C-1.
        vector<int> route_cost(C, 0); 
        
        // Começamos do penúltimo nó da rota (C-2) voltando até 0
        for (int i = C - 2; i >= 0; --i) {
            // Procuramos a aresta que conecta i a i+1
            int w = INF;
            for (auto& e : adj[i]) {
                if (e.v == i + 1) {
                    w = e.w;
                    break;
                }
            }
            // Acumula o custo: pedágio atual + custo do próximo até o fim
            route_cost[i] = w + route_cost[i+1];
        }

        // 2. Algoritmo de Dijkstra
        // Min-heap para priorizar menores distâncias
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(N, INF);

        dist[K] = 0;
        pq.push({0, K});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;
            
            // Se chegamos ao destino, não precisamos expandir (pois ele é o fim da linha)
            if (u == C - 1) continue;

            for (auto& e : adj[u]) {
                int v = e.v;
                int weight = e.w;

                if (v >= C) {
                    // Movimento entre cidades fora da rota (padrão)
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                } else {
                    // Movimento entrando na rota de serviço (cidade v < C)
                    // Isso nos força a ir até C-1.
                    // Custo efetivo = aresta física + custo restante da rota
                    int total_cost = weight + route_cost[v];
                    
                    if (dist[u] + total_cost < dist[C - 1]) {
                        dist[C - 1] = dist[u] + total_cost;
                        pq.push({dist[C - 1], C - 1});
                    }
                }
            }
        }

        cout << dist[C - 1] << endl;
    }
    return 0;
}