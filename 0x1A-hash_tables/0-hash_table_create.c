#include "hash_tables.h"

/**
 * hash_table_create - it create hash table.
 * @size: size of array.
 *
 * Return: If error - NULL.
 *         Otherwise - pointer to new hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *htb;
	unsigned long int z;

	htb = malloc(sizeof(hash_table_t));
	if (htb == NULL)
		return (NULL);

	htb->size = size;
	htb->array = malloc(sizeof(hash_node_t *) * size);
	if (htb->array == NULL)
		return (NULL);
	for (z = 0; z < size; z++)
		htb->array[z] = NULL;

	return (htb);
}
