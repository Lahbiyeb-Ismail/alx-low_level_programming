#include "main.h"

/**
 * print_times_table - Entry point
 *
 * @n: integer
 *
 * Description: Function that prints the n times table,
 * starting with 0.
 *
 * Prototype: void print_times_table(void);
 *
 */

void print_times_table(int n)
{
	int x, y, result;

	if (n > 0 && n < 15)
	{
		for (x = 0; x <= n; x++)
		{
			for (y = 0; y <= n; y++)
			{

				result = x * y;

				if (y == 0)
					_putchar(result + '0');

				formatResult(result, y);
			}
			_putchar('\n');
		}
	}


}

/**
 * formatResult - Entry point
 *
 * @n: number to format
 * @y: col number
 *
 * Description: Function that convert from ASCI code to Decimal
 * and format
 *
 * Return: nothing
 */

void formatResult(int n, int y)
{
	if (n < 10 && y != 0)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar(' ');
		_putchar(n + '0');
	}

	if (n > 9 && n <= 99)
	{
		_putchar(',');
		_putchar(' ');
		_putchar(' ');
		_putchar((n / 10) + '0');
		_putchar((n % 10) + '0');
	}

	if (n >= 100)
	{
		_putchar(',');
		_putchar(' ');
		_putchar((n / 100) + '0');
		_putchar((n / 10 % 10) + '0');
		_putchar((n % 10) + '0');
	}
}
