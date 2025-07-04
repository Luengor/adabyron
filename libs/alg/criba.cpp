#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll _sieve_size;
bitset<10000010> bs; // 1e7 (más o menos el tope de lo que es viable)
vll p;               // Vector de primos

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1; // +1 porque el límite es inclusivo
    bs.set();                     // Inicializar el bitset a 1
    bs[0] = bs[1] = 0;            // 0 y 1 no son primos
    for (ll i = 2; i <= _sieve_size; i++) {
        if (bs[i]) { // Si es primo
            for (ll j = i * i; j <= _sieve_size; j += i) {
                bs[j] = 0; // Marcar múltiplos de i como no primos
            }
            p.push_back(i); // Añadir i a la lista de primos
        }
    }
}

// Solo funciona para números menores que p.back()^2
bool is_prime(ll n) {
    if (n < _sieve_size) return bs[n]; // O(1) para números pequeños
    for (ll i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) return false; // Si es divisible por algún primo
    }
    return true; // Si no es divisible por ningún primo, es primo
}