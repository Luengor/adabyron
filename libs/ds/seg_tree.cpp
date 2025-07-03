#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define SEGTREE_EMPTY INT_MIN // cuidao con esto

class SegmentTree {
private:
    int n;
    vi A, st;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    int conquer(int a, int b) {
        if (a == SEGTREE_EMPTY) return b; // childs missing
        if (b == SEGTREE_EMPTY) return a;

        // Aquí va tu operación, la función que toma dos nodos consecutivos y
        // devuelve un valor. En este caso es multiplicar
        return a * b;
    }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L]; // this is a leaf node
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);                   // left
            build(r(p), m + 1, R);               // right
            st[p] = conquer(st[l(p)], st[r(p)]); // and conquer
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if (i > j) return SEGTREE_EMPTY; // invalid range

        if ((L >= i) && (R <= j)) return st[p]; // this is the node we want

        int m = (L + R) / 2;
        return conquer(rmq(l(p), L, m, i, min(m, j)),          // conquer left
                       rmq(r(p), m + 1, R, max(i, m + 1), j)); // and right
    }

    void update(int p, int L, int R, int i, int val) {
        if (L == R) {
            st[p] = val; // this is a leaf node, update it
            return;
        }

        int m = (L + R) / 2;
        if (i <= m)
            update(l(p), L, m, i, val); // go left
        else
            update(r(p), m + 1, R, i, val); // go right

        st[p] = conquer(st[l(p)], st[r(p)]); // conquer to update the value
    }

public:
    SegmentTree(int size) : n(size), st(4 * n) {}

    SegmentTree(const vi &A) : SegmentTree(A.size()) {
        // A TIENE que tener tamaño potencia de 2
        assert(fmod(log2(A.size()), 1) == 0); // check útil para debuggear

        this->A = A;
        build(1, 0, n - 1);
    }

    // actualiza el valor en la posición i con el valor val
    void update(int i, int val) { update(1, 0, n - 1, i, val); }

    // devuelve el valor del rango [i, j]
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};
