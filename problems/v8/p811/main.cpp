#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problema 811: ¡Acepta el reto! (https://aceptaelreto.com/problem/statement.php?id=811):
 * Quien más quien menos sabe que en el mundo de las matemáticas la complejidad
 * de demostrar una afirmación puede cambiar muchísimo ante cambios pequeños
 * del enunciado.
 * 
 * Por ejemplo, es más o menos sencillo demostrar que existen infinitas ternas
 * de números positivos que cumplen x2 + y2 = z2 pero costó más de 300 años
 * demostrar que si en lugar de un 2 ponemos cualquier otro número mayor,
 * entonces no existe ninguna terna que lo cumpla fuera de las triviales como
 * (1,0,1)*.
 * 
 * En el mundo de la algoritmia y la resolución de problemas ocurre algo
 * similar. Por ejemplo es bastante sencillo determinar si, dado un grafo, se
 * puede encontrar un recorrido que pase por todas las aristas sin repetir
 * ninguna pero es tremendamente costoso saber si hay un recorrido que pase por
 * todos los vértices sin repetir ninguno.
 * 
 * Hay ejemplos más fáciles de ver, al alcance de cualquiera con un poco de
 * sentido común. Por ejemplo, saber si un número es la raiz cuadrada de otro
 * no requiere saber hacer raíces cuadradas, sino que basta con saber
 * multiplicar; conocer el dígito menos significativo de un número elevado a
 * otro no requiere calcular el valor completo; incluso saber cuál es el último
 * dígito del factorial requiere únicamente comparaciones.
 * 
 * El último ejemplo que mencionaremos es el de la multiplicación de números
 * enteros: para saber si al multiplicar un puñado de números el resultado dará
 * positivo, negativo o cero, no se necesita hacer ninguna multiplicación.
 * 
 * Entrada:
 * La entrada está compuesta por distintos casos de prueba, cada uno ocupando
 * varias líneas.
 * 
 * La primera línea de cada caso tiene dos números: el primero, N, indica
 * cuántos valores hay que considerar y el segundo cuántas operaciones C se
 * realizan (ambos entre 1 y 300.000).
 * 
 * La siguiente línea contiene N valores entre -1000 y 1000. Tras ella vienen C
 * líneas con las distintas operaciones que pueden tener el siguiente formato:
 * 
 * La entrada termina con una línea con dos ceros que no debe procesarse.
 * 
 * Salida:
 * Por cada caso de prueba se escribirá una única línea con tantos caracteres
 * como operaciones de tipo ? haya en el caso. El resultado de la operación
 * será 0 si la multiplicación del intervalo de números dio 0, + si dio un
 * número positivo y - si fue negativo.
*/

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class SegmentTree
{
    constexpr static int EMPTY = INT_MIN;

private:
    int n;

    vi A, st;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    // the function that does something
    int conquer(int a, int b)
    {
        if (a == EMPTY) return b; // childs missing
        if (b == EMPTY) return a;

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
        if (i > j) return EMPTY;

        // if the current range is inside the searching range, return
        if ((L >= i) && (R <= j)) return st[p];

        // return conquer of left and right (breaking segments as needed)
        int m = (L+R)/2;
        return conquer(rmq(l(p),   L, m,           i, min(m, j)),
                       rmq(r(p), m+1, R, max(i, m+1), j       ));
    }

    void update(int p, int L, int R, int i, int k, int val)
    {
    }

public:
    SegmentTree(int size) : n(size), st(4*n) {}

    SegmentTree(const vi &A) : SegmentTree(A.size())
    {
        // Check if its a power of 2
        assert (fmod(log2(A.size()), 1) == 0);
        
        this->A = A;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val)
    {
        update(1, 0, n - 1, i, j, val);
    }

    int rmq(int i, int j)
    {
        return rmq(1, 0, n - 1, i, j);
    }
};

bool casoDePrueba()
{
    int n, c;
    cin >> n >> c;
    if (n == 0) return false;

    int act_size = pow(2, ceil(log2(n)));
    vi A(act_size);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] > 0) A[i] = 1;
        else if (A[i] < 0) A[i] = -1;
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
            cout << "-0+"[rmq + 1];
        }
        else
        {
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


