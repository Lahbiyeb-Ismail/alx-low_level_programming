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
	unsigned long int i;
	hash_node_t *node;
	char *comma = "";

	/* Check if the hash table is NULL */
	if (ht == NULL)
		return;

/* Print the opening curly brace for the entire hash table */
	printf("{");

	/* Iterate through each bucket in the hash table */
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		/* Traverse the linked list at the current bucket */
		while (node)
		{
			printf("%s'%s': '%s'", comma, node->key, node->value);
			comma = ", ";
			node = node->next;
		}
	}

	/* Print the closing curly brace for the entire hash table */
	printf("}\n");
}

