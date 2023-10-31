#include <stdio.h>
#include <stdlib.h>


/**
 * argstostr - Entry point
 *
 *  * @ac: arguments count
 *  * @av: arguments value
 *
 * Description: Function that concatenates all the arguments of
 * your program.
 *
 * Prototype: char *argstostr(int ac, char **av);
 *
 * Returns NULL if ac == 0 or av == NULL
 *
 * Returns a pointer to a new string, or NULL if it fails
 *
 * Each argument should be followed by a \n in the new string
 *
 *
 * Return: A pointer to a new string
 *
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int acIdx, avIdx, strIdx, strLen;

	if (ac == 0 || av == NULL)
		return (NULL);

	strLen = 0;

	for (acIdx = 0; acIdx < ac; acIdx++)
		for (avIdx = 0; av[acIdx][avIdx]; avIdx++)
			strLen++;

	str = malloc((strLen + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);


	strIdx = 0;

	for (acIdx = 0; acIdx < ac; acIdx++)
	{
		for (avIdx = 0; av[acIdx][avIdx]; avIdx++)
			str[strIdx++] = av[acIdx][avIdx];

		str[strIdx++] = '\n';
	}

	str[strIdx] = '\0';
	return (str);
}
