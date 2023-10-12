#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: '6-size.c' print size of var
 *
 * Return:  0 (Success)
 */

int main(void)
{
	char a;
	int b;
	long c;
	long long d;
	float e;

	printf("Size of a char: %u byte(s)\n", sizeof(a));
	printf("Size of an int: %u byte(s)\n", sizeof(b));
	printf("Size of a long int: %lu byte(s)\n", sizeof(c));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(d));
	printf("Size of a float: %lu byte(s)\n", sizeof(e));

	return (0);
}
