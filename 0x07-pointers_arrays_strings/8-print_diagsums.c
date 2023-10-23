#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - Entry point
 *
 *  * @a: matrix (2 dimensional array)
 *  * @size: size of the matrix
 *
 * Description: Function that prints the sum of the two diagonals
 * of a square matrix of integers.
 *
 * Prototype: void print_diagsums(int *a, int size);
 *
 *
 * Return: Nothing
 *
 */

void print_diagsums(int *a, int size)
{
	int diagSum1 = 0;
	int diagSum2 = 0;
	int i;
	int numItemsInMatrix = size * size;
	int lastIndexIMatrix = numItemsInMatrix - (size - 1);

	for (i = 0; i < numItemsInMatrix; i += size + 1)
		diagSum1 += a[i];


	for (i = size - 1; i < lastIndexIMatrix; i += size - 1)
		diagSum2 += a[i];


	printf("%d, %d \n", diagSum1, diagSum2);
}

