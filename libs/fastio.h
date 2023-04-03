#ifndef INCLUDE_FASTIO_H
#define INCLUDE_FASTIO_H

#include <stdio.h>

void fio_fast_print(const char *, size_t s);

int fio_parse_int();
void fio_consume_nchars(int n);
size_t fio_consume_until(char c);

#endif

