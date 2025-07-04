#include <bits/stdc++.h>
using namespace std;

// Modulo positivo siempre
int mod(int a, int m) { return ((a % m) + m) % m; }

// Exponente modular: b^p (mod m)
// 0 <= b < m
int modPow(int b, int p, int m) {
    if (p == 0) return 1;
    int ans = modPow(b, p / 2, m);
    ans = mod(ans * ans, m);
    if (p & 1) ans = mod(ans * b, m);
    return ans;
}

// Euclides extendido (devuelve gdc(a, b) y x, y tal que a*x + b*y == gdc(a, b))
int extEuclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a / b;
        tie(a, b) = make_tuple(b, a % b);
        tie(x, xx) = make_tuple(xx, x - q * xx);
        tie(y, yy) = make_tuple(yy, y - q * yy);
    }
    return a;
}

// Inverso modular: b^(-1) (mod m)
int modInverse(int b, int m) {
    int x, y;
    int d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}