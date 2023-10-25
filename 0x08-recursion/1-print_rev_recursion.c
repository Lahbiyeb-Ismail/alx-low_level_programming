#include "main.h"

/**
 * _print_rev_recursion - Entry point
 *
 *  * @s: This is the C string to be reversed.
 *
 * Description: that prints a string in reverse using recursion
 *
 * Prototype: void _print_rev_recursion(char *s);
 *
 *
 * Return: Nothing
 *
 */

void _print_rev_recursion(char *s)
{

	if (*s == '\0')
		return;

	_print_rev_recursion(s + 1);
	_putchar(*s);

}

