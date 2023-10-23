#include "main.h"

/**
 * _strstr - Entry point
 *
 *  * @haystack: This is the main C string to be scanned.
 *  * @needle: This is the small string to be searched with-in haystack string.
 *
 * Description: Function finds the first occurrence of the
 * substring needle in the string haystack.
 * The terminating '\0' characters are not compared.
 *
 * Prototype: char *_strstr(char *haystack, char *needle);
 *
 * The _strstr() function finds the first occurrence of the
 * substring needle in the string haystack. The terminating
 * null bytes (\0) are not compared
 *
 *
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 *
 *
 *
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;


	for (; needle[i] != '\0'; i++)
	{
		for (j = 0; haystack[j] != '\0'; j++)
		{
			if (needle[i] == haystack[j])
				return (haystack + j);
		}

	}

	return (NULL);

}

