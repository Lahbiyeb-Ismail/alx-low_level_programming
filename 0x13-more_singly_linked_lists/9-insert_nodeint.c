#include "lists.h"

/**
 * insert_nodeint_at_index - Entry point
 *
 * * @head: linked list head
 * * @idx: is the index of the list where the new node should be added,
 * starting at 0
 * * @n: new node value
 *
 * Description: Function that inserts a new node at a given position.
 *
 * if the node does not exist, return NULL
 *
 * Prototype:
 * insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);
 *
 * if it is not possible to add the new node at index idx, do not add the
 * new node and return NULL
 *
 * Return: the address of the new node, or NULL if it failed
 *
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *curr_node, *new_node;
	unsigned int i = 0;

	if (*head == NULL && idx != 0)
		return (NULL);

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		curr_node = *head;

		while (i < idx - 1 && curr_node)
		{
			curr_node = curr_node->next;
			i++;
		}

		/* Index out of bound */
		if (!curr_node)
		{
			free(new_node);
			return (NULL);
		}

		new_node->next = curr_node->next;
		curr_node->next = new_node;
	}

	return (new_node);
}
