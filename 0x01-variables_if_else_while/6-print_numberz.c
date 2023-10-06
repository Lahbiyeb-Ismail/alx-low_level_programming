#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints all the single digit
 * numbers of base 10 starting from 0, using putchar
 *
 * Return: Always 0
 */

int main(void)
{
	int number = 0;

	while (number <= 9)
	{
		putchar((number % 10) + '0');
		number++;
	}

	putchar('\n');
	return (0);
}
