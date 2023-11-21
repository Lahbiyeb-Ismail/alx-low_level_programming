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
	const listint_t *slow_ptr, *fast_ptr;
	int nodes_count = 0;

	if (!head)
		exit(98);

	slow_ptr = head;
	fast_ptr = head;


	while (slow_ptr && fast_ptr && fast_ptr->next && head)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if (slow_ptr == fast_ptr)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			exit(98);
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes_count++;
	}

	head = NULL;
	return (nodes_count);
}
