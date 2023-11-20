#include "lists.h"

/**
 * pop_listint - Entry point
 *
 * * @head: linked list head
 *
 * Description: Function that deletes the head node of a listint_t linked
 * list, and returns the head node’s data (n).
 *
 * Prototype: int pop_listint(listint_t **head);
 *
 * Return: the head node’s data (n) or (0) if the list is empty
 *
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *currNode;

	currNode = *head;

	if (currNode == NULL)
		return (0);


	(*head) = currNode->next;
	n = currNode->n;

	free(currNode);

	return (n);
}
