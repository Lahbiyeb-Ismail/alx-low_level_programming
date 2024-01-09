#include "lists.h"

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
	unsigned int len = 0;
	dlistint_t *curr_node = NULL;

	if (!*head)
		return (-1);


	if (index == 0)
	{
		*head = (*head)->next;
		return (1);
	}

	curr_node = *head;

	while (curr_node)
	{
		curr_node = curr_node->next;

		if (index - 1 == len)
		{
			curr_node->prev->next = curr_node->next;
			curr_node->next->prev = curr_node->prev;
			break;
		}

		len++;
	}

	free(curr_node);
	return (1);
}
