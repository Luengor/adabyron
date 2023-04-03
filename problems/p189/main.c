#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../../libs/darray.h"
#include "../../libs/fastio.h"

int testcase()
{
    uint32_t npasajeros, pasajero;
    uint32_t nops;
    char op;
    darray_t pasajeros;

    // Leer número de pasajeros
    npasajeros = fio_parse_int();

    // El caso 0 es fin
    if (npasajeros == 0)
        return 0;

    // Leo todos los pasajeros
    darray_init(&pasajeros);
    for (; npasajeros > 0; npasajeros--)
    {
        pasajero = fio_parse_int();
        darray_push(pasajero, &pasajeros);
    }

    // Leo número de operaciones
    nops = fio_parse_int();

    // Hago operaciones
    for (; nops > 0; nops--)
    {
        // Read op
        op = getchar_unlocked();
        fio_consume_nchars(8);
        pasajero = fio_parse_int();

        switch (op)
        {
            case 'E':
                // Embarque
                // Quito todos los pasajeros con ese número
                darray_del(pasajero, &pasajeros);

                // Imprimo los que quedan
                printf("%u\n", pasajeros.len);
                break;
        
            case 'C':
                // Consulta
                // Devuelvo el número que pida
                printf("%u\n", pasajeros.data[pasajero - 1]);
                break;
        }
    }

    fio_fast_print("*\n", 2);

    // Limpio
    darray_free(&pasajeros);
    return 1;
}

int main()
{
    while (testcase());
    return 0;
}

