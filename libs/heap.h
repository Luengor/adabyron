#ifndef INCLUDE_HEAP_H
#define INCLUDE_HEAP_H

#include <stdint.h>
#include <stdbool.h>

#define HEAP_INIT_CAP 8
#define HEAP_GROW_FACTOR 2

#ifndef HEAP_VALUE_T
#define HEAP_VALUE_T
    typedef uint32_t heap_value_t;
#endif

#ifndef HEAP_KEY_T
#define HEAP_KEY_T
    typedef uint32_t heap_key_t;
#endif

typedef struct {
    heap_key_t key;
    heap_value_t value;
} heap_node_t;

typedef struct {
    heap_node_t *data;
    uint32_t capacity, len;
} heap_t;


void heap_init(uint32_t capacity, heap_t *);
void heap_free(heap_t *);
bool heap_is_empty(heap_t *);
heap_t *heapify(heap_key_t *array, uint32_t len);
void heap_sort(heap_key_t *array, uint32_t len);
heap_value_t heap_findmin(heap_t *);
heap_node_t heap_popmin(heap_t *);
void heap_insert(heap_value_t v, heap_key_t k, heap_t *);
void heap_modify_key(heap_key_t k, heap_t *);

#endif

