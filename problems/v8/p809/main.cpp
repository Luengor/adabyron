#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector<vector<ii>> memo;

ii costes(int start, int end, const std::vector<int>& matrices)
{
    // Multiplicar una matriz tiene coste 0
    if (start + 1 == end) return {0, 0};

    // Comprobamos si ya hemos calculado el coste
    auto &m = memo[start][end];
    if (m.first != -1) return m;

    // Vamos partiendo el problema en subproblemas
    int coste_min = INT_MAX;
    int coste_max = INT_MIN;

    for (int i = start + 1; i < end; ++i)
    {
        // Calculamos el coste de multiplicar las matrices hasta i
        ii coste_izq = costes(start, i, matrices);

        // Calculamos el coste de multiplicar las matrices desde i hasta end
        ii coste_der = costes(i, end, matrices);

        // El coste de multiplicar las matrices es el producto de las dimensiones
        int coste_multiplicacion = matrices[start] * matrices[i] * matrices[end];

        // Actualizamos el coste mínimo y máximo
        coste_min = min(coste_min, coste_izq.first + coste_der.first + coste_multiplicacion);
        coste_max = max(coste_max, coste_izq.second + coste_der.second + coste_multiplicacion);
    }

    // Guardamos el resultado en el mapa
    memo[start][end] = {coste_min, coste_max};

    return {coste_min, coste_max};
}

bool casoDePrueba()
{
    int nmatrices;
    cin >> nmatrices;
    if (!cin) return false;

    std::vector<int> matrices(nmatrices + 1);
    cin >> matrices[0];
    for (int i = 0; i < nmatrices; ++i)
        cin >> matrices[i + 1];

    // Limpiamos el mapa de memorization
    memo.clear();
    memo.resize(nmatrices + 1, vector<ii>(nmatrices + 1, {-1, -1}));

    // Calculamos el coste mínimo y máximo de multiplicar las matrices
    ii result = costes(0, nmatrices, matrices);

    cout << result.first << " "
         << result.second << "\n";

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba()) {}

    return 0;
}

