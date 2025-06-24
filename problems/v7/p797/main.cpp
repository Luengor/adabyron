#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct tabla
{
    int apagados = 0;
    int encendidos = 0;
    int rotos = 0;

    string moviles;

    void add(char c)
    {
        moviles += c;

        switch (c)
        {
            case '0':
                apagados++;
                break;

            case '1':
                encendidos++;
                break;

            case 'R':
                rotos++;
                break;
        }
    }

    int carencia_encendidos(const tabla& other)
    {
        return other.encendidos - encendidos;
    }
};

bool casoDePrueba()
{
    int col, fil;

    // Caso malo
    cin >> fil >> col;
    if (col == 0)
        return false;

    // leer
    tabla estadoI, estadoF;
    for (int f = 0; f < fil; f++)
    {
        string line;
        getline(cin, line);
        if (line.size() == 0)
            getline(cin, line);

        int i = 0;
        for (int c = 0; c < col; c++, i++)
            estadoI.add(line[i]);
        i++;
        for (int c = 0; c < col; c++, i++)
            estadoF.add(line[i]);
    }

    // una búsqueda es imposible cuando hay más encendidos+rotos en el final
    // que en el inicial puesto que no hay manera de encender móviles
    if (estadoF.encendidos > estadoI.rotos + estadoI.encendidos)
    {
        cout << "IMPOSIBLE\n";
        return true;
    }

    const auto len = col * fil;
    int pasos = 0;

    // 1 enciendo los rotos que tengan un 1 debajo 
    for (int i = 0; i < len; i++)
    {
        if (estadoI.moviles[i] == 'R' && estadoF.moviles[i] == '1')
        {
            estadoI.moviles[i] = '1';
            estadoI.encendidos += 1;
            estadoI.rotos -= 1;
            pasos++;
        }
    }

    // 2. enciendo los rotos que hagan falta para quitar la carencia, si no, apago
    for (int i = 0; i < len; i++)
    {
        if (estadoI.moviles[i] == 'R')
        {
            estadoI.rotos -= 1;
            if (estadoI.carencia_encendidos(estadoF) > 0)
            {
                estadoI.moviles[i] = '1';
                estadoI.encendidos += 1;
            }
            else
            {
                estadoI.moviles[i] = '0';
                estadoI.apagados += 1;
            }
            pasos++;
        }
    }

    // 3. Apago los encendidos que no estén bien (sin apagar de más)
    for (int i = 0; i < len; i++)
    {
        if (estadoI.moviles[i] == '1' && estadoF.moviles[i] == '0' &&
                estadoI.carencia_encendidos(estadoF) < 0)
        {
            estadoI.moviles[i] = '0';
            estadoI.apagados += 1;
            estadoI.encendidos -= 1;
            pasos++;
        }
    }

    // aquí la carencia debería ser 0 siempre, pero porsi
    if (estadoI.carencia_encendidos(estadoF) != 0)
    {
        cout << "IMPOSIBLE\n";
        return true;
    }

    // 4. El número de posiciones diferentes / 2 es el número de pasos restantes
    int diff = 0;
    for (int i = 0; i < len; i++)
    {
        if (estadoI.moviles[i] != estadoF.moviles[i])
            diff++;
    }

    // assert(diff % 2 == 0);
    pasos += diff / 2;

    // cout << pasos << ": " << estadoI.moviles << endl;
    cout << pasos << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());
  
    return 0;
}

