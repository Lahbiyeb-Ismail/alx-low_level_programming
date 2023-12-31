#include "main.h"

/**
 * print_array - Entry point
 *
 *  * @a: array of integers
 *  * @n: is the number of elements of the array to be printed
 *
 * Description:  that prints n elements of an array of integers,
 * followed by a new line.
 *
 * Numbers must be separated by comma, followed by a space
 * The numbers should be displayed in the same order
 * as they are stored in the array
 * You are allowed to use printf
 *
 * Prototype: void print_array(int *a, int n);
 *
 * Return: void
 *
 */

void print_array(int *a, int n)
{
	int  i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);

		if (i < n - 1)
			printf(", ");
	}

	printf("\n");
}
