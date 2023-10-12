#include <stdio.h>

/**
 * main - Entry point
 *
 * @void: no parameter
 *
 * Description: Program that prints the numbers from 1 to 100,
 * followed by a new line.
 * But for multiples of three print Fizz instead of the number
 * and for the multiples of five print Buzz.
 * For numbers which are multiples of both three
 * and five print FizzBuzz.
 *
 * Each number or word should be separated by a space
 * You are allowed to use the standard library
 *
 * Return: 0
 *
 */

int main(void)
{
	int number;

	for (number = 1; number <= 100; number++)
	{
		if (number % 3 == 0)
			printf("Fizz");

		else if (number % 5 == 0)
			printf("Buzz");

		else if (number % 3 == 0 && number % 5 == 0)
			printf("FizzBuzz");

		else
			printf("%d", number);

		if (number != 100)
			printf(" ");
	}

	printf("\n");

	return (0);
}
