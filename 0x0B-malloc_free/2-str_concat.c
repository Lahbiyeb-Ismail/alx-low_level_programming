#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - Entry point
 *
 *  * @s1: pointer to the string 1
 *  * @s2: pointer to the string 2
 *
 * Description: Function that concatenates two strings.
 *
 * Prototype: char *str_concat(char *s1, char *s2);
 *
 * The _strdup() function returns a pointer to a new string which
 * is a duplicate of the string str. Memory for the new string
 * is obtained with malloc, and can be freed with free.
 *
 * Returns NULL if str = NULL
 *
 * The returned pointer should point to a newly allocated space in memory
 * which contains the contents of s1, followed by the contents of s2, and
 * null terminated
 *
 * if NULL is passed, treat it as an empty string
 *
 * The function should return NULL on failure
 *
 * Return: A pointer that point to the newly allocated space in memory
 * which contains the contents of s1, followed by the contents of s2, and
 * null terminated
 *
 *
 */

unsigned int str_len(char *str);

char *str_concat(char *s1, char *s2)
{
	unsigned int s1Len = str_len(s1);
	unsigned int s2Len = str_len(s2);
	unsigned int totalLen = s1Len + s2Len;
	unsigned int idx1 = 0, idx2 = 0;

	char *newStr = malloc((totalLen + 1) * sizeof(char));

	if (newStr == NULL)
		return (NULL);

	for (idx1 = 0; idx1 < s1Len; idx1++)
		newStr[idx1] = s1[idx1];

	for (idx2 = 0; idx2 < s2Len; idx2++)
		newStr[s1Len + idx2] = s2[idx2];

	newStr[totalLen] = '\0';

	return (newStr);
}

/**
 * str_len - Entry point
 *
 *  * @str: pointer to the string 1
 *
 * Description: Helper Function that calculate the length of a string
 *
 * Return: The length of a string
 *
 *
 */

unsigned int str_len(char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
