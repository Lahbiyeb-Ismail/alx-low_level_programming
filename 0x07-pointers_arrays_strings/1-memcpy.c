#include "main.h"

/**
 * _memcpy - Entry point
 *
 *  * @dest: This is pointer to the destination array where
 *  *        the content is to be copied
 *  * @src: This is pointer to the source of data to be copied
 *  * @n: This is the number of bytes to be copied.
 *
 * Description: Function that copies memory area.
 *
 * Prototype: char *_memcpy(char *dest, char *src, unsigned int n);
 *
 * The _memcpy() function copies n bytes from memory area src
 * to memory area dest
 *
 * Returns a pointer to dest
 *
 * Return: char
 *
 *
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);

}
