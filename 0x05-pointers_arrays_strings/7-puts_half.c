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

	if (len % 2 == 0)
		i = len / 2;

	else
		i = (len + 1) / 2;


	for (; i < len; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
