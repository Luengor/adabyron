#ifndef INCLUDE_DARRAY_H 
#define INCLUDE_DARRAY_H

#include <stdint.h>


#define INIT_DARRAY_CAP 8
#define GROW_FACTOR 2

#ifndef DEFINED_VALUE_T
#define DEFINED_VALUE_T
    typedef uint32_t value_t;
#endif

typedef struct {
    value_t *data;
    uint32_t len, capacity;
} darray_t;

void darray_init(darray_t *);
void darray_free(darray_t *);
void darray_push(value_t value, darray_t *);
void darray_del(value_t value, darray_t *); 

#endif
