#include "fastio.h"

/*
 * Prints a CONSTANT string fast
 */
void fio_print(const char *str, size_t str_len)
{
    fwrite_unlocked(str, 1, str_len, stdout); 
}

/*
 * Reads a integer from stdin and consumes the next char
 */
int fio_parse_int(void)
{
    int n, c;

    n = getchar_unlocked() - '0';
    if (n == ('-' - '0')) n = -1;

    while ((c = getchar_unlocked()) >= '0')
        n = 10 * n + c - '0';

    return n;
}

int fio_parse_inteof(int *n)
{
    int c;

    c = getchar_unlocked();
    if (c == EOF)
    {
        *n = 0;
        return 1;
    }

    c -= '0';
    *n = (c == ('-' - '0') ? -1 : c);

    while ((c = getchar_unlocked()) >= '0')
        *n = 10 * *n + c - '0';

    return c == EOF;
}

/*
 * Consumes n chars from stdin
 */
void fio_consume_nchars(int n)
{
    for (; n > 0; n--)
        getchar_unlocked();
}

/*
 * Consumes chars until c is found and returns the length
 */
size_t fio_consume_until(char c)
{
    size_t count = 0;
    
    while (getchar_unlocked() != c)
        count++;

    return count;
}

