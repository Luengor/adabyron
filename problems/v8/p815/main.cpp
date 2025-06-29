#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi g;
vi mt;
vector<bool> used;

bool kuhn(int v)
{
    if (used[v]) return false;
    used[v] = true;

    for (int to : g[v])
    {
        if (mt[to] == -1 || kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }

    return false;
}

bool casoDePrueba()
{
    int n;
    cin >> n;
    if (!n) return false;

    // leo el mapa
    vector<string> mapa(n);
    for (int y = 0; y < n; y++)
    {
        getline(cin, mapa[y]);
        if (mapa[y].size() == 0)
            getline(cin, mapa[y]);
    }

    vvi H(n, vi(n, -1));
    vvi V(n, vi(n, -1));
    int hc = 0, vc = 0;

    // lleno los mapitas 
    for (int y=0;y<n;y++)
        for (int x=0;x<n;x++)
            if (mapa[y][x] == '.')
            {
                if (x == 0 || mapa[y][x - 1] == 'X')
                    hc++;
                H[y][x] = hc;
            }

    for (int x=0;x<n;x++)
        for (int y=0;y<n;y++)
            if (mapa[y][x] == '.')
            {
                if (y == 0 || mapa[y - 1][x] == 'X')
                    vc++;
                V[y][x] = vc;
            }

    if (hc == 0 || vc == 0)
    {
        cout << "0\n";
        return true;
    }

    // hago el grafo
    vector<vector<bool>> con(hc, vector<bool>(vc, false));
    g.assign(hc, vi());

    for (int y=0;y<n;y++)
        for (int x=0;x<n;x++)
        {
            if (mapa[y][x] != '.') continue;
            auto h = H[y][x] - 1;
            auto v = V[y][x] - 1;
            if (!con[h][v])
            {
                con[h][v] = true;
                g[h].push_back(v);
            }
        }

    mt.assign(vc, -1);
    for (int v = 0; v < hc; ++v)
    {
        used.assign(hc, false);
        kuhn(v);
    }

    int matching_size = 0;
    for (auto v : mt)
        if (v != -1)
            matching_size++;

    cout << matching_size << '\n';

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


