#include "hash_tables.h"

/**
 * shash_table_create - Creates a new sorted hash table.
 *
 * @size: The size of the sorted hash table (number of buckets).
 *
 * Description:
 *   This function creates a new sorted hash table with a specified size. It
 *   allocates memory for the hash table structure, the array of buckets, and
 *   initializes the linked list head and tail pointers. The sorted hash table
 *   maintains an ordered linked list based on the hash values of the keys.
 *
 * Prototype:
 *   shash_table_t *shash_table_create(unsigned long int size);
 *
 * Return:
 *   A pointer to the created sorted hash table if successful, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	/* Allocate memory for the sorted hash table structure */
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

/* Set the size of the sorted hash table */
	ht->size = size;

	/* Allocate memory for the array of buckets */
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);

/* Initialize each bucket to NULL */
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

/* Initialize the sorted linked list head and tail pointers */
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}


/**
 * shash_table_set - Adds or updates a key-value pair in a sorted hash table.
 *
 * @ht: A pointer to the sorted hash table.
 * @key: The key (a string) to be added or updated in the hash table.
 * @value: The corresponding value associated with the key.
 *
 * Description:
 *   This function adds a new key-value pair to the sorted hash table or updates
 *   the value of an existing key. It uses the DJB2 hash function to compute
 *   the index where the key should be placed. If the key already exists
 *   in the sorted hash table, the function updates the value; otherwise, it
 *   creates a new node and adds it to the appropriate bucket in the hash table.
 *   Additionally, it maintains a sorted linked list based on the keys, ensuring
 *   that the linked list is always in ascending order.
 *
 * Prototype:
 *   int shash_table_set(shash_table_t *ht, const char *key, const char *value);
 *
 * Return:
 *   1 on success, 0 on failure (due to memory allocation or empty key).
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *value_copy;
	unsigned long int index;

	/* Check for NULL pointers and empty key or value */
	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

/* Create a copy of the value to be stored in the hash node */
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

/* Calculate the index using the DJB2 hash function */
	index = key_index((const unsigned char *)key, ht->size);

	/* Check if the key already exists in the sorted hash table */
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
				/* Update the value if the key already exists */
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}

	/* Allocate memory for a new hash node */
	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}

	/* Set the key, value, and next pointer for the new node */
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	/* Update the sorted linked list based on the keys */
	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}


/**
 * shash_table_get - Retrieves the value associated with a key in a sorted hash table.
 *
 * @ht: A pointer to the sorted hash table.
 * @key: The key (a string) whose associated value is to be retrieved.
 *
 * Description:
 *   This function looks up the provided key in the sorted hash table and returns
 *   the corresponding value if the key is found. It uses the DJB2 hash function
 *   to compute the index where the key should be located in the hash table.
 *   If the key is not found, the function returns NULL. The search is performed
 *   in the ordered linked list, ensuring quick access to the requested key.
 *
 * Prototype:
 *   char *shash_table_get(const shash_table_t *ht, const char *key);
 *
 * Return:
 *   A pointer to the value associated with the key, or NULL if not found
 *   or if the sorted hash table or key is NULL.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	/* Check if the sorted hash table or key is NULL or empty */
	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

/* Calculate the index using the DJB2 hash function */
	index = key_index((const unsigned char *)key, ht->size);

	/* Ensure the index is within the valid range of the array */
	if (index >= ht->size)
		return (NULL);

/* Traverse the ordered linked list to find the key */
	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

/* Return the value associated with the key, or NULL if not found */
	return ((node == NULL) ? NULL : node->value);
}


/**
 * shash_table_print - Prints the contents of a sorted hash table in a key-value format.
 *
 * @ht: A pointer to the sorted hash table.
 *
 * Description:
 *   This function prints the key-value pairs stored in a sorted hash table. It
 *   iterates through the ordered linked list in the hash table and prints the
 *   elements in a key-value format. The output is enclosed in curly braces and
 *   each key-value pair is separated by a comma. If the sorted hash table is
 *   empty, it prints an empty set of curly braces.
 *
 * Prototype:
 *   void shash_table_print(const shash_table_t *ht);
 *
 * Return:
 *   This function does not return a value.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	/* Check if the sorted hash table is NULL */
	if (ht == NULL)
		return;

/* Initialize the node pointer to the head of the ordered linked list */
	node = ht->shead;

	/* Print the opening curly brace for the entire sorted hash table */
	printf("{");

	/* Traverse the ordered linked list and print key-value pairs */
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;

		/* Print a comma if there are more key-value pairs in the list */
		if (node != NULL)
			printf(", ");
	}

	/* Print the closing curly brace for the entire sorted hash table */
	printf("}\n");
}


/**
 * shash_table_print_rev - Prints the contents of a sorted hash table in reverse order.
 *
 * @ht: A pointer to the sorted hash table.
 *
 * Description:
 *   This function prints the key-value pairs stored in a sorted hash table in
 *   reverse order. It traverses the ordered linked list in reverse, starting
 *   from the tail, and prints the elements in a key-value format. The output is
 *   enclosed in curly braces, and each key-value pair is separated by a comma.
 *   If the sorted hash table is empty, it prints an empty set of curly braces.
 *
 * Prototype:
 *   void shash_table_print_rev(const shash_table_t *ht);
 *
 * Return:
 *   This function does not return a value.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	/* Check if the sorted hash table is NULL */
	if (ht == NULL)
		return;

/* Initialize the node pointer to the tail of the ordered linked list */
	node = ht->stail;

	/* Print the opening curly brace for the entire sorted hash table */
	printf("{");

	/* Traverse the ordered linked list in reverse and print key-value pairs */
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;

		/* Print a comma if there are more key-value pairs in reverse order */
		if (node != NULL)
			printf(", ");
	}

	/* Print the closing curly brace for the entire sorted hash table */
	printf("}\n");
}


/**
 * shash_table_delete - Deletes a sorted hash table and its elements.
 *
 * @ht: A pointer to the sorted hash table to be deleted.
 *
 * Description:
 *   This function frees the memory allocated for a sorted hash table, including
 *   all its key-value pairs. It iterates through the ordered linked list, freeing
 *   the memory for each element in reverse order. Finally, it frees the array of
 *   buckets and the sorted hash table structure itself.
 *
 * Prototype:
 *   void shash_table_delete(shash_table_t *ht);
 *
 * Return:
 *   This function does not return a value.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *tmp;

	/* Check if the sorted hash table is NULL */
	if (ht == NULL)
		return;

/* Initialize the node pointer to the head of the ordered linked list */
	node = ht->shead;

	/* Traverse the ordered linked list and free memory for each element */
	while (node)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	/* Free the array of buckets and the sorted hash table structure itself */
	free(head->array);
	free(head);
}

