#include "search_algos.h"

/**
 * binary_search_2 - Searches for a value in a sorted array of integers
 *                   using the Binary search algorithm.
 *
 * @array: A pointer to the first element of the array to search in.
 * @low: The first index in the range to search.
 * @high: The last index in the range to search.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */

int binary_search_2(int *array, size_t low, size_t high, int value)
{
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

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm.
 *
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound, low, high;

	if (!array || size == 0)
		return (-1);

	if (array[0] == value)
		return (0);

	bound = 1;

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound, array[bound]);
		bound *= 2;
	}

	low = bound / 2;
	high = bound <= size - 1 ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	return (binary_search_2(array, low, high, value));
}
