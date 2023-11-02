#include <stdio.h>
#include <stdlib.h>
#include "main.h"

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
	int res, num1, num2, i;

	char *s = "ERROR";

	if (argc != 3)
	{
		for (i = 0; s[i]; i++)
			_putchar(s[i]);

		_putchar('\n');
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	res = num1 * num2;

	printf("%d\n", res);

	return (0);
}

