#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n;                  // Vértices del grafo
vector<vi> AL;          // Lista de adyacencia
vector<bool> visitados; // -1: no visitado, 0: visitado

void dfs(int u); // Prototipo de la función DFS

// Componentes conexas
int cc() {
    visitados.assign(AL.size(), -1);

    int numCC = 0;
    for (int u = 0; u < n; u++) // Por cada vértice
        if (!visitados[u]) {    // Si no ha sido visitado
            numCC++;            // Incrementa el contador de componentes conexas
            dfs(u); // Llama a DFS para visitar todos los vértices de esta
                    // componente
        }

    return numCC; // Retorna el número de componentes conexas
}
