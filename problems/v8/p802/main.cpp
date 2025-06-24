#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool ig(const uint64_t &a, const uint64_t &b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> ricos;
    ricos.reserve(1000);

    while(true)
    {
        int n, k;
        cin >> n >> k;
        if (!n) return 0;

        int64_t total = 0, total_ricos = 0, ahorro;
        ricos.clear();

        for (; n > 0; n--)
        {
            cin >> ahorro;
            total += ahorro;

            if (ricos.size() < k)
            {
                ricos.push_back(ahorro);
                push_heap(ricos.begin(), ricos.end(), ig);
                total_ricos += ahorro;
                continue;
            }

            if (ricos[0] >= ahorro)
                continue;

            pop_heap(ricos.begin(), ricos.end(), ig);
            total_ricos = total_ricos - ricos.back() + ahorro;
            ricos.back() = ahorro;
            push_heap(ricos.begin(), ricos.end(), ig);
        }

        cout << total << ' ' << total_ricos << '\n';
    }

    return 0;
}

