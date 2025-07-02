#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool casoDePrueba()
{
    int w, h;
    cin >> w >> h;
    if (w == 0) return false;

    int total = 0;
    for (int y = 0; y < h; y++)
    {
        bool dentro = false;
        char c;
        for (int x = 0; x < w; x++)
        {
            cin >> c;
            if (c == '.')
                total += 2 * dentro;
            else
            {
                dentro = !dentro;
                total++;
            }
        }
    }

    cout << total / 2 << '\n';

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


