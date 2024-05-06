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
	size_t i, start, end, jump_amount;

	if (array == NULL || size == 0)
		return (-1);

	jump_amount = sqrt(size);
	start = 0;
	end = jump_amount;

	while (array[end] < value && start < size)
	{
		printf("Value checked array[%lu] = [%d]\n", start, array[start]);

		start = end;
		end += jump_amount;

		if (start >= size)
			return (-1);
	}

	end = end > size - 1 ? size - 1 : end;

	printf("Value checked array[%lu] = [%d]\n", start, array[start]);
	printf("Value found between indexes [%lu] and [%lu]\n", start, end);

	for (i = start; i <= end; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
