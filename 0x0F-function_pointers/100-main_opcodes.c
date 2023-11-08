#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of the main function.
 *
 * * @argc: The number of command-line arguments.
 * * @argv: An array of strings containing the command-line arguments.
 *
 * Return: 0 if the program executed successfully.
 * 1 if the number of arguments is incorrect.
 * 2 if the number of bytes is negative.
 */

int main(int argc, char *argv[])
{
	int num_bytes, i;
	char *func_address;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	func_address = (char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		if (i == num_bytes - 1)
		{
			printf("%02hhx\n", func_address[i]);
			break;
		}

		printf("%02hhx ", func_address[i]);
	}

	return (0);
}
