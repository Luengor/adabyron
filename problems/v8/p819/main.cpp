#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// que demónios es un árbol de fenwick 
class FenwickTree
{
private:
    vi bit;
    int size;

public:
    FenwickTree(int n) : size(n), bit(n + 1, 0) {}

    int query(int index)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += bit[index];
            index -= index & -index; //???
        }
        return sum;
    }

    void update(int index, int delta)
    {
        while (index <= size)
        {
            bit[index] += delta;
            index += index & -index;
        }
    }
};


void casoDePrueba()
{
    int n;
    cin >> n;

    FenwickTree T(n);
    for (int i=0;i<n;i++)
        T.update(i + 1, 1);

    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;

        // ligera búsqueda binaria
        int low = 1, high = n;
        int d = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (T.query(mid) > f)
            {
                d = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        // eleminar "rapidísimo"
        T.update(d, -1);

        if (i == n - 1)
            cout << d << '\n';
        else
            cout << d << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i)
    {
        casoDePrueba();
    }

    return 0;
}

