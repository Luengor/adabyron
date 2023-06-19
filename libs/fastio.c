#include "fastio.h"
#include <stdlib.h>

/// Read
int fio_parse_int(void)
{
    int n, c;

    n = getchar_unlocked() - '0';
    if (n == ('-' - '0')) n = -1;

    while ((c = getchar_unlocked()) >= '0')
        n = 10 * n + c - '0';

    return n;
}

