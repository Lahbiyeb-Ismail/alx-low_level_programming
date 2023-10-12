#include "main.h"

/**
 * more_numbers - Entry point
 *
 *  * @void: no parameter
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
	int count = 0;

	while (count <= 10)
	{
		int number = 0;

		while (number <= 14)
		{
			if (number >= 10)
				_putchar((number / 10) + '0');

			_putchar((number % 10) + '0');
			number++;
		}

		count++;
		_putchar('\n');
	}



}
