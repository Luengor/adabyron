#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool casoDePrueba()
{
    uint64_t n;
    cin >> n;
    if (!cin) return false;

    auto root = uint64_t(sqrtl(n));
    if (root * root == n)
        cout << "ENCENDIDA\n";
    else
        cout << "APAGADA\n";
    
    return true;
} 

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}

