#include "variadic_functions.h"

/**
 * sum_them_all - Entry point
 *
 *  * @n: number of parameters
 *
 * Description: Function that calculate the sum of all its params
 *
 * Prototype: int sum_them_all(const unsigned int n, ...);
 *
 * Return: the sum of all its parameters.
 *
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int sum, i;

	if (n == 0)
		return (0);

	va_start(args, n);
	sum = 0;

	for (i = 0; i < n; i++)
		sum += va_arg(args, unsigned int);

	va_end(args);

	return ((int)sum);

}

