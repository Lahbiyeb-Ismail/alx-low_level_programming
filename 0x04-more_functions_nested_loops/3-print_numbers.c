#include "main.h"

/**
 * print_numbers - Entry point
 *
 *  * @void: no parameter
 *
 * Description: Function that prints the numbers, from 0 to 9,
 * followed by a new line.
 *
 * Prototype: void print_numbers(void);
 *
 * Return: The program should return numbers from 0 to 9
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
