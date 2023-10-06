#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints all the possible different combinations
 * of two digits
 * Numbers must be separated by ,, followed by a space
 * The two digits must be different
 * 01 and 10 are considered the same combination of the two digits 0 and 1
 * Print only the smallest combination of two digits
 * Numbers should be printed in ascending order, with two digits
 * You can only use the putchar function (every other function
 * (printf, puts, etc…) is forbidden)
 * You can only use putchar five times maximum in your code
 * You are not allowed to use any variable of type char
 * All your code should be in the main function
 * Return: Always 0
 */

int main(void)
{
	int left, right;

	for (left = 0; left <= 9; left++)
	{
		for (right = 1; right <= 9; right++)
		{
			if (left >= right)
				continue;

			putchar(left + '0');
			putchar(right + '0');

			putchar(44);
			putchar(32);
		}
	}

	putchar('\n');
	return (0);
}
