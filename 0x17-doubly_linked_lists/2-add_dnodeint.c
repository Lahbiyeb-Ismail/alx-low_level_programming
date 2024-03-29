#include "lists.h"

/**
 * add_dnodeint - Entry point
 *
 *  * @head: doubly-linked list head
 *  * @n: new doubly-linked list data
 *
 * Description: Function that adds a new node at the beginning of
 * a dlistint_t list.
 *
 * Prototype: dlistint_t *add_dnodeint(dlistint_t **head, const int n);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (!*head)
		new_node->next = NULL;
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}

	*head = new_node;
	return (*head);
}
