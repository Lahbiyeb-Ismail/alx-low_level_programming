#include "main.h"

/**
 * print_rev - Entry point
 *
 *  * @str: pointer to a string
 *
 * Description: Function that prints a string, in reverse,
 * followed by a new line.
 *
 * Prototype: void print_rev(char *str);
 *
 * Return: void
 *
 */

void print_rev(char *str)
{

	int i, j, len = 0;

	for (j = 0; str[j] != '\0'; j++)
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
