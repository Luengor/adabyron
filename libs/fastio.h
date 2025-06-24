#pragma once
#include <stdio.h>
#include <stdint.h>

/*
 * Prints a CONSTANT string fast
 */
#define fio_print(_str, _size)    \
    fwrite_unlocked(_str, 1, _size, stdout)

#define fio_get_char() getchar_unlocked()
    
/*
 * Reads an integer from stdin and consumes the next char
 */
int fio_parse_int(void);
    
/*
 * Reads a float from stdin and consumes the next char
 */
float fio_parse_float(void);

