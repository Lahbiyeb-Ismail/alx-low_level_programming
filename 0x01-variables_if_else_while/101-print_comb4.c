#include <stdio.h>

/**
 * main - Entry point
 *
 * Descripition: Program that prints all the possible different combinations
 * of tree digits
 * Numbers must be separated by ',', followed by a space
 * The tree digits must be different
 * 012, 120, 102, 021, 201, 210 are considered the same combination
 * of the three digits 0, 1 and 2
 * Print only the smallest combination of tree digits
 * Numbers should be printed in ascending order, with tree digits
 * You can only use the putchar function (every other function
 * (printf, puts, etc…) is forbidden)
 * You can only use putchar six times maximum in your code
 * You are not allowed to use any variable of type char
 * All your code should be in the main function
 *
 * Return: Always 0
 */

int main(void)
{
	int left, middle, right;

	for (left = 0; left <= 9; left++)
	{
		for (middle = 1; middle <= 9; middle++)
		{
			for (right = 2; right <= 9; right++)
			{
				if (left >= middle || middle >= right || left >= right)
					continue;

				putchar(left + '0');
				putchar(middle + '0');
				putchar(right + '0');

				if (left == 7 && middle == 8 && right == 9)
					continue;

				putchar(44);
				putchar(32);
			}
		}
	}

	putchar('\n');
	return (0);
}
