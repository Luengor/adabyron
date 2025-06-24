#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int monedas_distintas(const vector<int> &monedas, int total)
{
    int distintas = 0;
    for (int i = monedas.size() - 1; i >= 0; i--)
    {
        const auto m = monedas[i];

        if (total >= m)
        {
            distintas++;
            total -= m;
        }

        while (total >= m)
        {
            total -= m;
        }
    }

    return distintas;
}

bool casoDePrueba()
{
    int nmonedas;
    cin >> nmonedas;
    if (!nmonedas)
        return false;

    vector<int> todas_monedas(nmonedas);
    for (int i = 0; i < nmonedas; i++)
        cin >> todas_monedas[i];

    vector<int> monedas;
    int suma = 0;
    for (int i = 0; i < nmonedas; i++)
    {
        const auto moneda = todas_monedas[i];
        const auto next_moned = i < nmonedas - 1 ? todas_monedas[i + 1] : 2000000000;

        if (moneda > suma && suma + moneda < next_moned)
        {
            monedas.push_back(moneda);
            suma += moneda;
        }
    }


    cout << monedas.size() << endl;


    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());
  
    return 0;
}

