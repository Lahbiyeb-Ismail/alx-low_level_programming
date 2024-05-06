#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using the Binary
 *                 Search algorithm.
 *
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if the value is not
 *         present in the array.
 */

int binary_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1;

	if (array == NULL)
		return (-1);

	while (low <= high)
	{
		size_t mid = low + (high - low) / 2;
		size_t i;

		printf("Searching in array: ");

		for (i = low; i < high; i++)
			printf("%d, ", array[i]);

		printf("%d\n", array[i]);

		if (array[mid] == value)
			return (mid);

		if (array[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return (-1);
}
