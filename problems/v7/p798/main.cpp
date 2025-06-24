#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool casoDePrueba()
{
    int nvagones;
    cin >> nvagones;
    if (nvagones == 0)
        return false;

    queue<int> conf;
    for (int i = 0; i < nvagones; i++)
    {
        int vagon;
        cin >> vagon;
        conf.emplace(vagon);
    }

    // Vamos lellendo la configuración
    // Si toca un vagón que no podemos sacar, movemos trenes hasta poder o fallar
    stack<int> trenesDeh;
    int vagon_final = 1;

    while (!conf.empty())
    {
        int vagon = conf.front();
        conf.pop();
        // cout << vagon_final << ' ' << vagon << endl;
        // if (trenesDeh.size() > 0)
        //     cout << trenesDeh.top() << endl;
        
        // Se puede sacar directamente
        if (vagon == vagon_final)
        {
            vagon_final++;
            continue;
        }

        else if (trenesDeh.size() > 0 && vagon == trenesDeh.top())
        {
            trenesDeh.pop();
            continue;
        }

        // Miramos si está por venir
        if (vagon <= vagon_final)
        {
            // Si no, decimos que es imposible
            cout << "NO\n";
            return true;
        }

        // Metemos trenes en deh hasta que toque
        for (;vagon_final < vagon; vagon_final++)
            trenesDeh.emplace(vagon_final);

        // Se saca el vagón
        vagon_final += 1;
    }

    cout << "SI\n";

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());
  
    return 0;
}

