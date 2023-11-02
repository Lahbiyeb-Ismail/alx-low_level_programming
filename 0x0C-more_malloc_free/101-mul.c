#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void _puts(char *str);
int _atoi(char *s);
void print_int(unsigned long int n);

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv: arguments value
 *
 * Description: Function that multiplies two positive numbers.
 *
 *
 * Return: the pointer to the newly allocated memory block
 *
 */

int main(int argc, char *argv[])
{
	int res, num1, num2;

	if (argc != 3)
	{
		_puts("ERROR");

		exit(98);
	}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);

	res = num1 * num2;

	print_int(res);
	_putchar('\n');

	return (0);
}

/**
 * _puts - Entry point
 *
 *  * @str: pointer to a string
 *
 * Description: Function that prints a string, followed by a new line,
 * to stdout.
 *
 * Prototype: void _puts(char *str);
 *
 * Return: void
 *
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}

#include "main.h"

/**
 * _atoi - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that convert a string to an integer.
 *
 * Prototype: int _atoi(char *s);
 *
 * Return: string converted to an integer
 *
 */

int _atoi(char *s)
{

	int i;
	int sign = 1;
	unsigned int num = 0;
	int digit_encounter = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit_encounter = 1;
			num = num * 10 + (s[i] - '0');
		}

		else if (digit_encounter)
			break;

	}

	if (sign < 0)
		num = -num;

	return (num);
}

/**
 * print_int - Entry point
 *
 *  * @n: int
 *
 * Description: Function print an integer
 *
 *
 * Return: void
 *
 */

void print_int(unsigned long int n)
{
	unsigned long int divisor = 1, i, res;

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
		res = n / divisor;
		_putchar(res + '0');
	}

}
