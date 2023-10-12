#include "main.h"

/**
 * print_diagonal - Entry point
 *
 * @n: n is the number of times the character \ should be printed
 *
 * Description: Function that draws a diagonal line on the terminal.
 *
 * Prototype: void print_diagonal(int n);
 * You can only use _putchar function to print
 * The diagonal should end with a \n
 * If n is 0 or less, the function should only print a \n
 *
 * in ASCII \ == 92
 *
 * Return: The program should print the character \ n times
 *
 */

void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				_putchar(' ');
			}

			_putchar(92);
			_putchar('\n');
		}
	}

}
