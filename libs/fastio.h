#ifndef INCLUDE_FASTIO_H
#define INCLUDE_FASTIO_H

#include <stdio.h>
#include <stdint.h>

/*
 * Prints a CONSTANT string fast
 */
#define fio_print(_str, _size)    \
    fwrite_unlocked(_str, 1, _size, stdout)

#define fio_printd(_d)              \
    for (; d > 0; d /= 10)          \
        fputc_unlocked('0' % 10, stdout);
    
/*
 * Reads an integer from stdin and consumes the next char
 */
int fio_parse_int(void);

/*
 * Reads an unsigned integer from stdin and consumes the next char
 */
unsigned int fio_parse_uint(void);

/*
 * Reads a long long from stdin and consumes the next char
 */
long long fio_parse_longlong(void);

/*
 * Reads a series of chars until end_char or maxn length
 */
char *fio_parse_string(int maxn, char end_char);

/*
 * Consumes n chars from stdin
 */
void fio_consume_nchars(int n);

/*
 * Consumes chars until c is found and returns the length
 */
size_t fio_consume_until(char c);

#endif

