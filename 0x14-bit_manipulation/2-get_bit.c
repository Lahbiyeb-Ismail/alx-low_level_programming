#include "main.h"

/**
 * get_bit - Entry point
 *
 *  * @n: number to convert in binary
 *  * @index: is the index, starting from 0 of the bit you want to get
 *
 * Description: Function that returns the value of a bit at a given index.
 *
 * Prototype: set_bit(unsigned long int *n, unsigned int index);
 *
 * Return: The value of a bit at a given index.
 *
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > sizeof(n) * 8)
	{
		return (-1);
	}

	return ((n >> index) & 1);
}
