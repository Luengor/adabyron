#include <stdio.h> 
#include <stdint.h>

#include "../../libs/fastio.h"

#define TABLE_EVERY 4 
#define MOD 46337
static uint16_t powtables[100 + 1][25 + 1] = {0}; 

// (a + b) % k = ((a % k) + (b % k)) % k
// (a × b) % k = ((a % k) × (b % k)) % k

int testcase()
{
    int n, p, i, k;
    uint32_t total = 1, totali;

    // Leo n y p
    n = fio_parse_int();
    p = fio_parse_int();

    if (n == 0)
        return 0;

    // Hago la potencia
    for (i = 2, totali = 0; i <= n; i++)
    {
        // Busco la potencia anterior más cercana
        for (k = p >> 2; k > 0; k--)
            if (powtables[i][k] != 0)
                break;

        // Hago la potencia de lo que queda hasta p, rellenando la tabla
        // por el camino
        totali = (k == 0) ? 1 : powtables[i][k];
        for (k = (k << 2) + 1; k <= p; k++)
        {
            totali = (i * totali) % MOD; 

            if (k % TABLE_EVERY == 0)
                powtables[i][k >> 2] = totali;
        }

        total = (total + totali) % MOD;
    }

    printf("%d\n", total);

    return 1;
}

int main()
{
    while (testcase());
    return 0;
}

