#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

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
    int n, c, k;
    cin >> n >> c;
    if (!cin) return false;

    Graph g(n + 1);
    for (int i=0;i<c;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.edge(a, b, c);
    }

    cin >> k;
    for (int i=0;i<k;i++)
    {
        int from, to;
        cin >> from >> to;
        const auto dis = g.dijkstra(from, to);
        if (dis != -1) cout << dis << '\n';
        else cout << "NO LLEGA\n";
    }

    cout << "---\n";

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


