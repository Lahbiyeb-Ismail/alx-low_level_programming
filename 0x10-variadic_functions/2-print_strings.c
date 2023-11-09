#include "variadic_functions.h"

/**
 * print_strings - Entry point
 *
 *  * @separator: is the string to be printed between the strings
 *  * @n: is the number of strings passed to the function
 *
 * Description: Function that prints strings, followed by a new line.
 *
 * Prototype:
 * void print_strings(const char *separator, const unsigned int n, ...);
 *
 * If separator is NULL, don’t print it
 *
 * If one of the string is NULL, print (nil) instead
 *
 * Print a new line at the end of your function
 *
 * Return: void
 *
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int  i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		/**
		 * str == NULL ? printf("nil") : printf("%s", str);
		*/

		printf("%s", str == NULL ? "(nil)" : str);

		if (i != n - 1 && separator)
			printf("%s", separator);
	}

	va_end(args);
	printf("\n");
}



