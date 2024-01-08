#include "lists.h"

/**
 * dlistint_len - Entry point
 *
 *  * @h: doubly-linked list head
 *
 * Description: Function that returns the number of elements in a
 * linked dlistint_t list.
 *
 * Prototype: size_t dlistint_len(const dlistint_t *h);
 *
 * Return: the number of elements in a linked dlistint_t list.
 *
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}

	return (len);
}
