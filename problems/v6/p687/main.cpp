#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;

bool casoDePrueba()
{
    cin >> n;
    if (!n) return false;

    int edges = 0;

    for (;;)
    {
        int from, to;
        cin >> from >> to;

        if (from == 0) break;
        edges++;
    }

    cout << (edges - n + 1) << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


