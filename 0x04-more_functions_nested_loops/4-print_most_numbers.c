#include "main.h"

/**
 * print_most_numbers - Entry point
 *
 *  * @void: no parameter
 *
 * Description: Function that prints the numbers, from 0 to 9,
 * followed by a new line.
 *
 * Prototype: void print_most_numbers(void);
 *
 * Do not print 2 and 4
 *
 * Return: The program should return numbers from 0 to 9, except 2 and 4
 *
 */

void print_most_numbers(void)
{
	int number = 0;

	while (number <= 9)
	{
		if (number != 2 && number != 4)
			_putchar(number + '0');


		number++;
	}

	_putchar('\n');

}
