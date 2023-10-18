#include "main.h"

/**
 * _strncpy - Entry point
 *
 *  * @dest: pointer to the to the destination array where
 *  *         the content is to be copied.
 *  * @src: pointer to  the string to be copied.
 *  * @n:  represents The number of characters to be copied from source.
 *
 * Description: Function that copies up to n characters from
 * the string pointed to, by src to dest. In a case where
 * the length of src is less than that of n, the remainder
 * of dest will be padded with null bytes.
 *
 * Prototype: char *_strncpy(char *dest, char *src, int n);
 *
 *
 *
 * Return: the pointer to the copied string.
 *
 *
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
