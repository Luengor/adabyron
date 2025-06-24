#include "fastio.h"

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

float fio_parse_float(void)
{
    float f = 0;
    int neg = 1;
    int c;

    c = getchar_unlocked();
    if (c == '-')
        neg = -1;
    else
        f = (c - '0');
    
    while ((c = getchar_unlocked()) >= '0')
        f = f * 10 + (c - '0');

    if (c != '.') return f * neg;

    int i = 1;
    while ((c = getchar_unlocked()) >= '0')
    {
        f = f * 10 + (c - '0');
        i *= 10;
    }
    
    return f / i * neg;
}

