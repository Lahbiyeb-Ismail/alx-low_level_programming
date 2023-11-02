#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void _puts(char *str);
int _atoi(char *s);
int is_valid_number(char *s);
char *multiply_strings(char *s1, char *s2);

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
	char *res;

	if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		_puts("ERROR");

		exit(98);
	}

	res = multiply_strings(argv[1], argv[2]);

	if (res == NULL)
	{
		_puts("ERROR");
		exit(98);
	}

	_puts(res);

	free(res);

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

#include "main.h"

/**
 * _atoi - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that convert a string to an integer.
 *
 * Prototype: int _atoi(char *s);
 *
 * Return: string converted to an integer
 *
 */

int _atoi(char *s)
{

	int i;
	int sign = 1;
	unsigned int num = 0;
	int digit_encounter = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit_encounter = 1;
			num = num * 10 + (s[i] - '0');
		}

		else if (digit_encounter)
			break;

	}

	if (sign < 0)
		num = -num;

	return (num);
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
		if (i == 0 && s[i] == '-')
			i++;
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * multiply_strings - Entry point
 *
 *  * @s1: string
 *  * @s2: string
 *
 * Description: Function that multiplies two string number
 *
 *
 * Return: Result of s1 * s2
 *
 */

char *multiply_strings(char *s1, char *s2)
{
	int num1 = _atoi(s1);
	int num2 = _atoi(s2);
	int result = num1 * num2;
	int result_length = 0, sign, i, left, right;
	int temp_result = result;
	char *result_str;

	if (temp_result == 0)
		result_length = 1;
	else
	{
		while (temp_result != 0)
		{
			result_length++;
			temp_result /= 10;
		}
	}

	sign = 1;

	if (result < 0)
	{
		sign = -1;
		result_length--;
	}

	result_str = malloc((result_length + 1) * sizeof(char));

	if (result_str == NULL)
		return (NULL);


	i = 0;

	if (sign == -1)
		result_str[i++] = '-';


	if (result == 0)
		result_str[i] = '0';

	else
	{
		while (result != 0)
		{
			int digit = result % 10;

			result_str[i++] = ('0' + digit);
			result /= 10;
		}
	}

	result_str[i] = '\0';

	left = sign == -1 ? 1 : 0;
	right = i - 1;

	while (left < right)
	{
		char temp = result_str[left];

		result_str[left] = result_str[right];
		result_str[right] = temp;
		left++;
		right--;
	}

	return (result_str);
}
