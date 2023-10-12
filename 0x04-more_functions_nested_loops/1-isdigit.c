#include "main.h"

/**
 * _isdigit - Entry point
 *
 *  * @c: int parameter
 *
 * Description: Function that checks for a digit (0 through 9).
 *
 * Prototype: int _isdigit(int c);
 *
 * Return: The program should return 1 if c is a digit,
 * else should return 0
 *
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}

	return (0);

}
