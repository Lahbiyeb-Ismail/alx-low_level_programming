#include "lists.h"

/**
 * sum_listint - Entry point
 *
 * * @head: linked list head
 *
 * Description: Function that returns the sum of all the data (n) of a
 * listint_t
 * linked list.
 *
 * Prototype: int sum_listint(listint_t *head);
 *
 * Return: the sum of all the data (n) or (0) if the list is empty
 *
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *curr_node;

	if (!head)
		return (sum);

	curr_node = head;

	while (curr_node->next)
	{
		curr_node = curr_node->next;
		sum += curr_node->n;
	}

	return (sum);
}
