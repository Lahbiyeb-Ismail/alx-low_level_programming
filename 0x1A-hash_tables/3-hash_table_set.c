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
	hash_node_t *new;
	char *value_copy;
	unsigned long int index, i;

	/* Check for NULL pointers and empty key or value */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
/* Create a copy of the value to be stored in the hash node */
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	/* Linear probing to find an empty slot or the key in the hash table */
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
				/* Update the value if the key already exists */
			free(ht->array[i]->value);
			ht->array[i]->value = value_copy;
			return (1);
		}
	}
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	/* Set the key, value, and next pointer for the new node */
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}
