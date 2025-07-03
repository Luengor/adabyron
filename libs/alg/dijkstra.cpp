#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;  // Número de nodos
vvi AL; // Lista de adyacencia del grafo

// s es el nodo de inicio
void dijkstra(int s) {
    vi dist(n, 1e9);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); // Nodo con distancia mínima
        pq.pop();
        if (d > dist[u]) continue; // Si la distancia no es la mínima, saltamos

        // Si quisiesemos salir al llegar a un nodo destino, podríamos añadir
        // una condición aquí (sin no hay negativos):
        // if (u == destino) return;

        for (auto &[v, w] : AL[u]) {     // Recorremos los vecinos del nodo u
            if (dist[u] + w < dist[v]) { // Si encontramos una distancia menor
                dist[v] = dist[u] + w;   // Actualizamos la distancia
                pq.emplace(dist[v], v);  // Añadimos el nodo a la cola
            }
        }
    }
}
