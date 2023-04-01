#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Dynamic arrays'==>
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
/*<=='*/

int testcase()
{
    uint32_t npasajeros, pasajero;
    uint32_t nops;
    char op;
    darray_t pasajeros;

    // Leer número de pasajeros
    scanf("%u\n", &npasajeros);

    // El caso 0 es fin
    if (npasajeros == 0)
        return 0;

    // Leo todos los pasajeros
    darray_init(&pasajeros);
    for (; npasajeros > 0; npasajeros--)
    {
        scanf("%u%*c", &pasajero);
        darray_push(pasajero, &pasajeros);
    }

    // Leo número de operaciones
    scanf("%u\n", &nops);

    // Hago operaciones
    for (; nops > 0; nops--)
    {
        // Read op
        scanf("%c", &op);

        switch (op)
        {
            case 'E':
                // Embarque
                scanf("MBARQUE %u\n", &pasajero);

                // Quito todos los pasajeros con ese número
                darray_del(pasajero, &pasajeros);

                // Imprimo los que quedan
                printf("%u\n", pasajeros.len);
                break;
        
            case 'C':
                // Consulta
                scanf("ONSULTA %u\n", &pasajero);

                // Devuelvo el número que pida
                printf("%u\n", pasajeros.data[pasajero - 1]);
                break;
        }
    }

    printf("*\n");

    // Limpio
    darray_free(&pasajeros);
    return 1;
}

int main()
{
    while (testcase());
    return 0;
}

// Darrays again'==>
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
}
/*<=='*/

