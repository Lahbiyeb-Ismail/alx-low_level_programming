#include "lists.h"

/**
 * add_nodeint_end - Entry point
 *
 * * @head: linked list head
 * * @n: new node to add
 *
 * Description: Function that adds a new node at the end of a
 * listint_t list.
 *
 * Prototype: listint_t *add_nodeint_end(listint_t **head, const int n);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *last_node;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;

		while (last_node->next)
			last_node = last_node->next;

		last_node->next = new_node;
	}

	return (last_node);
}
