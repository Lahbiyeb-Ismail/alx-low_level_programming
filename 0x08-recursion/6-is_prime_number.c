#include "main.h"

int is_prime_recursive(int n, int i);

/**
 * is_prime_number - Entry point
 *
 *  * @n: number
 *
 * Description: Function that returns 1 if the input integer is
 * a prime number, otherwise return 0.
 *
 *
 * Prototype: int is_prime_number(int n);
 *
 *
 * Return: 1 if the input integer is
 * a prime number, otherwise return 0.
 *
 *
 */

int is_prime_number(int n)
{
	return (is_prime_recursive(n, n - 1));
}


/**
 * is_prime_recursive - Helper function
 *
 *  * @n: number
 *  * @i: number
 *
 * Description: Is a helper function that takes two arguments: n and i.
 * It checks if n is divisible by i, and if i reaches 1, it returns 1
 * indicating that n is a prime number. Otherwise, it continues to
 * recursively check with the next value of i.
 *
 *
 * Prototype: int is_prime_recursive(int n, int i);
 *
 *
 * Return: 1 if the input integer is
 * a prime number, otherwise return 0.
 *
 *
 */

int is_prime_recursive(int n, int i)
{
	if (n <= 1)
		return (0);

	if (i == 1)
		return (1);

	if (n % i == 0)
		return (0);

	return (is_prime_recursive(n, i - 1));
}
