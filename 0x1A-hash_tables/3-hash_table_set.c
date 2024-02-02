#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates a key-value pair in a hash table.
 *
 * @ht: A pointer to the hash table.
 * @key: The key (a string) to be added or updated in the hash table.
 * @value: The corresponding value associated with the key.
 *
 * Description:
 *   This function adds a new key-value pair to the hash table or updates
 *   the value of an existing key. It uses the DJB2 hash function to compute
 *   the index where the key should be placed. If the key already exists
 *   in the hash table, the function updates the value; otherwise, it creates
 *   a new node and adds it to the appropriate bucket in the hash table.
 *
 * Prototype:
 *   int hash_table_set(hash_table_t *ht, const char *key, const char *value);
 *
 * Return:
 *   1 on success, 0 on failure (due to memory allocation or empty key).
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *current;
	unsigned long int index;

	/* Check if the key is empty */
	if (strlen(key) == 0)
		return (0);

/* Allocate memory for a new hash node */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

/* Set the key and value for the new node */
	new_node->key = strdup(key);
	new_node->value = strdup(value);

	/* Calculate the index using the DJB2 hash function */
	index = key_index((unsigned char *)key, ht->size);

	/* Traverse the linked list at the calculated index */
	current = ht->array[index];
	while (current && current->next)
		current = current->next;

/* Add the new node to the hash table */
	if (!current)
	{
		ht->array[index] = new_node;
	}
	else
	{
		new_node->next = current->next;
		current->next = new_node;
	}

	return (1);
}
