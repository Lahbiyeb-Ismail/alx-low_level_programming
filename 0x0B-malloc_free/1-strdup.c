#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - Entry point
 *
 *  * @str: string to copy
 *
 * Description: Function that returns a pointer to a newly
 * allocated space in memory, which contains a copy of the
 * string given as a parameter.
 *
 * Prototype: char *_strdup(char *str);
 *
 * The _strdup() function returns a pointer to a new string which
 * is a duplicate of the string str. Memory for the new string
 * is obtained with malloc, and can be freed with free.
 *
 * Returns NULL if str = NULL
 *
 * On success, the _strdup function returns a pointer to the
 * duplicated string. It returns NULL if insufficient memory was available
 *
 * Return: A pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 */

char *_strdup(char *str)
{
	char *s;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	s = malloc(len * sizeof(char));

	if (s == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		s[i] = str[i];

	s[i] = '\0';

	return (s);
}

