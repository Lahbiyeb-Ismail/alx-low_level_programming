#include "main.h"

/**
 * _strchr - Entry point
 *
 *  * @s: This is the C string to be scanned.
 *  * @c: This is the character to be searched in str.
 *
 * Description: Function that copies memory area.
 *
 * Prototype: char *_strchr(char *s, char c);
 *
 *
 * Returns a pointer to the first occurrence of the
 * character c in the string s, or NULL if the character is not found
 *
 * Return: char
 *
 *
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);

		i++;
	}

	if (s[i] == c)
		return (s + i);

	return (NULL);

}

