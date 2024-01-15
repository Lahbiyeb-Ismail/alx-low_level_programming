#include "main.h"

/**
 * _strncat - Entry point
 *
 *  * @dest: pointer to the string where we want to append.
 *  * @src: pointer to  the string from which ‘n’
 *  *       characters are going to append.
 *  * @n:  represents a maximum number of characters
 *  *       to be appended. size_t is an unsigned integral type.
 *
 * Description: Function that appends not more than n
 * characters from the string pointed to by src to the
 * end of the string pointed to by dest plus a terminating
 * Null-character.
 *
 * Prototype: char *_strncat(char *dest, char *src, int n);
 *
 *
 *
 * Return: return the pointer to the string(dest).
 *
 *
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i++] = src[j];
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
