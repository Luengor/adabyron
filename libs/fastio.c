#include "fastio.h"
#include <stdio.h>

int fio_parse_int()
{
    register int n, c;

    n = getchar_unlocked() - '0';
    while ((c = getchar_unlocked()) >= '0')
        n = 10 * n + c - '0';

    return n;
}
