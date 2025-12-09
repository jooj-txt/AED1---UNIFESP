#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 40010
#define MAX_EDGES 50010

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank_arr[MAX_VERTICES];

// Função de comparação para ordenar as arestas por peso
int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Funções para Union-Find (Disjoint Set Union)
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank_arr[rootX] < rank_arr[rootY]) {
            parent[rootX] = rootY;
        } else if (rank_arr[rootX] > rank_arr[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank_arr[rootX]++;
        }
    }
}

// Algoritmo de Kruskal para encontrar a MST
long long kruskal(int M, int N) {
    long long total_weight = 0;
    int edges_used = 0;
    
    // Inicializar Union-Find
    for (int i = 0; i < M; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }
    
    // Ordenar arestas por peso
    qsort(edges, N, sizeof(Edge), compare);
    
    // Processar arestas em ordem crescente de peso
    for (int i = 0; i < N && edges_used < M - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (find(u) != find(v)) {
            union_sets(u, v);
            total_weight += weight;
            edges_used++;
        }
    }
    
    // Verificar se conseguimos conectar todas as cidades
    if (edges_used == M - 1) {
        return total_weight;
    } else {
        // Grafo não é conexo
        return -1;
    }
}

int main() {
    int M, N;
    
    while (1) {
        scanf("%d %d", &M, &N);
        
        if (M == 0 && N == 0) {
            break;
        }
        
        // Ler as arestas
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        }
        
        // Calcular a soma dos pesos da MST
        long long result = kruskal(M, N);
        
        printf("%lld\n", result);
    }
    
    return 0;
}