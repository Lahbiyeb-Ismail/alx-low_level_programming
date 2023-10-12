#include "main.h"

/**
 * print_line - Entry point
 *
 * @n: n is the number of times the character _ should be printed
 *
 * Description: Function that draws a straight line in the terminal.
 *
 * Prototype: void print_line(int n);
 *
 * Return: The program should print the character _ n times
 *
 */

void print_line(int n)
{
	int i;

	if (n <= 0)
	{

		_putchar('\n');
	}
	else
	{

		for (i = 1; i <= n; i++)
		{
			_putchar('_');
		}

		_putchar('\n');
	}

}
