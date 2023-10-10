#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: If we list all the natural numbers below
 * 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 * The sum of these multiples is 23. Write a program that
 * computes and prints the sum of all the multiples of
 * 3 or 5 below 1024 (excluded), followed by a new line.
 *
 * Return: 0
 */

int main(void)
{
	int sum, n = 0;

	while (n < 1024)
	{
		if (n % 3 == 0 || n % 5 == 0)
			sum += n;

		n++;
	}

	printf("%d\n", sum);

	return (0);
}
