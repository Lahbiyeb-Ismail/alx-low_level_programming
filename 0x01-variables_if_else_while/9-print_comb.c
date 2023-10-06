#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints all possible combinations of
 * single-digit numbers
 *
 * Return: Always 0
 */

int main(void)
{
	int digit;

	for (digit = 0; digit <= 9; digit++)
	{
		putchar(digit + '0');

		if (digit == 9)
			continue;

		putchar(44);
		putchar(32);
	}

	putchar('\n');
	return (0);
}
