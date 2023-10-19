#include "main.h"

/**
 * rot13 - Entry point
 *
 *  * @str: pointer to a string to encodes into 1337
 *
 *
 * Description: Function that encodes a string using rot13.
 *
 * ROT13 ("rotate by 13 places", sometimes hyphenated ROT-13)
 * is a simple letter substitution cipher that replaces a
 * letter with the 13th letter after it in the latin alphabet.
 * https://en.wikipedia.org/wiki/ROT13
 *
 * Prototype: char *rot13(char *);
 *
 *
 * Return: encodes string
 *
 *
 */

char *rot13(char *str)
{
	int i = 0, j;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char replacements[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (str[i] != '\0')
	{
		j = 0;

		while (letters[j] != '\0')
		{
			if (str[i] == letters[j])
			{
				str[i] = replacements[j];
				break;
			}

			j++;
		}

		i++;

	}

	return (str);
}
