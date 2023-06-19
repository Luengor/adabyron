#ifndef INCLUDE_FASTIO_H
#define INCLUDE_FASTIO_H

#include <stdio.h>
#include <stdint.h>

/*
 * Prints a CONSTANT string fast
 */
#define fio_print(_str, _size)    \
    fwrite_unlocked(_str, 1, _size, stdout)
    
/*
 * Reads an integer from stdin and consumes the next char
 */
int fio_parse_int(void);

#endif

