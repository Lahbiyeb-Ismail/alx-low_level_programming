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

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (i < n - 1 && separator)
			printf("%d%s", va_arg(args, int), separator);

		else
			printf("%d", va_arg(args, int));
	}

	va_end(args);
	printf("\n");
}



