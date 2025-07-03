#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;  // Número de nodos
vvi AL; // Lista de adyacencia del grafo

void bfs(int start) {
    vi dist(n, -1);  // Distancias desde el nodo inicial
    dist[start] = 0; // Distancia al nodo inicial es 0
    queue<int> q;    // Cola para BFS
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Se puede hacer algo con el nodo aquí

        for (auto &[v, w] : AL[u]) {
            if (dist[v] != -1)
                continue;          // Nodo visitado
            dist[v] = dist[u] + w; // Actualizar la distancia
            q.push(v);             // Añadir el nodo a la cola
        }
    }
}

vector<bool> visited(n, false); // Vector para DFS
void dfs(int u) {
    visited[u] = true; // Marcar el nodo como visitado

    // Se puede hacer algo con el nodo aquí

    for (auto &[v, w] : AL[u]) {
        if (!visited[v])
            dfs(v); // Llamada recursiva a DFS
    }
}
