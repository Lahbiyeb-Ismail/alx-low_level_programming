#include "main.h"

/**
 * print_numbers - Entry point
 *
 *  * @void: no parameter
 *
 * Description: that prints the numbers, from 0 to 9,
 * followed by a new line.
 *
 * Prototype: void print_numbers(void);
 *
 * Return: The program should return a * b
 *
 */

void print_numbers(void)
{
	int number = 0;

	while (number <= 9)
	{
		_putchar(number + '0');
		number++;
	}

	_putchar('\n');

}
