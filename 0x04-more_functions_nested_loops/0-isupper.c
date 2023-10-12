#include "main.h"

/**
 * _isupper - Entry point
 *
 *  * @c: int parameter
 *
 * Description: Write a function that checks for uppercase character.
 *
 * Prototype: int _isupper(int c);
 *
 * Return: The program should return 1 if c is uppercase,
 * else should return 0 if c is lowercase
 *
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}

	return (0);

}
