#include "lists.h"

/**
 * reverse_listint - Entry point
 *
 * * @head: linked list head
 *
 * Description: Function that reverses a listint_t linked list.
 *
 * You are not allowed to use more than 1 loop.
 * You are not allowed to use malloc, free or arrays
 * You can only declare a maximum of two variables in your function
 *
 * Prototype: listint_t *reverse_listint(listint_t **head);
 *
 * Return: a pointer to the first node of the reversed list
 *
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *next_node = NULL, *prev_node = NULL;

	if (*head == NULL)
		return (NULL);

	while (*head)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}

	*head = prev_node;

	return (*head);
}
