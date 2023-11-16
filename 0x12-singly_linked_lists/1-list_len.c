#include "lists.h"

/**
 * list_len - Entry point
 *
 *  * @h: linked list head
 *
 * Description: Function that returns the number of elements
 * in a linked list_t list.
 *
 * Prototype: size_t list_len(const list_t *h);
 *
 *
 * Return: returns the number of elements
 * in a linked list_t list
 *
 */


size_t list_len(const list_t *h)
{
	if (!h)
		return (0);

	return (1 + list_len(h->next));
}
