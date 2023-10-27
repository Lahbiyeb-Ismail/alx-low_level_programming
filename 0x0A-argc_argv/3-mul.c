#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv: arguments value
 *
 * Description: Program that multiplies two numbers.
 *
 * Your program should print the result of the multiplication,
 * followed by a new line
 * You can assume that the two numbers and result of the
 * multiplication can be stored in an integer
 * If the program does not receive two arguments,
 * your program should print Error, followed by a new line,
 * and return 1
 *
 * Return: 0
 *
 */

int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		int res = atoi(argv[1]) * atoi(argv[2]);

		printf("%d\n", res);
		return (0);
	}

	printf("Error\n");
	return (1);
}

