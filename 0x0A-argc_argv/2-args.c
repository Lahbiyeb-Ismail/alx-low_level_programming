#include <stdio.h>

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv: arguments value
 *
 * Description: Program that prints all arguments it receives.
 *
 * All arguments should be printed, including the first one
 * Only print one argument per line, ending with a new line
 *
 * Return: 0
 *
 */

int main(int argc, char *argv[])
{
	int i = 0;

	for (; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}

