#include <stdint.h>
#include <string.h>
#include <stdio.h>

#include "graph.h"
#include "heap.h"

/*
 * Prepares the graph for algorithms like bfs
 */
static void graph_prepare(graph_t *graph)
{
    // Set the distance of each vertex to infinite 
    // Set the prev_vertex of each vertex to -1
    // Set reached to 0
    int i;
    for (i = 0; i < graph->len; i++) 
    {
        graph->vertices[i].info.distance = INT32_MAX; 
        graph->vertices[i].info.prev_vertex = -1; 
        graph->vertices[i].info.reached = 0; 
    }
}

/*
 * Inits the graph
 */
void graph_init(graph_t *graph)
{
    graph->capacity = GRAPH_INIT_CAP;
    graph->len = 0;
    graph->vertices = malloc(sizeof(vertex_t) * graph->capacity);

    graph_prepare(graph);
}

/*
 * Free the graph 
 */
void graph_free(graph_t *graph)
{
    // Free each vertex, then the graph itself
    for (;graph->len > 0; graph->len--)
    {
        if (graph->vertices[graph->len - 1].data_size)
            free(graph->vertices[graph->len - 1].data);
        free(graph->vertices[graph->len - 1].edges);
    }

    free(graph->vertices);
    graph->vertices = NULL;
    graph->capacity = 0;
    graph->len = 0;
}


void graph_print(graph_t *graph)
{
#define vinfo graph->vertices[v].info
    int v, e;

    printf("      |     reach     |     dist     |     prev     | conections\n");

    for (v = 0; v < graph->len; v++)
    {
        printf("v: %2d | %13d | %12d | %12d | ", 
                v, vinfo.reached, vinfo.distance, vinfo.prev_vertex);
        
        for (e = 0; e < graph->vertices[v].edges_len; e++)
        {
            printf("(%2d %2d) ", 
                    graph->vertices[v].edges[e].vertex, graph->vertices[v].edges[e].weight);
        }
        printf("\n");
    }
    printf("\n");
#undef vinfo
}


uint32_t graph_add_vertex(graph_t *graph)
{
    vertex_t *newpt;

    // Grow if needed
    if (graph->len == graph->capacity)
    {
        graph->capacity *= GRAPH_GROW_FACTOR;

        newpt = malloc(sizeof(vertex_t) * graph->capacity);
        memcpy(newpt, graph->vertices, sizeof(vertex_t) * graph->len);
        free(graph->vertices);
        graph->vertices= newpt;
    }

    // Init vertex
    graph->vertices[graph->len] = (vertex_t){
        .data = NULL,
        .data_size = 0,
        .edges = malloc(sizeof(edge_t) * VERTEX_INIT_CAP),
        .edges_len = 0,
        .edges_capacity = VERTEX_INIT_CAP
    };

    graph->len++;
    return graph->len - 1;
}

void graph_remove_vertex(uint32_t v, graph_t *graph)
{
    // TODO
}

void *graph_get_vertex_data(uint32_t v, graph_t *graph)
{
    // TODO
    return NULL;
}

/*
 * This WILL COPY the value to the graph
 */
void graph_set_vertex_data(void *data, size_t size, uint32_t v, graph_t *graph)
{
    graph->vertices[v].data = malloc(size);
    memcpy(graph->vertices[v].data, data, size);
}


int graph_add_edge(uint32_t from, uint32_t to, uint32_t weight, graph_t *graph)
{
#define fromvertex graph->vertices[from]

    // Grow if needed
    edge_t *newpt;

    if (from >= graph->len || to >= graph->len)
        return 1;

    // Grow if needed
    if (fromvertex.edges_len == fromvertex.edges_capacity)
    {
        fromvertex.edges_capacity = (int)
            (fromvertex.edges_capacity * VERTEX_GROW_FACTOR);

        newpt = malloc(sizeof(edge_t) * fromvertex.edges_capacity);
        memcpy(newpt, fromvertex.edges, sizeof(edge_t) * fromvertex.edges_len);
        free(fromvertex.edges);
        fromvertex.edges = newpt;
    }

    // Add the edge
    fromvertex.edges[fromvertex.edges_len] = (edge_t){
        .vertex = to, .weight = weight
    };

    fromvertex.edges_len++;

    return 0;
    
#undef fromvertex
}

void graph_remove_edge(uint32_t from, uint32_t to, graph_t *graph)
{
    // TODO
}

void graph_bfs(uint32_t start_v, graph_t *graph)
{
    // TODO
}

void graph_dijkstra(uint32_t start_v, graph_t *graph)
{
#define edge_i graph->vertices[v].edges[i]
#define gvertices graph->vertices

    heap_t heap;
    uint32_t v, w, i;
    heap_node_t n;

    // Prepare the tree
    graph_prepare(graph);
    graph->vertices[start_v].info.distance = 0;

    // Init the heap
    heap_init(0, &heap);
    heap_insert(start_v, 0, &heap);

    while (heap.len > 0)
    {
        // Get the vertex with the smallest distance
        n = heap_popmin(&heap);
        v = n.value;

        // If its already reached, skip it 
        if (gvertices[v].info.reached)
            continue;

        // Reach it
        gvertices[v].info.reached = 1;

        // Get all children not yet reached and push them into the heap
        for (i = 0; i < gvertices[v].edges_len; i++)
        {
            w = edge_i.vertex;

            // Skip it if its already visited
            if (gvertices[w].info.reached)
                continue;
            
            // Only add it if we have a smaller distance
            if (gvertices[v].info.distance + edge_i.weight <
                    gvertices[w].info.distance)
            {
                gvertices[w].info.distance =
                    gvertices[v].info.distance + edge_i.weight;
                gvertices[w].info.prev_vertex = v;

                // Add it to the heap
                heap_insert(w, gvertices[w].info.distance, &heap);
            }
        }
    }

    // Free the heap
    heap_free(&heap);
    
#undef edge_i
#undef gvertices
}

