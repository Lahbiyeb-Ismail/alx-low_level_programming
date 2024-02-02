#include "hash_tables.h"

/**
 * hash_table_print - Prints the contents of a hash table in JSON-like format.
 *
 * @ht: A pointer to the hash table.
 *
 * Description:
 *   This function prints the key-value pairs stored in a hash table in a
 *   JSON-like format. It iterates through each bucket in the hash table and
 *   prints the elements of the linked list at each bucket. The output is
 *   enclosed in curly braces, and each key-value pair is formatted as
 *   "'key': 'value'" separated by commas. The entire hash table is enclosed
 *   in curly braces.
 *
 * Prototype:
 *   void hash_table_print(const hash_table_t *ht);
 *
 * Return:
 *   This function does not return a value.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	unsigned char comma_flag = 0;

	/* Check if the hash table is NULL */
	if (ht == NULL)
		return;

/* Print the opening curly brace for the entire hash table */
	printf("{");

	/* Iterate through each bucket in the hash table */
	for (i = 0; i < ht->size; i++)
	{
			/* Check if the current bucket is not empty */
		if (ht->array[i] != NULL)
		{
				/* Add a comma separator if it's not the first non-empty bucket */
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[i];

			/* Traverse the linked list at the current bucket */
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;

				/* Print a comma if there are more key-value pairs in the bucket */
				if (node != NULL)
					printf(", ");
			}

			/* Set the comma flag to indicate that a comma has been printed */
			comma_flag = 1;
		}
	}
	/* Print the closing curly brace for the entire hash table */
	printf("}\n");
}

