#include "main.h"

/**
 * print_alphabet - Entry point
 *
 *  * @void: no parameter needed
 *
 * Description: Write a function that prints the alphabet,
 * in lowercase, followed by a new line.
 *
 * Return: The program should return 0
 */

void print_alphabet(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		_putchar(letter);
		letter++;
	}

	_putchar('\n');
}
