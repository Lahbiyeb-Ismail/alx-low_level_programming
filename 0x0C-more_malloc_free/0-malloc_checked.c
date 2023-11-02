#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - Entry point
 *
 *  * @b: the size of the array
 *
 * Description: Function that allocates memory using malloc.
 *
 * Prototype: void *malloc_checked(unsigned int b);
 *
 * if malloc fails, the malloc_checked function should
 * cause normal process termination with a status value of 98
 *
 * Return: a pointer to the allocated memory
 *
 */

void *malloc_checked(unsigned int b)
{
	int *p;

	p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}

