#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool casoDePrueba()
{
    int cuchillos;
    cin >> cuchillos;

    if (cuchillos == 0)
        return false;

    int max_cuchillo;
    cin >> max_cuchillo;
    cuchillos--;
    int max_cadena = 0;
    int curr_cadena = 0;

    for (; cuchillos > 0; cuchillos--)
    {
        int new_cuchillo;
        cin >> new_cuchillo;
        curr_cadena++;

        if (new_cuchillo > max_cuchillo)
        {
            max_cuchillo = new_cuchillo;
            max_cadena = max(max_cadena, curr_cadena);
            curr_cadena = 1;
        }
    }

    max_cadena = max(curr_cadena, max_cadena);
    cout << max_cadena << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());
  
    return 0;
}

