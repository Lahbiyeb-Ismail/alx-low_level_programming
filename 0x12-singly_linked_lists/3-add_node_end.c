#include "lists.h"

/**
 * add_node_end - Entry point
 *
 *  * @head: linked list head
 *  * @str: linked list head
 *
 * Description: Function that adds a new node at the end of
 * a list_t list.
 *
 * Prototype: list_t *add_node_end(list_t **head, const char *str);
 *
 * Return: the address of the new element, or NULL if it failed
 *
 */


list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *last_node;
	int i = 0;

	new_node = malloc(sizeof(list_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}

	while (str[i])
		i++;

	new_node->str = strdup(str);
	new_node->len = i;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		last_node = *head;

		while (last_node->next)
			last_node = last_node->next;

		last_node->next = new_node;
	}

	return (last_node);
}
