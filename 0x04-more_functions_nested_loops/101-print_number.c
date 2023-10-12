#include "main.h"

/**
 * print_number - Entry point
 *
 * @n: number to print
 *
 * Description: Function that prints an integer.
 *
 * Prototype: void print_number(int n);
 * You can only use _putchar function to print
 * You are not allowed to use long
 * You are not allowed to use arrays or pointers
 * You are not allowed to hard-code special values
 *
 * Return: nothing
 */

void print_number(int n)
{
	unsigned int _abs;

	if (n < 0)
	{
		_abs = -n;
		_putchar('-');
	}
	else
	{
		_abs = n;
	}

	if ((n <= 9 && n >= 0) || (n < 0 && n >= 9))
	{
		_putchar(_abs + '0');
	}

	if ((n > 9 && n <= 99) || (n < -9 && n >= -99))
	{
		_putchar((_abs / 10) + '0');
		_putchar((_abs % 10) + '0');
	}

	if ((n > 99 && n <= 999) || (n < -99 && n >= -999))
	{
		_putchar((_abs / 100) + '0');
		_putchar((_abs / 10 % 10) + '0');
		_putchar((_abs % 10) + '0');
	}

	if ((n > 999 && n <= 9999) || (n < -999 && n >= -9999))
	{
		_putchar((_abs / 1000) + '0');
		_putchar((_abs / 100 % 10) + '0');
		_putchar((_abs / 10 % 10) + '0');
		_putchar((_abs % 10) + '0');
	}
}
