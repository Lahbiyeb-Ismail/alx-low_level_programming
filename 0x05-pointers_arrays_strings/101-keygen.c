#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - check the code
 *
 * Description: C program that generates random valid
 * passwords for the program 101-crackme.
 *
 * Return: Always 0.
 */

int main(void)
{
	int my_rand;
	int count;
	int total;

	srand(time(NULL));

	for (count = 0, total = 2772; total > 122; count++)
	{
		my_rand = (rand() % 125) + 1;
		printf("%c", my_rand);
		total -= my_rand;
	}
	printf("%c", total);

	return (0);
}
