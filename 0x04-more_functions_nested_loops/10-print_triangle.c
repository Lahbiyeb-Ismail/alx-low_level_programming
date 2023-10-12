#include "main.h"

/**
 * print_triangle - Entry point
 *
 * @size: size is  the size of the triangle
 *
 * Description: Function that prints a triangle, followed by a new line.
 *
 * Prototype: void print_triangle(int size);
 * You can only use _putchar function to print
 * If size is 0 or less, the function should print only a new line
 * Use the character # to print the triangle
 *
 *
 * Return: The program should print triangle of size n
 *
 */

void print_triangle(int size)
{
	int i, space, symbol;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{

		for (i = 1; i <= size; i++)
		{
			for (space = 1; space <= size - i; space++)
			{
				_putchar(' ');
			}

			for (symbol = 1; symbol <= i; symbol++)
			{
				_putchar('#');
			}

			_putchar('\n');
		}
	}

}
