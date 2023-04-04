#ifndef INCLUDE_KEYHEAP_H
#define INCLUDE_KEYHEAP_H

#include <stdint.h>
#include <stdbool.h>

#define KEYHEAP_INIT_CAP 8
#define KEYHEAP_GROW_FACTOR 2

#ifndef KEYHEAP_KEY_T
#define KEYHEAP_KEY_T
    typedef uint32_t kheap_key_t;
#endif

typedef struct {
    kheap_key_t *data;
    uint32_t capacity, len;
} kheap_t;


void kheap_init(uint32_t capacity, kheap_t *);
void kheap_free(kheap_t *);
bool kheap_is_empty(kheap_t *);
kheap_t *kheapify(kheap_key_t *array, uint32_t len);
void kheap_sort(kheap_key_t *array, uint32_t len);
kheap_key_t kheap_findmin(kheap_t *);
kheap_key_t kheap_popmin(kheap_t *);
void kheap_insert(kheap_key_t k, kheap_t *);
void kheap_set_key(uint32_t index, kheap_key_t k, kheap_t *);

#endif

