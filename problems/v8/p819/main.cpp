#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 *
 * 3
 * 0 0 0 -> representa el valor 0*2! + 0*1! + 0*0! = 0 -> la primera permutación de n (3) elementos -> 1 2 3
 *
 * 3
 * 1 0 0  -> representa el valor 1*2! + 0*1! + 0*0! = 2 -> la tercera permutación de n (3) elementos -> 2 1 3 
 *
 * 4
 * 2 2 0 0 
 *
 * 4
 * 3 2 1 0
 */

typedef vector<int> vi;

void casoDePrueba()
{
    int n;
    cin >> n;

    vi factroid(n);
    vi digits(n);
    for (int i=0;i<n;i++)
    {
        cin >> factroid[i];
        digits[i] = i+1;
    }

    for (int i = 0; i < n; i++)
    {
        const auto f = factroid[i];
        int d = digits[f];
        digits.erase(next(digits.begin(), f));
        if (i == n - 1)
            cout << d << '\n';
        else
            cout << d << ' ';
    }
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

