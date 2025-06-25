#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define SEGTREE_EMPTY INT_MIN

class SegmentTree
{
private:
    int n;

    vi A, st;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    // the function that does something
    int conquer(int a, int b)
    {
        if (a == SEGTREE_EMPTY) return b; // childs missing
        if (b == SEGTREE_EMPTY) return a;

        return a * b;       // CHANGE THIS 
    }

    void build(int p, int L, int R)
    {
        // p -> the position in the segment tree (st)
        // [L R] -> the range in the input array (A)
        if (L == R)
            st[p] = A[L];
        else
        {
            // build left and right and conquer
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    int rmq(int p, int L, int R, int i, int j)
    {
        // p -> the current node in the st
        // [L R] -> the range of the current node 
        // [i j] -> the range to rmq
        
        // ?
        if (i > j) return SEGTREE_EMPTY;

        // if the current range is inside the searching range, return
        if ((L >= i) && (R <= j)) return st[p];

        // return conquer of left and right (breaking segments as needed)
        int m = (L+R)/2;
        return conquer(rmq(l(p),   L, m,           i, min(m, j)),
                       rmq(r(p), m+1, R, max(i, m+1), j       ));
    }

    void update(int p, int L, int R, int i, int val)
    {
        // p -> the current node in the st
        // [L R] -> the range of the current node 
        // i -> the index to change 
        // val -> the value to change it to

        // check if am the node
        if (L == R)
        {
            assert(L == i);
            st[p] = val;
            return;
        }

        // check if its left or right and then conquer
        int m = (L+R)/2;
        if (i <= m)
            update(l(p), L, m, i, val);
        else
            update(r(p), m + 1, R, i, val);

        st[p] = conquer(st[l(p)], st[r(p)]);
    }

public:
    SegmentTree(int size) : n(size), st(4*n) {}

    SegmentTree(const vi &A) : SegmentTree(A.size())
    {
        // // Check if its a power of 2
        // assert (fmod(log2(A.size()), 1) == 0);
        
        this->A = A;
        build(1, 0, n - 1);
    }

    void update(int i, int val)
    {
        update(1, 0, n - 1, i, val);
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);
    }
};

int signum(int n)
{
    if (n > 0) return 1; 
    if (n < 0) return -1; 
    return 0;
}

bool casoDePrueba()
{
    int n, c;
    cin >> n >> c;
    if (n == 0) return false;

    int act_size = pow(2, ceil(log2(n)));
    vi A(act_size, SEGTREE_EMPTY);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        A[i] = signum(A[i]);
    }

    SegmentTree st(A);

    for (int i = 0; i < c; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == '?')
        {
            int rmq = st.rmq(a-1,b-1);
            // assert(abs(rmq) <= 1);
            cout << "-0+"[rmq + 1];
        }
        else
        {
            st.update(a - 1, signum(b));
        }
    }

    cout << endl;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(casoDePrueba());

    return 0;
}


