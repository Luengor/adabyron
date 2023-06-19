#include "fastio.h"
#include <stdlib.h>

/// Read
int fio_parse_int(void)
{
    int n, c;
    int neg = 1;

    n = getchar_unlocked();
    if (n == '-')
    {
        neg = -1;
        n = 0;
    }
    else
    {
        n -= '0';
    }
    
    while ((c = getchar_unlocked()) >= '0')
        n = 10 * n + c - '0';

    return n * neg;
}

