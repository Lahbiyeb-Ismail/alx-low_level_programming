#include "main.h"

/**
 * print_binary - Entry point
 *
 *  * @n: number to convert in binary
 *
 * Description: Function that prints the binary representation of a number.
 *
 * Prototype: void print_binary(unsigned long int n);
 *
 * Return: void
 *
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
