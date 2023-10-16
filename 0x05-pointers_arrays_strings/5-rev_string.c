#include "main.h"

/**
 * rev_string - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that reverses a string.
 *
 * Prototype: void rev_string(char *s);
 *
 * Return: void
 *
 */

void rev_string(char *s)
{

	int i, j, len = 0, strLen;
	char tmpChar;

	for (j = 0; s[j] != '\0'; j++)
	{
		len++;
	}

	strLen = len - 1;

	for (i = 0; i < len / 2; i++)
	{
		tmpChar = s[i];

		s[i] = s[strLen];
		s[strLen--] = tmpChar;
	}
}
