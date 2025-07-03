#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool casoDePrueba()
{
    int f, a, c;
    cin >> f >> a >> c;
    if (!cin) return false;

    vi libres(f, a);
    for (int i = 0; i < f; i++)
    {
        int ocupados;
        cin >> ocupados;
        libres[i] = a - ocupados;
    }

    priority_queue<int> L(libres.begin(), libres.end());
    int64_t acc = 0;
    while (c > 0 && !L.empty())
    {
        // Sacamos máximo, sumamos a acc, restamos uno y pal fondo
        int top = L.top();
        L.pop();

        if (top == 0) break;

        acc += top;
        if (acc > 1) L.push(top - 1);
        c--;
    }

    cout << acc << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


