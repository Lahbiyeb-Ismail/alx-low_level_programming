#include "main.h"

/**
 * print_alphabet_x10 - Entry point
 *
 *  * @void: no parameter needed
 *
 * Description: Write a function that prints
 * 10 times the alphabet, in lowercase, followed by a new line.
 *
 * Prototype: void print_alphabet_x10(void);
 * You can only use _putchar twice in your code
 *
 * Return: The program should return 0
 */

void print_alphabet_x10(void)
{
	int count = 0;

	while (count <= 9)
	{
		char letter = 'a';

		while (letter <= 'z')
		{
			_putchar(letter);
			letter++;
		}

		count++;
		_putchar('\n');
	}

}
