#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - Entry point
 *
 *  * @n: integer
 *
 * Description: Function that prints all natural numbers
 * from n to 98, followed by a new line.
 *
 * Prototype: void print_to_98(int n);
 *
 * Numbers must be separated by a comma, followed by a space
 * Numbers should be printed in order
 * The first printed number should be the number passed to your function
 * The last printed number should be 98
 * You are allowed to use the standard library
 *
 * Return: Count from 'n' to 98
 */

void print_to_98(int n)
{
	int count;

	if (n > 98)
	{
		for (count = n; count >= 98; count--)
		{
			printf("%d", count);

			if (count == 98)
				continue;

			printf(", ");
		}
	}


	for (count = n; count <= 98; count++)
	{
		printf("%d", count);

		if (count == 98)
			continue;

		printf(", ");
	}

	printf("\n");
}
