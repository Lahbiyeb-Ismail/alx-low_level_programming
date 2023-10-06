#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints all the numbers of base 16 starting from 0
 * in lowercase (0123456789abcdef)
 *
 * Return: Always 0
 */

int main(void)
{
	int number = 0;
	char letter = 'a';

	while (number <= 9)
	{
		putchar((number % 10) + '0');
		number++;
	}

	while (letter <= 'f')
	{
		putchar(letter);
		letter++;
	}

	putchar('\n');
	return (0);
}
