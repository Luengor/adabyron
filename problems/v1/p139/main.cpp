#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cubitable;

int cubi(const int n)
{
    auto found = cubitable.find(n);
    if (found != cubitable.end())
        return found->second;

    int total = 0;

    int n2 = n;
    while (n2 > 0)
    {
        int d = n2 % 10;
        total += d * d * d; 
        n2 /= 10;
    }

    cubitable[n] = total;

    return total;
}

bool casoDePrueba()
{
    int n;
    cin >> n;
    if (n == 0)
        return false;

    cout << n; 
    unordered_set<int> already_seen;
    already_seen.emplace(n);

    while(n != 1)
    {
        n = cubi(n);
        cout << " - " << n; 

        if (already_seen.find(n) != already_seen.end())
        {
            cout << " -> no cubifinito.\n"; 
            return true;
        }

        already_seen.emplace(n);
    }
    
    cout << " -> cubifinito.\n"; 

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());
  
    return 0;
}

