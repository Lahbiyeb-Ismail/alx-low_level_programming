#include "main.h"

/**
 * _strspn - Entry point
 *
 *  * @s: This is the main C string to be scanned.
 *  * @accept: This is the string containing the list of characters
 *  *          to match in s.
 *
 * Description: Function that gets the length of a prefix substring.
 *
 * Prototype: unsigned int _strspn(char *s, char *accept);
 *
 *
 * Returns the number of bytes in the initial segment of
 * s which consist only of bytes from accept
 *
 * Return: the length of a prefix substring.
 *
 *
 */

unsigned int _strspn(char *s, char *accept)
{
	int i = 0, j, len = 0;


	for (; accept[i] != '\0'; i++)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			if (s[j] == accept[i])
				len++;

			if (s[j] == ' ')
				break;
		}

	}

	return (len);

}

