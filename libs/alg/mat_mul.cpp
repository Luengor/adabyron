#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7; // Módulo para las operaciones (primo grande)
const int MAXN = 2;     // Tamaño máximo de la matriz
struct Matrix {
    ll mat[MAXN][MAXN];
};

// Asegura que el resultado sea positivo
ll mod(ll a, ll b) { return (a % b + b) % b; }

// Multiplica dos matrices
Matrix mat_mul(const Matrix &a, const Matrix &b) {
    Matrix ans;

    // Inicializa la matriz resultado a cero
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            ans.mat[i][j] = 0;

    // Realiza la multiplicación de matrices
    for (int i = 0; i < MAXN; i++) {
        for (int k = 0; k < MAXN; k++) {
            if (a.mat[i][k] == 0) continue;
            for (int j = 0; j < MAXN; j++) {
                ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
                ans.mat[i][j] = mod(ans.mat[i][j], MOD);
            }
        }
    }

    return ans;
}