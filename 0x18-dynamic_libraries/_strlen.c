#include "main.h"

/**
 * _strlen - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that returns the length of a string.
 *
 * Prototype: int _strlen(char *s);
 *
 * Return:  the length of a string.
 *
 */

int _strlen(char *s)
{
	int i, len = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;

	return (len);
}
