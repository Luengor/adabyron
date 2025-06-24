#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool vive(int64_t vidas, int64_t energia, const int64_t max_daNo, const vector<int64_t > &cosas)
{
    if (energia <= max_daNo)
    {
        // Si la energía es menor o igual al daño máximo, no se puede sobrevivir
        return false;
    }

    const int64_t energia_max = energia;
    for (auto cosa : cosas)
    {
        if (cosa > 0)
        {
            // Botiquín
            energia = min(energia + cosa, energia_max);
            continue;
        }

        // Enemigo
        energia += cosa; // cosa es negativo, así que resta
        if (energia <= 0)
        {
            vidas--;
            if (vidas <= 0)
            {
                // Si no quedan vidas, perdimos
                return false;
            }

            energia = energia_max + cosa;
        }
    }

    return true;
}

bool casoDePrueba()
{
    int64_t vidas, ncosas;

    cin >> vidas >> ncosas;
    if (!cin) return false;

    // Leemos las cosas
    vector<int64_t > cosas(ncosas);
    int64_t daNototal = 0, masmenos = 0;
    for (int64_t i = 0; i < ncosas; i++)
    {
        cin >> cosas[i];
        if (cosas[i] < 0)
        {
            daNototal += cosas[i];
            masmenos = min(masmenos, cosas[i]);
        }
    }

    int64_t max_daNo = masmenos * -1;

    int64_t arriba = daNototal * -1 + 1;
    int64_t abajo = masmenos * -1;
    int64_t sobrevive = arriba;
    while (abajo < arriba)
    {
        int64_t medio = (abajo + arriba) / 2;
        if (vive(vidas, medio, max_daNo, cosas))
        {
            arriba = medio;
            sobrevive = medio;
        }
        else
        {
            abajo = medio + 1;
        }
    }

    cout << sobrevive << '\n';

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}

