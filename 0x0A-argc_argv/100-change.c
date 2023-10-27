#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv: arguments value
 *
 * Description: Program that prints the minimum number of
 * coins to make change for an amount of money.
 *
 * Usage: ./change cents
 *
 * where cents is the amount of cents you need to give back
 *
 * if the number of arguments passed to your program is not exactly 1,
 * print Error, followed by a new line, and return 1
 *
 * you should use atoi to parse the parameter passed to your program
 *
 * If the number passed as the argument is negative, print 0,
 * followed by a new line
 *
 * You can use an unlimited number of coins of values 25, 10, 5, 2,
 * and 1 cent
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, minNumberOfCoins = 0;
	int coins[5] = { 25, 10, 5, 2, 1 };
	int amount;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	amount = atoi(argv[1]);

	if (amount < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		while (amount >= coins[i])
		{
			amount -= coins[i];
			minNumberOfCoins++;
		}
	}

	printf("%d\n", minNumberOfCoins);
	return (0);
}

