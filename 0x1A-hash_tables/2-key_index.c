#include "hash_tables.h"

/**
 * key_index - Get index where key/value
 *      pair should be stored in array of the hash table.
 * @key: key to get index of.
 * @size: hash table array size. 
 *
 * Return: index of key.
 * Description: this uses djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
