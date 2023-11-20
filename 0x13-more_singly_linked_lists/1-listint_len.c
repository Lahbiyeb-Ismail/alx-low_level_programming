#include "lists.h"

/**
 * listint_len - Entry point
 *
 * * @h: linked list head
 *
 * Description: Function that returns the number of elements
 * in a linked listint_t list.
 *
 * Prototype: size_t listint_len(const listint_t *h);
 *
 * Return: the number of nodes
 *
 */


size_t listint_len(const listint_t *h)
{
	if (h == NULL)
		return (0);

	return (1 + listint_len(h->next));
}
