#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "../../libs/fastio.h"

#define KAPREKAR 6174

bool valid_kaprekar(int n);
int kaprekar(int n);

int main()
{
    int testcases = fio_parse_int();
    int n;

    for (; testcases > 0; testcases--)
    {
        n = fio_parse_int();
        if (!valid_kaprekar(n))
        {
            printf("8\n");
            continue;
        }

        printf("%d\n", kaprekar(n));
    }

    return 0;
}

bool valid_kaprekar(int n)
{
    // Comprobar si tiene 2 dígitos distintos
    int i, j;
    for (i = 10; i < 10000; i *= 10)
        for (j = 1; j < i; j *= 10)
            if ((n / i % 10) != (n / j % 10))
                return true;

    return false;
}

int kaprekar(int n)
{
    int p, i, j, tmp;
    int ns[4] = {0};
    int kdes, kasc;

    // Comprobamos si es el número mágico
    if (n == KAPREKAR) 
        return 0;

    // Ordenamos las cifras
    for (i = 0, p = 1; i < 4; i++, p*=10)
        ns[i] = n / p % 10;

    for (i = 3; i > 0; i--)
        for (j = 0; j < i; j++) 
            if (ns[j] < ns[j+1])
            {
                tmp = ns[j];
                ns[j] = ns[j+1];
                ns[j+1] = tmp;
            }

    // Creamos los números
    kdes = kasc = 0;
    for (i = 0, p = 1; i < 4; i++, p *= 10)
    {
        kdes = kdes * 10 + ns[i]; 
        kasc = kasc + p * ns[i];
    }

    // Hacemos kaprekar otra vez
    return kaprekar((kdes > kasc) ? kdes - kasc : kasc - kdes) + 1;

    
}

