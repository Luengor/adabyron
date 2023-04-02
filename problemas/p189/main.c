#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "../../libs/darray.h"

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

