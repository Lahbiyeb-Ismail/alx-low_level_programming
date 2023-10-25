#include "main.h"

/**
 * _puts_recursion - Entry point
 *
 *  * @s: This is the C string to be written.
 *
 * Description: writes a string to stdout up to but not including
 * the null character. A newline character is appended to the output.
 *
 * Prototype: void _puts_recursion(char *s);
 *
 *
 * Return: Nothing
 *
 */

void _puts_recursion(char *s)
{

	if (!*s)
	{
		_putchar('\n');
		return;
	}

	_putchar(*s);
	_puts_recursion(s + 1);
}

