#include "main.h"

/**
 * factorial - Entry point
 *
 *  * @n: number
 *
 * Description: Function that returns the factorial of a given number.
 * !If n is lower than 0, the function should return -1 to indicate
 * !an error
 *
 * !Factorial of 0 is 1
 *
 * Prototype: int factorial(int n);
 *
 *
 * Return: The factorial of a given number (n)
 *
 */

int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (1);

	return (n * factorial(n - 1));

}

