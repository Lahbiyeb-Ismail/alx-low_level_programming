#include <stdio.h>
#include <stdlib.h>

/**
 * array_range - Entry point
 *
 *  * @min: min range of the array
 *  * @max: max range of the array
 *
 * Description: Function function that creates an array of integers.
 *
 * Prototype: int *array_range(int min, int max);
 *
 * The array created should contain all the values from min (included) to
 * max (included), ordered from min to max
 *
 * If min > max, return NULL
 *
 * If malloc fails, return NULL
 *
 *
 * Return: the pointer to the newly created array
 *
 */

int *array_range(int min, int max)
{
	int *array;
	int i, j;
	int totalSize;

	if (min > max)
		return (NULL);

	totalSize = (max - min) + 1;

	array = malloc(totalSize * sizeof(int));

	if (array == NULL)
		return (NULL);

	for (i = 0; i < totalSize; i++)
		array[i] = 0;

	for (j = min; j <= max; j++)
		array[j] = j;


	return (array);
}

