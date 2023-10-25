#include "main.h"

int is_palindrome_recursion(char *s, int left, int right);
int _strlen_recursion(char *s);

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
	int len = _strlen_recursion(s) - 1;

	printf("len = %d\n", len);

	return (is_palindrome_recursion(s, 0, len));
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

	if (s[left] != s[right])
		return (0);

	return (is_palindrome_recursion(s, left + 1, right - 1));
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
