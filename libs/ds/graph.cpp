#include <bits/stdc++.h>
using namespace std;

int n;  // Número de nodos

/*
 * Grafo como lista de adyacencia:
 *   - El elemento AL[i] es un vector que contiene los nodos adyacentes a i.
 *   - Si el grafo es ponderado, AL[i] contiene pares (nodo, peso).
 *   - Puede representar multigrafos.
 */
vector<vector<pair<int, int>>> AL(n);

/*
 * Grafo como matriz de adyacencia:
 *   - El elemento AM[i][j] es -1 si no hay arista entre i y j,
 *     o el peso de la arista si existe.
 *   - Si el grafo es no dirigido, AM es igual a su transpuesta.
 *   - No puede representar multigrafos
 *   - No debería usarse para grafos donde n > 5000
 */
vector<vector<int>> AM(n, vector<int>(n, -1));

/*
 * Grafo como lista de aristas:
 *   - El elemento E[i] es una trupla (n1, n2, peso)
 *   - Puede representar multigrafos.
 *   - No es eficiente para consultas de adyacencia.
 */
vector<tuple<int, int, int>> EL;

