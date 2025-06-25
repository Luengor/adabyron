#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

#define INV(n) (-(n))

vi get_lis(int n, const vi &A)
{
    // k -> longitud de la major cadena
    int k = 0;
    // L -> Lista de la "secuencia" creciente más larga 
    vi L(n, 0);

    // Longitud de la mejor secuencia hasta aquí
    vi endings(n);

    for (int i = 0; i < n; ++i)
    {
        // Buscamos el primer valor en L mayor que el elemento actual
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

        // La longitud de la secuencia es el índice que tenga en la secuencia más larga
        endings[i] = pos + 1;

        // Cambiamos ese valor en la secuencia más larga 
        L[pos] = A[i];

        // Si hemos añadido un elemento
        if (pos == k)
            // Aumentamos la longitud máxima
            k = pos + 1;
    }

    return endings;
}

bool casoDePrueba()
{
    int coches;
    cin >> coches;
    if(coches == 0) return false;

    vii coches_pesos(coches);
    for(int i = 0; i < coches; i++)
    {
        cin >> coches_pesos[i].first;
        coches_pesos[i].second = i; // Guardamos el índice original para mantener el orden de llegada
    }

    // Ordenamos los coches por peso (de mayor a menor) y por índice (de menor a mayor) para mantener el orden de llegada
    sort(coches_pesos.begin(), coches_pesos.end());

    // Nos quedamos con los índices de los coches en el orden decreciente de peso
    // Invertimos los índices ya que estamos
    vi indices(coches);
    for(int i = 0; i < coches; i++)
    {
        indices[i] = INV(coches_pesos[i].second);
        // cout << indices[i] << ' ';
    }
    // cout << endl;

    // Obtenemos la parte izquierda
    vi izq = get_lis(coches, indices);
    // for (auto v : izq)
    //     cout << v << ' ';
    // cout << endl;

    // Reverseamos el vector para obtener la derecha
    reverse(indices.begin(), indices.end());
    vi der = get_lis(coches, indices);
    reverse(der.begin(), der.end());

    // for (auto v : der)
    //     cout << v << ' ';
    // cout << endl;

    // Encontramos el máximo
    int ans = 0;
    for (int i = 0; i < coches; i++)
        ans = max(ans, izq[i] + der[i] - 1);

    cout << ans << '\n';

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


