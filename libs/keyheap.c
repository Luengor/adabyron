#include "keyheap.h"
#include <stdlib.h>
#include <string.h>

#define double_index(_i) (((_i) == 0) ? 1 : (_i) * 2)

/// Static declarations
static void kheap_shift_up(int32_t index, kheap_t *heap);
static void kheap_shift_down(int32_t index, kheap_t *heap);

/// Static definitions
static void kheap_shift_up(int32_t i, kheap_t *heap)
{
    kheap_key_t key;

    for (key = heap->data[i];
         i > 0 && key < heap->data[i/2];
         heap->data[i] = heap->data[i/2], i /= 2);

    heap->data[i] = key;
}

static void kheap_shift_down(int32_t i, kheap_t *heap)
{
    kheap_key_t key = heap->data[i];
    int32_t son;

    while (double_index(i) <= heap->len)
    {
        son = double_index(i);
        if (son + 1 <= heap->len &&
                heap->data[son + 1] < heap->data[son])
            son++;

        if (key <= heap->data[son])
            break;

        heap->data[i] = heap->data[son];
        i = son;
    }


    heap->data[i] = key;
}

/// Everything else
void kheap_init(uint32_t capacity, kheap_t *heap)
{
    heap->capacity = (capacity == 0) ? KEYHEAP_INIT_CAP : capacity;
    heap->len = 0;
    heap->data = malloc(sizeof(kheap_key_t) * heap->capacity);
}

void kheap_free(kheap_t *heap)
{
    heap->capacity = 0;
    heap->len = 0;
    free(heap->data);
    heap->data = NULL;
}

bool kheap_is_empty(kheap_t *heap)
{
    return heap->len == 0;
}

kheap_t *kheapify(kheap_key_t *array, uint32_t len)
{
    kheap_t *heap = malloc(sizeof(kheap_t));
    kheap_init(len, heap);

    for (; heap->len < len;)
    {
        heap->len++;
        kheap_set_key(heap->len - 1, array[heap->len-1], heap);
    }

    return heap;
}

void kheap_sort(kheap_key_t *array, uint32_t len)
{
    kheap_t *heap;
    int32_t i;

    heap = kheapify(array, len);

    for (i = 0; i < len; i++)
        array[i] = kheap_popmin(heap); 

    kheap_free(heap);
    free(heap);
}

kheap_key_t kheap_findmin(kheap_t *heap)
{
    // Error checking who?

    return heap->data[0];
}

kheap_key_t kheap_popmin(kheap_t *heap)
{
    kheap_key_t n;

    // Error checking who?
    heap->len--;
    
    n = heap->data[0];
    heap->data[0] = heap->data[heap->len];
    kheap_shift_down(0, heap);

    return n;
}

void kheap_insert(kheap_key_t k, kheap_t *heap)
{
    kheap_key_t *newpt;

    // Grow if needed
    if (heap->len == heap->capacity)
    {
        heap->capacity *= KEYHEAP_GROW_FACTOR;

        newpt = malloc(sizeof(kheap_key_t) * heap->capacity);
        memcpy(newpt, heap->data, sizeof(kheap_key_t) * heap->len);
        free(heap->data);
        heap->data = newpt;
    }

    heap->data[heap->len] = k;
    heap->len++;
    kheap_shift_up(heap->len-1, heap);
}

void kheap_set_key(uint32_t index, kheap_key_t k, kheap_t *heap)
{
    if (heap->data[index] > k)
    {
        heap->data[index] = k;
        kheap_shift_up(index, heap);
    }
    else 
    {
        heap->data[index] = k;
        kheap_shift_down(index, heap);
    }

}

