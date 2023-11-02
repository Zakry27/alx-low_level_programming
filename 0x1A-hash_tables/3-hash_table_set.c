#include "hash_tables.h"

/**
 * hash_table_set - Add/update element in hash table.
 * @ht: pointer to hash table.
 * @key: key to add - cannot be empty string.
 * @value: value associated with key.
 *
 * Return: failure - 0.
 *         Otherwise - 1.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new;
	char *values_copy;
	unsigned long int indec, z;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	values_copy = strdup(value);
	if (values_copy == NULL)
		return (0);

	indec = key_index((const unsigned char *)key, ht->size);
	for (z = indec; ht->array[z]; z++)
	{
		if (strcmp(ht->array[z]->key, key) == 0)
		{
			free(ht->array[z]->value);
			ht->array[z]->value = values_copy;
			return (1);
		}
	}

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(values_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = values_copy;
	new->next = ht->array[indec];
	ht->array[indec] = new;

	return (1);
}
