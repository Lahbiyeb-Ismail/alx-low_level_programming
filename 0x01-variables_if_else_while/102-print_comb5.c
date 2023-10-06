#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints all the possible combinations
 * of two two-digit numbers.
 * The numbers should range from 0 to 99
 * The two numbers should be separated by a space
 * All numbers should be printed with two digits. 1 should be printed as 01
 * The combination of numbers must be separated by comma, followed by a space
 * The combinations of numbers should be printed in ascending order
 * 00 01 and 01 00 are considered as the same combination
 * of the numbers 0 and 1
 * You can only use the putchar function (every other function
 * (printf, puts, etc…) is forbidden)
 * You can only use putchar eight times maximum in your code
 * You are not allowed to use any variable of type char
 * All your code should be in the main function
 *
 * Return: Always 0
 */

int main(void)
{
	int left, right;

	for (left = 0; left <= 99; left++)
	{
		for (right = left + 1; right <= 99; right++)
		{
			putchar((left / 10) + '0');
			putchar((left % 10) + '0');
			putchar(' ');
			putchar((right / 10) + '0');
			putchar((right % 10) + '0');

			if (left == 98 && right == 99)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}
