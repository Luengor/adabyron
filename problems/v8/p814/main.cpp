#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX_SIZE 50 
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

const static ii moves[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
typedef tuple<int, int, int> iii;
void normal()
{
    queue<iii> Q;
    Q.push({origen.first, origen.second, 0});

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
            cout << dis << ' ';
            return;
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

    cout << "IMPOSIBLE ";
}

#define ARRIBA 0
#define ABAJO 1
#define NORTE 2
#define SUR 3
#define ESTE 4
#define OESTE 5
// Las posiciones son: ARRIBA, ABAJO, NORTE, SUR, ESTE, OESTE
//                       0      1       2     3    4      5
// Las rotaciones son: NORTE, SUR, ESTE, OESTE

const static int tranlation[4][6] = {
    {NORTE, SUR, ABAJO, ARRIBA, ESTE, OESTE},   // Mover al norte
    {SUR, NORTE, ARRIBA, ABAJO, ESTE, OESTE},   // Mover al sur
    {ESTE, OESTE, NORTE, SUR, ABAJO, ARRIBA},   // Mover al este
    {OESTE, ESTE, NORTE, SUR, ARRIBA, ABAJO},   // Mover al oeste
};

// <<y, x> <cara, dst>>
typedef pair<ii, ii> iiii;
void qbo()
{
    vector<vector<vector<bool>>> V(ty, vector<vector<bool>>(tx, vector<bool>(6, false)));
    queue<iiii> Q;
    Q.push({{origen.first, origen.second}, {ABAJO, 0}});
    // int n = 0;

    while (!Q.empty())
    {
        // n++;
        auto state = Q.front();
        Q.pop();

        ii pos = state.first;
        int face = state.second.first, dis = state.second.second;

        // Fuera del mapa
        if (pos.first < 0 || pos.first > ty * 2 || pos.second < 0 || pos.second > tx * 2)
            continue;

        // Salimos si ya está visitado 
        if (V[(pos.first - 1)/2][(pos.second - 1) / 2][face]) continue;

        // cout << n << " (" << pos.first << ' ' << pos.second << ")\n";

        // Check if its the end
        if (destino == pos && face == ABAJO)
        {
            cout << dis << '\n';
            return;
        }

        // Mark it visited
        V[(pos.first - 1)/2][(pos.second - 1) / 2][face] = true;

        // Find childs
        for (int i = 0; i < 4;i++)
        {
            const auto move = moves[i];
            // If can move
            if (mapa[pos.first + move.first][pos.second + move.second] == '#') continue;

            Q.push({{pos.first + move.first * 2, pos.second + move.second * 2}, {tranlation[i][face], dis + 1}});
            // int new_n = n + Q.size();
            // cout << new_n<< endl;
        }
    }

    cout << "IMPOSIBLE\n";
}


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

    normal();
    qbo();


    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


