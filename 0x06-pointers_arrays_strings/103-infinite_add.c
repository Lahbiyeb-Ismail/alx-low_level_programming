#include "main.h"

/**
 * rev_string - reverse array
 * @n: integer params
 * Return: 0
 */

void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char temp;

	while (n[i] != '\0')
		i++;

	i--;

	for (j = 0; j < i; j++, i--)
	{
		temp = n[j];
		n[j] = n[i];
		n[i] = temp;
	}
}

/**
 * _strlen - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that returns the length of a string.
 *
 * Prototype: int _strlen(char *s);
 *
 * Return:  the length of a string.
 *
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * infinite_add - Entry point
 *
 *  * @n1: array of char numbers
 *  * @n2: array of char numbers
 *  * @r: buffer that the function will use to store the result
 *  * @size_r: the buffer size
 *
 * Description: Function that adds two numbers.
 *
 * Prototype: char *infinite_add(char *n1, char *n2, char *r, int size_r)
 *
 * Return: r
 *
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int overflow = 0, num_1_len = _strlen(n1),
		num_2_len = _strlen(n2), digits = 0, val1 = 0, val2 = 0,
		temp_tot = 0;
	int i = num_1_len - 1, j = num_2_len - 1;

	if (num_2_len >= size_r || num_1_len >= size_r)
		return (0);

	while (i >= 0 || j >= 0 || overflow == 1)
	{
		if (i < 0)
			val1 = 0;
		else
			val1 = n1[i] - '0';

		if (j < 0)
			val2 = 0;
		else
			val2 = n2[j] - '0';

		temp_tot = val1 + val2 + overflow;

		if (temp_tot >= 10)
			overflow = 1;
		else
			overflow = 0;

		if (digits >= (size_r - 1))
			return (0);

		r[digits] = (temp_tot % 10) + '0';
		digits++;
		j--;
		i--;
	}
	if (digits == size_r)
		return (0);
	r[digits] = '\0';
	rev_string(r);
	return (r);
}
