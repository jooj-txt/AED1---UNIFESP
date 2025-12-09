#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30 // Margem de segurança para 26 letras

// Variáveis Globais
int adj[MAX][MAX];           // Matriz de conexões (0 ou 1)
int visitado[MAX];           // Marca quem já foi encontrado
int lista_componente[MAX];   // Guarda temporariamente os vértices do componente atual
int tam_lista;               // Quantos vértices tem no componente atual

// Função para comparar inteiros (necessária para o qsort)
int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

// Busca em Profundidade (DFS)
void dfs(int u, int V) {
    visitado[u] = 1; // Marca como visitado
    lista_componente[tam_lista] = u; // Adiciona na lista para imprimir depois
    tam_lista++;

    // Verifica todos os possíveis vizinhos
    for (int v = 0; v < V; v++) {
        // Se existe conexão E o vizinho não foi visitado ainda
        if (adj[u][v] == 1 && visitado[v] == 0) {
            dfs(v, V);
        }
    }
}

int main() {
    int N, V, E;
    char u_char, v_char;
    int caso = 1;

    // Lê número de casos de teste
    scanf("%d", &N);

    while (N--) {
        scanf("%d %d", &V, &E);

        // Limpa a memória para o novo caso
        memset(adj, 0, sizeof(adj));
        memset(visitado, 0, sizeof(visitado));

        // Leitura das arestas
        for (int i = 0; i < E; i++) {
            // O espaço antes de %c é crucial para ignorar o 'enter' da linha anterior
            scanf(" %c %c", &u_char, &v_char);
            
            // Converte char para índice (a=0, b=1, c=2...)
            int u = u_char - 'a';
            int v = v_char - 'a';
            
            // Grafo não direcionado: vai e volta
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        printf("Case #%d:\n", caso++);

        int qtd_componentes = 0;

        // Percorre todas as letras possíveis do caso (de 0 até V-1)
        for (int i = 0; i < V; i++) {
            // Se encontrarmos um vértice que ainda não foi visitado,
            // significa que descobrimos um NOVO componente.
            if (visitado[i] == 0) {
                qtd_componentes++;
                tam_lista = 0; // Reseta a lista temporária
                
                // Dispara a busca para pegar todos os conectados a 'i'
                dfs(i, V);
                
                // Ordena a lista (a DFS pode ter pego fora de ordem ex: 0, 2, 1)
                qsort(lista_componente, tam_lista, sizeof(int), compare);

                // Imprime os vértices do componente
                for (int j = 0; j < tam_lista; j++) {
                    printf("%c,", lista_componente[j] + 'a');
                }
                printf("\n");
            }
        }

        // Imprime o total e a linha em branco obrigatória
        printf("%d connected components\n\n", qtd_componentes);
    }

    return 0;
}