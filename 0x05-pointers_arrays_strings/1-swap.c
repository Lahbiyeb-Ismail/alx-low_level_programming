#include "main.h"

/**
 * swap_int - Entry point
 *
 *  * @a: pointer to an int
 *  * @b: pointer to an int
 *
 * Description: Function that swaps the values of two integers.
 *
 * Prototype: void swap_int(int *a, int *b);
 *
 * Return: void
 *
 */

void swap_int(int *a, int *b)
{
	int curr_a = *a;

	*a = *b;
	*b = curr_a;
}
