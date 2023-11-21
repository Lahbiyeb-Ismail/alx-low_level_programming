#include "lists.h"

/**
 * print_listint_safe - Entry point
 *
 * * @head: linked list head
 *
 * Description: Function that prints a listint_t linked list.
 *
 * Prototype: size_t print_listint_safe(const listint_t *head);
 *
 * If the function fails, exit the program with status 98
 *
 * Return: the number of nodes in the list
 *
 */

size_t print_listint_safe(const listint_t *head)
{
	int i = 0;

	if (!head)
		exit(98);

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		i++;
	}

	return (i);
}
