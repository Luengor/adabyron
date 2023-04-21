#ifndef INCLUDE_HASHMAP_H
#define INCLUDE_HASHMAP_H

#include <stdint.h>
#include <stdbool.h>

#define HASHMAP_GROW_FACTOR 2
#define HASHMAP_MIN_CAP 32 
#define HASHMAP_HIGH_LOADFACTOR 0.7
#define HASHMAP_LOW_LOADFACTOR (HASHMAP_HIGH_LOADFACTOR / 4)

#define FNV_offset_basis 0x811c9dc5
#define FNV_prime 0x01000193

typedef uint32_t hash_t; 
typedef unsigned char byte; 

typedef struct hashmap_node_t {
    void *key;
    void *value;
    hash_t hash;

    struct hashmap_node_t *next;
} hashmap_node_t;

typedef struct {
    hashmap_node_t **data;
    uint16_t entries, buckets;
    uint16_t key_size, value_size;

    //hash_t (*hash_function)(void *);
} hashmap_t;


/*
 * FNV-1a 32bit hash function
 */
hash_t hash_function(byte *data, uint16_t data_size);

void hashmap_init(uint16_t key_size, uint16_t value_size, hashmap_t *);
void hashmap_destroy(hashmap_t *);

void hashmap_set(void *key, void *value, hashmap_t *);
bool hashmap_get(void *key, void *value, hashmap_t *);
bool hashmap_pop(void *key, hashmap_t *map);

#endif

