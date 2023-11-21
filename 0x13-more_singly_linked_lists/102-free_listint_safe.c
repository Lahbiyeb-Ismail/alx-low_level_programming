#include "lists.h"

/**
 * free_list2 - Entry point
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

void free_list2(listp_t **head)
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
 * free_listint_safe - Entry point
 *
 * * @h: linked list head
 *
 * * Description: Function that frees a listint_t list.
 *
 * Prototype: size_t free_listint_safe(listint_t **h);
 *
 * The function sets the head to NULL
 *
 * * Return: the number of nodes in the list
 *
 */

size_t free_listint_safe(listint_t **h)
{
	size_t nodes_count = 0;
	listp_t *visited_node, *curr_node, *new_node;
	listint_t *current;

	visited_node = NULL;
	while (*h != NULL)
	{
		curr_node = malloc(sizeof(listp_t));

		if (curr_node == NULL)
			exit(98);

		curr_node->p = (void *)*h;
		curr_node->next = visited_node;
		visited_node = curr_node;

		new_node = visited_node;

		while (new_node->next != NULL)
		{
			new_node = new_node->next;
			if (*h == new_node->p)
			{
				*h = NULL;
				free_list2(&visited_node);
				return (nodes_count);
			}
		}

		current = *h;
		*h = (*h)->next;
		free(current);
		nodes_count++;
	}

	*h = NULL;
	free_list2(&visited_node);
	return (nodes_count);
}
