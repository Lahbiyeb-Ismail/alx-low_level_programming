#include "variadic_functions.h"

/**
 * print_all - Entry point
 *
 *  * @format: is a list of types of arguments passed to the function
 * *c: char
 * *i: integer
 * *f: float
 * *s: char * (if the string is NULL, print (nil) instead
 * *any other char should be ignored
 *
 * Description: Function that prints anything.
 *
 * Prototype: void print_all(const char * const format, ...);
 *
 * You are not allowed to use for, goto, ternary operator, else, do ... while
 *
 * You can use a maximum of:
 * 2 while loops
 * 2 if
 *
 * You can declare a maximum of 9 variables
 *
 * You are allowed to use printf
 *
 * Print a new line at the end of your function
 *
 * Return: void
 *
 */

void print_all(const char *const format, ...)
{
	op_t ops[] = {
		 {"c", print_char},
		 {"i", print_int},
		 {"f", print_float},
		 {"s", print_string},
	};
	va_list args;
	int i, j, specifier_num = 4;
	char *separator = "";

	va_start(args, format);
	i = 0;

	while (format && format[i])
	{
		j = 0;

		while (j < specifier_num)
		{
			if (format[i] == ops[j].specifier[0])
			{
				printf("%s", separator);
				separator = ", ";
				ops[j].f(args);
				break;
			}
			j++;
		}

		i++;
	}

	printf("\n");
	va_end(args);
}

/**
 * print_char - Entry point
 *
 *  * @args: char to print
 *
 * Description: Function that print a char
 *
 * Return: void
 *
 */

void print_char(va_list args)
{
	char c = va_arg(args, int);

	printf("%c", c);
}

/**
 * print_int - Entry point
 *
 *  * @args: int to print
 *
 * Description: Function that print an integer
 *
 * Return: void
 *
 */

void print_int(va_list args)
{
	int i = va_arg(args, int);

	printf("%d", i);
}

/**
 * print_float - Entry point
 *
 *  * @args: float to print
 *
 * Description: Function that print a float number
 *
 * Return: void
 *
 */

void print_float(va_list args)
{
	double f = va_arg(args, double);

	printf("%f", f);
}

/**
 * print_string - Entry point
 *
 *  * @args: string to print
 *
 * Description: Function that print a string
 *
 * Return: void
 *
 */

void print_string(va_list args)
{
	char *s = va_arg(args, char *);

	printf("%s", (s) ? s : "(nil)");
}
