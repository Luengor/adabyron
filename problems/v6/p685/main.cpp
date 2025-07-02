#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool casoDePrueba()
{
    int tx, ty, ix, iy;
    cin >> tx >> ty >> ix >> iy;

    if (tx + ty + ix + iy == 0) return false;

    // true cuando estén en la misma línea o diagonal
    if (tx == ix || ty == iy || (abs(iy - ty) == abs(ix - tx)))
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


