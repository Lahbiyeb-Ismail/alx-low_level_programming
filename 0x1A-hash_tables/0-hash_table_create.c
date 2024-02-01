#include "hash_tables.h"

/**
 * hash_table_create - Create a new hash table with a specified size.
 *
 * @size: The size of the hash table (number of buckets).
 *
 * Description:
 *   This function dynamically allocates memory for a new hash table
 *   structure and an array of pointers to hash nodes. The size of the
 *   hash table is set to the specified 'size'. If any memory allocation
 *   fails during the process, the function frees the allocated memory
 *   and returns NULL to indicate failure.
 *
 * Prototype:
 *   hash_table_t *hash_table_create(unsigned long int size);
 *
 * Return:
 *   A pointer to the created hash table if successful, or NULL on failure.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	/* Allocate memory for the hash table structure */
	hash_table_t *ht = malloc(sizeof(hash_table_t));

	/* Check if memory allocation was successful */
	if (!ht)
		return (NULL);

	/* Set the size of the hash table */
	ht->size = size;

	/* Allocate memory for the array of hash nodes */
	ht->array = malloc(sizeof(hash_node_t *) * size);

	/* Check if memory allocation for the array was successful */
	if (!ht->array)
	{
		/* Free the previously allocated memory for the hash table structure */
		free(ht);
		return (NULL);
	}

	/* Return the created hash table */
	return (ht);
}
