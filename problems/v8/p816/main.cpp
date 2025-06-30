#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int categorias, incubadora;
int n;
vector<vii> ady;

#define pi(n) (1 + (n))
#define ci(n) (1 + incubadora + (n))

bool casoDePrueba()
{
    cin >> categorias >> incubadora;
    if (!cin) return false;

    // Fuente + Incubadora + Categorias + Sumidero 
    n = 1 + categorias + incubadora + 1;
    ady.assign(n, vii());

    // Aristas desde la fuente a la los problemas
    for (int i = 0; i < incubadora; i++)
        ady[0].push_back({pi(i), 1});
    
    // Aristas desde las categorias al sumidero
    // La capacidad es el número de problemas de esa categoria
    for (int i = 0; i < categorias; i++)
    {
        int capacidad;
        cin >> capacidad;
        ady[ci(i)].push_back({ady.size() - 1, capacidad});
    }

    // Aristas desde cada problema a las categorías que tenga
    for (int p = 0; p < incubadora; p++)
    {
        int c;
        for (int i = 0; i < categorias; i++)
        {
            cin >> c;
            if (c) ady[pi(p)].push_back({ci(i), 1});
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


