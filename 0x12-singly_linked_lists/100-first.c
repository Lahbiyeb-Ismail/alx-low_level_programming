#include <stdio.h>

/**
 * first - function that executed befor the main function
 *
 * Return: void.
 */

void __attribute__((constructor)) first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
