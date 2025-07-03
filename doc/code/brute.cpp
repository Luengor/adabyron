#include <bits/stdc++.h>
using namespace std;

// Búsqueda exhaustiva incluye, entre otras cosas:
//  Probar permutaciones
void permutaciones() {
    int n = 8, p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    do {
        // Comprobar si la permutación p es válida
    } while (
        next_permutation(p, p + n)); // next_permutation genera la siguiente
                                     // permutación y devuelve true si existe
}

// Backtracking
bool se_puede_colocar(int c, const vector<int> &reinas);

void backtrack(int c, vector<int> &reinas) {
    // Ejemplo de backtracking para el problema de las 8 reinas
    if (c == 8) {
        // Solución encontrada, imprimir reinas o devolver o lo que sea
        // Para salir del todo estaría bien devolver un booleano, o algo así
        // ...
        return;
    }

    // Buscamos todos los estados hijos
    for (int i = 0; i < 8; i++) {
        if (se_puede_colocar(c, reinas)) {
            reinas[c] = i; // Colocamos la reina en la columna c y fila i
            backtrack(c + 1, reinas); // Llamamos al siguiente nivel
            reinas[c] = -1;           // Deshacemos el movimiento (backtracking)
        }
    }

    // Si no se puede colocar ninguna reina en la columna c, no hacemos nada
    return;
}
