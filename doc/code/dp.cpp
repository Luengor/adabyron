#include <bits/stdc++.h>
using namespace std;

int fib_tonto(int n) {
    if (n <= 1) return n;                       // Caso base
    return fib_tonto(n - 1) + fib_tonto(n - 2); // Llamadas recursivas
}

// Programación dinámica, top-down
// Utiliza la tabla de memoización para evitar cálculos repetidos
// Basicamente, "cachea" los resultados de las llamadas recursivas
vector<int> memo_td(100, -1); // Tabla de memoización, inicializada a -1
int fib_dp_td(int n) {
    if (n <= 1) return n;      // Caso base
    auto &res = memo_td[n];    // Referencia a la posición n de memo
    if (res != -1) return res; // Si ya está calculado, lo devolvemos
    res = fib_dp_td(n - 1) +
          fib_dp_td(n - 2); // Si no, lo calculamos y lo guardamos
    return res;             // Devolvemos el resultado
}

// Programación dinámica, bottom-up
// Rellena en la tabla de memoización los casos base. A partir de ahí, calcula
// los siguientes casos utilizando los anteriores hasta llegar al caso n.
vector<int> memo_bu(100, -1); // Tabla de memoización, inicializada a -1
int fib_dp_bu(int n) {
    memo_bu[0] = 0; // Caso base
    memo_bu[1] = 1; // Caso base

    for (int i = 2; i <= n; i++) {
        memo_bu[i] = memo_bu[i - 1] + memo_bu[i - 2]; // Calculamos el valor
    }
    return memo_bu[n]; // Devolvemos el resultado
}
