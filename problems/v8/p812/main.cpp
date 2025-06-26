#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Entrada:
 * La entrada está compuesta por distintos casos de prueba, cada uno
 * representando un grafo no dirigido no necesariamente conexo.
 * 
 * Cada grafo comienza con una línea con dos números que indican el número nv
 * de vértices (entre 1 y 100) y el número de aristas no dirigidas (hasta
 * 1.000). A continuación vendrán tantas líneas como aristas con la información
 * de cada una: una pareja de números distintos entre 1 y nv. Se garantiza que
 * no habrá más de una arista entre el mismo par de vértices.
 * 
 * Salida:
 * Por cada grafo se escribirá una línea con tres números: el número de
 * vértices aislados en el grafo (aquellos de los que no sale ninguna arista),
 * el número de árboles de dos o más vértices y el número de componentes
 * conexas con ciclos.
*/

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Graph
{
    vector<vi> AL;

    Graph(int s) : AL(s, vi()) {};

    void edge(int i, int j)
    {
        AL[i].push_back(j);
        AL[j].push_back(i);
    }

    const vi& edges(int i) { return AL[i]; }
};


bool casoDePrueba()
{
    int nv, na;
    cin >> nv >> na;
    if (!cin) return false;

    Graph g(nv);
    for (int i=0;i<na;++i)
    {
        int a, b;
        cin >> a >> b;
        g.edge(a - 1, b - 1);
    }

    vi visited(nv, -1); // prev or -1 if not visited
    int visited_count = 0;

    int alone = 0, trees = 0, neither = 0;
#define visit(n, f) visited[(n)] = (f); visited_count++;

    while (visited_count != nv)
    {
        // Find the first non visited node;
        int non_visited = -1;
        for (int i = 0; i < nv; i++)
            if (visited[i] == -1)
            {
                non_visited = i;
                break;
            }

        // visit
        visit(non_visited, non_visited);

        // check if they are alone :(
        if (g.edges(non_visited).size() == 0)
        {

            alone++;
            continue;
        }

        // they are not :D 
        // search it and check if they are a tree 
        queue<int> pend;
        pend.push(non_visited);
        bool is_tree = true;
        
        while (!pend.empty())
        {
            int node = pend.front();
            pend.pop();

            const int my_prev = visited[node];

            // add neighbors
            for (const auto n : g.edges(node))
            {
                if (n == my_prev) continue;
                if (visited[n] != -1)
                    is_tree = false;
                else
                {
                    visit(n, node);
                    pend.push(n);
                }
            }
        }

        if (is_tree) trees++;
        else neither++;
    }

    cout << alone << ' ' << trees << ' ' << neither << '\n';

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


