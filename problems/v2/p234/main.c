#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../../libs/fastio.h"
#include "../../libs/keyheap.h"

void test()
{
    uint32_t npilas, nvoltios, i, j, validas = 0;
    uint32_t *pilas;
    kheap_t heap;

    // Leo datos iniciales
    npilas = fio_parse_int();
    nvoltios = fio_parse_int(); 

    // Voy metiendo las pilas a un montículo para que salgan ordenadas luego 
    kheap_init(npilas, &heap);
    for (i = 0; i < npilas; i++)
        kheap_insert(fio_parse_int(), &heap);

    pilas = malloc(sizeof(uint32_t) * npilas); 
    for (i = 0; i < npilas; i++)
        pilas[i] = kheap_popmin(&heap);

    // Recorro el array con un puntero en cada extremo.
    // El puntero de la izquierda avanza siempre y el de la derecha solo cuando
    // una buena combinación de pilas se encuentre
    for (i = 0, j = npilas-1; i < j; i++)
    {
        if (pilas[i] + pilas[j] >= nvoltios)
        {
            validas++;
            j--;
        }
    }

    printf("%d\n", validas);

    // Libero las pilas
    kheap_free(&heap);
    free(pilas);
}

int main()
{
    uint16_t tests;

    for (tests = fio_parse_int(); tests > 0; test(), tests--);

    return 0;
}

