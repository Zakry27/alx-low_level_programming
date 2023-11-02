#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - the node of hash table
 * @key: key, string
 * key is unique in HashTable
 * @value: value corresponding to key
 * @next: The next node in the list is indicated by this pointer.
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - the hash table data structure
 * @size: size of array
 * @array: array of size @size
 * first node of linked list is pointed to by each cell in the array,
 * because our objective is to have HashTable use Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

/**
 * struct shash_node_s - Node of sorted hash table
 * @key: key, string
 * key is unique in HashTable
 * @value: value corresponding to key
 * @next: The next node in the list is indicated by this pointer.
 * @sprev: Pointer to previous element in linked list that has been sorted.
 * @snext: Pointer to next element in linked list that has been sorted.
 */
typedef struct shash_node_s
{
	char *key;
	char *value;
	struct shash_node_s *next;
	struct shash_node_s *sprev;
	struct shash_node_s *snext;
} shash_node_t;

/**
 * struct shash_table_s - the sorted hash table data structure
 * @size: size of array
 * @array: array of size @size
 * first node of linked list is pointed to by each cell in the array,
 * because we want HashTable to use Chaining collision handling
 * @shead: Pointer to initial element in linked list that has been sorted.
 * @stail: Pointer to last element in linked list that has been sorted.
 */
typedef struct shash_table_s
{
	unsigned long int size;
	shash_node_t **array;
	shash_node_t *shead;
	shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

#endif /* HASH_TABLES_H */
