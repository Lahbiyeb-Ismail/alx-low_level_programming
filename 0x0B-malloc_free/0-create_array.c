#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - Entry point
 *
 *  * @size: the size of the array
 *  * @c: char
 *
 * Description: Function that creates an array of chars, and
 * initializes it with a specific char.
 *
 * Prototype: char *create_array(unsigned int size, char c);
 *
 * Returns NULL if size = 0
 *
 * Return: a pointer to the array, or NULL if it fails
 *
 */

char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int i;

	s = malloc(size * sizeof(c));

	if (s == NULL || size <= 0)
		return (NULL);

	for (i = 0; i < size; i++)
		s[i] = c;

	s[i] = '\0';

	return (s);
}

