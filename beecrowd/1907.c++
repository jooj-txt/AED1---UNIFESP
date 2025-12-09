#include <iostream>
#include <queue> // Necessário para a fila da BFS

using namespace std;

#define MAX 1030 // Tamanho máximo N, M <= 1024 com margem de segurança

int N, M;
char grid[MAX][MAX]; // Matriz global para não estourar a pilha da main

// Arrays auxiliares para mover nas 4 direções (Cima, Baixo, Esquerda, Direita)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// Função de Busca em Largura (Flood Fill)
void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    grid[r][c] = 'o'; // Marca o ponto inicial como visitado (pintado)

    while (!q.empty()) {
        pair<int, int> atual = q.front();
        q.pop();

        int cr = atual.first;
        int cc = atual.second;

        // Tenta mover para as 4 direções vizinhas
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; // Nova linha
            int nc = cc + dc[i]; // Nova coluna

            // Verifica se a nova posição está DENTRO do mapa
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                // Se for um pixel branco (.), pinta e adiciona na fila
                if (grid[nr][nc] == '.') {
                    grid[nr][nc] = 'o'; // Pinta para não visitar de novo
                    q.push({nr, nc});
                }
            }
        }
    }
}

int main() {
    // Otimização de Entrada e Saída (Essencial para matrizes grandes)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // Leitura da Matriz
    for (int i = 0; i < N; i++) {
        cin >> grid[i]; // Lê a linha inteira como string (mais rápido que char por char)
    }

    int cliques = 0;

    // Varredura da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // Se acharmos um pixel branco, é uma nova região
            if (grid[i][j] == '.') {
                cliques++;    // Conta 1 clique
                bfs(i, j);    // Pinta toda a região conectada a este pixel
            }
        }
    }

    cout << cliques << endl;

    return 0;
}