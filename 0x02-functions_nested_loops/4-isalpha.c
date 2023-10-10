#include <ctype.h>
#include "main.h"

/**
 * _isalpha - Entry point
 *
 *  * @c: int parameter
 *
 * Description: Write a function that checks for alphabetic character.
 *
 * Prototype: int _isalpha(int c);
 * Returns 1 if c is a letter, lowercase or uppercase
 * Returns 0 otherwise
 *
 * Return: The program should return 0
 */

int _isalpha(int c)
{

	if (isalpha(c) != 0)
	{
		return (1);
	};

	return (0);

}
