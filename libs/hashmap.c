#include "hashmap.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/// Static declarations 
static void hashmap_resizeifneeded(hashmap_t *);

/// Static definitions
static void hashmap_resizeifneeded(hashmap_t *map)
{
    float lf;
    hashmap_node_t **old_data = NULL, *node, *next;
    uint16_t old_size, i, new_bucket;

    // Calculate load factor
    lf = (float)map->entries / map->buckets;

    // Prepare this
    old_data = map->data;
    old_size = map->buckets;
    
    // Grow
    if (lf > HASHMAP_HIGH_LOADFACTOR) 
    {
        map->buckets *= HASHMAP_GROW_FACTOR;
        map->data = calloc(map->buckets, sizeof(hashmap_node_t*));
    }
    // Shrink
    else if (lf < HASHMAP_LOW_LOADFACTOR && map->buckets > HASHMAP_MIN_CAP)
    {
        map->buckets /= HASHMAP_GROW_FACTOR;
        map->data = calloc(map->buckets, sizeof(hashmap_node_t*));
    }
    else
        // Nothing
        return;

    // "Rehash"
    // (everything is already hashed)
    for (i = 0; i < old_size; i++)
    {
        for (next = old_data[i]; next != NULL; )
        {
            node = next;
            next = next->next;

            new_bucket = node->hash % map->buckets;
            node->next = map->data[new_bucket];
            map->data[new_bucket] = node;
        }
    }

    free(old_data);
}


/// Non-static definitions 
hash_t hash_function(byte *data, uint16_t data_size)
{
    uint16_t i;
    hash_t hash = FNV_offset_basis; 

    for (i = 0; i < data_size; i++)
    {
        hash = hash ^ data[i];
        hash = hash * FNV_prime;
    }

    return hash;
}

void hashmap_init(uint16_t key_size, uint16_t value_size, hashmap_t *map)
{
    map->key_size = key_size;
    map->value_size = value_size;
    map->buckets = HASHMAP_MIN_CAP;
    map->entries = 0;

    map->data = calloc(map->buckets, sizeof(hashmap_node_t*));
}

void hashmap_destroy(hashmap_t *map)
{
    int b;
    hashmap_node_t *node, *next;

    // Free every bucket first
    for (b = 0; b < map->buckets; b++)
    {
        next = map->data[b];
        while (next != NULL)
        {
            node = next;
            next = node->next;

            free(node->key);
            free(node->value);
            free(node);
        }
    }

    // Free the entire hasmap
    free(map->data);
    
    map->data = NULL;
    map->entries = 0;
    map->buckets = 0;
}

void hashmap_set(void *key, void *value, hashmap_t *map)
{
    hashmap_node_t *node;
    uint16_t bucket;

    // Grow if needed
    hashmap_resizeifneeded(map);

    // Create a node
    node = malloc(sizeof(hashmap_node_t));

    node->key = malloc(map->key_size);
    memcpy(node->key, key, map->key_size);

    node->value = malloc(map->value_size);
    memcpy(node->value, value, map->value_size);

    node->hash = hash_function(key, map->key_size);

    // Find bucket and add it
    bucket = node->hash % map->buckets;

    node->next = map->data[bucket];
    map->data[bucket] = node;

    // Update structure
    map->entries++;
}

bool hashmap_get(void *key, void *value, hashmap_t *map)
{
    uint16_t bucket;
    hashmap_node_t *node;

    // Get bucket 
    bucket = hash_function(key, map->key_size) % map->buckets;

    // Check if it is on the list
    for (node = map->data[bucket]; node != NULL; node = node->next)
    {
        if (!memcmp(node->key, key, map->key_size))
        {
            memcpy(value, node->value, map->value_size);
            return true;
        }
    }

    return false;
}

bool hashmap_pop(void *key, hashmap_t *map)
{
    uint16_t bucket;
    hashmap_node_t *node, *prev;

    // Get bucket 
    bucket = hash_function(key, map->key_size) % map->buckets;

    // Check if it is on the list
    for (prev = NULL, node = map->data[bucket]; node != NULL; 
            prev = node, node = node->next)
    {
        if (!memcmp(node->key, key, map->key_size))
        {
            // Remove it
            if (prev != NULL)
                prev->next = node->next;
            else
                map->data[bucket] = node->next;

            free(node->key);
            free(node->value);
            free(node);

            map->entries--;
            hashmap_resizeifneeded(map);
            return true;
        }
    }

    return false;
}

