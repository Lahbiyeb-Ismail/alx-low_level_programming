#include "lists.h"

/**
 * free_list - Entry point
 *
 * * @head: A pointer to the head of the list.
 *
 * * Description:
 * This function takes a pointer to the head of a linked list and frees
 * the memory allocated for each node in the list. It sets the head
 * pointer to NULL after freeing the entire list.
 *
 * * Return: Void
 */

void free_list(listp_t **head)
{
	listp_t *curr_node, *next_node;

	if (head != NULL)
	{
		curr_node = *head;
		while ((next_node = curr_node) != NULL)
		{
			curr_node = curr_node->next;
			free(next_node);
		}
		*head = NULL;
	}
}

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
	size_t nodes_count = 0;
	listp_t *visited_node, *curr_node, *new_node;

	visited_node = NULL;
	while (head != NULL)
	{
		curr_node = malloc(sizeof(listp_t));

		if (curr_node == NULL)
			exit(98);

		curr_node->p = (void *)head;
		curr_node->next = visited_node;
		visited_node = curr_node;

		new_node = visited_node;

		while (new_node->next != NULL)
		{
			new_node = new_node->next;
			if (head == new_node->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_list(&visited_node);
				return (nodes_count);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes_count++;
	}

	free_list(&visited_node);
	return (nodes_count);
}
