#include "hash_tables.h"

/**
 * hash_table_delete - this deletes hash table.
 * @ht: pointer to hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *heads = ht;
	hash_node_t *nodes, *tmp;
	unsigned long int z;

	for (z = 0; z < ht->size; z++)
	{
		if (ht->array[z] != NULL)
		{
			nodes = ht->array[z];
			while (nodes != NULL)
			{
				tmp = nodes->next;
				free(nodes->key);
				free(nodes->value);
				free(nodes);
				nodes = tmp;
			}
		}
	}
	free(heads->array);
	free(heads);
}
