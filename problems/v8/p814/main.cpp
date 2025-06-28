#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX_SIZE 5
#define ACTUAL_MAX_SIZE (MAX_SIZE * 2 + 1)

int tx, ty;
char mapa[ACTUAL_MAX_SIZE][ACTUAL_MAX_SIZE];
ii origen, destino;

struct Graph
{
    vector<vii> AL;

    Graph(int s) : AL(s, vii()) {};

    void edge(int i, int j, int k)
    {
        AL[i].push_back({j, k});
        AL[j].push_back({i, k});
    }

    const vii& edges(int i) { return AL[i]; }

    int dijkstra(int from, int to)
    {
        vi distances(AL.size(), -1);
        priority_queue<ii> Q;
        Q.push({0, from});
        
        while (!Q.empty())
        {
            auto to_check = Q.top(); Q.pop();
            const auto dis = to_check.first, node = to_check.second;

            if (node == to) return -dis;

            if (distances[node] != -1)
                continue;
            distances[node] = -dis;

            for (auto neigh : edges(node))
            {
                Q.push({-neigh.second + dis, neigh.first});
            }
        }

        return -1;
    }
};



bool casoDePrueba()
{
    cin >> tx >> ty;
    if (tx == 0) return false;

    // Read input
    for (int y=0; y < ty*2 + 1; y++)
    {
        string line;
        getline(cin, line);
        if (line.size() == 0)
            getline(cin, line);

        for (int x=0; x<line.size(); x++)
        {
            char c = line[x];
            switch (c)
            {
                case 'O':
                    origen = {y, x};
                    mapa[y][x] = ' ';
                    break;

                case 'D':
                    destino = {y, x};
                    mapa[y][x] = ' ';
                    break;

                case ' ':
                    mapa[y][x] = ' ';
                    break;

                default:
                    mapa[y][x] = '#';
            }
        }
    }

    // Bfs normal 
    const static ii moves[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    queue<iii> Q;
    Q.push({origen.first, origen.second, 0});
    bool found = false;

    while (!Q.empty())
    {
        auto state = Q.front();
        Q.pop();

        int sy = get<0>(state), sx = get<1>(state), dis = get<2>(state);

        // Fuera del mapa
        if (sy < 0 || sy > ty * 2 || sx < 0 || sx > tx * 2)
            continue;

        // Salimos si ya está visitado 
        if (mapa[sy][sx] == '1') continue;

        // Check if its the end
        if (destino.first == sy && destino.second == sx)
        {
            cout << dis << endl;
            found = true;
            break;
        }

        // Mark it visited
        mapa[sy][sx] = '1';

        // Find childs
        for (const auto move : moves)
        {
            // If can move
            if (mapa[sy + move.first][sx + move.second] == '#') continue;
            Q.push({sy + move.first * 2, sx + move.second * 2, dis + 1});
        }
    }

    if (!found) cout << "IMPOSIBLE" << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


