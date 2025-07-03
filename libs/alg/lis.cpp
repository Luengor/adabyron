#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

/*
 * Si solo se quiere la longitud del LIS, se puede obviar todo lo relacionado
 * con el array de predecesores (p, lis_end, L_id) y la función print_lis.
 */

int n; // Longitud del array A
vi A;  // Array de entrada
vi p;  // Array de predecesores

void print_lis(int i) {
    if (p[i] == -1) {
        cout << A[i];
        return;
    }

    print_lis(p[i]);     // Imprimir el LIS recursivamente
    cout << " " << A[i]; // Imprimir el elemento actual
}

void lis() {
    int k = 0;       // Longitud del LIS
    int lis_end = 0; // Índice del último elemento del LIS
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1); // Inicializar el array de predecesores

    for (int i = 0; i < n; i++) {
        // Búsqueda binaria para encontrar la posición de A[i] en L
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i]; // Actualizar L con el nuevo valor
        L_id[pos] = i; // Guardar el índice del elemento en L_id
        p[i] = pos ? L_id[pos - 1] : -1; // Actualizar el predecesor
        if (pos == k) {
            k++;         // Incrementar la longitud del LIS
            lis_end = i; // Actualizar el índice del último elemento del LIS
        }
    }

    // La longitud del LIS es k
    print_lis(lis_end); // Imprimir el LIS
}
