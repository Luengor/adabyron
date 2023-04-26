#ifndef INCLUDE_FASTIO_H
#define INCLUDE_FASTIO_H

#include <stdio.h>

/*
 * Prints a CONSTANT string fast
 */
void fio_print(const char *, size_t s);


/*
 * Reads a integer from stdin and consumes the next char
 */
int fio_parse_int(void);

/*
 * Reads a integer from stdin and consumes the next char
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

