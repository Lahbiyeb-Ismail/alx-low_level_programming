#include "main.h"

/**
 * string_toupper - Entry point
 *
 *  * @str: pointer to an array of integers.
 *
 *
 * Description: Function that changes all lowercase letters
 * of a string to uppercase.
 *
 *
 * Prototype: char *string_toupper(char *);
 *
 *
 * Return: uppercase string
 *
 *
 */

char *string_toupper(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		i++;
	}

	return (str);
}
