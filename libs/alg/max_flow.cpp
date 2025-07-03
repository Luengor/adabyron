#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF 1e9

int n;        // Nodos del grafo
vvi capacity; // capacity[i][j] = capacidad de la arista i -> j
vvi adj;      // adj[i] = lista de nodos adyacentes a i (grafo NO dirigido)

int bfs(int s, int t, vector<int> &parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

// Flujo máximo usando el algoritmo de Edmonds-Karp
// desde el nodo source al nodo drain
int maxflow(int source, int drain) {
    int flow = 0; // Flujo total encontrado
    vi parent(n); // Vector para almacenar el camino encontrado por BFS
    int new_flow; // Flujo encontrado en cada iteración

    // Mientras haya un camino aumentante desde source a drain
    // se actualiza el flujo total y las capacidades de las aristas
    // en el camino encontrado
    while ((new_flow = bfs(source, drain, parent))) {
        flow += new_flow; // Aumenta el flujo total con el flujo encontrado
        int cur = drain;  // Recorremos el camino encontrado hacia atrás
        while (cur != source) { // actualizando las capacidades residuales
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}