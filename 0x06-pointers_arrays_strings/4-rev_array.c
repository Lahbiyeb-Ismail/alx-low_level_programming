#include "main.h"

/**
 * reverse_array - Entry point
 *
 *  * @a: pointer to an array of integers.
 *  * @n: the number of elements of the array
 *
 *
 * Description: Function that reverses the content of an
 * array of integers.
 *
 *
 * Prototype: void reverse_array(int *a, int n);
 *
 *
 * Return: void
 *
 *
 */

void reverse_array(int *a, int n)
{
	int i = 0, tmp_val;
	int last_idx = n - 1;

	while (i < n / 2)
	{

		tmp_val = a[i];
		a[i] = a[last_idx];
		a[last_idx] = tmp_val;

		i++;
		last_idx--;
	}
}
