#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Double pointer to the head of the list.
 * @idx: Index of the list where the new node should be added. Starts at 0.
 * @n: Value to be assigned to the data (n) of the new node.
 *
 * Return: Address of the new node.
 *         NULL if it failed to add the new node or if it's not possible to add index idx.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *N, *current_node;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	if (idx == 0)
		return (add_nodeint_end(head,n));
	current_node = *head;
	for (i = 0; i < idx - 1 && current_node != NULL; i++)
	{
		current_node = current_node->next;
	}

	if (current_node == NULL)
		return (NULL);

	N = malloc(sizeof(listint_t));
	if (N == NULL)
		return (NULL);
	
	N->n = n;
	N->next = current_node->next;
	current_node->next = N;

	return (N);
}
