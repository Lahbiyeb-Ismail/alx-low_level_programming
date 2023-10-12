#include "main.h"

/**
 * more_numbers - Entry point
 *
 * @void: no parameter
 *
 * Description: Function that prints 10 times the numbers,
 * from 0 to 14, followed by a new line.
 *
 * Prototype: void more_numbers(void);
 *
 * Return: The program should return numbers from 0 to 14, 10 times
 *
 */

void more_numbers(void)
{
	int count, number;

	for (count = 0; count < 10; count++)
	{
		for (number = 0; number < 15; number++)
		{
			if (number >= 10)
				_putchar(number / 10 + '0');
			_putchar(number % 10 + '0');
		}
		_putchar('\n');
	}
}
