#include "lists.h"

/**
 * dlistint_len - Entry point
 *
 *  * @h: doubly-linked list head
 *
 * Description: Function that returns the number of elements in a
 * linked dlistint_t list.
 *
 * Prototype: size_t dlistint_len(const dlistint_t *h);
 *
 * Return: the number of elements in a linked dlistint_t list.
 *
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}

	return (len);
}

/**
 * delete_dnodeint_at_index - Entry point
 *
 *  * @head: doubly-linked list head
 *  * @index: is the index of the node that should be deleted
 *
 * Description: Function that deletes the node at index index of
 * a dlistint_t linked list.
 *
 * Prototype: int delete_dnodeint_at_index(dlistint_t **head,
 * unsigned int index);
 *
 * Return: 1 if it succeeded, -1 if it failed
 *
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int len = dlistint_len(*head);
	dlistint_t *curr_node = NULL, *tmp_node = NULL;

	if (!*head || index >= len)
		return (-1);

	tmp_node = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;

		free(tmp_node);
		return (1);
	}

	for (len = 0; len < index; len++)
		tmp_node = tmp_node->next;

	curr_node = tmp_node->prev;
	curr_node->next = tmp_node->next;

	if (tmp_node->next)
		tmp_node->next->prev = curr_node;

	free(tmp_node);
	return (1);
}
