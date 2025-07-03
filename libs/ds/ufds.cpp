#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UFDS
{
private:
    vi p, rank;

public:
    // Crea un UFDS con n elementos
    UFDS(int n) : p(n, 0), rank(n, 0)
    {
        for (int i = 0; i < n; i++) p[i] = i;
    }

    // Encuentra el representante del conjunto al que pertenece i
    int findRep(int i)
    {
        if (p[i] != i)
        {
            p[i] = findRep(p[i]); // Path compression
        }
        return p[i];
    }

    // Comprueba si i y j pertenecen al mismo conjunto
    bool sameSet(int i, int j)
    {
        return findRep(i) == findRep(j);
    }

    // Hacer que i y j pertenezcan al mismo conjunto
    void unionSet(int i, int j)
    {
        if (sameSet(i, j)) return;
        int repI = findRep(i);
        int repJ = findRep(j);
        if (rank[repI] > rank[repJ]) swap(repI, repJ);
        p[repI] = repJ; // Unir los conjuntos
        if (rank[repI] == rank[repJ]) rank[repJ]++;
    }
};