#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10004
#define MAX_ROADS 100008
#define INF INT_MAX

typedef struct {
    int city;
    int cost;
    int parity; // 0 para par, 1 para ímpar
} State;

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

Edge edges[MAX_ROADS];
int head[MAX_CITIES][2]; // head[city][parity]
int dist[MAX_CITIES][2];
int visited[MAX_CITIES][2];
int edge_count = 0;
int heap_size = 0;
State heap[MAX_ROADS * 4];

void add_edge(int u, int v, int cost) {
    edges[edge_count].to = v;
    edges[edge_count].cost = cost;
    edges[edge_count].next = head[u][0];
    head[u][0] = edge_count++;
    
    edges[edge_count].to = u;
    edges[edge_count].cost = cost;
    edges[edge_count].next = head[v][0];
    head[v][0] = edge_count++;
}

void heap_push(State state) {
    int i = heap_size++;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].cost <= state.cost) break;
        heap[i] = heap[parent];
        i = parent;
    }
    heap[i] = state;
}

State heap_pop() {
    State result = heap[0];
    State last = heap[--heap_size];
    
    int i = 0;
    while (i * 2 + 1 < heap_size) {
        int child = i * 2 + 1;
        if (child + 1 < heap_size && heap[child + 1].cost < heap[child].cost) {
            child++;
        }
        if (last.cost <= heap[child].cost) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return result;
}

int dijkstra(int start, int target, int C) {
    // Inicializa distâncias
    for (int i = 1; i <= C; i++) {
        dist[i][0] = dist[i][1] = INF;
        visited[i][0] = visited[i][1] = 0;
    }
    
    dist[start][0] = 0;
    heap_size = 0;
    
    State initial;
    initial.city = start;
    initial.cost = 0;
    initial.parity = 0;
    heap_push(initial);
    
    while (heap_size > 0) {
        State current = heap_pop();
        int u = current.city;
        int parity = current.parity;
        
        if (visited[u][parity]) continue;
        visited[u][parity] = 1;
        
        // Para cada estrada saindo de u
        for (int i = head[u][0]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int cost = edges[i].cost;
            int new_parity = parity ^ 1; // Alterna paridade
            int new_cost = dist[u][parity] + cost;
            
            if (new_cost < dist[v][new_parity]) {
                dist[v][new_parity] = new_cost;
                State next;
                next.city = v;
                next.cost = new_cost;
                next.parity = new_parity;
                heap_push(next);
            }
        }
    }
    
    return dist[target][0] == INF ? -1 : dist[target][0];
}

int main() {
    int C, V;
    
    while (scanf("%d %d", &C, &V) == 2) {
        // Inicializa listas de adjacência
        for (int i = 1; i <= C; i++) {
            head[i][0] = -1;
        }
        edge_count = 0;
        
        // Lê as estradas
        for (int i = 0; i < V; i++) {
            int C1, C2, G;
            scanf("%d %d %d", &C1, &C2, &G);
            add_edge(C1, C2, G);
        }
        
        int result = dijkstra(1, C, C);
        printf("%d\n", result);
    }
    
    return 0;
}