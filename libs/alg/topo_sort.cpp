#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;                  // Vértices del grafo
vector<vii> AL;         // Lista de adyacencia
vector<bool> visitados; // -1: no visitado, 0: visitado
vi ts;                  // Vector para almacenar el orden topológico

void toposort(int u) {
    visitados[u] = true;
    for (auto &[v, w] : AL[u])
        if (visitados[v] == false) toposort(v);
    ts.push_back(u); // this is the only change
}

// Componentes conexas
void calc_toposort() {
    visitados.assign(AL.size(), -1);
    ts.clear(); // Limpiar el vector de orden topológico

    for (int u = 0; u < n; u++) // Por cada vértice
        if (!visitados[u])      // Si no ha sido visitado
            toposort(u);

    reverse(ts.begin(),
            ts.end()); // Invertir el orden para obtener el topológico

    // Ahora `ts` contiene el orden topológico de los vértices
}
