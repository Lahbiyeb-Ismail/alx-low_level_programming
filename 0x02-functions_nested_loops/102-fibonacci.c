#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Write a program that prints the first
 * 50 Fibonacci numbers, starting with 1 and 2,
 * followed by a new line.
 *
 * The numbers must be separated by comma, followed by a space ,
 * You are allowed to use the standard library
 *
 * Return: 0
 */

int main(void)
{
	int x;
	unsigned long y, z, sum;

	y = 0;
	z = 1;

	for (x = 0; x < 50; x++)
	{
		sum = y + z;
		y = z;
		z = sum;
		printf("%lu", sum);

		if (x == 49)
			printf("\n");
		else
			printf(", ");
	}
	return (0);
}
