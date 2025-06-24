#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void casoDePrueba()
{
    bool tableroAtacadoOcupado[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            tableroAtacadoOcupado[i][j] = false;
    int posicionesAtacadas = 0;
    char tableroOcupado[8][8] = {false};

    auto atacar = [&tableroAtacadoOcupado, &posicionesAtacadas](int fila, int columna)
    {
        if (fila < 0 || fila >= 8 || columna < 0 || columna >= 8)
            return;
        if (!tableroAtacadoOcupado[fila][columna])
        {
            tableroAtacadoOcupado[fila][columna] = true;
            posicionesAtacadas++;
        }
    };

    // Leer FEN
    string fen;
    getline(cin, fen);
    if (fen.empty())
        getline(cin, fen); // Para evitar problemas con el salto de línea
    // cout << fen << endl;

    // Llenar el tablero con las piezas
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            tableroOcupado[i][j] = ' ';

    int fila = 0, columna = 0;
    for (char c : fen)
    {
        tableroOcupado[fila][columna] = ' ';

        // Avanzar por filas
        if (isdigit(c))
        {
            columna += c - '0';
            continue;
        }

        // Avanzar por columnas
        if (c == '/')
        {
            fila++;
            columna = 0;
            continue;
        }

        // Colocar pieza
        tableroOcupado[fila][columna] = c;
        atacar(fila, columna);
        columna++;
    }

    // Ver que se ataca
    for (int fila = 0; fila < 8; ++fila)
    {
        for (int columna = 0; columna < 8; ++columna)
        {
            // cout << tableroOcupado[fila][columna];
            if (tableroOcupado[fila][columna] == ' ')
                continue;

            // Ver lo que ataca
            char pieza = tableroOcupado[fila][columna];
            switch (pieza)
            {
                case 'P': // Peón blanco
                    // Ataca hacia arriba (resta a la fila)
                    atacar(fila - 1, columna - 1);
                    atacar(fila - 1, columna + 1);
                    break;
                
                case 'p': // Peon negro
                    // Ataca hacia abajo (suma a la fila)
                    atacar(fila + 1, columna - 1);
                    atacar(fila + 1, columna + 1);
                    break;
                
                case 'R': // Torre blanca
                case 'r': // Torre negra
                    // Ataca en línea recta horizontal y vertical
                    // Se choca con piezas
                    // Arriba
                    for (int i = fila - 1; i >= 0; --i)
                    {
                        atacar(i, columna);
                        if (tableroOcupado[i][columna] != ' ')
                            break;
                    }
                    // Abajo
                    for (int i = fila + 1; i < 8; ++i)
                    {
                        atacar(i, columna);
                        if (tableroOcupado[i][columna] != ' ')
                            break;
                    }
                    // Izquierda
                    for (int j = columna - 1; j >= 0; --j)
                    {
                        atacar(fila, j);
                        if (tableroOcupado[fila][j] != ' ')
                            break;
                    }
                    // Derecha
                    for (int j = columna + 1; j < 8; ++j)
                    {
                        atacar(fila, j);
                        if (tableroOcupado[fila][j] != ' ')
                            break;
                    }
                break;

                case 'B': // Alfil blanco
                case 'b': // Alfil negro
                    // Ataca en diagonal
                    // Arriba izquierda
                    for (int i = fila - 1, j = columna - 1; i >= 0 && j >= 0; --i, --j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    // Arriba derecha
                    for (int i = fila - 1, j = columna + 1; i >= 0 && j < 8; --i, ++j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    // Abajo izquierda
                    for (int i = fila + 1, j = columna - 1; i < 8 && j >= 0; ++i, --j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    // Abajo derecha
                    for (int i = fila + 1, j = columna + 1; i < 8 && j < 8; ++i, ++j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                break;

                case 'N': // Caballo blanco
                case 'n': // Caballo
                    atacar(fila + 2, columna + 1);
                    atacar(fila + 2, columna - 1);
                    atacar(fila - 2, columna + 1);
                    atacar(fila - 2, columna - 1);
                    atacar(fila + 1, columna + 2);
                    atacar(fila + 1, columna - 2);
                    atacar(fila - 1, columna + 2);
                    atacar(fila - 1, columna - 2);
                    break;

                case 'Q': // Dama blanca
                case 'q': // Dama negra
                    // Ataca en línea recta horizontal y vertical
                    // Se choca con piezas
                    // Arriba
                    for (int i = fila - 1; i >= 0; --i)
                    {
                        atacar(i, columna);
                        if (tableroOcupado[i][columna] != ' ')
                            break;
                    }
                    // Abajo
                    for (int i = fila + 1; i < 8; ++i)
                    {
                        atacar(i, columna);
                        if (tableroOcupado[i][columna] != ' ')
                            break;
                    }
                    // Izquierda
                    for (int j = columna - 1; j >= 0; --j)
                    {
                        atacar(fila, j);
                        if (tableroOcupado[fila][j] != ' ')
                            break;
                    }
                    // Derecha
                    for (int j = columna + 1; j < 8; ++j)
                    {
                        atacar(fila, j);
                        if (tableroOcupado[fila][j] != ' ')
                            break;
                    }
                    
                    // Ataca en diagonal
                    // Arriba izquierda
                    for (int i = fila - 1, j = columna - 1; i >= 0 && j >= 0; --i, --j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    // Arriba derecha
                    for (int i = fila - 1, j = columna + 1; i >= 0 && j < 8; --i, ++j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    // Abajo izquierda
                    for (int i = fila + 1, j = columna - 1; i < 8 && j >= 0; ++i, --j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    // Abajo derecha
                    for (int i = fila + 1, j = columna + 1; i < 8 && j < 8; ++i, ++j)
                    {
                        atacar(i, j);
                        if (tableroOcupado[i][j] != ' ')
                            break;
                    }
                    break;
                
                case 'K': // Rey blanco
                case 'k': // Rey negro 
                    atacar(fila + 0, columna + 1);
                    atacar(fila + 1, columna + 1);
                    atacar(fila + 1, columna + 0);
                    atacar(fila + 1, columna - 1);
                    atacar(fila + 0, columna - 1);
                    atacar(fila - 1, columna - 1);
                    atacar(fila - 1, columna + 0);
                    atacar(fila - 1, columna + 1);
                    break;

            }
        }
        // cout << endl;
    }

    // // Imprimir posiciones sin atacar
    // for (int f = 0; f < 8; f++)
    //     for (int c = 0; c < 8; c++)
    //         if (!tableroAtacadoOcupado[f][c])
    //         {
    //             cout << c << ' ' << f << endl;
    //         }

    cout << 64 - posicionesAtacadas << endl;
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


