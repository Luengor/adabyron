#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool esPosible(int start, int end, int max_altura)
{
    // Si el rango es vacío, es posible
    if (start > end) return true;

    // Si la altura máxima es 0, no es posible
    if (max_altura <= 0) return false;

    // Si el rango tiene un solo elemento, es posible
    if (start == end) return true;


    int min_altura_posible = floor(log2(end - start + 1)) + 1;
    return min_altura_posible <= max_altura;
}

typedef tuple<int, int, int> Rango;

int encontrar_minimo_valido(Rango rango)
{
    int start, end, max_altura;
    tie(start, end, max_altura) = rango;

    assert (start <= end); // El rango debe ser válido

    int last_valid = -1;

    int search_start = start;
    int search_end = end;
    while (true)
    {
        // Salimos si el rango es vacío
        if (search_start > search_end) break;
        int mid = floor((search_start + search_end) / 2.0);

        if (esPosible(start, mid - 1, max_altura - 1))
        {
            // Es posible por la izquierda
            if (esPosible(mid + 1, end, max_altura - 1))
            {
                // Si es posible por la derecha, bajamos el end
                last_valid = mid;
                search_end = mid - 1;
            }
            else
            {
                // Si no es posible por la derecha, subimos el start
                search_start = mid + 1;
            }
        }
        else
        {
            // Si no es posible por la izquierda, subimos el start
            search_start = mid + 1;
        }
    }

    return last_valid;
}

void generar_secuencia_preorden(int start, int end, int max_altura, bool &primero) {
    // Caso base: el rango no tiene nodos.
    if (start > end) {
        return;
    }

    // Encontrar la raíz lexicográficamente más pequeña para el rango actual.
    int raiz = encontrar_minimo_valido(make_tuple(start, end, max_altura));

    // Imprimir la raíz.
    if (!primero) {
        cout << " ";
    }
    cout << raiz;
    primero = false;

    // Generar recursivamente la secuencia para el subárbol izquierdo.
    generar_secuencia_preorden(start, raiz - 1, max_altura - 1, primero);

    // Generar recursivamente la secuencia para el subárbol derecho.
    generar_secuencia_preorden(raiz + 1, end, max_altura - 1, primero);
}

void casoDePrueba()
{
    int nodos, altura_max;
    cin >> nodos >> altura_max;

    int min_altura_posible = floor(log2(nodos)) + 1;

    if (min_altura_posible > altura_max)
    {
        cout << "IMPOSIBLE\n";
        return;
    }

    // El mejor árbol posible
    bool primero = true;
    generar_secuencia_preorden(1, nodos, altura_max, primero);
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i)
    {
        casoDePrueba();
    }

    return 0;
}

