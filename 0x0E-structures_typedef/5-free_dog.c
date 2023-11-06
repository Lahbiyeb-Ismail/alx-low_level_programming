#include "dog.h"

/**
 * free_dog - Entry point
 *
 *  * @d: struct dog to be free
 *
 * Description: Function that frees dogs.
 *
 * Prototype: void free_dog(dog_t *d);
 *
 * Return: void
 *
 */

void free_dog(dog_t *d)
{
	if (!d)
		return;

	free(d->name);
	free(d->owner);
	free(d);

}

