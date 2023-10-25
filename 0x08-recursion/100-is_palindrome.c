#include "main.h"

int _strlen_recursion(char *s);
int is_palindrome_recursion(char *s, int left, int right);

/**
 * is_palindrome - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that returns 1 if a string is a palindrome
 * and 0 if not.
 *
 *
 * Prototype: int is_palindrome(char *s);
 *
 *
 * Return: 1 if a string is a palindrome
 * and 0 if not.
 *
 *
 */

int is_palindrome(char *s)
{
	int right = _strlen_recursion(s) - 1;

	return (is_palindrome_recursion(s, 0, right));
}

/**
 * _strlen_recursion - Entry point
 *
 *  * @s: string.
 *
 * Description: Function that returns the length of a string.
 * using recursion
 *
 * Prototype: int _strlen_recursion(char *s);
 *
 *
 * Return: The length of a string.
 *
 */

int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * is_palindrome_recursion - Entry point
 *
 *  * @s: string to check if is palindrome
 *  * @left: left side of the string
 *  * @right: right side of the string
 *
 * Description: Helper function that check if a string is palindrome
 *
 * Prototype: int is_palindrome_recursion(char *s, int left, int right);
 *
 *
 * Return: The length of a string.
 *
 */

int is_palindrome_recursion(char *s, int left, int right)
{
	if (left >= right)
		return (1);

	else if (s[left] != s[right])
		return (0);

	else
		return (is_palindrome_recursion(s, left + 1, right - 1));
}


