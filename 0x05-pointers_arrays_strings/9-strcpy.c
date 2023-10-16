#include "main.h"

/**
 * _strcpy - Entry point
 *
 *  * @dest: pointer to a string
 *  * @src: pointer to a string
 *
 * Description: that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * Prototype: char *_strcpy(char *dest, char *src);
 *
 * Return: the pointer to dest
 *
 */

char *_strcpy(char *dest, char *src)
{
	int i, j, len = 0;

	for (j = 0; src[j] != '\0'; j++)
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}


	return (dest);
}
