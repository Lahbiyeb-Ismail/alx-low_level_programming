#include "3-calc.h"

/**
 * main - check the code
 *
 * * @argc: arguments count
 * * @argv: arguments value
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int (*op_func)(int, int);
	char *operation;
	int num1, num2, result;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	operation = argv[2];
	op_func = get_op_func(operation);


	if (!op_func)
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	result = op_func(num1, num2);

	printf("%d\n", result);

	return (0);
}
