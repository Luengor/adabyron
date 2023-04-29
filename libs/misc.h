#ifndef INCLUDE_MISC_H
#define INCLUDE_MISC_H

#define fast_swap(a, b)         \
    do {                        \
        (a) ^= (b);             \
        (b) ^= (a);             \
        (a) ^= (b);             \
    while (0)

#endif
