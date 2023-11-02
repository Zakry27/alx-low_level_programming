#include "hash_tables.h"

/**
 * hash_table_print -  it prints hash table.
 * @ht: pointer to hash table to print.
 *
 * Description: Key/value pairs are printed in order
 *              they show up in array of hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *nodes;
	unsigned long int z;
	unsigned char comma_flags = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (z = 0; z < ht->size; z++)
	{
		if (ht->array[z] != NULL)
		{
			if (comma_flags == 1)
				printf(", ");

			nodes = ht->array[z];
			while (nodes != NULL)
			{
				printf("'%s': '%s'", nodes->key, nodes->value);
				nodes = nodes->next;
				if (nodes != NULL)
					printf(", ");
			}
			comma_flags = 1;
		}
	}
	printf("}\n");
}
