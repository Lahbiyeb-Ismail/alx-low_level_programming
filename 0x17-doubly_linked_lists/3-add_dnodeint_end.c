#include "lists.h"

/**
 * dlistint_t *add_dnodeint_end - Entry point
 *
 *  * @head: doubly-linked list head
 *  * @n: new doubly-linked list data
 *
 * Description: Function that adds a new node at the end of
 * a dlistint_t list.
 *
 * Prototype: dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *last_node;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if ((*head) == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		last_node = *head;

		while (last_node->next)
			last_node = last_node->next;

		new_node->prev = last_node;
		last_node->next = new_node;
	}

	return (new_node);
}
