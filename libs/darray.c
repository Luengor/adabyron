#include <stdlib.h>
#include <string.h>

#include "darray.h"


void darray_init(darray_t *darray)
{
    darray->len = 0;
    darray->capacity = INIT_DARRAY_CAP;
    darray->data = malloc(sizeof(value_t) * INIT_DARRAY_CAP);
}

void darray_free(darray_t *darray)
{
    darray->len = 0;
    darray->capacity = 0;
    free(darray->data);
    darray->data = NULL;
}

void darray_push(value_t value, darray_t *darray)
{
    value_t *newpt;

    // Grow if needed
    if (darray->len == darray->capacity)
    {
        darray->capacity *= GROW_FACTOR;

        newpt = malloc(sizeof(value_t) * darray->capacity);
        memcpy(newpt, darray->data, sizeof(value_t) * darray->len);
        free(darray->data);
        darray->data = newpt;

        // a "Acepta el reto" no le gusta realloc
        /*darray->data = realloc(darray->data, darray->capacity * sizeof(value_t));*/
    }
    
    // Add
    darray->data[darray->len] = value;
    darray->len++;
}

void darray_del(value_t value, darray_t *darray) 
{
    int32_t i, j;

    for (i = 0, j = 0; j < darray->len; i++, j++)
    {
        // Check if j is valid
        for (; j < darray->len; j++)
            if (darray->data[j] != value)
                break;

        if (j == darray->len)
            break;
        
        darray->data[i] = darray->data[j];
    }

    darray->len = i;
}

value_t darray_pop(uint32_t index, darray_t *darray)
{
    value_t v = darray->data[index];

    for (; index < darray->len; index++)
        darray->data[index] = darray->data[index + 1];

    darray->len--;
    return v;
}

