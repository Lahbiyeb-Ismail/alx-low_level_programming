#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table.
 *
 * @ht: A pointer to the hash table.
 * @key: The key (a string) whose associated value is to be retrieved.
 *
 * Description:
 *   This function looks up the provided key in the hash table and returns
 *   the corresponding value if the key is found. It uses the DJB2 hash
 * function to compute the index where the key should be located in the*
 *   hash table.
 *   If the key is not found, the function returns NULL.
 *
 * Prototype:
 *   char *hash_table_get(const hash_table_t *ht, const char *key);
 *
 * Return:
 *   A pointer to the value associated with the key, or NULL if not found
 *   or if the hash table or key is NULL.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	/* Check if the hash table or key is NULL */
	if (!ht || !key)
		return (NULL);

/* Calculate the index using the DJB2 hash function */
	index = key_index((unsigned char *)key, ht->size);

	/* Traverse the linked list at the calculated index */
	node = ht->array[index];

	/* Search for the key in the linked list */
	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			return (node->value);
		}
		node = node->next;
	}

	/* Key not found in the hash table */
	return (NULL);
}

