#include "main.h"

/**
 * _abs - Entry point
 *
 *  * @n: int parameter
 *
 * Description: Write a function that computes the absolute
 * value of an integer.
 *
 * Prototype: int _abs(int);
 *
 * Return: The program should return 0
 */

int _abs(int n)
{

	if (n < 0)
	{
		return (n * -1);
	}

	return (n);
}
