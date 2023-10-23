#include "main.h"

/**
 * set_string - Entry point
 *
 *  * @s: double pointer
 *  * @to: pointer to a char var
 *
 * Description: Function that sets the value of a pointer to a char.
 *
 * Prototype: void set_string(char **s, char *to);
 *
 *
 * Return: Nothing
 *
 */

void set_string(char **s, char *to)
{
	*s = to;
}

