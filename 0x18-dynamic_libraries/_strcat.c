#include "main.h"

/**
 * _strcat - Entry point
 *
 *  * @dest: pointer to a string
 *  * @src: pointer to a string
 *
 * Description: Function that concatenates two strings.
 *
 * Prototype: char *_strcat(char *dest, char *src);
 *
 * This function appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest
 * and then adds a terminating null byte
 *
 * Returns a pointer to the resulting string dest
 *
 * Return: char
 *
 *
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i++] = src[j];
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
