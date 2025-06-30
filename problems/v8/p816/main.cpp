#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int categorias, incubadora;
int n;
vector<vi> ady;
vector<vi> cap; 

#define pi(n) (1 + (n))
#define ci(n) (1 + incubadora + (n))

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<ii> q;
    q.push({s, INT_MAX});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : ady[cur])
        {
            if (parent[next] == -1 && cap[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, cap[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while ((new_flow = bfs(s, t, parent)))
    {
        flow += new_flow;
        int cur = t;

        while (cur != s)
        {
            int prev = parent[cur];
            cap[prev][cur] -= new_flow;
            cap[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

#define add_edge(from, to, c) ady[from].push_back(to); ady[to].push_back(from); cap[from][to] = c; 

bool casoDePrueba()
{
    cin >> categorias >> incubadora;
    if (!cin) return false;

    // Fuente + Incubadora + Categorias + Sumidero 
    n = 1 + categorias + incubadora + 1;
    ady.assign(n, vi());
    cap.assign(n, vi(n, 0));

    // Aristas desde la fuente a la los problemas
    for (int i = 0; i < incubadora; i++)
    {
        add_edge(0, pi(i), 1);
    }
    
    // Aristas desde las categorias al sumidero
    // La capacidad es el número de problemas de esa categoria
    for (int i = 0; i < categorias; i++)
    {
        int capacidad;
        cin >> capacidad;
        add_edge(ci(i), ady.size() - 1, capacidad);
    }

    // Aristas desde cada problema a las categorías que tenga
    for (int p = 0; p < incubadora; p++)
    {
        int c;
        for (;;)
        {
            cin >> c;
            if (c == 0) break;

            add_edge(pi(p), ci(c - 1), 1);
        }
    }

    cout << maxflow(0, ady.size() - 1) << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


