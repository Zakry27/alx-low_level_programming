#include "hash_tables.h"

/**
 * hash_table_get - this retrieves value associated with
 *                  key in hash table.
 * @ht: pointer to hash table.
 * @key: key to get the value of.
 *
 * Return: If key cannot be matched - NULL.
 *         Otherwise - value associated with key in ht.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *nodes;
	unsigned long int indec;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	indec = key_index((const unsigned char *)key, ht->size);
	if (indec >= ht->size)
		return (NULL);

	nodes = ht->array[indec];
	while (nodes && strcmp(nodes->key, key) != 0)
		nodes = nodes->next;

	return ((nodes == NULL) ? NULL : nodes->value);
}
