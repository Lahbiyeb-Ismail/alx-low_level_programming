#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: print all the alphabet letters in lower case except q and e
 *
 * Return: Always 0
 */

int main(void)
{
	char alphabet;

	for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
	{
		if (alphabet == 'q' || alphabet == 'e')
		{
			continue;
		}

		putchar(alphabet);
	}

	putchar('\n');
	return (0);
}
