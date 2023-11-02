#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - Entry point
 *
 *  * @ptr: a pointer to the memory previously allocated with a call to
 * malloc: malloc(old_size)
 *  * @old_size: is the size, in bytes, of the allocated space for ptr
 *  * @new_size: is the new size, in bytes of the new memory block
 *
 * Description: Function that reallocates a memory block using malloc and
 * free
 *
 * Prototype:
 * void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
 *
 * where ptr is a pointer to the memory previously allocated with a call
 * to malloc: malloc(old_size)
 *
 * old_size is the size, in bytes, of the allocated space for ptr
 *
 * and new_size is the new size, in bytes of the new memory block
 *
 * The contents will be copied to the newly allocated space, in the range
 * from the start of ptr up to the minimum of the old and new sizes
 *
 * If new_size > old_size, the “added” memory should not be initialized
 *
 * If new_size == old_size do not do anything and return ptr
 *
 * If ptr is NULL, then the call is equivalent to malloc(new_size), for
 * all values of old_size and new_size
 *
 * If new_size is equal to zero, and ptr is not NULL, then the call is
 * equivalent to free(ptr). Return NULL
 *
 *
 * Return: the pointer to the newly allocated memory block
 *
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_ptr;
	unsigned int i;
	unsigned int size;


	/*If new_size == old_size do not do anything and return ptr*/
	if (new_size == old_size)
		return (ptr);

	/**
	 * If new_size is equal to zero, and ptr is not NULL, then the call is
	 * equivalent to free(ptr). Return NULL
	*/
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_ptr = ptr;

	/*If new_size > old_size, the “added” memory should not be initialized*/
	if (new_size > old_size)
		size = old_size;
	else
		size = new_size;

	for (i = 0; i < size; i++)
		new_ptr[i] = old_ptr[i];

	free(ptr);
	return (new_ptr);
}


















/*
 char *new_ptr;
char *old_ptr;
unsigned int i;

if (new_size == old_size)
return (ptr);

if (!ptr)
return (malloc(new_size));

if (new_size == 0 && ptr)
{
	free(ptr);
	return (NULL);
}

new_ptr = malloc(new_size);

if (!new_ptr)
return (NULL);

old_ptr = ptr;

if (new_size < old_size)
{
	for (i = 0; i < new_size; i++)
		new_ptr[i] = old_ptr[i];
}


if (new_size > old_size)
{
	for (i = 0; i < old_size; i++)
		new_ptr[i] = old_ptr[i];
}

free(ptr);
return (new_ptr);*/
