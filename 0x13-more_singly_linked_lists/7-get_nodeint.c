#include "lists.h"

/**
 * get_nodeint_at_index - returns the node located at a specific index in a linked list
 * @head: is the first node in the linked list
 * @index: is the index of the node to return
 *
 * Return: is the pointer to the node we're looking for or NULL if it fails
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
