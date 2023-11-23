#include "main.h"

/**
 * flip_bits - Entry point
 *
 *  * @n: unsigned long number
 *  * @m: unsigned long number
 *
 * Description: Function that returns the number of bits you would need
 * to flip to get from one number to another.
 *
 * Prototype: unsigned int flip_bits(unsigned long int n, unsigned long int m);
 *
 * Return: The number of bits you would need to flip to get from one
 * number to another.
 *
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bit_num = 0;
	unsigned long int xor = n ^ m;

	while (xor)
	{
		bit_num += 1 & xor;
		xor >>= 1;
	}

	return (bit_num);
}
