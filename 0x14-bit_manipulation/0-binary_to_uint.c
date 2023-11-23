#include "main.h"

/**
 * _pow_recursion - Entry point
 *
 *  * @x: number
 *  * @y: number
 *
 * Description: Function that returns the value of x raised to the
 * power of y.
 *
 * !If y is lower than 0, the function should return -1
 *
 * Prototype: int _pow_recursion(int x, int y);
 *
 * Return: The value of x raised to the power of y. (x**y)
 *
 * EXAMPLE:
 * pow(2,4) --> 2 * pow(2,3) --> 2 * pow(2,2) --> 2 * pow(2,1) --> 2 * pow(2,0)
 *
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	else
		return (x * _pow_recursion(x, y - 1));
}

/**
 * binary_to_uint - Entry point
 *
 *  * @b: A pointer to a string of 0 and 1 chars
 *
 * Description: Function that converts a binary number to an unsigned int.
 *
 * Prototype: unsigned int binary_to_uint(const char *b);
 *
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 *
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num_val = 0;
	int i, j, len = 0;

	if (!b)
		return (0);

	while (b[len])
		len++;

	for (i = len - 1, j = 0; i >= 0; j++, i--)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		if (b[i] == '1')
			num_val += (unsigned int)_pow_recursion(2, j);
	}

	return (num_val);
}
