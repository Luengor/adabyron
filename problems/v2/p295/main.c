#include <stdio.h>
#include <stdint.h>

#include "../../libs/fastio.h"

#define MOD 31543

int testcase()
{
    uint32_t i, j, total;
    uint32_t x, n;
    uint32_t is[32] = {0};
    uint32_t totals[32] = {0};

    // Leo x y n 
    x = fio_parse_int() % MOD;
    n = fio_parse_int();

    if (x == 0 && n == 0)
        return 0;

    // Calculo las 32 partes primero 
    totals[1] = x, is[1] = 1;
    for (j = 2; j < 32; j++)
    {
        is[j] = is[j - 1] << 1;
        totals[j] = (totals[j - 1] * totals[j - 1]) % MOD;
    }

    // Luego vuelvo cogiendo el máximo posible siempre 
    total = 1; 
    i = 0;
    j = 31;
    for (; i < n;) 
    {
        if (is[j] + i > n) 
        {
            j--;
            continue;
        }
        else
        {
            i += is[j];
            total = (total * totals[j]) % MOD;
        }
    }

    printf("%d\n", total);

    return 1;
}

int main()
{
    while (testcase());
    return 0;
}

