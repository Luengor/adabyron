#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Entrada:
 *   La entrada está formada por distintos casos de prueba.
 *   Cada caso comienza con una línea con dos números indicando el número de reinas, Q, y el número de torres, R que hay que colocar (N = Q + R ≤ 8).
 *   A continuación aparece la información del tablero: N líneas cada una con N números entre 1 y 1000 con el valor de cada escaque.
 *
 * Salida:
 *   Por cada caso de prueba se escribirá una línea con el valor más alto que puede conseguirse colocando en el tablero Q reinas y R torres sin que se ataquen entre ellas.
 *   Recuerda que en el ajedrez las reinas atacan a cualquier pieza que esté en la misma fila, columna o diagonal, mientras que las torres solo pueden moverse en línea recta en horizontal o vertical.
 */

struct Pieza {
    int columna;
    bool reina;
};

vector<Pieza> piezas;
vector<bool> columna_ocupada(8, false); // Para controlar las columnas ocupadas
vector<short> tablero; // Para almacenar el tablero, máximo 8x8
vector<short> filaMax; // Para almacenar el máximo de cada fila

int backtrack(int Q, int R, int N, int &mejor, int puntos)
{
    // Vemos si hemos colocado todas las piezas
    if (Q == 0 && R == 0)
        return puntos; // Si hemos colocado todas las piezas, devolvemos el valor acumulado

    // Si el mejor resultado que tenemos es mayor que el valor actual más el máximo de las filas restantes, no seguimos
    if (puntos + filaMax[piezas.size()] <= mejor)
        return mejor; // Si no podemos mejorar el resultado, devolvemos el valor actual

    // Si no, probamos a colocar alguno de los tipos en la siguiente fila
    int fila = piezas.size();

    if (R > 0) // Si quedan torres por colocar
    {
        for (int columna = 0; columna < N; ++columna)
        {
            // Comprobamos si hay algo en esa columna
            if (columna_ocupada[columna]) continue;

            // Comprobamos si hay una reina en las diagonales
            bool reinaEnDiagonal = false;
            for (int pieza_fila = 0; pieza_fila < piezas.size(); ++pieza_fila)
            {
                const Pieza &pieza = piezas[pieza_fila];
                if (pieza.reina && abs(pieza.columna - columna) == abs(pieza_fila - fila))
                {
                    reinaEnDiagonal = true;
                    break;
                }
            }

            if (reinaEnDiagonal) continue; // Si hay una reina en la diagonal, no podemos colocar una torre

            // Colocamos la torre
            piezas.push_back({columna, false});
            columna_ocupada[columna] = true; // Marcamos la columna como ocupada
            int resultado = backtrack(Q, R - 1, N, mejor, puntos + tablero[fila * N + columna]);
            columna_ocupada[columna] = false; // Desmarcamos la columna como ocupada
            piezas.pop_back(); // Deshacemos el movimiento
            mejor = max(mejor, resultado);
        }
    }

    // Si el mejor resultado que tenemos es mayor que el valor actual más el máximo de las filas restantes, no seguimos
    if (puntos + filaMax[piezas.size()] <= mejor)
        return mejor; // Si no podemos mejorar el resultado, devolvemos el valor actual

    if (Q > 0) // Si quedan reinas por colocar
    {
        for (int columna = 0; columna < N; ++columna)
        {
            // Comprobamos si hay algo en esa columna
            if (columna_ocupada[columna]) continue;

            // Comprobamos si hay algo en las diagonales
            bool algoEnDiagonal = false;
            for (int pieza_fila = 0; pieza_fila < piezas.size(); ++pieza_fila)
            {
                const Pieza &pieza = piezas[pieza_fila];
                if (abs(pieza.columna - columna) == abs(pieza_fila - fila))
                {
                    algoEnDiagonal = true;
                    break;
                }
            }
            if (algoEnDiagonal) continue; // Si hay algo en la diagonal, no podemos colocar una reina

            // Colocamos la reina
            piezas.push_back({columna, true});
            columna_ocupada[columna] = true; // Marcamos la columna como ocupada
            int resultado = backtrack(Q - 1, R, N, mejor, puntos + tablero[fila * N + columna]);
            columna_ocupada[columna] = false; // Desmarcamos la columna como ocupada
            piezas.pop_back(); // Deshacemos el movimiento
            mejor = max(mejor, resultado);
        }
    }

    return mejor;
}

bool casoDePrueba()
{
    int Q, R; // número de reinas y torres
    cin >> Q >> R;

    if (!cin) return false;

    // Leemos el tablero y almacenamos el máximo de cada fila
    int N = Q + R;

    tablero.clear();
    filaMax.assign(N, 0); // Inicializamos el vector filaMax con ceros

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            tablero.push_back(0);
            cin >> tablero.back();
            filaMax[i] = max(filaMax[i], tablero.back());
        }

    // Hacemos que filaMax sea acumulativo
    // es decir, que filaMax[i] es el máximo numero de puntos que se pueden conseguir a partir de la fila i
    for (int i = N - 2; i >= 0; --i)
        filaMax[i] += filaMax[i + 1];

    // Creamos los vectores de reinas y torres
    piezas.clear();

    int mejor = 0;
    backtrack(Q, R, N, mejor, 0);
    cout << mejor << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    piezas.reserve(8); // Reservamos espacio para las piezas, máximo 8 (N ≤ 8)
    tablero.reserve(64); // Reservamos espacio para el tablero, máximo 8x8
    filaMax.reserve(8); // Reservamos espacio para el máximo de cada fila, máximo 8

    while(casoDePrueba());

    return 0;
}

