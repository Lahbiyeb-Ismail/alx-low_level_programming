#include "main.h"

/**
 * is_separators - Entry point
 *
 *  * @c: separator char
 *
 *
 * Description: Function that check if the c char is a separator
 *
 *
 * Prototype: int is_separators(char c);
 *
 *
 * Return: 0 or 1
 *
 *
 */

int is_separators(char c)
{
	int i = 0;
	char str[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);

		i++;
	}

	return (0);
}



/**
 * cap_string - Entry point
 *
 *  * @str: pointer to an array of integers.
 *
 *
 * Description: Function that capitalizes all words of a string.
 *
 *
 * Prototype: char *cap_string(char *);
 *
 *
 * Return: string capitalizes
 *
 *
 */

char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;

		if (is_separators(str[i]) && str[i + 1] >= 'a' && str[i + 1] <= 'z')
			str[i + 1] -= 32;

		i++;
	}

	return (str);
}
