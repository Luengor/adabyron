#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi match, vis;
vvi AL;

int try_kuhn(int v) {
    if (vis[v]) return 0;    // Si ya hemos visitado este nodo, no hacemos nada
    vis[v] = 1;              // Marcamos el nodo como visitado
    for (auto &to : AL[v]) { // Recorremos los nodos derechos conectados
        if (match[to] == -1 ||     // Si el nodo derecho no está emparejado
            try_kuhn(match[to])) { // o podemos emparejarlo recursivamente
            match[to] = v; // Emparejamos el nodo derecho con el izquierdo
            return 1;      // Retornamos que hemos encontrado un emparejamiento
        }
    }

    return 0; // Si no hemos encontrado un emparejamiento, retornamos 0
}

int n, m; // n = nodos izquierdos, m = nodos derechos
int mcbm() {
    match.assign(m, -1); // Inicializamos el emparejamiento con -1
    int MCVM = 0;
    for (int v = 0; v < n; v++) {
        vis.assign(n, 0);    // Reiniciamos el vector de visitados
        MCVM += try_kuhn(v); // Intentamos emparejar el nodo izquierdo v
    }

    // En este punto, match contiene el emparejamiento máximo
    // match[i] = j significa que el nodo i de la parte izquierda está
    // emparejado con el nodo j de la parte derecha.
    return MCVM; // Retornamos el número máximo de emparejamientos
}
