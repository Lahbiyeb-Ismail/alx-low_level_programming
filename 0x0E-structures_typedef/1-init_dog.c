#include "dog.h"

/**
 * init_dog - Entry point
 *
 *  * @d: struct
 *  * @name: char pointer
 *  * @age: float
 *  * @owner: owner
 *
 * Description: Function that initialize a variable of type struct dog
 *
 *
 * Return: void
 *
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (!d)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;

	/**
	 * (*d).name = name;
	 * (*d).age = age;
	 * (*d).owner = owner;
	*/
}

