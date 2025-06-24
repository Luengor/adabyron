#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Nodo
{
    char c = 0;
    bool fin = false;
    Nodo *a = nullptr, *b = nullptr;

    void add(const string &hash, int i = 0)
    {
        if (i >= hash.size()) return;

        bool es_fin = i == (hash.size() - 1);
        if (hash[i] == 'a')
        {
            if (!this->a)
            {
                this->a = new Nodo();
                this->a->c = 'a';
                this->a->fin = es_fin;
            }

            this->a->add(hash, i + 1);
        }
        else
        {
            if (!this->b)
            {
                this->b = new Nodo();
                this->b->c = 'b';
                this->b->fin = es_fin;
            }

            this->b->add(hash, i + 1);
        }
    }

    void fin_reduce()
    {
        if (a) a->fin_reduce();
        if (b) b->fin_reduce();

        // No podemos reducir un fin sobre otro
        if (this->fin) return;

        // Si a es un fin y b no existe (no hay bifurcaciones)
        if (a && a->fin && !b)
        {
            // Subimos el fin a nosotros
            this->fin = true;
            delete a;
            a = nullptr;
        }

        else if (b && b->fin && !a)
        {
            // Subimos el fin a nosotros
            this->fin = true;
            delete b;
            b = nullptr;
        }
    }

    int sum(int depth = 0)
    {
        int total = 0;
        if (fin) total += depth;

        if (a) total+=a->sum(depth+1);
        if (b) total+=b->sum(depth+1);
        return total;
    }

    ~Nodo()
    {
        if (a) delete a;
        if (b) delete b;
    }

    void print(int depth = 0) const
    {
        string indent(depth * 2, ' '); // 2 spaces per level for indentation

        // Print current node
        cout << indent << c;
        if (fin) cout << " (FIN)";
        cout << endl;

        // Recursively print children
        if (a) a->print(depth + 1);
        if (b) b->print(depth + 1);
    }
};

bool casoDePrueba()
{
    int hashes;
    cin >> hashes;
    if (hashes == 0)
        return false;

    // Construir el árbol
    auto raiz = new Nodo();
    for (int i = 0; i < hashes; i++)
    {
        std::string line;
        cin >> line;
        raiz->add(line);
    }

    raiz->fin_reduce();
    // raiz->print();
    cout << raiz->sum() << '\n';

    delete raiz;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}

