#include "lists.h"

/**
 * dlistint_len - return num of elements in
 * double link list
 *
 * @h: head list
 * Return: number nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int cnt;

	cnt = 0;

	if (h == NULL)
		return (cnt);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		cnt++;
		h = h->next;
	}

	return (cnt);
}
