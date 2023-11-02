#include <stdio.h>
#include <stdlib.h>

unsigned int str_len(char *str);

/**
 * string_nconcat - Entry point
 *
 *  * @s1: string 1
 *  * @s2: string 2
 *  * @n: number of char to concatenates
 *
 *
 * Description: Function that concatenates two strings.
 *
 * Prototype: char *string_nconcat(char *s1, char *s2, unsigned int n);
 *
 *
 * If the function fails, it should return NULL
 *
 * If n is greater or equal to the length of s2 then use the entire
 * string s2
 *
 * if NULL is passed, treat it as an empty string
 *
 * Return: A pointer shall point to a newly allocated space in memory,
 * which contains s1, followed by the first n bytes of s2, and null
 * terminated
 *
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_len, s2_len;
	unsigned int total_len = 0;
	unsigned int i, j;

	char *new_str;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	s1_len = str_len(s1);
	s2_len = str_len(s2);

	if (n >= s2_len)
		total_len = s1_len + s2_len;
	else
		total_len = s1_len + n;

	new_str = malloc((total_len + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);


	for (i = 0; i < s1_len; i++)
		new_str[i] = s1[i];

	for (j = 0; j < n && s2[j] != '\0'; j++)
		new_str[s1_len + j] = s2[j];


	new_str[total_len] = '\0';

	return (new_str);
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
	if (!*str)
		return (0);

	return (1 + str_len(str + 1));
}

