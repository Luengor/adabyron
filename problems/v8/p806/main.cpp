#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool casoDePrueba()
{
    int alto, tipos;
    cin >> alto >> tipos;
    if (!cin) return false;

    vector<int> monedas(tipos);
    for (int i = 0; i < tipos; i++)
    {
        cin >> monedas[i];
    }

    // Obtengo el minimo comun multiplo de todos las combinaciones de 4 monedas
    unordered_set<int> mcm_set;
    for (int i = 0; i < tipos; i++)
    {
        for (int j = i + 1; j < tipos; j++)
        {
            for (int k = j + 1; k < tipos; k++)
            {
                for (int l = k + 1; l < tipos; l++)
                {
                    int mcm = (monedas[i] * monedas[j]) / __gcd(monedas[i], monedas[j]);
                    mcm = (mcm * monedas[k]) / __gcd(mcm, monedas[k]);
                    mcm = (mcm * monedas[l]) / __gcd(mcm, monedas[l]);
                    mcm_set.insert(mcm);
                }
            }
        }
    }

    // Recorro los mcm y veo el menor más cercano al alto y el mayor más cercano al alto
    int mejor_menor = 0, mejor_mayor = 10000000;
    for (int mcm : mcm_set)
    {
        int abajo = (alto / mcm) * mcm;
        int arriba = ((alto + mcm - 1) / mcm) * mcm;
        if (abajo <= alto && abajo > mejor_menor)
        {
            mejor_menor = abajo;
        }
        if (arriba >= alto && arriba < mejor_mayor)
        {
            mejor_mayor = arriba;
        }
    }

    cout << mejor_menor << " " << mejor_mayor << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}

