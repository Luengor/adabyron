#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

// El problema realmente se basa en encontrar la subsecuencia decreciente seguida de una subsecuencia creciente más larga
// longest decreasing subsequence (LDS) + longest increasing subsequence (LIS) = longest bitonic subsequence (LBS)

// left_memo[i] contiene la longitud de la subsecuencia decreciente máxima que termina en el coche i
vi left_memo;
int left(int from, int to, const vi &pesos)
{
    if(from == to) return 1; // Si solo hay un coche, la subsecuencia decreciente es de longitud 1
    auto &memo = left_memo[to];
    if(memo != -1) return memo; // Si ya hemos calculado este subproblema, lo devolvemos

    // Inicializamos la longitud de la subsecuencia decreciente
    int max_length = 1;

    for (int i = to - 1; i >= from; i--)
    {
        // Si el coche que estamos viendo es más pesado que el último
        if (pesos[i] > pesos[to])
        {
            // Obtenemos la subsecuencia decreciente máxima hasta ese coche y le añadimos este coche
            int length = left(from, i, pesos) + 1; // +1 por el coche actual
            max_length = max(max_length, length); // Actualizamos la longitud máxima
        }
    }

    return memo = max_length;
}

vi right_memo;
int lis(int from, int to, const vi &pesos)
{
    if(from == to) return 1; // Si solo hay un coche, la subsecuencia creciente es de longitud 1
    auto &memo = right_memo[from];
    if(memo != -1) return memo; // Si ya hemos calculado este subproblema, lo devolvemos

    // Inicializamos la longitud de la subsecuencia creciente
    int max_length = 1; // La longitud mínima es 1 (el coche actual)

    // Recorremos los coches desde 'from' hasta 'to'
    for (int i = from + 1; i <= to; i++)
    {
        // Si el coche que estamos viendo es más pesado que el primero
        if (pesos[i] > pesos[from])
        {
            // Obtenemos la subsecuencia creciente máxima a partir de ese coche y le añadimos este coche
            int length = lis(i, to, pesos) + 1; // +1 por el coche actual
            max_length = max(max_length, length); // Actualizamos la longitud máxima
        }
    }

    return memo = max_length;
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
    sort(coches_pesos.begin(), coches_pesos.end(), [](const ii &a, const ii &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    // Nos quedamos con los índices de los coches en el orden decreciente de peso
    vi indices(coches);
    for(int i = 0; i < coches; i++)
        indices[i] = coches_pesos[i].second;

    left_memo.assign(coches, -1);
    right_memo.assign(coches, -1);

    // Buscamos el punto medio con la mayor longitud de subsecuencia decreciente y creciente
    int max_length = 0;
    for (int i = 0; i < coches; i++)
    {
        // Longitud de la subsecuencia decreciente desde el inicio hasta el coche i
        int left_length = left(0, i, indices);
        // Longitud de la subsecuencia creciente desde el coche i hasta el final
        int right_length = lis(i, coches - 1, indices);

        // Actualizamos la longitud máxima
        max_length = max(max_length, left_length + right_length - 1); // -1 porque contamos el coche i dos veces
    }

    cout << max_length << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


