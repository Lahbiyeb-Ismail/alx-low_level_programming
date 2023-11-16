#include "lists.h"

/**
 * print_list - Entry point
 *
 *  * @h: linked list head
 *
 * Description: Function that prints all the elements of a list_t list.
 *
 * Prototype: size_t print_list(const list_t *h);
 *
 * If str is NULL, print [0] (nil)
 *
 * Return: the number of nodes
 *
 */


size_t print_list(const list_t *h)
{
	int i = 0;

	while (h)
	{
		printf("[%d] %s\n", h->len, h->str ? h->str : "(nil)");
		h = h->next;
		i++;
	}

	return (i);
}
