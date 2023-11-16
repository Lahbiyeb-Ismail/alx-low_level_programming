#include "lists.h"

/**
 * add_node - Entry point
 *
 *  * @head: linked list head
 *  * @str: linked list head
 *
 * Description: Function that adds a new node at the beginning of
 * a list_t list.
 *
 * Prototype: list_t *add_node(list_t **head, const char *str);
 *
 * Return: returns the number of elements
 * in a linked list_t list
 *
 */


list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
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
	new_node->next = *head;

	*head = new_node;

	return (*head);
}
