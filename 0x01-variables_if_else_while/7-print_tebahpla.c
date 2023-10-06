#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints the lowercase alphabet in reverse
 *
 * Return: Always 0
 */

int main(void)
{
	char alphabet = 'z';

	while (alphabet >= 'a')
	{
		putchar(alphabet);
		alphabet--;
	}

	putchar('\n');
	return (0);
}
