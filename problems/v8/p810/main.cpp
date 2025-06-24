#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

/*
 * Problema 810: ¡Acepta el reto! (https://aceptaelreto.com/problem/statement.php?id=810):
 * Cuando, ahora que está apunto de completar su título universitario, ha visto
 * que en las ofertas de empleo que llegan a su facultad hay una de mozo de
 * estación, se le ha caído el alma a los pies. Después de tanto esfuerzo y
 * sufrimiento estudiando asignaturas con el objetivo de abaratar los costes de
 * producción de empresas industriales, no esperaba que le llegaran ofertas de
 * ese tipo.
 *
 * Sin embargo, cuando después ha visto en qué consiste exactamente el empleo,
 * ha entendido que el trabajo en cuestión requiere educación superior. Si se
 * hace bien, se consigue un ahorro brutal en consumo de energía y se reduce la
 * contaminación de la zona.
 *
 * El trabajo consiste en enfrentarse, diariamente, a una casi-infinita fila de
 * coches esperando ansiosos a ser subidos a un tren que les llevará al otro
 * lado del país. El tren permite que los coches suban o bien por la parte
 * delantera o por la parte trasera, por lo que se debe, en pocos segundos,
 * decidir por orden de llegada, si le pide al siguiente coche en la fila que
 * suba por uno u otro lado del tren.
 *
 * Contado así no parece difícil. Podría basar su decisión en el lanzamiento de
 * una moneda, la paridad de la matrícula o cualquier otro criterio. El problema
 * es que hay otra restricción. Para garantizar la seguridad del tren, los
 * coches deben ir por orden decreciente de peso: el más pesado irá al lado de
 * la locomotora (entrará el último por el lado de la cabeza) y el más ligero
 * irá al final del todo (entrará el último por el lado trasero).
 *
 * Teniendo en cuenta esa restricción y que los coches de la fila no pueden
 * reordenarse, nuestro mozo de estación tiene que decidir si el coche va para
 * un lado u otro del tren o si, para que los coches queden ordenados por peso,
 * se tendrá que "quedar en tierra" a esperar al próximo tren. Que le cojan o no
 * en el trabajo depende de si es capaz de cargar el tren con el mayor número de
 * coches posible.
 *
 * Entrada:
 * La entrada está formada por distintos casos de prueba, cada uno ocupando dos
 * líneas.
 *
 * La primera línea de cada caso de prueba contiene el número de coches que
 * están esperando en la fila para ser transportados (entre 1 y 500.000). La
 * segunda línea contiene los pesos de cada uno de los coches (valores entre 1 y
 * 106, todos distintos) en el orden de espera.
 *
 * Tras el último caso de prueba viene una línea con un 0.
 *
 * Salida:
 * Por cada caso de prueba se escribirá una única línea indicando cuántos coches
 * podrán cargarse como mucho en el tren cumpliendo las restricciones indicadas.
*/

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

// El problema realmente se basa en encontrar la subsecuencia decreciente seguida de una subsecuencia creciente más larga
// longest decreasing subsequence (LDS) + longest increasing subsequence (LIS) = longest bitonic subsequence (LBS)

vvi left_memo;
int left(int from, int to, const vi &pesos)
{
    if(from == to) return 1; // Si solo hay un coche, la subsecuencia decreciente es de longitud 1
    auto &memo = left_memo[from][to];
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

vvi right_memo;
int lis(int from, int to, const vi &pesos)
{
    if(from == to) return 1; // Si solo hay un coche, la subsecuencia creciente es de longitud 1
    auto &memo = right_memo[from][to];
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

    left_memo.assign(coches, vi(coches, -1));
    right_memo.assign(coches, vi(coches, -1));

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


