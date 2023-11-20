#include "lists.h"

/**
 * free_listint - Entry point
 *
 * * @head: linked list head
 *
 * Description: Function that that frees a listint_t list.
 *
 * Prototype: void free_listint(listint_t *head);
 *
 * Return: Void
 *
 */

void free_listint(listint_t *head)
{
	listint_t *curr_node;

	while ((curr_node = head) != NULL)
	{
		head = head->next;
		free(curr_node);
	}
}
