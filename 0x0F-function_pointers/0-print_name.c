#include "function_pointers.h"

/**
 * print_name - Entry point
 *
 *  * @name: name to print
 *  * @f: function pointer
 *
 * Description: Function that prints a name.
 *
 * Prototype: void print_name(char *name, void (*f)(char *));
 *
 * Return: void
 *
 */

void print_name(char *name, void (*f)(char *))
{
	/*
	 *void (*function_pointer)(char *) = f;
	 *function_pointer(name);
	*/

	if (!name || !f)
		return;

	f(name);
}

