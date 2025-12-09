#include <stdio.h>
#include <string.h>

// Definimos um tamanho seguro. O problema diz max 7x7 = 49 nodos.
// 60 é mais que suficiente.
#define MAX 60

// Matriz de Adjacência para representar o grafo
int grafo[MAX][MAX];
// Vetor para marcar nodos visitados na DFS
int visitado[MAX];

// Função de Busca em Profundidade (DFS)
// Ela retorna a quantidade de arestas encontradas a partir do nodo 'u'
int dfs(int u) {
    int arestas_contadas = 0;
    visitado[u] = 1; // Marca o nodo atual como visitado

    // Varre todos os possíveis vizinhos (até o limite MAX)
    for (int v = 0; v < MAX; v++) {
        // Se existe uma conexão no grafo
        if (grafo[u][v] == 1) {
            // E se o vizinho ainda não foi visitado
            if (!visitado[v]) {
                // Encontramos uma aresta válida de u para v
                arestas_contadas++; 
                
                // Soma as arestas encontradas a partir desse vizinho (recursão)
                arestas_contadas += dfs(v);
            }
        }
    }
    return arestas_contadas;
}

int main() {
    int T, N; // T = casos de teste, N = nodo de início
    int V, A; // V = quantidade de vértices, A = quantidade de arestas
    int u, v; // Nodos auxiliares para ler as ligações
    
    // Lê o número de casos de teste
    scanf("%d", &T);

    while(T--) {
        // Lê o ponto de partida
        scanf("%d", &N);
        
        // Lê quantidade de Vértices e Arestas
        scanf("%d %d", &V, &A);

        // Limpa a memória para o novo caso de teste
        // memset preenche a matriz/vetor com 0
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));

        // Lê todas as arestas
        for(int i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);
            // Marca na matriz que existe conexão entre u e v
            // Como é não-direcionado, marcamos ida e volta
            grafo[u][v] = 1;
            grafo[v][u] = 1;
            // Nota: Se a entrada repetir a mesma aresta (ex: 1-4 e 4-1),
            // a matriz apenas sobrescreve 1 com 1, resolvendo o problema de duplicatas.
        }

        // Executa a DFS a partir do nodo de início (N)
        // para saber quantas arestas compõem o desenho conectado
        int total_arestas = dfs(N);

        // O resultado é sempre o dobro das arestas, 
        // pois ele vai e volta por cada linha.
        printf("%d\n", total_arestas * 2);
    }

    return 0;
}