#include "3-calc.h"

/**
 * op_add - Entry point
 *
 *  * @a: num1
 *  * @b: num2
 *
 * Description: Function that performs addition
 *
 * Prototype: int op_add(int a, int b);
 *
 * Return: the sum of a and b
 *
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Entry point
 *
 *  * @a: num1
 *  * @b: num2
 *
 * Description: Function that performs subtraction
 *
 * Prototype: int op_sub(int a, int b);
 *
 * Return:  the difference of a and b
 *
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Entry point
 *
 *  * @a: num1
 *  * @b: num2
 *
 * Description: Function that performs multiplication
 *
 * Prototype: int op_mul(int a, int b);
 *
 * Return:  the product of a and b
 *
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Entry point
 *
 *  * @a: num1
 *  * @b: num2
 *
 * Description: Function that performs division
 *
 * Prototype: int op_div(int a, int b);
 *
 * Return:  the result of the division of a by b
 *
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
 * op_mod - Entry point
 *
 *  * @a: num1
 *  * @b: num2
 *
 * Description: Function that performs modulo
 *
 * Prototype: int op_mod(int a, int b);
 *
 * Return:  the remainder of the division of a by b.
 *
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
