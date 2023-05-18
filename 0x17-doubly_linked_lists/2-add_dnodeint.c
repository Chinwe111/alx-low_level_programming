#include "lists.h"
#include <stdlib.h>
/**
 * add_dnodeint - adds a node to the beginning of a linked list
 * @head: double pointer to the beginning of the linked list
 * @n: integer
 *
 * Return: pointer to the new node, or NULL on failure
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head == NULL)
	{
		(*head)->prev = new;
		*head = new;
	}

	*head = new;
	return (new);
}
