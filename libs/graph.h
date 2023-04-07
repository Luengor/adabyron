#ifndef INCLUDE_GRAPH_H
#define INCLUDE_GRAPH_H

#include <stdint.h>
#include <stdlib.h>

#define GRAPH_INIT_CAP 8
#define GRAPH_GROW_FACTOR 2

#define VERTEX_INIT_CAP 4
#define VERTEX_GROW_FACTOR 1.5

typedef struct {
    uint32_t vertex;
    int weight; 
} edge_t;

typedef struct {
    void *data;
    size_t data_size;

    edge_t *edges;
    size_t edges_len, edges_capacity;

    struct
    {
        int32_t distance;
        int prev_vertex;
        uint8_t reached;
    } info;

} vertex_t;

typedef struct {
    vertex_t *vertices;
    size_t len, capacity;
} graph_t;


void graph_init(graph_t *);
void graph_free(graph_t *);
//void graph_prepare(graph_t *);

void graph_print(graph_t *);

uint32_t graph_add_vertex(graph_t *);
void graph_remove_vertex(uint32_t v, graph_t *);
void *graph_get_vertex_data(uint32_t v, graph_t *);
void graph_set_vertex_data(void *data, size_t size, uint32_t v, graph_t *graph);

int graph_add_edge(uint32_t from, uint32_t to, uint32_t weight, graph_t *);
void graph_remove_edge(uint32_t from, uint32_t to, graph_t *);

void graph_bfs(uint32_t start_v, graph_t *);
void graph_dijkstra(uint32_t start_v, graph_t *);

#endif

