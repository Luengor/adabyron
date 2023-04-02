#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ever (;;)

int main()
{
    // Por qué tenerlo todo aparte, cuando se puede hacer aquí
    uint16_t ncalles, nint, from, to;
    register uint16_t i;
    uint8_t *data = calloc(sizeof(uint8_t), 50);

    for ever    // me encanta esto
    {
        // Leo número de calles e intersecciones
        scanf("%hu\n", &ncalles);
        if (ncalles == 0)
            return 0;

        scanf("%hu\n", &nint);

        for (; ncalles > 0; ncalles--)
        {
            // Leo la calle
            scanf("%hu %hu\n", &from, &to);

            data[from - 1]++;
            data[to - 1]++;
        }

        // Compruebo que son todos pares o 2 impares
        ncalles = 0;
        for (i = 0; i < nint; i++)
        {
            ncalles += data[i] % 2;
            data[i] = 0;
        }

        if (ncalles == 0 || ncalles == 2)
            printf("SI\n");
        else
            printf("NO\n");
    }
}
