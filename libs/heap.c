#include "heap.h"
#include <stdlib.h>
#include <string.h>

#define double_index(_i) (((_i) == 0) ? 1 : (_i) * 2)

/// Static declarations
static void heap_shift_up(int32_t index, heap_t *heap);
static void heap_shift_down(int32_t index, heap_t *heap);

/// Static definitions
static void heap_shift_up(int32_t i, heap_t *heap)
{
    heap_node_t node;

    for (node = heap->data[i];
         i > 0 && node.key < heap->data[i/2].key;
         heap->data[i] = heap->data[i/2], i /= 2);

    heap->data[i] = node;
}

static void heap_shift_down(int32_t i, heap_t *heap)
{
    heap_node_t node = heap->data[i];
    int32_t son;

    while (double_index(i) <= heap->len)
    {
        son = double_index(i);
        if (son + 1 <= heap->len &&
                heap->data[son + 1].key < heap->data[son].key)
            son++;

        if (node.key <= heap->data[son].key)
            break;

        heap->data[i] = heap->data[son];
        i = son;
    }


    heap->data[i] = node;
}

/// Everything else
void heap_init(uint32_t capacity, heap_t *heap)
{
    heap->capacity = (capacity == 0) ? HEAP_INIT_CAP : capacity;
    heap->len = 0;
    heap->data = malloc(sizeof(heap_node_t) * heap->capacity);
}

void heap_free(heap_t *heap)
{
    heap->capacity = 0;
    heap->len = 0;
    free(heap->data);
    heap->data = NULL;
}

bool heap_is_empty(heap_t *heap)
{
    return heap->len == 0;
}

heap_t *heapify(heap_key_t *array, uint32_t len)
{
    heap_t *heap = malloc(sizeof(heap_t));
    heap_init(len, heap);

    for (; len > 0; len--)
        heap_insert(array[len - 1], array[len - 1], heap);

    return heap;
}

void heap_sort(heap_key_t *array, uint32_t len)
{
    heap_t *heap;
    int32_t i;

    heap = heapify(array, len);

    for (i = 0; i < len; i++)
        array[i] = heap_popmin(heap).key; 

    heap_free(heap);
    free(heap);
}

heap_value_t heap_findmin(heap_t *heap)
{
    // Error checking who?

    return heap->data[0].value;
}

heap_node_t heap_popmin(heap_t *heap)
{
    heap_node_t n;

    // Error checking who?
    heap->len--;
    
    n = heap->data[0];
    heap->data[0].key = heap->data[heap->len].key;
    heap_shift_down(0, heap);

    return n;
}

void heap_insert(heap_value_t v, heap_key_t k, heap_t *heap)
{
    heap_node_t n = {.value = v, .key = k};
    heap_node_t *newpt;

    // Grow if needed
    if (heap->len == heap->capacity)
    {
        heap->capacity *= HEAP_GROW_FACTOR;

        newpt = malloc(sizeof(heap_node_t) * heap->capacity);
        memcpy(newpt, heap->data, sizeof(heap_node_t) * heap->len);
        free(heap->data);
        heap->data = newpt;
    }

    heap->data[heap->len] = n;
    heap->len++;
    heap_shift_up(heap->len-1, heap);
}

