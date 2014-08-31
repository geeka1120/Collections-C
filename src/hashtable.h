/*
 * Collections-C
 * Copyright (C) 2013-2014 Srđan Panić <srdja.panic@gmail.com>
 *
 * This file is part of Collections-C.
 *
 * Collections-C is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Collections-C is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Collections-C. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "list.h"

#define KEY_LENGTH_VARIABLE  -1
#define KEY_LENGTH_DOUBLE    sizeof(double)
#define KEY_LENGTH_FLOAT     sizeof(float)
#define KEY_LENGTH_INT       sizeof(int)
#define KEY_LENGTH_CHAR      sizeof(char)
#define KEY_LENGTH_SHORT     sizeof(short)
#define KEY_LENGHT_LONG      sizeof(long)
#define KEY_LENGTH_POINTER   sizeof(void*)

#define hashtable_string_hash  STRING_HASH
#define hashtable_murmur_hash3 GENERAL_HASH

#define hashtable_string_key_cmp  CMP_STRING
#define hashtable_float_key_cmp   CMP_FLOAT
#define hashtable_char_key_cmp    CMP_CHAR
#define hasthable_short_key_cmp   CMP_SHORT
#define hashtable_long_key_cmp    CMP_LONG
#define hashtable_double_key_cmp  CMP_DOUBLE
#define hashtable_int_key_cmp     CMP_INT
#define hashtable_pointer_key_cmp CMP_POINTER

typedef struct hashtable_s HashTable;
typedef struct hashtable_key_iter HashTableIter;

typedef struct hashtable_init_properties_s {
    float    load_factor;
    uint32_t initial_capacity;
    int      key_length;
    uint32_t hash_seed;

    uint32_t (*hash)        (const void *key, int l, uint32_t seed);
    bool     (*key_compare) (void *key1, void *key2);
} HashTableProperties;

HashTableProperties *hashtable_properties_new();
HashTable *hashtable_new(HashTableProperties *properties);

void hashtable_properties_destroy(HashTableProperties *properties);
void hashtable_destroy(HashTable *table);

void hashtable_put(HashTable *table, void *key, void *val);
void *hashtable_get(HashTable *table, void *key);
void *hashtable_remove(HashTable *table, void *key);
void hashtable_remove_all(HashTable *table);

bool hashtable_contains_key(HashTable *table, void *key);

List *hashtable_get_keys(HashTable *table);
List *hashtable_get_values(HashTable *table);

bool hashtable_string_key_cmp(void *key1, void *key2);
bool hashtable_float_key_cmp(void *key1, void *key2);
bool hashtable_char_key_cmp(void *key1, void *key2);
bool hasthable_short_key_cmp(void *key1, void *key2);
bool hashtable_double_key_cmp(void *key1, void *key2);
bool hashtable_int_key_cmp(void *key1, void *key2);
bool hashtable_long_key_cmp(void *key1, void *key2);
bool hashtable_pointer_key_cmp(void *key1, void *key2);

uint32_t hashtable_hash_string(const void *key, int len, uint32_t seed);
uint32_t hashtable_murmur_hash3(const void *key, int len, uint32_t seed);

HashTableIter *hashtable_iter_new(HashTable *table);
bool hashtable_iter_hash_next(HashTableIter *iter);
void hashtable_iter_next(HashTableIter *iter);
void const *hashtable_iter_get_key(HashTableIter *iter);
void *hashtable_iter_get_value(HashTableIter *iter);
void hashtable_iter_remove(HashTableIter *iter);

#endif /* HASHMAP_H_ */
