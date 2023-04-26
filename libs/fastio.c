#include "fastio.h"
#include <stdlib.h>

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

/*
 * Reads a integer from stdin and consumes the next char
 */
long long fio_parse_longlong(void)
{
    long long n;
    int c;

    n = getchar_unlocked() - '0';
    if (n == ('-' - '0')) n = -1;

    while ((c = getchar_unlocked()) >= '0')
        n = 10 * n + c - '0';

    return n;
}

char *fio_parse_string(int maxn, char end_char)
{
    char *out = malloc(sizeof(char) * maxn);
    int i;

    out[end_char - 1] = 0;

    for (i = 0; i < maxn - 1; i++)
        if ((out[i] = getchar_unlocked()) == end_char)
        {
            out[i + 1] = 0;
            break;
        }
            
    return out;
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

