#include "main.h"

/**
 * _puts - Entry point
 *
 *  * @str: pointer to a string
 *
 * Description: Function that prints a string, followed by a new line,
 * to stdout.
 *
 * Prototype: void _puts(char *str);
 *
 * Return: void
 *
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
