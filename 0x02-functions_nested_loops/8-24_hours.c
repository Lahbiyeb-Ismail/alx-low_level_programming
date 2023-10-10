#include "main.h"

/**
 * jack_bauer - Entry point
 *
 *  * @void: no parameter
 *
 * Description: Function that prints every minute of
 * the day of Jack Bauer, starting from 00:00 to 23:59.
 *
 * Prototype: void jack_bauer(void);
 *
 */

void jack_bauer(void)
{
	int left, right;

	for (left = 0; left <= 23; left++)
	{
		for (right = 0; right <= 59; right++)
		{
			_putchar((left / 10) + '0');
			_putchar((left % 10) + '0');
			_putchar(':');
			_putchar((right / 10) + '0');
			_putchar((right % 10) + '0');
			_putchar('\n');
		}

	}
}
