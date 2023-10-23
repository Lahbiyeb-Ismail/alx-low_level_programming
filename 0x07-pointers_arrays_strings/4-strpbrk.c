#include "main.h"

/**
 * _strpbrk - Entry point
 *
 *  * @s: This is the main C string to be scanned.
 *  * @accept: This is the C string containing the characters to match.
 *
 * Description: Function finds the first character in the string *s
 * that matches any character specified in *accept.
 * This does not include the terminating null-characters.
 *
 * Prototype: char *_strpbrk(char *s, char *accept);
 *
 * The _strpbrk() function locates the first occurrence in
 * the string s of any of the bytes in the string accept
 *
 *
 * Return: a pointer to the byte in s that matches one of the
 * bytes in accept, or NULL if no such byte is found
 *
 *
 *
 */

char *_strpbrk(char *s, char *accept)
{
	int i = 0, j;


	for (; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}

	}

	return (NULL);

}

