#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv: arguments value
 *
 * Description: Function that multiplies two positive numbers.
 *
 *
 * Return: the pointer to the newly allocated memory block
 *
 */

int main(int argc, char *argv[])
{
	char *s1 = argv[1], *s2 = argv[2], *result;
	int s1Len, s2Len, totalLen, i, carry, digit1, digit2, a = 0;

	if (argc != 3 || !is_valid_number(s1) || !is_valid_number(s2))
	{
		_puts("ERROR");
		exit(98);
	}
	s1Len = _strlen(s1), s2Len = _strlen(s2), totalLen = s1Len + s2Len;

	result = malloc(sizeof(int) * totalLen);

	initValue(result, totalLen);

	for (s1Len = s1Len - 1; s1Len >= 0; s1Len--)
	{
		digit1 = s1[s1Len] - '0';
		carry = 0;
		for (s2Len = _strlen(s2) - 1; s2Len >= 0; s2Len--)
		{
			digit2 = s2[s2Len] - '0';
			carry += result[s1Len + s2Len + 1] + (digit1 * digit2);
			result[s1Len + s2Len + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[s1Len + s2Len + 1] += carry;
	}
	for (i = 0; i < totalLen; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}

/**
 * _puts - Entry point
 *
 *  * @str: pointer to a string
 *
 * Description: Function that prints a string, followed by a new line,
 * to stdout.
 *
 * Prototype: void _puts(char *str);
 *
 * Return: void
 *
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);

	_putchar('\n');
}

/**
 * is_valid_number - Entry point
 *
 *  * @s: string
 *
 * Description: Function that check if a given string is a valid number
 *
 *
 * Return: void
 *
 */

int is_valid_number(char *s)
{
	int i;

	if (!s || !s[0])
		return (0);

	i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);

		i++;
	}

	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}


/**
 * initValue - Entry point
 *
 *  * @str: string
 *  * @totalLen: the array type sizeof
 *
 * Description: Helper function
 *
 * Return: void
 *
 */

void initValue(char *str, int totalLen)
{
	int i;

	if (str == NULL)
	{
		_puts("ERROR");
		exit(98);
	}

	for (i = 0; i < totalLen; i++)
		str[i] = 0;


	str[totalLen] = '\0';
}
