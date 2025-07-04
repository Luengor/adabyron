#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

vll p; // Vector de primos

vll fac_primos(ll n) {
    vll res;
    for (ll i = 0; (i < (int)p.size()) && (p[i] * p[i] <= n); i++) {
        while (n % p[i] == 0) {
            res.push_back(p[i]);
            n /= p[i];
        }
    }

    if (n > 1) {
        res.push_back(n); // Si queda un factor primo mayor que sqrt(n)
    }
    return res;
}

// Número de primos de n
int numPF(ll n) {
    int ans = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= n); i++) {
        while (n % p[i] == 0) {
            n /= p[i];
            ans++;
        }
    }
    return ans + (n > 1); // Si queda un factor primo mayor que sqrt(n)
}

// Número de factores primos distintos de n
int numDiffPF(ll n) {
    int ans = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= n); i++) {
        if (n % p[i] == 0) ans++;
        while (n % p[i] == 0)
            n /= p[i];
    }

    return ans + (n > 1); // Si queda un factor primo mayor que sqrt(n)
}

// Número de divisores de n
int numDiv(ll n) {
    int ans = 1;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= n); i++) {
        int cnt = 0;
        while (n % p[i] == 0) {
            n /= p[i];
            cnt++;
        }
        ans *= (cnt + 1);
    }

    return n > 1 ? ans * 2 : ans; // Si queda un factor primo mayor que sqrt(n)
}

// Suma de divisores de n
ll sumDiv(ll n) {
    ll ans = 1;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= n); i++) {
        ll multiplier = p[i], total = 1;
        while (n % p[i] == 0) {
            n /= p[i];
            total += multiplier;
            multiplier *= p[i];
        }
        ans *= total;
    }

    return (n > 1) ? ans * (n + 1)
                   : ans; // Si queda un factor primo mayor que sqrt(n)
}

ll phi(ll n) {
    ll ans = n;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= n); i++) {
        if (n % p[i] == 0) ans -= ans / p[i];
        while (n % p[i] == 0)
            n /= p[i];
    }
    return (n > 1) ? ans - ans / n
                   : ans; // Si queda un factor primo mayor que sqrt(n)
}
