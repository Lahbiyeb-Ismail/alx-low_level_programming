#include "function_pointers.h"

/**
 * int_index - Entry point
 *
 *  * @array: array of integers
 *  * @size: is the size of the array
 *  * @cmp: is a pointer to the function to be used to compare values
 *
 * Description: Function that searches for an integer.
 *
 * Prototype:
 * int int_index(int *array, int size, int (*cmp)(int));
 *
 * Return: the index of the first element for which the cmp function does
 * not return 0
 *
 * If no element matches, return -1
 *
 * If size <= 0, return -1
 *
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int index;

	if (!array || size <= 0 || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
		{
			index = i;
			break;
		}
	}

	if (!index)
		return (-1);

	return (index);

}

