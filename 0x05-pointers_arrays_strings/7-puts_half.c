#include "main.h"

/**
 * puts_half - Entry point
 *
 *  * @str: pointer to a string
 *
 * Description: Function that prints half of a string,
 * followed by a new line.
 *
 * Prototype: void puts_half(char *str);
 *
 * Return: void
 *
 */

void puts_half(char *str)
{
	int i, j, len;

	for (j = 0; str[j] != '\0'; j++)
	{
		len++;
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i > (len - 1) / 2)
			_putchar(str[i]);
	}

	_putchar('\n');
}
