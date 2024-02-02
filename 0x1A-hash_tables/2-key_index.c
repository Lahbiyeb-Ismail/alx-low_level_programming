#include "hash_tables.h"

/**
 * key_index - Computes the index of a key in a hash table.
 *
 * @key: A pointer to the key (a string) whose index needs to be calculated.
 * @size: The size of the hash table.
 *
 * Description:
 *   This function uses the DJB2 hash function to calculate the hash value
 *   of the given key and then computes the index where the key should be
 *   placed in the hash table based on the calculated hash value and the
 *   size of the hash table.
 *
 * Prototype:
 *   unsigned long int key_index(const unsigned char *key,
 * unsigned long int size);
 *
 * Return:
 *   The index in the hash table where the key should be placed.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* Calculate the hash value using the DJB2 hash function */
	unsigned long int hash_value = hash_djb2(key);

	/* Compute the index where the key should be placed in the hash table */
	return (hash_value % size);
}
