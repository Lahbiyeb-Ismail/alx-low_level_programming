#include <stdio.h>

/**
* main - causes an infinite loop
*
* Comment out (don’t delete it!) the part of the code that is
* causing the  output to go into an infinite loop.
* Don’t add or remove any lines of code, as we will be
* checking your line * count. You are only allowed to
* comment out existing code.
* You do not have to compile with
* -Wall -Werror -Wextra -pedantic for
* this task.
*
* Return: 0
*/

int main(void)
{
	int i;

	printf("Infinite loop incoming :(\n");

	i = 0;

	/**
	* while (i < 10)
	* {
	*	putchar(i);
	* }
	*/

	printf("Infinite loop avoided! \\o/\n");

	return (0);
}
