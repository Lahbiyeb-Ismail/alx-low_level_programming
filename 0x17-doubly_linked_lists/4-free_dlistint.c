#include "lists.h"

/**
 * free_dlistint - Entry point
 *
 * * @head: doubly-linked list head
 *
 * Description: Function that that frees a dlistint_t list.
 *
 * Prototype: void free_dlistint(listint_t *head);
 *
 * Return: Void
 *
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *curr_node;

	while ((curr_node = head) != NULL)
	{
		head = head->next;
		free(curr_node);
	}
}
