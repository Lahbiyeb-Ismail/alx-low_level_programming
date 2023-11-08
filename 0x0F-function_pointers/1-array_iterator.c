#include "function_pointers.h"

/**
 * array_iterator - Entry point
 *
 *  * @array: array of integers
 *  * @size: is the size of the array
 *  * @action: is a pointer to the function you need to use
 *
 * Description: Function that executes a function given as a parameter on
 * each element of an array.
 *
 * Prototype:
 * void array_iterator(int *array, size_t size, void (*action (int));
 *
 * Return: void
 *
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (!array || size <= 0 || !action)
		return;

	size_t i;

	for (i = 0; i < size; i++)
		action(array[i]);
}

