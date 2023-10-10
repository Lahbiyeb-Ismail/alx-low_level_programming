#include "main.h"

/**
 * _islower - Entry point
 *
 *  * @c: int parameter
 *
 * Description: Write a function that checks for lowercase character.
 *
 * Prototype: int _islower(int c);
 * Returns 1 if c is lowercase
 *  Returns 0 otherwise
 *
 * Return: The program should return 0
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}

	return (0);

}
