#include "lists.h"

/**
 * free_listint - it frees a linked list
 * @head: listint_t list thet will be freed
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
