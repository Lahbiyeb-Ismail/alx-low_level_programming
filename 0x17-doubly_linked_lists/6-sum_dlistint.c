#include "lists.h"

/**
 * sum_dlistint - Entry point
 *
 *  * @head: doubly-linked list head
 *
 * Description: Function that returns the sum of all the data (n) of
 * a dlistint_t linked list.
 *
 * Prototype: int sum_dlistint(dlistint_t *head);
 *
 * Return: the sum of all the data (n), or NULL if the list is empty
 *
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *curr_node;

	if (!head)
		return (sum);

	curr_node = head;

	while (curr_node)
	{
		sum += curr_node->n;
		curr_node = curr_node->next;
	}

	return (sum);
}
