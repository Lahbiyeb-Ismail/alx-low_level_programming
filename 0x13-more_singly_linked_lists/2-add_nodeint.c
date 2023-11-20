#include "lists.h"

/**
 * add_nodeint - Entry point
 *
 * * @head: linked list head
 * * @n: new node to add
 *
 * Description: Function that adds a new node at the beginning of a
 * listint_t list.
 *
 * Prototype: listint_t *add_nodeint(listint_t **head, const int n);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */


listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;

	*head = new_node;

	return (*head);
}
