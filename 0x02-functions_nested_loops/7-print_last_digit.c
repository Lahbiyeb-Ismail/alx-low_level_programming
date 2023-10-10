#include "main.h"

/**
 * print_last_digit - Entry point
 *
 *  * @n: int parameter
 *
 * Description: Function that prints the last digit of a number.
 *
 * Prototype: int print_last_digit(int);
 *
 * Return: The program should return the lastDigit of a number
 */

int print_last_digit(int n)
{
	int lastDigit;

	if (n < 0)
	{
		lastDigit = -n % 10;
	}
	else
	{
		lastDigit = n % 10;
	}

	_putchar(lastDigit + '0');

	return (lastDigit);

}
