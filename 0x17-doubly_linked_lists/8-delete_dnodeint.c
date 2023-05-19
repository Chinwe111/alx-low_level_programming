#include "lists.h"
#include <stdlib.h>
/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 *
 * Return: 1 on success, -1 on failure
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *prnt;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	prnt = *head;
	if (index == 0)
	{
		*head = prnt->next;
		if (prnt->next != NULL)
		{
			prnt->next->prev = NULL;
		}
		free(prnt);
		return (1);
	}
	for (i = 0; i < index; i++)
	{
		if (prnt->next == NULL)
			return (-1);
		prnt = prnt->next;
	}
	prnt->prev->next = prnt->next;
	if (prnt->next != NULL)
		prnt->next->prev = prnt->prev;
	free(prnt);
	return (1);
}
