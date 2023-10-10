#include "main.h"

/**
 * times_table - Entry point
 *
 *  * @void: no parameter
 *
 * Description: Function that prints the 9 times table,
 * starting with 0.
 *
 * Prototype: void times_table(void);
 *
 */

void times_table(void)
{
	int x, y, n;

	for (x = 0; x <= 9; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			n = x * y;

			if (y == 0)
				_putchar(n + '0');

			if (n < 10 && y != 0)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(n + '0');
			}

			if (n >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((n / 10) + '0');
				_putchar((n % 10) + '0');
			}

		}
		_putchar('\n');
	}
}
