#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - this creates sorted hash table.
 * @size: size of new sorted hash table.
 *
 * Return: If error - NULL.
 *         Otherwise - pointer to new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int z;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (z = 0; z < size; z++)
		ht->array[z] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - this adds element to sorted hash table.
 * @ht: pointer to a hash table that is sorted.
 * @key: key to add - cannot be empty string.
 * @value: value associated with key.
 *
 * Return: failure - 0.
 *         Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *news, *tmp;
	char *values_copy;
	unsigned long int indec;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	values_copy = strdup(value);
	if (values_copy == NULL)
		return (0);

	indec = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = values_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	news = malloc(sizeof(shash_node_t));
	if (news == NULL)
	{
		free(values_copy);
		return (0);
	}
	news->key = strdup(key);
	if (news->key == NULL)
	{
		free(values_copy);
		free(news);
		return (0);
	}
	news->value = values_copy;
	news->next = ht->array[indec];
	ht->array[indec] = news;

	if (ht->shead == NULL)
	{
		news->sprev = NULL;
		news->snext = NULL;
		ht->shead = news;
		ht->stail = news;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		news->sprev = NULL;
		news->snext = ht->shead;
		ht->shead->sprev = news;
		ht->shead = news;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		news->sprev = tmp;
		news->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = news;
		else
			tmp->snext->sprev = news;
		tmp->snext = news;
	}

	return (1);
}

/**
 * shash_table_get - this retrieves value associated with
 *                   key in sorted hash table.
 * @ht: pointer to a hash table that is sorted.
 * @key: key to get value from.
 *
 * Return: If key can't be matched - NULL.
 *         Otherwise - value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *nodes;
	unsigned long int indec;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	indec = key_index((const unsigned char *)key, ht->size);
	if (indec >= ht->size)
		return (NULL);

	nodes = ht->shead;
	while (nodes != NULL && strcmp(nodes->key, key) != 0)
		nodes = nodes->snext;

	return ((nodes == NULL) ? NULL : nodes->value);
}

/**
 * shash_table_print - this prints sorted hash table in order.
 * @ht: pointer to a hash table that is sorted.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *nodes;

	if (ht == NULL)
		return;

	nodes = ht->shead;
	printf("{");
	while (nodes != NULL)
	{
		printf("'%s': '%s'", nodes->key, nodes->value);
		nodes = nodes->snext;
		if (nodes != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - this prints sorted hash table in reverse order.
 * @ht: pointer to a hash table that is sorted to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *nodes;

	if (ht == NULL)
		return;

	nodes = ht->stail;
	printf("{");
	while (nodes != NULL)
	{
		printf("'%s': '%s'", nodes->key, nodes->value);
		nodes = nodes->sprev;
		if (nodes != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - this deletes sorted hash table.
 * @ht: pointer to a hash table that is sorted.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *heads = ht;
	shash_node_t *nodes, *tmp;

	if (ht == NULL)
		return;

	nodes = ht->shead;
	while (nodes)
	{
		tmp = nodes->snext;
		free(nodes->key);
		free(nodes->value);
		free(nodes);
		nodes = tmp;
	}

	free(heads->array);
	free(heads);
}
