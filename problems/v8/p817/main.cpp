#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;


long double area(const vii &fig)
{
    long double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        ii p = i ? fig[i - 1] : fig.back();
        ii q = fig[i];
        res += (p.first - q.first) * (p.second + q.second);
    }
    return fabs(res) / 2;
}

bool casoDePrueba()
{
    int p;
    cin >> p;
    if (p == 0) return false;
    long double total = 0;
    vector<ii> points;
    points.reserve(100);

    for (int i = 0; i < p; i++)
    {
        // Read number of points
        int npoints;
        cin >> npoints;
        
        // Read points
        points.assign(npoints, {0, 0});
        for (int j = 0; j < npoints; j++)
            cin >> points[j].first >> points[j].second;

        // Calculate area
        total += area(points);
    }

    if (total == floorl(total))
        cout << static_cast<long long>(total) << '\n';
    else
        cout << total << '\n';

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(1);

    while(casoDePrueba());

    return 0;
}

