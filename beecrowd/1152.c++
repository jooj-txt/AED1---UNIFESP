#include <iostream>
#include <vector>
#include <algorithm> // Para sort
#include <numeric>   // Para accumulate

using namespace std;

// Estrutura para representar uma estrada (aresta)
struct Aresta {
    int u, v, peso;
};

// Comparador para ordenar as arestas pelo peso (menor para maior)
bool compararArestas(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

// --- Estrutura Union-Find (DSU) ---
// Serve para gerenciar os conjuntos de cidades conectadas
struct DSU {
    vector<int> pai;
    
    // Construtor: inicializa cada cidade como seu próprio "pai"
    DSU(int n) {
        pai.resize(n);
        iota(pai.begin(), pai.end(), 0); // Preenche 0, 1, 2...
    }
    
    // Encontra o representante do conjunto (com compressão de caminho)
    int find(int i) {
        if (pai[i] == i)
            return i;
        return pai[i] = find(pai[i]);
    }
    
    // Une dois conjuntos
    void unite(int i, int j) {
        int raiz_i = find(i);
        int raiz_j = find(j);
        if (raiz_i != raiz_j) {
            pai[raiz_i] = raiz_j;
        }
    }
};

int main() {
    // Otimização de E/S
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n; // m = junções (vértices), n = estradas (arestas)

    // Loop de leitura: para quando m=0 e n=0
    while (cin >> m >> n && (m != 0 || n != 0)) {
        
        vector<Aresta> arestas;
        long long custo_total = 0; // Usar long long para evitar overflow na soma total
        
        for (int i = 0; i < n; i++) {
            int u, v, z;
            cin >> u >> v >> z;
            arestas.push_back({u, v, z});
            custo_total += z;
        }

        // 1. Ordenar as arestas pelo menor custo (Passo crucial do Kruskal)
        sort(arestas.begin(), arestas.end(), compararArestas);

        // 2. Inicializar o Union-Find
        DSU dsu(m);
        long long custo_mst = 0;
        int arestas_na_arvore = 0;

        // 3. Construir a MST
        for (const auto& aresta : arestas) {
            // Se u e v não estão conectados ainda
            if (dsu.find(aresta.u) != dsu.find(aresta.v)) {
                dsu.unite(aresta.u, aresta.v); // Conecta eles
                custo_mst += aresta.peso;      // Soma o custo na MST
                arestas_na_arvore++;
            }
        }

        // 4. Calcular e imprimir a economia
        // Economia = Tudo o que gastávamos antes - O mínimo necessário agora
        cout << (custo_total - custo_mst) << "\n";
    }

    return 0;
}