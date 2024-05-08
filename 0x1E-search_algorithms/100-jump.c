#include "search_algos.h"

/**
 * jump_search - Searches for a value in an array using
 * the Jump search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index of the value if found, otherwise -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t low, high, jump_amount;

	if (!array || size == 0)
		return (-1);

	jump_amount = sqrt(size);

	for (high = 0; high < size && array[high] < value;
	     low = high, high += jump_amount)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       high, array[high]);
	}

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	high = high > size - 1 ? size - 1 : high;

	for (; low <= high; low++)
	{
		printf("Value checked array[%lu] = [%d]\n", low, array[low]);
		if (array[low] == value)
			return (low);
	}

	return (-1);
}
