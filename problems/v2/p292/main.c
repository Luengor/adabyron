#include <stdio.h>
#include <stdlib.h>

#include "../../libs/fastio.h"
#include "../../libs/graph.h"

int testcase(void)
{
    graph_t grafo;
    int ncasas, ncaminos, i, oficina, npaquetes;
    uint32_t from, to, distancia, tmp;
    int *paquetes;

    // Leo cosas iniciales
    if (fio_parse_inteof(&ncasas))
        return 0;

    if (fio_parse_inteof(&ncaminos))
        return 0;

    // Creo el grafo 
    graph_init(&grafo);
    for (i = 0; i < ncasas; i++)
        graph_add_vertex(&grafo);

    for (i = 0; i < ncaminos; i++)
    {
        from = fio_parse_int() - 1;
        to = fio_parse_int() - 1;

        graph_add_edge(from, to, fio_parse_int(), &grafo);
    }

    // Leo los paquetes
    oficina = fio_parse_int() - 1; 
    npaquetes = fio_parse_int();

    paquetes = malloc(sizeof(*paquetes) * npaquetes);
    for (i = 0; i < npaquetes; i++)
        paquetes[i] = fio_parse_int() - 1;


    // Aquí viene
    distancia = 0;

    // Primero calculo la mejor distancia hacia los paquetes
    graph_dijkstra(oficina, &grafo); 
    for (i = 0; i < npaquetes; i++)
    {
        if (grafo.vertices[paquetes[i]].info.reached) 
        {
            distancia += grafo.vertices[paquetes[i]].info.distance;
        }
        else
        {
            printf("Imposible\n");
            graph_free(&grafo);
            free(paquetes);
            return 1;
        }
    }

    // Ahora calculamos la distancia de vuelta
    for (i = 0; i < npaquetes; i++)
    {
        tmp = graph_pathfind_dijkstra(paquetes[i], oficina, &grafo);

        if (tmp >= 0) 
        {
            distancia += tmp; 
        }
        else
        {
            printf("Imposible\n");
            graph_free(&grafo);
            free(paquetes);
            return 1;
        }
    }


    printf("%d\n", distancia);
    graph_free(&grafo);
    free(paquetes);

    return 1;
}

int main(void)
{
    while(testcase());
    return 0;
}

