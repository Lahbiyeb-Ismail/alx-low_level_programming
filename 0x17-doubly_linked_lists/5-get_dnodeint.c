#include "lists.h"

/**
 * get_dnodeint_at_index - Entry point
 *
 *  * @head: doubly-linked list head
 *  * @index: is the index of the node, starting from 0
 *
 * Description: Function that returns the nth node of a dlistint_t
 * linked list.
 *
 * Prototype: dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *curr_node = head;
	size_t len = 0;

	if (index == 0)
		return (head);

	while (curr_node)
	{
		if (len == index)
			return (curr_node);

		curr_node = curr_node->next;
		len++;
	}

	return (NULL);
}
