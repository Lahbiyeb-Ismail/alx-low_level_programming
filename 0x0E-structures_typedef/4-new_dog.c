#include "dog.h"

char *_strcpy(char *str);

/**
 * new_dog - Entry point
 *
 *  * @name: char pointer
 *  * @age: float
 *  * @owner: owner
 *
 * Description: Function that creates a new dog.
 *
 * Prototype: dog_t *new_dog(char *name, float age, char *owner);
 *
 *
 * You have to store a copy of name and owner
 *
 * Return NULL if the function fails
 *
 * Return: void
 *
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;

	newDog = malloc(sizeof(dog_t));

	if (!newDog)
		return (NULL);

	newDog->name = _strcpy(name);

	if (!newDog->name)
	{
		free(newDog);
		return (NULL);
	}

	newDog->owner = _strcpy(owner);
	if (!newDog->owner)
	{
		free(newDog);
		free(newDog->name);
		return (NULL);
	}

	newDog->age = age;

	return (newDog);
}

/**
 * _strcpy - Entry point
 *
 *  * @str: pointer to a string
 *
 * Description: that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 *
 * Prototype: char *_strcpy(char *dest, char *src);
 *
 * Return: the pointer to dest
 *
 */

char *_strcpy(char *str)
{
	int i, j, len = 0;
	char *new;

	for (j = 0; str[j] != '\0'; j++)
		len++;

	new = malloc(sizeof(char) * len + 1);

	if (!new)
		return (NULL);

	for (i = 0; i < len; i++)
		new[i] = str[i];

	new[i] = '\0';

	return (new);
}
