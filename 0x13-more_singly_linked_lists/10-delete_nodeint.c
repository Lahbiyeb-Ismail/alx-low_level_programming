#include "lists.h"

/**
 * delete_nodeint_at_index - Entry point
 *
 * * @head: linked list head
 * * @index: is the index of the node that should be deleted,
 * starting at 0
 *
 * Description: Function that deletes the node at index index of a
 * listint_t linked list.
 *
 *
 * Prototype:
 * int delete_nodeint_at_index(listint_t **head, unsigned int index);
 *
 *
 * Return: 1 if it succeeded, -1 if it failed
 *
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *curr_node, *prev_node;
	unsigned int i = 0;

	/* Check if the list is empty */
	if (*head == NULL)
		return (-1);

	curr_node = *head;
	prev_node = *head;

	/* Check if the given index == 0 */
	if (index == 0)
	{
		*head = (*head)->next;
	}
	else
	{
		/* Traverse the list to the node before the one to be deleted */
		while (i < index && curr_node)
		{
			prev_node = curr_node;
			curr_node = curr_node->next;
			i++;
		}

		/* Index out of bounds */
		if (!curr_node)
			return (-1);

		/* Update the pointers to bypass the node to be deleted */
		prev_node->next = curr_node->next;
	}

	/* Free the memory of the deleted node */
	free(curr_node);
	return (1);
}
