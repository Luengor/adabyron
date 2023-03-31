#include <stdlib.h>
#include <stdint.h>

// Declarations
#define INIT_DARRAY_CAP 8
#define GROW_FACTOR 2

typedef uint32_t value_t;
typedef struct {
    value_t *data;
    uint32_t len, capacity;
} darray_t;

void darray_init(darray_t *);
void darray_free(darray_t *);
void darray_push(value_t value, darray_t *);
void darray_del(value_t value, darray_t *); 

// Definitions
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

        // Maybe it dislikes malloc?
        newpt = malloc(sizeof(value_t) * darray->capacity);
        memcpy(newpt, darray->data, sizeof(value_t) * darray->len);
        free(darray->data);
        darray->data = newpt;

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

    /*for (i = darray->len - 1; i >= 0; i--)*/
        /*if (darray->data[i] == value)*/
        /*{*/
            /*darray->len--;*/
            /*for (j = i; j < darray->len; j++)*/
                /*darray->data[j] = darray->data[j + 1];*/
        /*}*/
}


