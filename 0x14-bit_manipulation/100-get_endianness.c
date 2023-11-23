#include "main.h"

/**
 * get_endianness - Function that checks the endianness.
 *
 * Prototype: int get_endianness(void)
 *
 * Return: 0 if big endian, 1 if little endian
 *
 */

int get_endianness(void)
{
	int num = 1;
	char *byte_ptr = (char *)&num;

	return (*byte_ptr);
}
