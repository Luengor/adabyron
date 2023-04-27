#include <stdio.h>
#include <stdlib.h>

#include "../../libs/fastio.h"

int testcase()
{
    int gente;
    int i, ninos, ninos_extra, nino_mas_alto, nino_extra_mas_alto, nino;

    // Leo número de personas
    gente = fio_parse_int();

    if (!gente) return 0;

    // Hacer cosas
    ninos_extra = 0;
    ninos = 1;
    nino_mas_alto = fio_parse_int();
    nino_extra_mas_alto = nino_mas_alto;
    for (i = 1; i < gente; i++)
    {
        nino = fio_parse_int();

        if (nino <= nino_mas_alto)
        {
            if (ninos_extra)
            {
                nino_mas_alto = nino_extra_mas_alto;
                ninos += ninos_extra;
                ninos_extra = 0;
            }
            ninos++;
        }
        else
        {
            ninos_extra++;
            if (nino >= nino_extra_mas_alto)
                nino_extra_mas_alto = nino;
        }
    }

    printf("%d\n", ninos);

    return 1;
}

int main()
{
    while (testcase());
    return 0;
}

