#include "main.h"

/**
 * print_number - Entry point
 * @n: number to print
 * Description: Function that prints an integer.
 * Return: nothing
 */

void print_number(int n)
{
	unsigned int _abs;
	int ones, tens, hundreds, thousands;

	if (n < 0)
	{
		_abs = n * -1;
		_putchar('-');
	}
	else
	{
		_abs = n;
	}

	ones = _abs % 10;
	tens = ((_abs % 100) - ones) / 10;
	hundreds = (_abs % 1000 - _abs % 100) / 100;
	thousands = (_abs - (_abs % 1000)) / 1000;

	if ((n <= 9 && n >= 0) || (n < 0 && n >= 9))
	{
		_putchar(_abs + '0');
	}
	else if ((n > 9 && n <= 99) || (n < -9 && n >= -99))
	{
		_putchar(tens + '0');
		_putchar(ones + '0');
	}
	else if ((n > 99 && n <= 999) || (n < -99 && n >= -999))
	{
		_putchar(hundreds + '0');
		_putchar(tens + '0');
		_putchar(ones + '0');
	}
	else if ((n > 999 && n <= 9999) || (n < -999 && n >= -9999))
	{
		_putchar(thousands + '0');
		_putchar(hundreds + '0');
		_putchar(tens + '0');
		_putchar(ones + '0');
	}
}
