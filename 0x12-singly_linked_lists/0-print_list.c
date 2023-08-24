#include <stdio.h>
#include "lists.h"

/**
 *print_list - prints all items from the linked list
 *@h: Pointer to the 'list_t list' for printing
 *
 *Return: the number of the nodes printed
 */
size_t print_list(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		s++;
	}

	return (s);
}
