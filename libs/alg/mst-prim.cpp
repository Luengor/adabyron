#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;                 // Número de nodos
vector<vii> AL;        // Lista de adyacencia del grafo
vi taken;              // Vector para marcar nodos visitados
priority_queue<ii> pq; // Para escoger los edges (es un max-heap por defecto)
                       // así que usamos el peso negativo

void process(int u) {
    taken[u] = 1; // Marcar el nodo como visitado
    for (auto &[v, w] : AL[u])
        if (!taken[v])
            pq.push({-w, -v}); // Añadir los edges al priority queue
}

void prim() {
    taken.assign(n, 0); // Inicializar el vector de nodos visitados
    process(0);         // Empezar desde el nodo 0

    int mst_cost = 0, num_taken = 0; // Coste del MST y número de nodos tomados
    while (!pq.empty()) {
        auto [w, u] = pq.top(); // Obtener el edge con menor peso
        pq.pop();
        w = -w; // Convertir el peso y el nodo a su valor original
        u = -u;
        if (taken[u])
            continue; // Si el nodo ya está visitado, saltar

        mst_cost += w; // Añadir el peso al coste del MST

        process(u);  // Procesar el nodo
        num_taken++; // Incrementar el número de nodos tomados
        if (num_taken == n - 1) {
            break; // Si ya hemos tomado n-1 nodos, el MST está completo
        }
    }
}
