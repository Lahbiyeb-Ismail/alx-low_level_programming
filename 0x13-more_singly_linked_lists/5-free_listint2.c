#include "lists.h"

/**
 * free_listint2 - Entry point
 *
 * * @head: linked list head
 *
 * Description: Function that that frees a listint_t list.
 * The function sets the head to NULL
 *
 * Prototype: void free_listint2(listint_t *head);
 *
 * Return: Void
 *
 */

void free_listint2(listint_t **head)
{
	listint_t *curr_node;

	if (*head == NULL)
		return;

	while (*head)
	{
		curr_node = *head;
		*head = (*head)->next;
		free(curr_node);
	}

	head = NULL;
}
