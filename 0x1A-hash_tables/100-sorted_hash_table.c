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
 *   A pointer to the created sorted hash table if successful,
 * or NULL on failure.
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
 *   This function adds a new key-value pair to the sorted hash table
 * or updates
 *   the value of an existing key. It uses the DJB2 hash function to compute
 *   the index where the key should be placed. If the key already exists
 *   in the sorted hash table, the function updates the value;
 * otherwise, it
 *   creates a new node and adds it to the appropriate bucket in the
 * hash table.
 *   Additionally, it maintains a sorted linked list based on the keys,
 * ensuring
 *   that the linked list is always in ascending order.
 *
 * Prototype:
 *   int shash_table_set(shash_table_t *ht, const char *key,
 * const char *value);
 *
 * Return:
 *   1 on success, 0 on failure (due to memory allocation or empty key).
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node = NULL;

	if (!ht || !key || !*key || !value)
		return (0);

	node = get_node(ht, key);

	if (node)
	{
		free(node->value);
		node->value = strdup(value);
		return (1);
	}

	node = create_node(key, value);
	if (!node)
		return (0);

	add_node(ht, node);

	return (1);
}

/**
 * get_node - Retrieves a node with a specific key from a sorted hash table.
 *
 * @ht: A pointer to the sorted hash table.
 * @key: The key to search for in the hash table.
 *
 * Description:
 *   This function searches for a node with a specific key in
 * a sorted hash table.
 *   It calculates the index using the DJB2 hash function and
 * then traverses the
 *   linked list at that index, comparing keys until a matching key is found or
 *   the end of the list is reached. If a match is found, the function returns
 *   a pointer to the matching node; otherwise, it returns NULL.
 *
 * Prototype:
 *   shash_node_t *get_node(shash_table_t *ht, const char *key);
 *
 * Return:
 *   A pointer to the found node with the specified key, or NULL if not found.
 */
shash_node_t *get_node(shash_table_t *ht, const char *key)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *tmp = ht->array[index];

	/* Traverse the linked list at the calculated index */
	while (tmp)
	{
			/* Check if the key of the current node matches the specified key */
		if (strcmp(tmp->key, key) == 0)
			return (tmp);

	/* Move to the next node in the linked list */
		tmp = tmp->next;
	}

	/* Return NULL if the key is not found in the linked list */
	return (NULL);
}


/**
 * create_node - Creates a new node with the given key and value.
 *
 * @key: The key for the new node.
 * @value: The value for the new node.
 *
 * Description:
 *   This function allocates memory for a new node in a sorted hash table. It
 *   creates a new `shash_node_t` structure and copies the provided key and
 *   value into the allocated memory. If successful, it returns a pointer to
 *   the newly created node; otherwise, it returns NULL. It is the caller's
 *   responsibility to manage the memory of the returned node.
 *
 * Prototype:
 *   shash_node_t *create_node(const char *key, const char *value);
 *
 * Return:
 *   A pointer to the newly created node if successful, or NULL on failure.
 */
shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

	/* Check if memory allocation for the new node is successful */
	if (!node)
		return (NULL);

/* Copy the provided key into the allocated memory */
	node->key = strdup(key);

	/* Check if memory allocation for the key is successful */
	if (!node->key)
	{
		free(node);
		return (NULL);
	}

	/* Copy the provided value into the allocated memory */
	node->value = strdup(value);

	/* Check if memory allocation for the value is successful */
	if (!node->value)
	{
			/* Free the memory for the key and the node itself */
		free(node->key);
		free(node);
		return (NULL);
	}

	/* Return a pointer to the newly created node */
	return (node);
}


/**
 * add_node - Adds a node to a sorted hash table, maintaining
 * order in linked list.
 *
 * @ht: A pointer to the sorted hash table.
 * @node: A pointer to the node to be added.
 *
 * Description:
 *   This function adds a node to a sorted hash table, maintaining the order
 *   in the linked list. It calculates the index using the DJB2 hash function
 *   and inserts the node at the beginning of the linked list at that index.
 *   The function also updates the sorted linked list to ensure it remains in
 *   ascending order based on the keys. If the sorted linked list is empty, the
 *   added node becomes both the head and tail of the list.
 *
 * Prototype:
 *   void add_node(shash_table_t *ht, shash_node_t *node);
 *
 * Return:
 *   This function does not return a value. It modifies
 * the hash table in place.
 */
void add_node(shash_table_t *ht, shash_node_t *node)
{
	unsigned long int index =
		key_index((const unsigned char *)node->key, ht->size);
	shash_node_t *tmp = NULL;

	/* Insert the node at the beginning of the linked list */
	node->next = ht->array[index];
	ht->array[index] = node;

	/* Update the sorted linked list based on key order */
	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		node->sprev = NULL;
		node->snext = NULL;
		return;
	}

	if (strcmp(ht->shead->key, node->key) > 0)
	{
		node->snext = ht->shead;
		node->sprev = NULL;
		ht->shead->sprev = node;
		ht->shead = node;
		return;
	}

	tmp = ht->shead;
	while (tmp->snext && strcmp(tmp->snext->key, node->key) < 0)
		tmp = tmp->snext;

	node->sprev = tmp;
	node->snext = tmp->snext;

	if (tmp->snext)
		tmp->snext->sprev = node;
	else
		ht->stail = node;

	tmp->snext = node;
}


/**
 * shash_table_get - Retrieves the value associated with a key in
 * a sorted hash table.
 *
 * @ht: A pointer to the sorted hash table.
 * @key: The key (a string) whose associated value is to be retrieved.
 *
 * Description:
 *   This function looks up the provided key in the sorted
 * hash table and returns the corresponding value if the key
 * is found. It uses the DJB2 hash function to compute the index
 * where the key should be located in the hash table.
 *   If the key is not found, the function returns NULL.
 * The search is performed in the ordered linked list, ensuring
 * quick access to the requested key.
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
 * shash_table_print - Prints the contents of a sorted hash table
 * in a key-value format.
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
 * shash_table_print_rev - Prints the contents of a sorted hash
 * table in reverse order.
 *
 * @ht: A pointer to the sorted hash table.
 *
 * Description:
 *   This function prints the key-value pairs stored in a sorted hash table in
 *   reverse order. It traverses the ordered linked list in reverse, starting
 *   from the tail, and prints the elements in a key-value format.
 * The output is enclosed in curly braces, and each key-value pair
 * is separated by a comma.
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
 *   This function frees the memory allocated for a sorted hash table,
 * including all its key-value pairs. It iterates through the ordered
 * linked list, freeing the memory for each element in reverse order.
 * Finally, it frees the array of
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

