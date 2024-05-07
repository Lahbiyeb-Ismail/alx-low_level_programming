#include "search_algos.h"

/**
 * binary_search_recursion - Perform a binary search on a sorted integer array
 * @array: Pointer to the first element of the array to search in
 * @low: The first index in the range within the array to search
 * @high: The last index in the range within the array to search
 * @value: The value to search for
 *
 * This function performs a binary search for a specific value within a sorted
 * integer array. The search is performed within the range [low, high] of the
 * array. The function uses recursion to divide the search range in half
 * at each step, which makes the search operation very efficient for
 * large arrays.
 *
 * The function also prints the current search range at each step, which can be
 * useful for understanding how the binary search algorithm works.
 *
 * Return: If the value is found, the function returns the index of the value
 * within the array. If the value is not found, the function returns -1.
 */

int binary_search_recursion(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (!array)
		return (-1);

	if (low > high)
		return (-1);

	printf("Searching in array: ");
	for (i = low; i < high; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	mid = low + (high - low) / 2;

	if (array[low] == value)
		return (low);
	
	if (array[mid] == value)
		return (mid);

	if (array[mid] < value)
		return (binary_search_recursion(array, mid + 1, high, value));

	return (binary_search_recursion(array, low, mid - 1, value));
}

/**
 * advanced_binary - Perform a binary search on a sorted integer array
 * @array: Pointer to the first element of the array to search in
 * @size: The size of the array
 * @value: The value to search for
 *
 * This function performs a binary search for a specific value within a sorted
 * integer array. It uses the binary_search_recursion function to perform the
 * search. Before calling binary_search_recursion, it checks if the array is
 * NULL or if the size is 0, in which case it returns -1. It also checks if the
 * first element of the array is the value to search for, in which case it
 * returns 0.
 *
 * Return: If the value is found, the function returns the index of the value
 * within the array. If the value is not found, the function returns -1.
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t low, high;

	if (!array || size == 0)
		return (-1);

	low = 0;
	high = size - 1;

	return (binary_search_recursion(array, low, high, value));
}
