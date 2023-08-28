#include "lists.h"

/**
 * find_listint_loop - It's used to find the loop in a linked list
 * @head: Is the linked list to search for
 *
 * Return: is the address of the node where the loop starts or NULL if it fails to do so
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (!head)
		return (NULL);

	while (slow && fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}

	return (NULL);
}
