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
 *
 * Prototype: int _pow_recursion(int x, int y);
 *
 *
 * Return: The value of x raised to the power of y. (x**y)
 *
 *
 * EXAMPLE:
 * pow(2,4) --> 2 * pow(2,3) --> 2 * pow(2,2) --> 2 * pow(2,1) --> 2 * pow(2,0)
 *
 *
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

