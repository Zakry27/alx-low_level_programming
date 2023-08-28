#include "lists.h"

/**
 * add_nodeint - Adds a new node to the starting point of a linked list
 * @head: is the pointer to the first node in the list
 * @n: is the data to insert in that new node
 *
 * Return: is the pointer to the new node or NULL if it fails to do so
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
