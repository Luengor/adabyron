#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void casoDePrueba()
{
    int n;
    cin >> n;

    ordered_set digits;
    for (int i=0;i<n;i++)
        digits.insert(i + 1);

    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;

        // f-ésimo elemento
        auto it = digits.find_by_order(f);
        int d = *it;

        // eleminar rapidísimo
        digits.erase(it);

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

