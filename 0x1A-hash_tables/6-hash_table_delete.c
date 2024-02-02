#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its elements.
 *
 * @ht: A pointer to the hash table to be deleted.
 *
 * Description:
 *   This function frees the memory allocated for a hash table, including
 *   all its key-value pairs. It iterates through each bucket in the
 * hash table,
 *   freeing the memory for each element in the linked list. Finally, it frees
 *   the array of buckets and the hash table structure itself.
 *
 * Prototype:
 *   void hash_table_delete(hash_table_t *ht);
 *
 * Return:
 *   This function does not return a value.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *tmp;
	unsigned long int i;

	/* Iterate through each bucket in the hash table */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		/* Traverse the linked list at the current bucket */
		while (node)
		{
			tmp = node;
			node = node->next;

			/* Free memory for key, value, and the hash node */
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}

	/* Free the array of buckets and the hash table structure itself */
	free(ht->array);
	free(ht);
}
