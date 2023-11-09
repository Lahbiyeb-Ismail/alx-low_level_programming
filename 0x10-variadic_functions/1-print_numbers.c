#include "variadic_functions.h"

/**
 * print_numbers - Entry point
 *
 *  * @separator: is the string to be printed between numbers
 *  * @n: is the number of integers passed to the function
 *
 * Description: Function that prints numbers, followed by a new line.
 *
 * Prototype:
 * void print_numbers(const char *separator, const unsigned int n, ...);
 *
 * If separator is NULL, don’t print it
 *
 * Print a new line at the end of your function
 *
 * Return: void
 *
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int  i;

	if (n == 0)
		return;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%d\n", va_arg(args, int));
		else
			printf("%d%s", va_arg(args, int), separator == NULL ? " " : separator);
	}

	va_end(args);
}

