#include <stdio.h>
#include <stdbool.h>

#define MAX 505          // O problema diz N <= 500, damos uma margem
#define INF 99999999     // Um valor muito alto para representar "sem conexão"

// Matriz de Adjacência: grafo[origem][destino] = peso
int grafo[MAX][MAX];
int N, E; // N = Cidades, E = Acordos

// Algoritmo de Dijkstra para encontrar o menor caminho
int dijkstra(int origem, int destino) {
    int distancia[MAX];
    bool visitado[MAX];

    // 1. Inicialização
    for (int i = 1; i <= N; i++) {
        distancia[i] = INF;   // Ninguém foi alcançado ainda
        visitado[i] = false;  // Ninguém foi visitado
    }

    distancia[origem] = 0; // A distância para si mesmo é 0

    // 2. Loop Principal (repete N vezes)
    for (int i = 1; i <= N; i++) {
        int u = -1;
        int menorDist = INF;

        // Procura o vértice 'u' que tem a menor distância e ainda não foi visitado
        for (int j = 1; j <= N; j++) {
            if (!visitado[j] && distancia[j] < menorDist) {
                menorDist = distancia[j];
                u = j;
            }
        }

        // Se não achou ninguém alcançável ou já chegou no destino, para
        if (u == -1) break; 
        
        visitado[u] = true;
        
        // Se já fechamos o menor caminho para o destino, podemos retornar (otimização)
        if (u == destino) return distancia[destino];

        // 3. Relaxamento: Atualiza os vizinhos de 'u'
        for (int v = 1; v <= N; v++) {
            // Se existe aresta de u para v
            if (grafo[u][v] != INF) {
                // Se o caminho passando por u é mais rápido do que o que já tínhamos
                if (distancia[u] + grafo[u][v] < distancia[v]) {
                    distancia[v] = distancia[u] + grafo[u][v];
                }
            }
        }
    }

    return distancia[destino];
}

int main() {
    int X, Y, H;
    int K, O, D;

    // Loop de leitura dos casos de teste. Para quando N = 0 e E = 0.
    while (scanf("%d %d", &N, &E) && N != 0) {
        
        // Passo A: Limpar a matriz (preencher com INF)
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                grafo[i][j] = INF;
            }
        }

        // Passo B: Ler as arestas (acordos)
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);
            grafo[X][Y] = H;
        }

        // Passo C: A Lógica do "Mesmo País"
        // Varre a matriz. Se vai e volta, o custo vira 0.
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (grafo[i][j] != INF && grafo[j][i] != INF) {
                    grafo[i][j] = 0;
                    grafo[j][i] = 0;
                }
            }
        }

        // Passo D: Processar as consultas
        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &O, &D);
            int resultado = dijkstra(O, D);

            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        
        // O problema pede uma linha em branco após cada caso de teste
        printf("\n");
    }

    return 0;
}