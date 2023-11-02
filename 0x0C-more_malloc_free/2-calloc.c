#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Entry point
 *
 *  * @nmemb: the size of the array
 *  * @size: the array type sizeof
 *
 * Description: Function that allocates memory for an array, using malloc.
 *
 * Prototype: void *_calloc(unsigned int nmemb, unsigned int size);
 *
 * The _calloc function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.
 *
 * The memory is set to zero
 *
 * If nmemb or size is 0, then _calloc returns NULL
 *
 * If malloc fails, then _calloc returns NULL
 *
 * Return: a pointer to the allocated memory
 *
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *m;
	unsigned int i;

	if (size == 0 || nmemb == 0)
		return (NULL);

	m = malloc(nmemb * size);

	if (m == NULL)
		return (NULL);

	for (i = 0; i < nmemb; i++)
		m[i] = 0;


	return (m);
}

