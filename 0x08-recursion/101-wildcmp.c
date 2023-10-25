#include "main.h"

int is_prime_recursive(int n, int i);

/**
 * wildcmp - Entry point
 *
 *  * @s1: string 1
 *  * @s2: string 2
 *
 * Description: Function that compares two strings and returns 1
 * if the strings can be considered identical, otherwise return 0.
 *
 *
 * Prototype: int wildcmp(char *s1, char *s2);
 *
 * s2 can contain the special character *.
 *
 * The special char * can replace any string (including an empty string)
 *
 * Return: 1 if the strings can be considered identical,
 * otherwise return 0.
 *
 *
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	return (0);
}

