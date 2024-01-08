#include "lists.h"

/**
 * list_len - Entry point
 *
 *  * @head: doubly-linked list head
 *
 * Description: Function that returns the number of elements in a
 * linked dlistint_t list.
 *
 * Prototype: size_t dlistint_len(const dlistint_t *h);
 *
 * Return: the number of elements in a linked dlistint_t list.
 *
 */

size_t list_len(dlistint_t *head)
{
	size_t len = 0;

	while (head)
	{
		head = head->next;
		len++;
	}

	return (len);
}

/**
 * insert_new_node - Entry point
 *
 *  * @h: doubly-linked list head
 *  * @idx: is the index of the list where the new node should be added.
 *  * @n: the new node data
 *
 * Description: Function that that inserts a new node at a given position.
 *
 * Prototype: dlistint_t *insert_new_node(dlistint_t **h,
 * unsigned int idx, int n);
 *
 * Return: the address of the new node, or NULL if it failed
 *
 */

dlistint_t *insert_new_node(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr_node;
	dlistint_t *new_node = NULL;
	size_t len = 0;

	curr_node = *h;
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	while (curr_node)
	{
		curr_node = curr_node->next;

		if (idx - 1 == len)
		{
			new_node->n = n;
			new_node->next = curr_node;
			new_node->prev = curr_node->prev;

			if (curr_node->prev)
				curr_node->prev->next = new_node;
			else
				*h = new_node;

			curr_node->prev = new_node;
			return (new_node);
		}
		len++;
	}

	free(new_node);
	return (NULL);
}

/**
 * insert_dnodeint_at_index - Entry point
 *
 *  * @h: doubly-linked list head
 *  * @idx: is the index of the list where the new node should be added.
 *  * @n: the new node data
 *
 * Description: Function that that inserts a new node at a given position.
 *
 * Prototype: dlistint_t *insert_dnodeint_at_index(dlistint_t **h,
 * unsigned int idx, int n);
 *
 * Return: the address of the new node, or NULL if it failed
 *
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	size_t len = list_len(*h);

	if (idx == 0 || !*h)
		return (add_dnodeint(h, n));

	if (idx > len)
		return (NULL);

	if (idx == len)
		return (add_dnodeint_end(h, n));

	return (insert_new_node(h, idx, n));
}
