#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

typedef long double ld;

struct pt
{
    double x, y;
    pt() {};
    pt(double x, double y) : x(x), y(y) {};

    bool operator==(pt const &o) const
    {
        return x == o.x && y == o.y;
    }
};

int p;
vector<pt> P; 

ld area(const vector<pt> &fig)
{
    ld res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        const auto p = i ? fig[i - 1] : fig.back();
        const auto q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

int orientation(pt a, pt b, pt c)
{
    // Producto cruzado y ver el signo
    ld v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

ld convex_hull()
{
    // Encontrar el punto mínimo
    auto lt_func = [](pt a, pt b){
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    };
    pt p0 = *min_element(P.begin(), P.end(), lt_func);

    // Ordenar por ángulo (o distancia si coninciden)
    auto ang_func = [&p0](const pt &a, const pt &b){
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    };
    sort(P.begin(), P.end(), ang_func);
    
    // Sacamos los puntos que forman el borde
    vector<pt> fig;
    for (int i = 0; i < (int)P.size(); i++)
    {
        while (fig.size() > 1 && !(orientation(fig[fig.size() - 2], fig.back(), P[i]) < 0))
            fig.pop_back();
        fig.push_back(P[i]);
    }

    // Devolvemos el area 
    return area(fig);
}

bool casoDePrueba()
{
    cin >> p;
    if (!p) return false;

    P.resize(p);
    for (int i=0;i<p;++i)
        cin >> P[i].x >> P[i].y;

    long double total = convex_hull();
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
    P.reserve(300000);

    while(casoDePrueba());

    return 0;
}


