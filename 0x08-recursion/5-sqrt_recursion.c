#include "main.h"

int _sqrt(int n, int x);

/**
 * _sqrt_recursion - Entry point
 *
 *  * @n: number
 *
 * Description: Function that returns the natural square root of a number.
 *
 * !If n does not have a natural square root, the function
 * !should return -1
 *
 *
 * Prototype: int _sqrt_recursion(int n);
 *
 *
 * Return: The natural square root of a number.
 *
 *
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_sqrt(n, 1));
}

/**
 * _sqrt - Entry point
 *
 *  * @n: int
 *  * @x: int
 *
 *
 * Description: Function that returns the natural square root of a number.
 *
 *
 * Prototype: int _sqrt(int n, int x);
 *
 *
 * Return: The natural square root of a number.
 *
 *
 */

int _sqrt(int n, int x)
{
	if (x * x == n)
		return (x);

	if (n == x)
		return (-1);

	return (_sqrt(n, x + 1));
}

