#include "main.h"

/**
 * leet - Entry point
 *
 *  * @str: pointer to a string to encodes into 1337
 *
 *
 * Description: Function that encodes a string into 1337.
 * https://en.wikipedia.org/wiki/Leet
 *
 * Prototype: char *leet(char *);
 *
 *
 * Return: encodes string
 *
 *
 */

char *leet(char *str)
{
	int i = 0, j;
	char letters[] = "aeotl";
	char replacements[] = "43071";

	while (str[i] != '\0')
	{
		j = 0;

		while (letters[j] != '\0')
		{
			if (str[i] == letters[j] ||
				str[i] == letters[j] - 32)
			{
				str[i] = replacements[j];
			}

			j++;
		}

		i++;
	}

	return (str);
}
