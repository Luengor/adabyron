#include <bits/stdc++.h>
using namespace std;

// Pongamos una función que nos dice si un valor x cumple y
bool can(int x);

// El problema quiere encontrar el mínimo valor x que cumpla y
// Para ello, podemos hacer una búsqueda binaria sobre el espacio de soluciones
int bsta(int low, int high) {
    while (low < high) {
        int mid = (low + high) / 2; // Punto medio
        if (can(mid))               // Lo probamos
            high = mid;             // Si cumple, buscamos valores más pequeños
        else                        // Si no,
            low = mid + 1;          // buscamos valores más grandes
    }

    // Al final, low y high valen lo mismo, y es el valor mínimo que cumple la
    // condición
    return low;
}

// Se puede hacer con flontantes también, estableciendo un epsilon y sin
// necesidad de incrementar low en 1
