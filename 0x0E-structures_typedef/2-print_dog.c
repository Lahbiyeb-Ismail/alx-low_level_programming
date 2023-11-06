#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Entry point
 *
 *  * @d: struct
 *
 * Description: Function that prints a struct dog
 *
 * Prototype: void print_dog(struct dog *d);
 *
 *
 * If an element of d is NULL, print (nil) instead of this element.
 * (if name is NULL, print Name: (nil))
 *
 * If d is NULL print nothing.
 *
 * Return: void
 *
 */

void print_dog(struct dog *d)
{
	if (!d)
		return;

	printf("Name: %s\n", (d->name ? d->name : "(nil)"));
	printf("Age: %f\n", (d->age ? d->age : 0));
	printf("Owner: %s\n", (d->owner ? d->owner : "(nil)"));
}

