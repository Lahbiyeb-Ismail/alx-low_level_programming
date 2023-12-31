#include "lists.h"

/**
 * get_nodeint_at_index - Entry point
 *
 * * @head: linked list head
 * * @index: is the index of the node, starting at 0
 *
 * Description: Function that returns the nth node of a listint_t linked list.
 *
 * where index is the index of the node, starting at 0
 *
 * if the node does not exist, return NULL
 *
 * Prototype:
 * listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);
 *
 * Return: the node or (NULL) if it's does no exit
 *
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *curr_node;
	listint_t *found_node;


	if (!head)
		return (NULL);

	if (index == 0)
		return (head);

	curr_node = head;

	while (i < index - 1 && curr_node)
	{
		curr_node = curr_node->next;
		i++;
	}

	if (!curr_node || !curr_node->next)
		return (NULL);

	found_node = curr_node->next;

	return (found_node);
}
