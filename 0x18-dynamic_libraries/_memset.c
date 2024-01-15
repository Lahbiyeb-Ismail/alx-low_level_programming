#include "main.h"

/**
 * _memset - Entry point
 *
 *  * @s: This is a pointer to the block of memory to fill.
 *  * @b: This is the value to be set.
 *  * @n: This is the number of bytes to be set to the value.
 *
 * Description: Function that fills memory with a constant byte.
 *
 * Prototype: char *_memset(char *s, char b, unsigned int n);
 *
 * The _memset() function fills the first n bytes of
 * the memory area pointed to by s with the constant byte b
 *
 * Returns a pointer to the memory area s
 *
 * Return: char
 *
 *
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);

}
