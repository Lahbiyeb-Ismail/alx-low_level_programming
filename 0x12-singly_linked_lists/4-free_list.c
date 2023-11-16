#include "lists.h"

/**
 * free_list- Entry point
 *
 *  * @head: linked list head
 *
 * Description: that frees a list_t list.
 *
 * Prototype: void free_list(list_t *head);
 *
 * Return: void
 *
 */


void free_list(list_t *head)
{
	list_t *curr_node;

	while ((curr_node = head) != NULL)
	{
		head = head->next;
		free(curr_node->str);
		free(curr_node);
	}
}
