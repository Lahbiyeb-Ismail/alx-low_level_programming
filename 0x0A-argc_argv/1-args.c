#include <stdio.h>

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv: arguments value
 *
 * Description: Program that prints the number of arguments passed
 * into it.
 *
 * Return: 0
 *
 */

int main(int argc, char *argv[])
{
	if (argc && argv)
		printf("%d\n", argc - 1);

	return (0);
}

